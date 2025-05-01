#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace PtLimits{

    int npu_b;
    float met_b;
    float jet_pt_b;
    float jet_eta_b;
    float jet_phi_b;
    float jet_mass_b;
    float jet_softdrop_mass_b;
    float R_ref;
    float Z_pt;
    float jet_pt_truth_b;
    float jet_eta_truth_b;
    float jet_phi_truth_b;
    float jet_mass_truth_b;
    float ratio_jetres_pt;
    float ratio_jetres_mass;

    bool match_DR_res_jet;
    bool match_DR_dau_jet;
    int matched_res_decay_id;

}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupPtLimits() {

    //======SETUP CUTFLOW==========================================================================
    _cutFlow.insert(pair<string,double>("NumBadGenEvent", 0) );
    _cutFlow.insert(pair<string,double>("00_Total", 0) );
    _cutFlow.insert(pair<string,double>("01_PassBaseCuts", 0) );
    _cutFlow.insert(pair<string,double>("02_SignalResCuts", 0) );
    //_cutFlow.insert(pair<string,double>("03_HasJetLooseId", 0) );
    _cutFlow.insert(pair<string,double>("04_MassCut", 0) );

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
    HDF_insert("R_ref", &PtLimits::R_ref );
    HDF_insert("Z_pt", &PtLimits::Z_pt );
    HDF_insert("jet_pt_truth",&PtLimits::jet_pt_truth_b);
    HDF_insert("jet_eta_truth",&PtLimits::jet_eta_truth_b);
    HDF_insert("jet_phi_truth",&PtLimits::jet_phi_truth_b);
    HDF_insert("jet_mass_truth",&PtLimits::jet_mass_truth_b);
    HDF_insert("ratio_jetres_pt",&PtLimits::ratio_jetres_pt);
    HDF_insert("ratio_jetres_mass",&PtLimits::ratio_jetres_mass);

    HDF_insert("match_DR_res_jet", &PtLimits::match_DR_res_jet);
    HDF_insert("match_DR_dau_jet", &PtLimits::match_DR_dau_jet);
    HDF_insert("matched_res_decay_id", &PtLimits::matched_res_decay_id);


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
    bool saveOnlyResonanceMatchedJets = true; // In case of signal type of sample, save only jets matched to a resonance
    bool saveLeptonOppositeFlavor = false; // save or not jets matched to two GEN leptons of opposite flavour

    string dsName = _datasetName.substr(0,_datasetName.length()-5);


    //--------------------------------------------------------------------
    // Build resonances matching Higgs/W/Z/top pdgId
    bool badGenEvent = false;
    std::vector<Resonance> resonances;
    for(size_t igen = 0; igen < gen_particle_pt->size(); igen++){
      if(abs(gen_particle_id->at(igen)) == 23 or
        abs(gen_particle_id->at(igen)) == 24 or
        abs(gen_particle_id->at(igen)) == 25 or
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
      }
    }

    if(badGenEvent){
      _cutFlow.at("NumBadGenEvent") += 1;
      return;
    }


    //--------------------------------------------------------------------
    /// Loop over the main jet collection
    for(size_t ijet = 0; ijet < jet_pt->size(); ijet++){

      float dRCone;
      float dRMatchingDaughterJet;
      if( dsName.substr(dsName.length()-4,dsName.length()) == "_AK8" ){
        dRCone = 0.8;
        dRMatchingDaughterJet = 0.8;
      }else{
        float R_HOTVR = 600/jet_pt->at(ijet);
        if( R_HOTVR > 1.5 ) R_HOTVR = 1.5;
        if( R_HOTVR < 0.1 ) R_HOTVR = 0.1;
        dRCone = R_HOTVR;
        dRMatchingDaughterJet = R_HOTVR;
      }
      PtLimits::R_ref = dRCone;

      _cutFlow.at("00_Total") += 1;

      // Base Selection
      if(jet_pt->at(ijet) < jetPtMin or jet_pt->at(ijet) > jetPtMax or fabs(jet_eta->at(ijet)) > jetEtaMax or fabs(jet_eta->at(ijet)) < jetEtaMin) continue;
      _cutFlow.at("01_PassBaseCuts") += 1;

      TLorentzVector jet4V;
      jet4V.SetPtEtaPhiM(jet_pt->at(ijet),jet_eta->at(ijet),jet_phi->at(ijet),jet_mass->at(ijet));

      // Matching with the resonance for signal jets using the kinematics
      int match_index_dR_res_jet = -1;
      float mindR_jetres = 1000;
      PtLimits::match_DR_res_jet = false;
      PtLimits::match_DR_dau_jet = false;
      for(size_t ires = 0; ires < resonances.size(); ires++){
        float dRjres = jet4V.DeltaR(resonances.at(ires).p4);
        if(dRjres < dRCone and dRjres < mindR_jetres){
          PtLimits::match_DR_res_jet = true;
          match_index_dR_res_jet = ires;
          mindR_jetres = dRjres;
          if(resonances.at(ires).daugp4.size() == 2){
            float dR1 = resonances.at(ires).daugp4.at(0).DeltaR(jet4V);
            float dR2 = resonances.at(ires).daugp4.at(1).DeltaR(jet4V);
            float dR  = resonances.at(ires).daugp4.front().DeltaR(resonances.at(ires).daugp4.back());
            if(dR1 < dRMatchingDaughterJet and dR2 < dRMatchingDaughterJet){
              PtLimits::match_DR_dau_jet = true;
            }
          }else if(resonances.at(ires).daugp4.size() == 3){
            float dR1 = resonances.at(ires).daugp4.at(0).DeltaR(jet4V);
            float dR2 = resonances.at(ires).daugp4.at(1).DeltaR(jet4V);
            float dR3 = resonances.at(ires).daugp4.at(2).DeltaR(jet4V);
            if(dR1 < dRMatchingDaughterJet and dR2 < dRMatchingDaughterJet and dR3 < dRMatchingDaughterJet){
              PtLimits::match_DR_dau_jet = true;
            }
          }
        }
      }


      // matching based on dR parton-jet
      PtLimits::matched_res_decay_id = -1; // only real QCD jets / not-matched resonances
      if(match_index_dR_res_jet != -1){
        if(resonances.at(match_index_dR_res_jet).daugid.size() == 2){
          if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) == 5 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) == 5) // X(bb)
            PtLimits::matched_res_decay_id = 5;
          else if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) == 4 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) == 4) // X(cc)
            PtLimits::matched_res_decay_id = 4;
          else if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) <= 3 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) <= 3) // X(qq)
            PtLimits::matched_res_decay_id = 3;
          else if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) == 21 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) == 21) // X(gg)
            PtLimits::matched_res_decay_id = 21;
          else
            PtLimits::matched_res_decay_id = 0; // whatever remains
        }else if(resonances.at(match_index_dR_res_jet).daugid.size() == 3){
          if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) < 6 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) < 6  and abs(resonances.at(match_index_dR_res_jet).daugid.at(2)) < 6) // Top(qqb)
            PtLimits::matched_res_decay_id = 1;
          else
            PtLimits::matched_res_decay_id = 0; // whatever remains
        }
      }


      // for signal samples exclude all jets unmatched (if enabled) to avoid labelling as QCD signal jets that are not matched to a resonance
      if((dsName.substr(0,5) == "Zto2Q") || (dsName.substr(0,2) == "TT")){
        if(saveOnlyResonanceMatchedJets and PtLimits::matched_res_decay_id <= 0) continue;
        _cutFlow.at("02_SignalResCuts") += 1;
      }

      //if( jet_id->at(ijet) == 0 ) continue;
      //_cutFlow.at("03_HasJetLooseId") += 1;



      // if found, take the truth kinematic of the resonance from its GEN level (neutrinos included) and blacklist the resonance
      if(match_index_dR_res_jet != -1){
        // truth corresponds to the pole resonance kinematic properties
        PtLimits::jet_pt_truth_b   = resonances.at(match_index_dR_res_jet).p4.Pt();
        PtLimits::jet_eta_truth_b  = resonances.at(match_index_dR_res_jet).p4.Eta();
        PtLimits::jet_phi_truth_b  = resonances.at(match_index_dR_res_jet).p4.Phi();
        PtLimits::jet_mass_truth_b = resonances.at(match_index_dR_res_jet).p4.M();
      }
      else{
        // take the gen soft drop in QCD jets or un-matched jets, no need for the neutrino correction, everything fixed to be soft-drop
        PtLimits::jet_pt_truth_b   = 0;
        PtLimits::jet_eta_truth_b  = 0;
        PtLimits::jet_phi_truth_b  = 0;
        PtLimits::jet_mass_truth_b = 0;
      }

      // selection on the truth mass
      if((dsName.substr(0,5) == "Zto2Q") || (dsName.substr(0,2) == "TT")){
        if(PtLimits::jet_mass_truth_b < jetMassTruthMin) continue;
        _cutFlow.at("04_MassCut") += 1;
      }




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
