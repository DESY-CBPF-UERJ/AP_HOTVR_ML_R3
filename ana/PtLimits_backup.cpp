#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace PtLimits{

    int jet_flav_2prong_parton_match_b;

    int npu_b;
    float met_b;
    float jet_pt_b;
    float jet_eta_b;
    float jet_phi_b;
    float jet_mass_b;
    float jet_softdrop_mass_b;
    int jet_partonjet_match_b;
    int jet_resjet_match_b;
    float R_ref;
    float Z_pt;
    float jet_pt_truth_b;
    float jet_eta_truth_b;
    float jet_phi_truth_b;
    float jet_mass_truth_b;
    float ratio_jetres_pt;
    float ratio_jetres_mass;
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupPtLimits() {

    //======SETUP CUTFLOW==========================================================================
    _cutFlow.insert(pair<string,double>("Total", 0) );
    _cutFlow.insert(pair<string,double>("RejEvents", 0) );
    _cutFlow.insert(pair<string,double>("RejBaseCuts", 0) );
    _cutFlow.insert(pair<string,double>("RejSignalResCuts", 0) );
    _cutFlow.insert(pair<string,double>("RejJetId", 0) );
    _cutFlow.insert(pair<string,double>("RejLeptonContent", 0) );
    _cutFlow.insert(pair<string,double>("RejMassCut", 0) );
    _cutFlow.insert(pair<string,double>("Selected", 0) );

    //======SETUP HISTOGRAMS=======================================================================
    //makeHist( "histogram1DName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeHist( "histogram2DName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP SYSTEMATIC HISTOGRAMS============================================================
    //sys_regions = { 0, 1, 2 }; [example] // Choose regions as defined in RegionID. Empty vector means that all events will be used.
    //makeSysHist( "histogram1DSysName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeSysHist( "histogram2DSysName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP OUTPUT BRANCHES==================================================================
    //_outputTree->Branch("variable1NameInTheTree", &PtLimits::variable1Name );  [example]

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    HDF_insert("npu",&PtLimits::npu_b);
    HDF_insert("met",&PtLimits::met_b);
    HDF_insert("jet_pt",&PtLimits::jet_pt_b);
    HDF_insert("jet_eta",&PtLimits::jet_eta_b);
    HDF_insert("jet_phi",&PtLimits::jet_phi_b);
    HDF_insert("jet_mass",&PtLimits::jet_mass_b);
    HDF_insert("jet_softdrop_mass",&PtLimits::jet_softdrop_mass_b);
    HDF_insert("jet_partonjet_match",&PtLimits::jet_partonjet_match_b);
    HDF_insert("jet_resjet_match", &PtLimits::jet_resjet_match_b );
    HDF_insert("R_ref", &PtLimits::R_ref );
    HDF_insert("Z_pt", &PtLimits::Z_pt );
    HDF_insert("jet_pt_truth",&PtLimits::jet_pt_truth_b);
    HDF_insert("jet_eta_truth",&PtLimits::jet_eta_truth_b);
    HDF_insert("jet_phi_truth",&PtLimits::jet_phi_truth_b);
    HDF_insert("jet_mass_truth",&PtLimits::jet_mass_truth_b);
    HDF_insert("ratio_jetres_pt",&PtLimits::ratio_jetres_pt);
    HDF_insert("ratio_jetres_mass",&PtLimits::ratio_jetres_mass);

    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::PtLimitsRegion() {

    //-------------------------------------------------------------------------
    // Cut description
    //-------------------------------------------------------------------------
    //if( !(CutCondition) ) return false;           [Example]
    //_cutFlow.at("CutName") += evtWeight;          [Example]

    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::PtLimitsSelection() {


    /// Simple object to store resonance and daughter GEN kinematics
    class Resonance {
    public:
        Resonance(){};
        ~Resonance(){};
        TLorentzVector p4;
        std::vector<int> daugid;
        std::vector<TLorentzVector> daugp4;
    };

    /// thresholds for matching
    float dRMatchingPF = 0.1;
    float ptGenLeptonMin  = 8;
    float ptGenTauVisibleMin = 15;

    /// Global parameters
    int pfcand_lenght = 100;
    int sv_lenght = 10;
    float jetPtMax = 2500; // Max jet pT to apply
    float jetPtMin = 80; // Min jet pT to apply
    float jetEtaMax = 2.5; // Max jet eta to apply
    float jetEtaMin = 0.; // Min jet eta to apply
    float jetMassTruthMin = 50; // Min mass selection to apply based on the truth definition given in the code
    float pfCandPtMin = 0.; // Minimum pf candidate pt
    float pfCandPuppiWeightMin = 0.; // Minimum pf candidate puppi weight
    bool saveOnlyGenMatchedJets = false; // save or not jets matched to GEN jets
    bool saveOnlyResonanceMatchedJets = false; // In case of signal type of sample, save only jets matched to a resonance
    bool saveLeptonOppositeFlavor = false; // save or not jets matched to two GEN leptons of opposite flavour


    // Gen leptons from resonance decay as well as neutrinos
    std::vector<TLorentzVector> genLepFromResonance4V;
    std::vector<TLorentzVector> genMuonsFromResonance4V;
    std::vector<TLorentzVector> genElectronsFromResonance4V;
    std::vector<int> genMuonsFromResonanceCharge;
    std::vector<int> genElectronsFromResonanceCharge;


    for(size_t igen = 0; igen < gen_particle_pt->size(); igen++){
      // select resonances like Higgs, W, Z, taus
      if(abs(gen_particle_id->at(igen)) == 25 or
        abs(gen_particle_id->at(igen)) == 23 or
        abs(gen_particle_id->at(igen)) == 6 or
        abs(gen_particle_id->at(igen)) == 15){
        for(size_t idau = 0; idau < gen_particle_daughters_id->size(); idau++){
          // select electrons or muons from the resonance / tau decay
          if(gen_particle_daughters_igen->at(idau) == igen and
            (abs(gen_particle_daughters_id->at(idau)) == 11 or
            abs(gen_particle_daughters_id->at(idau)) == 13)){
            TLorentzVector gen4V;
            gen4V.SetPtEtaPhiM(gen_particle_daughters_pt->at(idau),gen_particle_daughters_eta->at(idau),gen_particle_daughters_phi->at(idau),gen_particle_daughters_mass->at(idau));
            if(std::find(genLepFromResonance4V.begin(),genLepFromResonance4V.end(),gen4V) == genLepFromResonance4V.end())
              genLepFromResonance4V.push_back(gen4V);
            if(abs(gen_particle_daughters_id->at(idau)) == 13 and
              std::find(genMuonsFromResonance4V.begin(),genMuonsFromResonance4V.end(),gen4V) == genMuonsFromResonance4V.end()){
              genMuonsFromResonance4V.push_back(gen4V);
              genMuonsFromResonanceCharge.push_back(gen_particle_daughters_charge->at(idau));
            }
            if(abs(gen_particle_daughters_id->at(idau)) == 11 and
              std::find(genElectronsFromResonance4V.begin(),genElectronsFromResonance4V.end(),gen4V) == genElectronsFromResonance4V.end()){
              genElectronsFromResonance4V.push_back(gen4V);
              genElectronsFromResonanceCharge.push_back(gen_particle_daughters_charge->at(idau));
            }
          }
        }
      }
    }

    // Gen hadronic taus
    std::vector<TLorentzVector> tau_gen_visible;
    std::vector<TLorentzVector> tau_gen;
    std::vector<int> tau_gen_charge;
    std::vector<unsigned int> tau_gen_nch;
    std::vector<unsigned int> tau_gen_np0;
    std::vector<unsigned int> tau_gen_nnh;

    for(size_t igen = 0; igen < gen_particle_pt->size(); igen++){
      if(abs(gen_particle_id->at(igen)) == 15){ // hadronic or leptonic tau
        TLorentzVector tau_gen_tmp;
        unsigned int tau_gen_nch_tmp = 0;
        unsigned int tau_gen_np0_tmp = 0;
        unsigned int tau_gen_nnh_tmp = 0;
        for(size_t idau = 0; idau < gen_particle_daughters_pt->size(); idau++){
          if(gen_particle_daughters_igen->at(idau) == igen and
            abs(gen_particle_daughters_id->at(idau)) != 11 and // no mu
            abs(gen_particle_daughters_id->at(idau)) != 13 and // no el
            abs(gen_particle_daughters_id->at(idau)) != 12 and // no neutrinos
            abs(gen_particle_daughters_id->at(idau)) != 14 and
            abs(gen_particle_daughters_id->at(idau)) != 16){
            TLorentzVector tmp4V;
            tmp4V.SetPtEtaPhiM(gen_particle_daughters_pt->at(idau),gen_particle_daughters_eta->at(idau),gen_particle_daughters_phi->at(idau),gen_particle_daughters_mass->at(idau));
            tau_gen_tmp += tmp4V;
            if (gen_particle_daughters_charge->at(idau) != 0 and gen_particle_daughters_status->at(idau) == 1) tau_gen_nch_tmp ++; // charged particles
            else if(gen_particle_daughters_charge->at(idau) == 0 and gen_particle_daughters_id->at(idau) == 111) tau_gen_np0_tmp++;
            else if(gen_particle_daughters_charge->at(idau) == 0 and gen_particle_daughters_id->at(idau) != 111) tau_gen_nnh_tmp++;
          }
        }
        if(tau_gen_tmp.Pt() > 0){ // good hadronic tau
          tau_gen_visible.push_back(tau_gen_tmp);
          tau_gen_tmp.SetPtEtaPhiM(gen_particle_pt->at(igen),gen_particle_eta->at(igen),gen_particle_phi->at(igen),gen_particle_mass->at(igen));
          tau_gen_charge.push_back((gen_particle_id->at(igen) > 0) ? -1 : 1);
          tau_gen.push_back(tau_gen_tmp);
          tau_gen_nch.push_back(tau_gen_nch_tmp);
          tau_gen_np0.push_back(tau_gen_np0_tmp);
          tau_gen_nnh.push_back(tau_gen_nnh_tmp);
        }
      }
    }

    // Build 2-prong resonances matching Higgs/W/Z pdgId
    bool badGenEvent = false;
    std::vector<Resonance> resonances;
    std::vector<unsigned int> skipTaus;
    for(size_t igen = 0; igen < gen_particle_pt->size(); igen++){
      if(abs(gen_particle_id->at(igen)) == 25 or
        abs(gen_particle_id->at(igen)) == 23 or
        abs(gen_particle_id->at(igen)) == 6){
        TLorentzVector resonace4V;
        resonace4V.SetPtEtaPhiM(gen_particle_pt->at(igen),gen_particle_eta->at(igen),gen_particle_phi->at(igen),gen_particle_mass->at(igen));
        resonances.push_back(Resonance());
        resonances.back().p4 = resonace4V;
        for(size_t idau = 0; idau < gen_particle_daughters_id->size(); idau++){
          if(gen_particle_daughters_igen->at(idau) == igen){
            resonances.back().daugid.push_back(gen_particle_daughters_id->at(idau));
            TLorentzVector daughter4V;
            daughter4V.SetPtEtaPhiM(gen_particle_daughters_pt->at(idau),gen_particle_daughters_eta->at(idau),gen_particle_daughters_phi->at(idau),gen_particle_daughters_mass->at(idau));
            resonances.back().daugp4.push_back(daughter4V);
          }
        }
        if((resonances.back().daugp4.size() != 2) and (abs(gen_particle_id->at(igen)) > 20)){
          std::cerr<<"Found more than two decay particles from Higgs or W or Z --> please check!!! --> rejecting the event"<<std::endl;
          badGenEvent = true;
        }else if((resonances.back().daugp4.size() != 3) and (abs(gen_particle_id->at(igen)) == 6)){
          std::cerr<<"Found more than three decay particles from top --> please check!!! --> rejecting the event"<<std::endl;
          badGenEvent = true;
        }

        // replace the tau gen kinematics with visible one for the daughters
        for(size_t idau = 0; idau > resonances.back().daugp4.size(); idau++){
          if(abs(resonances.back().daugid.at(idau)) == 15){
            float minDR  = 1000;
            int tauIndex = -1;
            for(size_t itau = 0; itau < tau_gen_visible.size(); itau++){
              if(tau_gen_visible.at(itau).DeltaR(resonances.back().daugp4.at(idau)) < minDR and std::find(skipTaus.begin(),skipTaus.end(),itau) == skipTaus.end()){
                resonances.back().daugp4.at(idau) = tau_gen_visible.at(itau);
                tauIndex = itau;
              }
            }
            skipTaus.push_back(tauIndex);
          }
        }
      }
    }

    if(badGenEvent){
      _cutFlow.at("RejEvents") += 1;
      return;
    }

    // list used later in the jet-event loop
    std::vector<unsigned int> vetoResonancePosition;

    /// Loop over the main jet collection
    for(size_t ijet = 0; ijet < jet_pt->size(); ijet++){

      string dsName = _datasetName.substr(0,_datasetName.length()-5);
      float dRCone;
      float dRConeCounting;
      float dRMatchingDaughterJet;
      float dRMatchingDaughters;
      if( dsName.substr(dsName.length()-4,dsName.length()) == "_AK8" ){
        dRCone = 0.8;
        dRConeCounting = 0.8;
        dRMatchingDaughterJet = 0.8;
        dRMatchingDaughters = 0.8;
      }else{
        float R_HOTVR = 600/jet_pt->at(ijet);
        if( R_HOTVR > 1.5 ) R_HOTVR = 1.5;
        if( R_HOTVR < 0.1 ) R_HOTVR = 0.1;
        dRCone = R_HOTVR;
        dRConeCounting = R_HOTVR;
        dRMatchingDaughterJet = R_HOTVR;
        dRMatchingDaughters = R_HOTVR;
      }
      PtLimits::R_ref = dRCone;

      _cutFlow.at("Total") += 1;

      ///// Selection
      if(jet_pt->at(ijet) < jetPtMin or
        jet_pt->at(ijet) > jetPtMax or
        fabs(jet_eta->at(ijet)) > jetEtaMax or
        fabs(jet_eta->at(ijet)) < jetEtaMin or
        saveOnlyGenMatchedJets){
        _cutFlow.at("RejBaseCuts") += 1;
        continue;
      }

      //// Jet 4V
      TLorentzVector jet4V;
      jet4V.SetPtEtaPhiM(jet_pt->at(ijet),jet_eta->at(ijet),jet_phi->at(ijet),jet_mass->at(ijet));

      // Matching with the resonance for signal jets using the kinematics
      int match_index_dR_parton_jet = -1;
      int match_index_dR_partons = -1;
      float mindR_jetres = 1000;
      PtLimits::jet_resjet_match_b = 0;
      for(size_t ipair = 0; ipair < resonances.size(); ipair++){
        float dRjres = jet4V.DeltaR(resonances.at(ipair).p4);
        if(dRjres < dRCone and dRjres < mindR_jetres){
          PtLimits::jet_resjet_match_b = 1;
          mindR_jetres = dRjres;
          float dR1 = resonances.at(ipair).daugp4.front().DeltaR(jet4V);
          float dR2 = resonances.at(ipair).daugp4.back().DeltaR(jet4V);
          float dR  = resonances.at(ipair).daugp4.front().DeltaR(resonances.at(ipair).daugp4.back());
          if(dR1 < dRMatchingDaughterJet and dR2 < dRMatchingDaughterJet)
            match_index_dR_parton_jet = ipair;
          if(dR < dRMatchingDaughters)
            match_index_dR_partons = ipair;
        }
      }




      // matching based on dR parton-jet
      if(match_index_dR_parton_jet != -1 and resonances.at(match_index_dR_parton_jet).daugid.size() == 2){
        if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) == 15 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) == 15)// X(tt)
          PtLimits::jet_partonjet_match_b = 7;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) == 5 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) == 5) // X(bb)
          PtLimits::jet_partonjet_match_b = 6;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) == 4 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) == 4) // X(cc)
          PtLimits::jet_partonjet_match_b = 5;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) <= 3 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) <= 3) // X(qq)
          PtLimits::jet_partonjet_match_b = 4;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) == 21 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) == 21) // X(gg)
          PtLimits::jet_partonjet_match_b = 3;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) == 13 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) == 13) // X(mm)
          PtLimits::jet_partonjet_match_b = 2;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) == 11 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) == 11) // X(ee)
          PtLimits::jet_partonjet_match_b = 1;
        else
          PtLimits::jet_partonjet_match_b = 0; // whatever remains
      }
      else
        PtLimits::jet_partonjet_match_b = -1; // only real QCD jets / not-matched resonances

      // matching based on dR parton-parton
      if(match_index_dR_partons != -1 and resonances.at(match_index_dR_partons).daugid.size() == 2){
        if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 15 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 15) // X(tt)
          PtLimits::jet_flav_2prong_parton_match_b = 7;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 5 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 5) // X(bb)
          PtLimits::jet_flav_2prong_parton_match_b = 6;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 4 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 4) // X(cc)
          PtLimits::jet_flav_2prong_parton_match_b = 5;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) <= 3 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) <= 3) // X(qq)
          PtLimits::jet_flav_2prong_parton_match_b = 4;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 21 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 21) // X(gg)
          PtLimits::jet_flav_2prong_parton_match_b = 3;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 13 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 13) // X(mm)
          PtLimits::jet_flav_2prong_parton_match_b = 2;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 11 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 11) // X(ee)
          PtLimits::jet_flav_2prong_parton_match_b = 1;
        else
          PtLimits::jet_flav_2prong_parton_match_b = 0; // whatever remains
      }
      else
        PtLimits::jet_flav_2prong_parton_match_b = -1;  // only real QCD jets / not-matched resonances

      // for signal samples exclude all jets unmatched (if enabled) to avoid labelling as QCD signal jets that are not matched to a resonance
      //if(saveOnlyResonanceMatchedJets and PtLimits::jet_partonjet_match_b == -1 and PtLimits::jet_flav_2prong_parton_match_b == -1){

      if((dsName.substr(0,5) == "Zto2Q") || (dsName.substr(0,2) == "TT")){
        if(PtLimits::jet_resjet_match_b == 0){
          _cutFlow.at("RejSignalResCuts") += 1;
          continue;
        }
      }



      // Matching with gen muons/electrons/hadronic taus
      std::vector<TLorentzVector> genMuonsMatched;
      std::vector<TLorentzVector> genElectronsMatched;
      std::vector<TLorentzVector> genTausHMatched;
      std::vector<TLorentzVector> genLepton4V;
      std::vector<TLorentzVector> genLeptonVis4V;
      TLorentzVector genLepton4V_total;
      TLorentzVector genLeptonVis4V_total;

      // pt ordering priviledge in the assignement
      for(size_t igen = 0; igen < genMuonsFromResonance4V.size(); igen++){
        float dR = jet4V.DeltaR(genMuonsFromResonance4V.at(igen));
        if(dR < dRConeCounting){
          genMuonsMatched.push_back(genMuonsFromResonance4V.at(igen));
          genLepton4V.push_back(genMuonsFromResonance4V.at(igen));
          genLeptonVis4V.push_back(genMuonsFromResonance4V.at(igen));
          genLepton4V_total += genMuonsFromResonance4V.at(igen);
          genLeptonVis4V_total += genMuonsFromResonance4V.at(igen);
        }
      }
      for(size_t igen = 0; igen < genElectronsFromResonance4V.size(); igen++){
        float dR = jet4V.DeltaR(genElectronsFromResonance4V.at(igen));
        if(dR < dRConeCounting){
          genElectronsMatched.push_back(genElectronsFromResonance4V.at(igen));
          genLepton4V.push_back(genElectronsFromResonance4V.at(igen));
          genLeptonVis4V.push_back(genElectronsFromResonance4V.at(igen));
          genLepton4V_total += genElectronsFromResonance4V.at(igen);
          genLeptonVis4V_total += genElectronsFromResonance4V.at(igen);
        }
      }
      for(size_t itau = 0; itau < tau_gen_visible.size(); itau++){
        float dR = tau_gen_visible.at(itau).DeltaR(jet4V);
        if(dR < dRConeCounting){
          genTausHMatched.push_back(tau_gen_visible.at(itau));
          genLepton4V.push_back(tau_gen.at(itau));
          genLeptonVis4V.push_back(tau_gen_visible.at(itau));
          genLepton4V_total += tau_gen.at(itau);
          genLeptonVis4V_total += tau_gen_visible.at(itau);
        }
      }

      // Jet id applied only to jets not overlapping with gen-leptons
      if(genMuonsMatched.size() == 0 and
        genElectronsMatched.size() == 0 and
        genTausHMatched.size() == 0 and
        jet_id->at(ijet) == 0){
        _cutFlow.at("RejJetId") += 1;
        continue;
      }

      // Reject jets on the basis of lepton content
      if(not saveLeptonOppositeFlavor  and ((genTausHMatched.size() != 0 and genMuonsMatched.size() != 0) or (genTausHMatched.size() != 0 and genElectronsMatched.size() != 0) or
      (genElectronsMatched.size() != 0 and genMuonsMatched.size() != 0))){
        _cutFlow.at("RejLeptonContent") += 1;
        continue;
      }

      // reject on the basis of the GEN lepton
      bool reject = false;
      for(size_t igen = 0; igen < genMuonsMatched.size(); igen++){
        if(genMuonsMatched.at(igen).Pt() < ptGenLeptonMin) reject = true;
      }
      for(size_t igen = 0; igen < genElectronsMatched.size(); igen++){
        if(genElectronsMatched.at(igen).Pt() < ptGenLeptonMin) reject = true;
      }
      for(size_t igen = 0; igen < genTausHMatched.size(); igen++){
        if(genTausHMatched.at(igen).Pt() < ptGenTauVisibleMin) reject = true;
      }
      if(reject){
        _cutFlow.at("RejLeptonContent") += 1;
        continue;
      }

      /// apply neutrino contribution to GEN softdrop (status 1 neutrinos)
      TLorentzVector jet_gen_4V;
      TLorentzVector jet_gen_wnu_4V;
      TLorentzVector jet_gen_softdrop_4V;
      jet_gen_4V.SetPtEtaPhiM(jet_genmatch_pt->at(ijet),jet_genmatch_eta->at(ijet),jet_genmatch_phi->at(ijet),jet_genmatch_mass->at(ijet));
      jet_gen_wnu_4V.SetPtEtaPhiM(jet_genmatch_wnu_pt->at(ijet),jet_genmatch_wnu_eta->at(ijet),jet_genmatch_wnu_phi->at(ijet),jet_genmatch_wnu_mass->at(ijet));
      jet_gen_softdrop_4V.SetPtEtaPhiM(jet_softdrop_genmatch_pt->at(ijet),jet_softdrop_genmatch_eta->at(ijet),jet_softdrop_genmatch_phi->at(ijet),jet_softdrop_genmatch_mass->at(ijet));
      TLorentzVector jet_gen_neutrino_4V = (jet_gen_wnu_4V-jet_gen_4V);
      TLorentzVector jet_gen_softdrop_wnu_4V = (jet_gen_softdrop_4V+jet_gen_neutrino_4V);

      // take the mass of the closest resonance
      float minDR = 1000;
      int closest_resonance = -1;
      for(size_t ires = 0; ires < resonances.size(); ires++){
        // skip resonances that decay directly with a neutrino
        if(fabs(resonances.at(ires).daugid.at(0)) == 12 or fabs(resonances.at(ires).daugid.at(0)) == 14 or fabs(resonances.at(ires).daugid.at(0)) == 16) continue;
        if(fabs(resonances.at(ires).daugid.at(1)) == 12 or fabs(resonances.at(ires).daugid.at(1)) == 14 or fabs(resonances.at(ires).daugid.at(1)) == 16) continue;
        if(find(vetoResonancePosition.begin(),vetoResonancePosition.end(),ires) != vetoResonancePosition.end()) continue;
        if(jet4V.DeltaR(resonances.at(ires).p4) < minDR and jet4V.DeltaR(resonances.at(ires).p4) < dRCone){
          minDR = jet4V.DeltaR(resonances.at(ires).p4);
          closest_resonance = ires;
        }
      }

      // if found, take the truth kinematic of the resonance from its GEN level (neutrinos included) and blacklist the resonance
      if(closest_resonance != -1){
        vetoResonancePosition.push_back(closest_resonance);
        // truth corresponds to the pole resonance kinematic properties
        PtLimits::jet_pt_truth_b   = resonances.at(closest_resonance).p4.Pt();
        PtLimits::jet_eta_truth_b  = resonances.at(closest_resonance).p4.Eta();
        PtLimits::jet_phi_truth_b  = resonances.at(closest_resonance).p4.Phi();
        PtLimits::jet_mass_truth_b = resonances.at(closest_resonance).p4.M();
      }
      else{
        // take the gen soft drop in QCD jets or un-matched jets, no need for the neutrino correction, everything fixed to be soft-drop
        PtLimits::jet_pt_truth_b   = jet_gen_wnu_4V.Pt();
        PtLimits::jet_eta_truth_b  = jet_gen_wnu_4V.Eta();
        PtLimits::jet_phi_truth_b  = jet_gen_wnu_4V.Phi();
        PtLimits::jet_mass_truth_b = jet_gen_wnu_4V.M();
      }

      // selection on the truth mass
      if((dsName.substr(0,5) == "Zto2Q") || (dsName.substr(0,2) == "TT")){
        if(PtLimits::jet_mass_truth_b < jetMassTruthMin){
          _cutFlow.at("RejMassCut") += 1;
          continue;
        }
      }


      // good jets for the analysis
      _cutFlow.at("Selected") += 1;

      /// Fill event branches
      //PtLimits::run_b = run;
      //PtLimits::lumi_b = lumi;
      //PtLimits::event_b = event;
      PtLimits::npu_b = putrue;
      //PtLimits::npv_b = npv;
      //PtLimits::nsv_b = nsv;
      //PtLimits::rho_b = rho;
      PtLimits::met_b = met;
      //PtLimits::ijet_b = ijet;

      // fill jet branches
      PtLimits::jet_pt_b = jet_pt->at(ijet);
      PtLimits::jet_eta_b = jet_eta->at(ijet);
      PtLimits::jet_phi_b = jet_phi->at(ijet);
      PtLimits::jet_mass_b = jet_mass->at(ijet);

      // soft drop
      //PtLimits::jet_softdrop_pt_b = jet_softdrop_pt->at(ijet);
      //PtLimits::jet_softdrop_eta_b = jet_softdrop_eta->at(ijet);
      //PtLimits::jet_softdrop_phi_b = jet_softdrop_phi->at(ijet);
      PtLimits::jet_softdrop_mass_b = jet_softdrop_mass->at(ijet);

      PtLimits::Z_pt = 0;
      if( dsName.substr(0,14) == "Zto2Q_PTQQ-100" ) PtLimits::Z_pt = 100;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-200" ) PtLimits::Z_pt = 200;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-400" ) PtLimits::Z_pt = 400;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-600" ) PtLimits::Z_pt = 600;


      PtLimits::ratio_jetres_pt = PtLimits::jet_pt_b/PtLimits::jet_pt_truth_b;
      PtLimits::ratio_jetres_mass = PtLimits::jet_mass_b/PtLimits::jet_mass_truth_b;


      HDF_fill();
    }

    return;
}


//-------------------------------------------------------------------------------------------------
// Produce systematic histograms
//-------------------------------------------------------------------------------------------------
void HEPHero::PtLimitsSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishPtLimits() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
