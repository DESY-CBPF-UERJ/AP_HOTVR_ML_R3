#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace Evaluate{

    int sample_b;

    unsigned int run_b, lumi_b, event_b, npv_b, nsv_b, npu_b;
    float rho_b,met_b;
    unsigned int ijet_b;

    float jet_pt_b,jet_eta_b,jet_abseta_b,jet_phi_b,jet_mass_b,jet_pt_raw_b,jet_mass_raw_b;

    unsigned int jet_ncand_b, jet_nbhad_b, jet_nchad_b, jet_hflav_b;
    float jet_chf_b, jet_nhf_b, jet_phf_b, jet_elf_b, jet_muf_b;
    int jet_pflav_b, jet_tauflav_b, jet_muflav_b, jet_elflav_b, jet_lepflav_b;
    int jet_flav_2prong_partonjet_match_b, jet_flav_2prong_parton_match_b;

    int jet_flav_2prong_resjet_match_b;

    float jet_genmatch_pt_b,jet_genmatch_eta_b,jet_genmatch_phi_b,jet_genmatch_mass_b;
    float jet_genmatch_wnu_pt_b, jet_genmatch_wnu_eta_b, jet_genmatch_wnu_phi_b, jet_genmatch_wnu_mass_b;
    float jet_genmatch_nu_pt_b, jet_genmatch_nu_eta_b, jet_genmatch_nu_phi_b, jet_genmatch_nu_mass_b, jet_genmatch_nu_energy_b;

    float jet_softdrop_pt_b, jet_softdrop_eta_b, jet_softdrop_phi_b, jet_softdrop_mass_b;

    float jet_softdrop_genmatch_pt_b, jet_softdrop_genmatch_eta_b, jet_softdrop_genmatch_phi_b, jet_softdrop_genmatch_mass_b;

    float jet_pt_truth_b,jet_eta_truth_b,jet_phi_truth_b,jet_mass_truth_b;
    float jet_pt_truth_vis_b,jet_eta_truth_vis_b,jet_phi_truth_vis_b,jet_mass_truth_vis_b;

    std::vector<float> jet_pfcand_pt_b, jet_pfcand_eta_b, jet_pfcand_phi_b, jet_pfcand_mass_b, jet_pfcand_energy_b, jet_pfcand_pt_log_b, jet_pfcand_energy_log_b, jet_pfcand_calofraction_b, jet_pfcand_abseta_b;
    std::vector<float> jet_pfcand_hcalfraction_b, jet_pfcand_dxy_b, jet_pfcand_dz_b, jet_pfcand_dxysig_b, jet_pfcand_dzsig_b, jet_pfcand_pperp_ratio_b, jet_pfcand_ppara_ratio_b;
    std::vector<float> jet_pfcand_deta_b, jet_pfcand_dphi_b, jet_pfcand_etarel_b, jet_pfcand_puppiw_b;

    // All floats to allow transformations
    std::vector<float> jet_pfcand_frompv_b, jet_pfcand_id_b, jet_pfcand_track_qual_b, jet_pfcand_track_chi2_b, jet_pfcand_track_pterr_b, jet_pfcand_track_etaerr_b, jet_pfcand_track_phierr_b;
    std::vector<float> jet_pfcand_nhits_b, jet_pfcand_npixhits_b, jet_pfcand_nstriphits_b, jet_pfcand_nlosthits_b, jet_pfcand_npixlayers_b, jet_pfcand_nstriplayers_b, jet_pfcand_track_algo_b;
    std::vector<float> jet_pfcand_tau_signal_b, jet_pfcand_tau_boosted_signal_b, jet_pfcand_charge_b;
    std::vector<float> jet_pfcand_muon_id_b, jet_pfcand_muon_chi2_b, jet_pfcand_muon_segcomp_b, jet_pfcand_muon_isglobal_b, jet_pfcand_muon_nvalidhit_b, jet_pfcand_muon_nstation_b;
    std::vector<float> jet_pfcand_electron_eOverP_b, jet_pfcand_electron_detaIn_b, jet_pfcand_electron_dphiIn_b, jet_pfcand_electron_r9_b, jet_pfcand_electron_sigIetaIeta_b;
    std::vector<float> jet_pfcand_electron_convProb_b, jet_pfcand_electron_sigIphiIphi_b;

    std::vector<float> jet_pfcand_photon_sigIetaIeta_b, jet_pfcand_photon_r9_b, jet_pfcand_photon_eVeto_b;

    std::vector<float> jet_pfcand_trackjet_d3d_b, jet_pfcand_trackjet_d3dsig_b;
    std::vector<float> jet_pfcand_trackjet_dist_b, jet_pfcand_trackjet_decayL_b;

    std::vector<float> jet_sv_pt_b, jet_sv_pt_log_b, jet_sv_eta_b, jet_sv_phi_b, jet_sv_mass_b, jet_sv_energy_b, jet_sv_energy_log_b, jet_sv_abseta_b;
    std::vector<float> jet_sv_deta_b, jet_sv_dphi_b, jet_sv_chi2_b, jet_sv_dxy_b, jet_sv_dxysig_b;
    std::vector<float> jet_sv_d3d_b, jet_sv_d3dsig_b;
    std::vector<float> jet_sv_ntrack_b;

    float ZtoQQxQCD_tag;
    float R_ref;
    float Z_pt;

}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupEvaluate() {


    //======SETUP CUTFLOW==========================================================================
    _cutFlow.insert(pair<string,double>("Total", 0) );
    _cutFlow.insert(pair<string,double>("RejEvents", 0) );
    _cutFlow.insert(pair<string,double>("RejBaseCuts", 0) );
    _cutFlow.insert(pair<string,double>("RejSignalResCuts", 0) );
    _cutFlow.insert(pair<string,double>("RejJetId", 0) );
    _cutFlow.insert(pair<string,double>("RejLeptonContent", 0) );
    _cutFlow.insert(pair<string,double>("RejMassCut", 0) );
    _cutFlow.insert(pair<string,double>("Training", 0) );

    //======SETUP HISTOGRAMS=======================================================================
    //makeHist( "histogram1DName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeHist( "histogram2DName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP SYSTEMATIC HISTOGRAMS============================================================
    //sys_regions = { 0, 1, 2 }; [example] // Choose regions as defined in RegionID. Empty vector means that all events will be used.
    //makeSysHist( "histogram1DSysName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeSysHist( "histogram2DSysName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP OUTPUT BRANCHES==================================================================
    //_outputTree->Branch("variable1NameInTheTree", &Evaluate::variable1Name );  [example]

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    HDF_insert("run",&Evaluate::run_b);
    HDF_insert("lumi",&Evaluate::lumi_b);
    HDF_insert("event",&Evaluate::event_b);
    HDF_insert("npv",&Evaluate::npv_b);
    //HDF_insert("nsv",&Evaluate::nsv_b);
    HDF_insert("npu",&Evaluate::npu_b);
    //HDF_insert("rho",&Evaluate::rho_b);
    HDF_insert("met",&Evaluate::met_b);
    //HDF_insert("ijet",&Evaluate::ijet_b);
    HDF_insert("sample",&Evaluate::sample_b);

    HDF_insert("jet_pt",&Evaluate::jet_pt_b);
    HDF_insert("jet_eta",&Evaluate::jet_eta_b);
    HDF_insert("jet_abseta",&Evaluate::jet_abseta_b);
    //HDF_insert("jet_phi",&Evaluate::jet_phi_b);
    HDF_insert("jet_mass",&Evaluate::jet_mass_b);
    //HDF_insert("jet_pt_raw",&Evaluate::jet_pt_raw_b);
    //HDF_insert("jet_mass_raw",&Evaluate::jet_mass_raw_b);


    HDF_insert("jet_softdrop_mass",&Evaluate::jet_softdrop_mass_b);
    /*
    HDF_insert("jet_chf",&Evaluate::jet_chf_b);
    HDF_insert("jet_nhf",&Evaluate::jet_nhf_b);
    HDF_insert("jet_phf",&Evaluate::jet_phf_b);
    HDF_insert("jet_elf",&Evaluate::jet_elf_b);
    HDF_insert("jet_muf",&Evaluate::jet_muf_b);
    HDF_insert("jet_ncand",&Evaluate::jet_ncand_b);
    HDF_insert("jet_nbhad",&Evaluate::jet_nbhad_b);
    HDF_insert("jet_nchad",&Evaluate::jet_nchad_b);
    HDF_insert("jet_hflav",&Evaluate::jet_hflav_b);
    HDF_insert("jet_pflav",&Evaluate::jet_pflav_b);
    HDF_insert("jet_muflav",&Evaluate::jet_muflav_b);
    HDF_insert("jet_elflav",&Evaluate::jet_elflav_b);
    HDF_insert("jet_lepflav",&Evaluate::jet_lepflav_b);
    HDF_insert("jet_tauflav",&Evaluate::jet_tauflav_b);

    HDF_insert("jet_flav_2prong_parton_match",&Evaluate::jet_flav_2prong_parton_match_b);

    HDF_insert("jet_genmatch_pt",&Evaluate::jet_genmatch_pt_b);
    HDF_insert("jet_genmatch_eta",&Evaluate::jet_genmatch_eta_b);
    HDF_insert("jet_genmatch_phi",&Evaluate::jet_genmatch_phi_b);
    HDF_insert("jet_genmatch_mass",&Evaluate::jet_genmatch_mass_b);
    HDF_insert("jet_genmatch_wnu_pt",&Evaluate::jet_genmatch_wnu_pt_b);
    HDF_insert("jet_genmatch_wnu_eta",&Evaluate::jet_genmatch_wnu_eta_b);
    HDF_insert("jet_genmatch_wnu_phi",&Evaluate::jet_genmatch_wnu_phi_b);
    HDF_insert("jet_genmatch_wnu_mass",&Evaluate::jet_genmatch_wnu_mass_b);
    HDF_insert("jet_genmatch_nu_pt",&Evaluate::jet_genmatch_nu_pt_b);
    HDF_insert("jet_genmatch_nu_eta",&Evaluate::jet_genmatch_nu_eta_b);
    HDF_insert("jet_genmatch_nu_phi",&Evaluate::jet_genmatch_nu_phi_b);
    HDF_insert("jet_genmatch_nu_mass",&Evaluate::jet_genmatch_nu_mass_b);
    HDF_insert("jet_genmatch_nu_energy",&Evaluate::jet_genmatch_nu_energy_b);

    HDF_insert("jet_softdrop_pt",&Evaluate::jet_softdrop_pt_b);
    HDF_insert("jet_softdrop_eta",&Evaluate::jet_softdrop_eta_b);
    HDF_insert("jet_softdrop_phi",&Evaluate::jet_softdrop_phi_b);
    HDF_insert("jet_softdrop_mass",&Evaluate::jet_softdrop_mass_b);

    HDF_insert("jet_softdrop_genmatch_pt",&Evaluate::jet_softdrop_genmatch_pt_b);
    HDF_insert("jet_softdrop_genmatch_eta",&Evaluate::jet_softdrop_genmatch_eta_b);
    HDF_insert("jet_softdrop_genmatch_phi",&Evaluate::jet_softdrop_genmatch_phi_b);
    HDF_insert("jet_softdrop_genmatch_mass",&Evaluate::jet_softdrop_genmatch_mass_b);


    HDF_insert("jet_eta_truth",&Evaluate::jet_eta_truth_b);
    HDF_insert("jet_phi_truth",&Evaluate::jet_phi_truth_b);
    HDF_insert("jet_mass_truth",&Evaluate::jet_mass_truth_b);
    HDF_insert("jet_pt_truth_vis",&Evaluate::jet_pt_truth_vis_b);
    HDF_insert("jet_eta_truth_vis",&Evaluate::jet_eta_truth_vis_b);
    HDF_insert("jet_phi_truth_vis",&Evaluate::jet_phi_truth_vis_b);
    HDF_insert("jet_mass_truth_vis",&Evaluate::jet_mass_truth_vis_b);
    */

    HDF_insert("jet_flav_2prong_partonjet_match",&Evaluate::jet_flav_2prong_partonjet_match_b);
    HDF_insert("jet_flav_2prong_resjet_match", &Evaluate::jet_flav_2prong_resjet_match_b );

    HDF_insert("jet_pt_truth",&Evaluate::jet_pt_truth_b);

    HDF_insert("jet_ZtoQQxQCD_tag", &Evaluate::ZtoQQxQCD_tag );
    HDF_insert("R_ref", &Evaluate::R_ref );
    HDF_insert("Z_pt", &Evaluate::Z_pt );

    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::EvaluateRegion() {

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
void HEPHero::EvaluateSelection() {

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
    float jetPtMin = 200; // Min jet pT to apply
    float jetEtaMax = 2.5; // Max jet eta to apply
    float jetEtaMin = 0.; // Min jet eta to apply
    float jetMassTruthMin = 80; // Min mass selection to apply based on the truth definition given in the code
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
        abs(gen_particle_id->at(igen)) == 24 or
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
        abs(gen_particle_id->at(igen)) == 24){
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
        if(resonances.back().daugp4.size() != 2){
          std::cerr<<"Found more than two decay particles from Higgs or W or Z --> please check!!! --> rejecting the event"<<std::endl;
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
      Evaluate::R_ref = dRCone;

      _cutFlow.at("Total") += 1;

      ///// Selection
      if(jet_pt->at(ijet) < jetPtMin or
        jet_pt->at(ijet) > jetPtMax or
        fabs(jet_eta->at(ijet)) > jetEtaMax or
        fabs(jet_eta->at(ijet)) < jetEtaMin or
        (saveOnlyGenMatchedJets and jet_genmatch_pt->at(ijet) <= 0)){
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
      Evaluate::jet_flav_2prong_resjet_match_b = 0;
      for(size_t ipair = 0; ipair < resonances.size(); ipair++){
        float dRjres = jet4V.DeltaR(resonances.at(ipair).p4);
        if(dRjres < dRCone and dRjres < mindR_jetres){
          Evaluate::jet_flav_2prong_resjet_match_b = 1;
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
          Evaluate::jet_flav_2prong_partonjet_match_b = 7;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) == 5 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) == 5) // X(bb)
          Evaluate::jet_flav_2prong_partonjet_match_b = 6;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) == 4 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) == 4) // X(cc)
          Evaluate::jet_flav_2prong_partonjet_match_b = 5;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) <= 3 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) <= 3) // X(qq)
          Evaluate::jet_flav_2prong_partonjet_match_b = 4;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) == 21 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) == 21) // X(gg)
          Evaluate::jet_flav_2prong_partonjet_match_b = 3;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) == 13 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) == 13) // X(mm)
          Evaluate::jet_flav_2prong_partonjet_match_b = 2;
        else if(abs(resonances.at(match_index_dR_parton_jet).daugid.at(0)) == 11 and abs(resonances.at(match_index_dR_parton_jet).daugid.at(1)) == 11) // X(ee)
          Evaluate::jet_flav_2prong_partonjet_match_b = 1;
        else
          Evaluate::jet_flav_2prong_partonjet_match_b = 0; // whatever remains
      }
      else
        Evaluate::jet_flav_2prong_partonjet_match_b = -1; // only real QCD jets / not-matched resonances

      // matching based on dR parton-parton
      if(match_index_dR_partons != -1 and resonances.at(match_index_dR_partons).daugid.size() == 2){
        if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 15 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 15) // X(tt)
          Evaluate::jet_flav_2prong_parton_match_b = 7;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 5 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 5) // X(bb)
          Evaluate::jet_flav_2prong_parton_match_b = 6;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 4 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 4) // X(cc)
          Evaluate::jet_flav_2prong_parton_match_b = 5;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) <= 3 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) <= 3) // X(qq)
          Evaluate::jet_flav_2prong_parton_match_b = 4;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 21 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 21) // X(gg)
          Evaluate::jet_flav_2prong_parton_match_b = 3;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 13 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 13) // X(mm)
          Evaluate::jet_flav_2prong_parton_match_b = 2;
        else if(abs(resonances.at(match_index_dR_partons).daugid.at(0)) == 11 and abs(resonances.at(match_index_dR_partons).daugid.at(1)) == 11) // X(ee)
          Evaluate::jet_flav_2prong_parton_match_b = 1;
        else
          Evaluate::jet_flav_2prong_parton_match_b = 0; // whatever remains
      }
      else
        Evaluate::jet_flav_2prong_parton_match_b = -1;  // only real QCD jets / not-matched resonances

      // for signal samples exclude all jets unmatched (if enabled) to avoid labelling as QCD signal jets that are not matched to a resonance
      if(saveOnlyResonanceMatchedJets and Evaluate::jet_flav_2prong_partonjet_match_b == -1 and Evaluate::jet_flav_2prong_parton_match_b == -1){
        _cutFlow.at("RejSignalResCuts") += 1;
        continue;
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
        Evaluate::jet_pt_truth_b   = resonances.at(closest_resonance).p4.Pt();
        Evaluate::jet_eta_truth_b  = resonances.at(closest_resonance).p4.Eta();
        Evaluate::jet_phi_truth_b  = resonances.at(closest_resonance).p4.Phi();
        Evaluate::jet_mass_truth_b = resonances.at(closest_resonance).p4.M();
        // visible kinematic properties i.e. deconvolve the neutrino 4V
        Evaluate::jet_pt_truth_vis_b = (resonances.at(closest_resonance).p4-jet_gen_neutrino_4V).Pt();
        Evaluate::jet_eta_truth_vis_b = (resonances.at(closest_resonance).p4-jet_gen_neutrino_4V).Eta();
        Evaluate::jet_phi_truth_vis_b = (resonances.at(closest_resonance).p4-jet_gen_neutrino_4V).Phi();
        Evaluate::jet_mass_truth_vis_b = (resonances.at(closest_resonance).p4-jet_gen_neutrino_4V).M();
      }
      else{
        // take the gen soft drop in QCD jets or un-matched jets, no need for the neutrino correction, everything fixed to be soft-drop
        Evaluate::jet_pt_truth_b   = jet_gen_wnu_4V.Pt();
        Evaluate::jet_eta_truth_b  = jet_gen_wnu_4V.Eta();
        Evaluate::jet_phi_truth_b  = jet_gen_wnu_4V.Phi();
        Evaluate::jet_mass_truth_b = jet_gen_wnu_4V.M();
        Evaluate::jet_pt_truth_vis_b = jet_gen_4V.Pt();
        Evaluate::jet_eta_truth_vis_b = jet_gen_4V.Eta();
        Evaluate::jet_phi_truth_vis_b = jet_gen_4V.Phi();
        Evaluate::jet_mass_truth_vis_b = jet_gen_softdrop_4V.M();
      }

      // selection on the truth mass
      Evaluate::sample_b = -1;
      if(dsName.substr(0,5) == "Zto2Q"){
        if(Evaluate::jet_mass_truth_b < jetMassTruthMin){
          _cutFlow.at("RejMassCut") += 1;
          continue;
        }
        Evaluate::sample_b = 1;
      }else if(dsName.substr(0,3) == "QCD"){
        Evaluate::sample_b = 0;
      }


      // good jets for the analysis
      _cutFlow.at("Training") += 1;

      /// Fill event branches
      Evaluate::run_b = run;
      Evaluate::lumi_b = lumi;
      Evaluate::event_b = event;
      Evaluate::npu_b = putrue;
      Evaluate::npv_b = npv;
      Evaluate::nsv_b = nsv;
      Evaluate::rho_b = rho;
      Evaluate::met_b = met;
      Evaluate::ijet_b = ijet;

      // fill jet branches
      Evaluate::jet_pt_b = jet_pt->at(ijet);
      Evaluate::jet_eta_b = jet_eta->at(ijet);
      Evaluate::jet_abseta_b = abs(jet_eta->at(ijet));
      Evaluate::jet_phi_b = jet_phi->at(ijet);
      Evaluate::jet_mass_b = jet_mass->at(ijet);
      Evaluate::jet_pt_raw_b = jet_pt_raw->at(ijet);
      Evaluate::jet_mass_raw_b = jet_mass_raw->at(ijet);

      Evaluate::jet_chf_b = jet_chf->at(ijet);
      Evaluate::jet_nhf_b = jet_nhf->at(ijet);
      Evaluate::jet_phf_b = jet_phf->at(ijet);
      Evaluate::jet_elf_b = jet_elf->at(ijet);
      Evaluate::jet_muf_b = jet_muf->at(ijet);

      Evaluate::jet_ncand_b = jet_ncand->at(ijet);
      Evaluate::jet_nbhad_b = jet_nbhad->at(ijet);
      Evaluate::jet_nchad_b = jet_nchad->at(ijet);
      Evaluate::jet_hflav_b = jet_hflav->at(ijet);
      Evaluate::jet_pflav_b = jet_pflav->at(ijet);

      Evaluate::jet_genmatch_pt_b = jet_genmatch_pt->at(ijet);
      Evaluate::jet_genmatch_eta_b = jet_genmatch_eta->at(ijet);
      Evaluate::jet_genmatch_phi_b = jet_genmatch_phi->at(ijet);
      Evaluate::jet_genmatch_mass_b = jet_genmatch_mass->at(ijet);

      Evaluate::jet_genmatch_wnu_pt_b = jet_genmatch_wnu_pt->at(ijet);
      Evaluate::jet_genmatch_wnu_eta_b = jet_genmatch_wnu_eta->at(ijet);
      Evaluate::jet_genmatch_wnu_phi_b = jet_genmatch_wnu_phi->at(ijet);
      Evaluate::jet_genmatch_wnu_mass_b = jet_genmatch_wnu_mass->at(ijet);

      Evaluate::jet_genmatch_nu_pt_b = jet_gen_neutrino_4V.Pt();
      Evaluate::jet_genmatch_nu_eta_b = jet_gen_neutrino_4V.Eta();
      Evaluate::jet_genmatch_nu_phi_b = jet_gen_neutrino_4V.Phi();
      Evaluate::jet_genmatch_nu_mass_b = jet_gen_neutrino_4V.M();

      Evaluate::jet_muflav_b = genMuonsMatched.size();
      Evaluate::jet_elflav_b = genElectronsMatched.size();
      Evaluate::jet_tauflav_b = genTausHMatched.size();
      Evaluate::jet_lepflav_b = genMuonsMatched.size()+genElectronsMatched.size()+genTausHMatched.size();

      // soft drop
      Evaluate::jet_softdrop_pt_b = jet_softdrop_pt->at(ijet);
      Evaluate::jet_softdrop_eta_b = jet_softdrop_eta->at(ijet);
      Evaluate::jet_softdrop_phi_b = jet_softdrop_phi->at(ijet);
      Evaluate::jet_softdrop_mass_b = jet_softdrop_mass->at(ijet);

      Evaluate::jet_softdrop_genmatch_pt_b = jet_softdrop_genmatch_pt->at(ijet);
      Evaluate::jet_softdrop_genmatch_eta_b = jet_softdrop_genmatch_eta->at(ijet);
      Evaluate::jet_softdrop_genmatch_phi_b = jet_softdrop_genmatch_phi->at(ijet);
      Evaluate::jet_softdrop_genmatch_mass_b = jet_softdrop_genmatch_mass->at(ijet);

      Evaluate::Z_pt = 0;
      if( dsName.substr(0,14) == "Zto2Q_PTQQ-100" ) Evaluate::Z_pt = 100;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-200" ) Evaluate::Z_pt = 200;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-400" ) Evaluate::Z_pt = 400;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-600" ) Evaluate::Z_pt = 600;


      // SV
      Evaluate::jet_sv_pt_b.clear(); Evaluate::jet_sv_eta_b.clear(); Evaluate::jet_sv_abseta_b.clear(); Evaluate::jet_sv_phi_b.clear(); Evaluate::jet_sv_mass_b.clear(); Evaluate::jet_sv_energy_b.clear();
      Evaluate::jet_sv_deta_b.clear(); Evaluate::jet_sv_dphi_b.clear();
      Evaluate::jet_sv_chi2_b.clear(); Evaluate::jet_sv_dxy_b.clear(); Evaluate::jet_sv_dxysig_b.clear();
      Evaluate::jet_sv_d3d_b.clear(); Evaluate::jet_sv_d3dsig_b.clear(); Evaluate::jet_sv_ntrack_b.clear();
      Evaluate::jet_sv_pt_log_b.clear(); Evaluate::jet_sv_energy_log_b.clear();

      for(size_t isv = 0; isv < jet_sv_pt->size(); isv++){

        if(ijet != jet_sv_ijet->at(isv)) continue;

        Evaluate::jet_sv_pt_b.push_back(jet_sv_pt->at(isv));
        Evaluate::jet_sv_pt_log_b.push_back(std::isnan(std::log(jet_sv_pt->at(isv))) ? 0 : std::log(jet_sv_pt->at(isv)));
        Evaluate::jet_sv_eta_b.push_back(jet_sv_eta->at(isv));
        Evaluate::jet_sv_abseta_b.push_back(abs(jet_sv_eta->at(isv)));
        Evaluate::jet_sv_phi_b.push_back(jet_sv_phi->at(isv));
        Evaluate::jet_sv_energy_b.push_back(jet_sv_energy->at(isv));
        Evaluate::jet_sv_energy_log_b.push_back(std::isnan(std::log(jet_sv_energy->at(isv))) ? 0 : std::log(jet_sv_energy->at(isv)));
        Evaluate::jet_sv_mass_b.push_back(jet_sv_mass->at(isv));
        Evaluate::jet_sv_deta_b.push_back(jet_sv_eta->at(isv)-jet_eta->at(ijet));
        Evaluate::jet_sv_dphi_b.push_back(jet_sv_phi->at(isv)-jet_phi->at(ijet));
        Evaluate::jet_sv_chi2_b.push_back(jet_sv_chi2->at(isv));
        Evaluate::jet_sv_dxy_b.push_back(std::isnan(jet_sv_dxy->at(isv)) ? 0 : jet_sv_dxy->at(isv));
        Evaluate::jet_sv_dxysig_b.push_back(std::isnan(jet_sv_dxysig->at(isv)) ? 0 : jet_sv_dxysig->at(isv));
        Evaluate::jet_sv_d3d_b.push_back(std::isnan(jet_sv_d3d->at(isv)) ? 0 : jet_sv_d3d->at(isv));
        Evaluate::jet_sv_d3dsig_b.push_back(std::isnan(jet_sv_d3dsig->at(isv)) ? 0 : jet_sv_d3dsig->at(isv));
        Evaluate::jet_sv_ntrack_b.push_back(jet_sv_ntrack->at(isv));

        if( Evaluate::jet_sv_pt_b.size() == sv_lenght ) break;
      }


      for(size_t isv = Evaluate::jet_sv_pt_b.size(); isv < sv_lenght; isv++){
        Evaluate::jet_sv_pt_b.push_back(0);
        Evaluate::jet_sv_pt_log_b.push_back(0);
        Evaluate::jet_sv_eta_b.push_back(0);
        Evaluate::jet_sv_abseta_b.push_back(0);
        Evaluate::jet_sv_phi_b.push_back(0);
        Evaluate::jet_sv_energy_b.push_back(0);
        Evaluate::jet_sv_energy_log_b.push_back(0);
        Evaluate::jet_sv_mass_b.push_back(0);
        Evaluate::jet_sv_deta_b.push_back(0);
        Evaluate::jet_sv_dphi_b.push_back(0);
        Evaluate::jet_sv_chi2_b.push_back(0);
        Evaluate::jet_sv_dxy_b.push_back(0);
        Evaluate::jet_sv_dxysig_b.push_back(0);
        Evaluate::jet_sv_d3d_b.push_back(0);
        Evaluate::jet_sv_d3dsig_b.push_back(0);
        Evaluate::jet_sv_ntrack_b.push_back(0);
      }



      // PF candidates
      Evaluate::jet_pfcand_pt_b.clear(); Evaluate::jet_pfcand_eta_b.clear(); Evaluate::jet_pfcand_abseta_b.clear(); Evaluate::jet_pfcand_phi_b.clear(); Evaluate::jet_pfcand_mass_b.clear(); Evaluate::jet_pfcand_energy_b.clear(); Evaluate::jet_pfcand_calofraction_b.clear();
      Evaluate::jet_pfcand_hcalfraction_b.clear(); Evaluate::jet_pfcand_dxy_b.clear(); Evaluate::jet_pfcand_dz_b.clear(); Evaluate::jet_pfcand_dxysig_b.clear(); Evaluate::jet_pfcand_dzsig_b.clear();
      Evaluate::jet_pfcand_pperp_ratio_b.clear(); Evaluate::jet_pfcand_ppara_ratio_b.clear(); Evaluate::jet_pfcand_deta_b.clear(); Evaluate::jet_pfcand_dphi_b.clear();
      Evaluate::jet_pfcand_pt_log_b.clear(); Evaluate::jet_pfcand_energy_log_b.clear(); Evaluate::jet_pfcand_etarel_b.clear(); Evaluate::jet_pfcand_puppiw_b.clear();
      Evaluate::jet_pfcand_charge_b.clear(); Evaluate::jet_pfcand_frompv_b.clear(); Evaluate::jet_pfcand_id_b.clear(); Evaluate::jet_pfcand_track_qual_b.clear(); Evaluate::jet_pfcand_track_chi2_b.clear();
      Evaluate::jet_pfcand_trackjet_d3d_b.clear(); Evaluate::jet_pfcand_trackjet_d3dsig_b.clear(); Evaluate::jet_pfcand_trackjet_dist_b.clear(); Evaluate::jet_pfcand_trackjet_decayL_b.clear();
      Evaluate::jet_pfcand_track_pterr_b.clear(); Evaluate::jet_pfcand_track_etaerr_b.clear(); Evaluate::jet_pfcand_track_phierr_b.clear();
      Evaluate::jet_pfcand_nhits_b.clear(); Evaluate::jet_pfcand_npixhits_b.clear(); Evaluate::jet_pfcand_nstriphits_b.clear(); Evaluate::jet_pfcand_nlosthits_b.clear();
      Evaluate::jet_pfcand_npixlayers_b.clear(); Evaluate::jet_pfcand_nstriplayers_b.clear(), Evaluate::jet_pfcand_track_algo_b.clear();
      Evaluate::jet_pfcand_tau_signal_b.clear(); Evaluate::jet_pfcand_tau_boosted_signal_b.clear();
      Evaluate::jet_pfcand_muon_id_b.clear(); Evaluate::jet_pfcand_muon_chi2_b.clear(); Evaluate::jet_pfcand_muon_segcomp_b.clear(); Evaluate::jet_pfcand_muon_isglobal_b.clear();
      Evaluate::jet_pfcand_muon_nvalidhit_b.clear(); Evaluate::jet_pfcand_muon_nstation_b.clear();
      Evaluate::jet_pfcand_electron_eOverP_b.clear(); Evaluate::jet_pfcand_electron_detaIn_b.clear(); Evaluate::jet_pfcand_electron_dphiIn_b.clear(); Evaluate::jet_pfcand_electron_r9_b.clear();
      Evaluate::jet_pfcand_electron_convProb_b.clear(); Evaluate::jet_pfcand_electron_sigIetaIeta_b.clear(); Evaluate::jet_pfcand_electron_sigIphiIphi_b.clear();
      Evaluate::jet_pfcand_photon_sigIetaIeta_b.clear(); Evaluate::jet_pfcand_photon_r9_b.clear(); Evaluate::jet_pfcand_photon_eVeto_b.clear();

      std::vector<TLorentzVector> muon4V_fromPF;
      std::vector<TLorentzVector> electron4V_fromPF;
      std::vector<TLorentzVector> photon4V_fromPF;
      TLorentzVector tau4V_fromPF;
      TLorentzVector tau4V_boosted_fromPF;

      vector<int> jet_pfcand_idx(jet_pfcand_pt->size());
      // initializing using iota()
      iota(jet_pfcand_idx.begin(), jet_pfcand_idx.end(), 0);
      sort(jet_pfcand_idx.begin(), jet_pfcand_idx.end(), [&](int A, int B) -> bool {
        return jet_pfcand_pt->at(A) > jet_pfcand_pt->at(B);
      });

      //cout << "New jet ===================================================" << endl;
      for(size_t idx = 0; idx < jet_pfcand_idx.size(); idx++){
        int icand = jet_pfcand_idx.at(idx);
        //cout << "jet_pfcand_pt: " << jet_pfcand_pt->at(icand) << endl;
        if(ijet != jet_pfcand_ijet->at(icand)) continue;
        if(jet_pfcand_pt->at(icand) < pfCandPtMin) continue;
        if(jet_pfcand_puppiw->at(icand) < pfCandPuppiWeightMin) continue;

        Evaluate::jet_pfcand_pt_b.push_back(jet_pfcand_pt->at(icand));
        Evaluate::jet_pfcand_pt_log_b.push_back(std::isnan(std::log(jet_pfcand_pt->at(icand))) ? 0 : std::log(jet_pfcand_pt->at(icand)));
        Evaluate::jet_pfcand_eta_b.push_back(jet_pfcand_eta->at(icand));
        Evaluate::jet_pfcand_abseta_b.push_back(abs(jet_pfcand_eta->at(icand)));
        Evaluate::jet_pfcand_phi_b.push_back(jet_pfcand_phi->at(icand));
        Evaluate::jet_pfcand_mass_b.push_back(jet_pfcand_mass->at(icand));
        Evaluate::jet_pfcand_energy_b.push_back(jet_pfcand_energy->at(icand));
        Evaluate::jet_pfcand_energy_log_b.push_back(std::isnan(std::log(jet_pfcand_energy->at(icand))) ? 0 : std::log(jet_pfcand_energy->at(icand)));
        Evaluate::jet_pfcand_calofraction_b.push_back(std::isnan(jet_pfcand_calofraction->at(icand)) ? 0 : jet_pfcand_calofraction->at(icand));
        Evaluate::jet_pfcand_hcalfraction_b.push_back(std::isnan(jet_pfcand_hcalfraction->at(icand)) ? 0 : jet_pfcand_hcalfraction->at(icand));
        Evaluate::jet_pfcand_dxy_b.push_back(std::isnan(jet_pfcand_dxy->at(icand)) ? 0 : jet_pfcand_dxy->at(icand));
        Evaluate::jet_pfcand_dz_b.push_back(std::isnan(jet_pfcand_dz->at(icand)) ? 0 : jet_pfcand_dz->at(icand));
        Evaluate::jet_pfcand_dzsig_b.push_back(std::isnan(jet_pfcand_dzsig->at(icand)) ? 0 : jet_pfcand_dzsig->at(icand));
        Evaluate::jet_pfcand_dxysig_b.push_back(std::isnan(jet_pfcand_dxysig->at(icand)) ? 0 : jet_pfcand_dxysig->at(icand));
        Evaluate::jet_pfcand_pperp_ratio_b.push_back(std::isnan(jet_pfcand_pperp_ratio->at(icand)) ? 0 : jet_pfcand_pperp_ratio->at(icand));
        Evaluate::jet_pfcand_ppara_ratio_b.push_back(std::isnan(jet_pfcand_ppara_ratio->at(icand)) ? 0 : jet_pfcand_ppara_ratio->at(icand));
        Evaluate::jet_pfcand_deta_b.push_back(jet_pfcand_deta->at(icand));
        Evaluate::jet_pfcand_dphi_b.push_back(jet_pfcand_dphi->at(icand));
        Evaluate::jet_pfcand_etarel_b.push_back(std::isnan(jet_pfcand_etarel->at(icand)) ? 0 : jet_pfcand_etarel->at(icand));
        Evaluate::jet_pfcand_frompv_b.push_back(jet_pfcand_frompv->at(icand));
        Evaluate::jet_pfcand_charge_b.push_back(jet_pfcand_charge->at(icand));
        Evaluate::jet_pfcand_puppiw_b.push_back(jet_pfcand_puppiw->at(icand));

        Evaluate::jet_pfcand_track_qual_b.push_back(jet_pfcand_track_qual->at(icand));
        Evaluate::jet_pfcand_track_chi2_b.push_back(jet_pfcand_track_chi2->at(icand));
        Evaluate::jet_pfcand_track_algo_b.push_back(jet_pfcand_track_algo->at(icand));
        Evaluate::jet_pfcand_track_pterr_b.push_back((std::isnan(jet_pfcand_track_pterr->at(icand)) ? 0 : jet_pfcand_track_pterr->at(icand)));
        Evaluate::jet_pfcand_track_etaerr_b.push_back((std::isnan(jet_pfcand_track_etaerr->at(icand)) ? 0 : jet_pfcand_track_etaerr->at(icand)));
        Evaluate::jet_pfcand_track_phierr_b.push_back((std::isnan(jet_pfcand_track_phierr->at(icand)) ? 0 : jet_pfcand_track_phierr->at(icand)));
        Evaluate::jet_pfcand_nhits_b.push_back(jet_pfcand_nhits->at(icand));
        Evaluate::jet_pfcand_npixhits_b.push_back(jet_pfcand_npixhits->at(icand));
        Evaluate::jet_pfcand_nstriphits_b.push_back(jet_pfcand_nstriphits->at(icand));
        Evaluate::jet_pfcand_nlosthits_b.push_back(jet_pfcand_nlosthits->at(icand));
        Evaluate::jet_pfcand_npixlayers_b.push_back(jet_pfcand_npixlayers->at(icand));
        Evaluate::jet_pfcand_nstriplayers_b.push_back(jet_pfcand_nstriplayers->at(icand));

        if(jet_pfcand_id->at(icand) == 11 and jet_pfcand_charge->at(icand) != 0)
          Evaluate::jet_pfcand_id_b.push_back(0);
        else if(jet_pfcand_id->at(icand) == 13 and jet_pfcand_charge->at(icand) != 0)
          Evaluate::jet_pfcand_id_b.push_back(1);
        else if(jet_pfcand_id->at(icand) == 22 and jet_pfcand_charge->at(icand) == 0)
          Evaluate::jet_pfcand_id_b.push_back(2);
        else if(jet_pfcand_id->at(icand) != 22 and jet_pfcand_charge->at(icand) == 0 and jet_pfcand_id->at(icand) != 1 and jet_pfcand_id->at(icand) != 2)
          Evaluate::jet_pfcand_id_b.push_back(3);
        else if(jet_pfcand_id->at(icand) != 11 and jet_pfcand_id->at(icand) != 13 and jet_pfcand_charge->at(icand) != 0)
          Evaluate::jet_pfcand_id_b.push_back(4);
        else if(jet_pfcand_charge->at(icand) == 0  and jet_pfcand_id->at(icand) == 1)
          Evaluate::jet_pfcand_id_b.push_back(5);
        else if(jet_pfcand_charge->at(icand) == 0  and jet_pfcand_id->at(icand) == 2)
          Evaluate::jet_pfcand_id_b.push_back(6);
        else
          Evaluate::jet_pfcand_id_b.push_back(-1);

        Evaluate::jet_pfcand_trackjet_d3d_b.push_back(std::isnan(jet_pfcand_trackjet_d3d->at(icand)) ? 0 : jet_pfcand_trackjet_d3d->at(icand));
        Evaluate::jet_pfcand_trackjet_d3dsig_b.push_back(std::isnan(jet_pfcand_trackjet_d3dsig->at(icand)) ? 0 : jet_pfcand_trackjet_d3dsig->at(icand));
        Evaluate::jet_pfcand_trackjet_dist_b.push_back(std::isnan(jet_pfcand_trackjet_dist->at(icand)) ? 0 : jet_pfcand_trackjet_dist->at(icand));
        Evaluate::jet_pfcand_trackjet_decayL_b.push_back(std::isnan(jet_pfcand_trackjet_decayL->at(icand)) ? 0 : jet_pfcand_trackjet_decayL->at(icand));

        Evaluate::jet_pfcand_tau_signal_b.push_back(jet_pfcand_tau_signal->at(icand));
        Evaluate::jet_pfcand_tau_boosted_signal_b.push_back(jet_pfcand_tau_boosted_signal->at(icand));

        Evaluate::jet_pfcand_muon_id_b.push_back(jet_pfcand_muon_id->at(icand));
        Evaluate::jet_pfcand_muon_chi2_b.push_back(jet_pfcand_muon_chi2->at(icand));
        Evaluate::jet_pfcand_muon_segcomp_b.push_back(jet_pfcand_muon_segcomp->at(icand));
        Evaluate::jet_pfcand_muon_isglobal_b.push_back(jet_pfcand_muon_isglobal->at(icand));
        Evaluate::jet_pfcand_muon_nvalidhit_b.push_back(jet_pfcand_muon_nvalidhit->at(icand));
        Evaluate::jet_pfcand_muon_nstation_b.push_back(jet_pfcand_muon_nstation->at(icand));

        Evaluate::jet_pfcand_electron_eOverP_b.push_back(std::isnan(jet_pfcand_electron_eOverP->at(icand)) ? 0 : jet_pfcand_electron_eOverP->at(icand));
        Evaluate::jet_pfcand_electron_detaIn_b.push_back(jet_pfcand_electron_detaIn->at(icand));
        Evaluate::jet_pfcand_electron_dphiIn_b.push_back(jet_pfcand_electron_dphiIn->at(icand));
        Evaluate::jet_pfcand_electron_r9_b.push_back(std::isnan(jet_pfcand_electron_r9->at(icand)) ? 0 : jet_pfcand_electron_r9->at(icand));
        Evaluate::jet_pfcand_electron_sigIetaIeta_b.push_back(jet_pfcand_electron_sigIetaIeta->at(icand));
        Evaluate::jet_pfcand_electron_convProb_b.push_back(std::isnan(jet_pfcand_electron_convProb->at(icand)) ? 0 : jet_pfcand_electron_convProb->at(icand));
        Evaluate::jet_pfcand_electron_sigIphiIphi_b.push_back(std::isnan(jet_pfcand_electron_sigIphiIphi->at(icand)) ? 0 : jet_pfcand_electron_sigIphiIphi->at(icand));

        Evaluate::jet_pfcand_photon_sigIetaIeta_b.push_back(std::isnan(jet_pfcand_photon_sigIetaIeta->at(icand)) ? 0 : jet_pfcand_photon_sigIetaIeta->at(icand));
        Evaluate::jet_pfcand_photon_r9_b.push_back(std::isnan(jet_pfcand_photon_r9->at(icand)) ? 0 : jet_pfcand_photon_r9->at(icand));
        Evaluate::jet_pfcand_photon_eVeto_b.push_back(std::isnan(jet_pfcand_photon_eVeto->at(icand)) ? 0 : jet_pfcand_photon_eVeto->at(icand));

        // take muons
        if(jet_pfcand_id->at(icand) == 11){
          TLorentzVector tmp4V;
          tmp4V.SetPtEtaPhiM(jet_pfcand_pt->at(icand),jet_pfcand_eta->at(icand),jet_pfcand_phi->at(icand),jet_pfcand_mass->at(icand));
          electron4V_fromPF.push_back(tmp4V);
        }
        // take electrons
        if(jet_pfcand_id->at(icand) == 13){
          TLorentzVector tmp4V;
          tmp4V.SetPtEtaPhiM(jet_pfcand_pt->at(icand),jet_pfcand_eta->at(icand),jet_pfcand_phi->at(icand),jet_pfcand_mass->at(icand));
          muon4V_fromPF.push_back(tmp4V);
        }
        // take photons
        if(jet_pfcand_id->at(icand) == 22){
          TLorentzVector tmp4V;
          tmp4V.SetPtEtaPhiM(jet_pfcand_pt->at(icand),jet_pfcand_eta->at(icand),jet_pfcand_phi->at(icand),jet_pfcand_mass->at(icand));
          photon4V_fromPF.push_back(tmp4V);
        }
        // take every tau candidate
        if(jet_pfcand_tau_signal->at(icand)){
          TLorentzVector tmp4V;
          tmp4V.SetPtEtaPhiM(jet_pfcand_pt->at(icand),jet_pfcand_eta->at(icand),jet_pfcand_phi->at(icand),jet_pfcand_mass->at(icand));
          tau4V_fromPF += tmp4V;
        }
        if(jet_pfcand_tau_boosted_signal->at(icand)){
          TLorentzVector tmp4V;
          tmp4V.SetPtEtaPhiM(jet_pfcand_pt->at(icand),jet_pfcand_eta->at(icand),jet_pfcand_phi->at(icand),jet_pfcand_mass->at(icand));
          tau4V_boosted_fromPF += tmp4V;
        }

        if( Evaluate::jet_pfcand_pt_b.size() == pfcand_lenght ) break;
      }


      for(size_t icand = Evaluate::jet_pfcand_pt_b.size(); icand < pfcand_lenght; icand++){
        Evaluate::jet_pfcand_pt_b.push_back(0);
        Evaluate::jet_pfcand_pt_log_b.push_back(0);
        Evaluate::jet_pfcand_eta_b.push_back(0);
        Evaluate::jet_pfcand_abseta_b.push_back(0);
        Evaluate::jet_pfcand_phi_b.push_back(0);
        Evaluate::jet_pfcand_mass_b.push_back(0);
        Evaluate::jet_pfcand_energy_b.push_back(0);
        Evaluate::jet_pfcand_energy_log_b.push_back(0);
        Evaluate::jet_pfcand_calofraction_b.push_back(0);
        Evaluate::jet_pfcand_hcalfraction_b.push_back(0);
        Evaluate::jet_pfcand_dxy_b.push_back(0);
        Evaluate::jet_pfcand_dz_b.push_back(0);
        Evaluate::jet_pfcand_dzsig_b.push_back(0);
        Evaluate::jet_pfcand_dxysig_b.push_back(0);
        Evaluate::jet_pfcand_pperp_ratio_b.push_back(0);
        Evaluate::jet_pfcand_ppara_ratio_b.push_back(0);
        Evaluate::jet_pfcand_deta_b.push_back(0);
        Evaluate::jet_pfcand_dphi_b.push_back(0);
        Evaluate::jet_pfcand_etarel_b.push_back(0);
        Evaluate::jet_pfcand_frompv_b.push_back(0);
        Evaluate::jet_pfcand_charge_b.push_back(0);
        Evaluate::jet_pfcand_puppiw_b.push_back(0);

        Evaluate::jet_pfcand_track_qual_b.push_back(0);
        Evaluate::jet_pfcand_track_chi2_b.push_back(0);
        Evaluate::jet_pfcand_track_algo_b.push_back(0);
        Evaluate::jet_pfcand_track_pterr_b.push_back(0);
        Evaluate::jet_pfcand_track_etaerr_b.push_back(0);
        Evaluate::jet_pfcand_track_phierr_b.push_back(0);
        Evaluate::jet_pfcand_nhits_b.push_back(0);
        Evaluate::jet_pfcand_npixhits_b.push_back(0);
        Evaluate::jet_pfcand_nstriphits_b.push_back(0);
        Evaluate::jet_pfcand_nlosthits_b.push_back(0);
        Evaluate::jet_pfcand_npixlayers_b.push_back(0);
        Evaluate::jet_pfcand_nstriplayers_b.push_back(0);

        Evaluate::jet_pfcand_id_b.push_back(0);

        Evaluate::jet_pfcand_trackjet_d3d_b.push_back(0);
        Evaluate::jet_pfcand_trackjet_d3dsig_b.push_back(0);
        Evaluate::jet_pfcand_trackjet_dist_b.push_back(0);
        Evaluate::jet_pfcand_trackjet_decayL_b.push_back(0);

        Evaluate::jet_pfcand_tau_signal_b.push_back(0);
        Evaluate::jet_pfcand_tau_boosted_signal_b.push_back(0);

        Evaluate::jet_pfcand_muon_id_b.push_back(0);
        Evaluate::jet_pfcand_muon_chi2_b.push_back(0);
        Evaluate::jet_pfcand_muon_segcomp_b.push_back(0);
        Evaluate::jet_pfcand_muon_isglobal_b.push_back(0);
        Evaluate::jet_pfcand_muon_nvalidhit_b.push_back(0);
        Evaluate::jet_pfcand_muon_nstation_b.push_back(0);

        Evaluate::jet_pfcand_electron_eOverP_b.push_back(0);
        Evaluate::jet_pfcand_electron_detaIn_b.push_back(0);
        Evaluate::jet_pfcand_electron_dphiIn_b.push_back(0);
        Evaluate::jet_pfcand_electron_r9_b.push_back(0);
        Evaluate::jet_pfcand_electron_sigIetaIeta_b.push_back(0);
        Evaluate::jet_pfcand_electron_convProb_b.push_back(0);
        Evaluate::jet_pfcand_electron_sigIphiIphi_b.push_back(0);

        Evaluate::jet_pfcand_photon_sigIetaIeta_b.push_back(0);
        Evaluate::jet_pfcand_photon_r9_b.push_back(0);
        Evaluate::jet_pfcand_photon_eVeto_b.push_back(0);
      }


      vector<float> pf_points;
      pf_points.insert( pf_points.end(), Evaluate::jet_pfcand_deta_b.begin(), Evaluate::jet_pfcand_deta_b.end() );
      pf_points.insert( pf_points.end(), Evaluate::jet_pfcand_dphi_b.begin(), Evaluate::jet_pfcand_dphi_b.end() );
      //cout << "pf_points_size " << pf_points.size() << endl;

      vector<float> pf_features;
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_abseta_b.begin(), Evaluate::jet_pfcand_abseta_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_pt_log_b.begin(), Evaluate::jet_pfcand_pt_log_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_energy_log_b.begin(), Evaluate::jet_pfcand_energy_log_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_dxy_b.begin(), Evaluate::jet_pfcand_dxy_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_dxysig_b.begin(), Evaluate::jet_pfcand_dxysig_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_dz_b.begin(), Evaluate::jet_pfcand_dz_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_dzsig_b.begin(), Evaluate::jet_pfcand_dzsig_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_deta_b.begin(), Evaluate::jet_pfcand_deta_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_dphi_b.begin(), Evaluate::jet_pfcand_dphi_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_frompv_b.begin(), Evaluate::jet_pfcand_frompv_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_charge_b.begin(), Evaluate::jet_pfcand_charge_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_track_qual_b.begin(), Evaluate::jet_pfcand_track_qual_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_track_chi2_b.begin(), Evaluate::jet_pfcand_track_chi2_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_nhits_b.begin(), Evaluate::jet_pfcand_nhits_b.end() );
      pf_features.insert( pf_features.end(), Evaluate::jet_pfcand_nlosthits_b.begin(), Evaluate::jet_pfcand_nlosthits_b.end() );
      //cout << "pf_features_size " << pf_features.size() << endl;

      vector<float> pf_mask;
      for(int i = 0; i < pfcand_lenght; i++){
          float mask_i = 0;
          for(int j = 0; j < 15; j++){
              if(pf_features.at(i+j*pfcand_lenght) != 0) mask_i = 1;
          }
          pf_mask.push_back(mask_i);
      }
      //cout << "pf_mask " << pf_mask << endl;

      vector<float> sv_points;
      sv_points.insert( sv_points.end(), Evaluate::jet_sv_deta_b.begin(), Evaluate::jet_sv_deta_b.end() );
      sv_points.insert( sv_points.end(), Evaluate::jet_sv_dphi_b.begin(), Evaluate::jet_sv_dphi_b.end() );
      //cout << "sv_points_size " << sv_points.size() << endl;

      vector<float> sv_features;
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_pt_log_b.begin(), Evaluate::jet_sv_pt_log_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_abseta_b.begin(), Evaluate::jet_sv_abseta_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_mass_b.begin(), Evaluate::jet_sv_mass_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_deta_b.begin(), Evaluate::jet_sv_deta_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_dphi_b.begin(), Evaluate::jet_sv_dphi_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_chi2_b.begin(), Evaluate::jet_sv_chi2_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_dxy_b.begin(), Evaluate::jet_sv_dxy_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_dxysig_b.begin(), Evaluate::jet_sv_dxysig_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_d3d_b.begin(), Evaluate::jet_sv_d3d_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_d3dsig_b.begin(), Evaluate::jet_sv_d3dsig_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_ntrack_b.begin(), Evaluate::jet_sv_ntrack_b.end() );
      //cout << "sv_features_size " << sv_features.size() << endl;

      vector<float> sv_mask;
      for(int i = 0; i < sv_lenght; i++){
          float mask_i = 0;
          for(int j = 0; j < 11; j++){
              if(sv_features.at(i+j*sv_lenght) != 0) mask_i = 1;
          }
          sv_mask.push_back(mask_i);
      }
      //cout << "sv_mask " << sv_mask << endl;


      vector<vector<float>> inputTensorValues = {pf_points, pf_features, pf_mask, sv_points, sv_features, sv_mask};
      vector<vector<int64_t>> inputTensorDims = {{1, 2, 100}, {1, 15, 100}, {1, 1, 100}, {1, 2, 10}, {1, 11, 10}, {1, 1, 10}};
      const char* inputNames[] = {"pf_points", "pf_features", "pf_mask", "sv_points", "sv_features", "sv_mask"};

      vector<vector<float>> outputTensorValues = {{999.}};
      vector<vector<int64_t>> outputTensorDims = {{1, 1}};
      const char* outputNames[] = {"softmax"};


      vector<float> ZtoQQxQCD_tag_vec = ZtoQQxQCD_tagger.predict(inputNames, inputTensorValues, inputTensorDims, outputNames, outputTensorValues, outputTensorDims);

      Evaluate::ZtoQQxQCD_tag = ZtoQQxQCD_tag_vec.at(0);




      HDF_fill();
      //_outputTree->Fill();
    }

    return;
}


//-------------------------------------------------------------------------------------------------
// Produce systematic histograms
//-------------------------------------------------------------------------------------------------
void HEPHero::EvaluateSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishEvaluate() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
