#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace Skimming{

    int sample_b;

    unsigned int run_b, lumi_b, event_b, npv_b, nsv_b, npu_b;
    float rho_b,met_b;
    unsigned int ijet_b;

    float jet_pt_b,jet_eta_b,jet_abseta_b,jet_phi_b,jet_mass_b,jet_pt_raw_b,jet_mass_raw_b;

    unsigned int jet_ncand_b, jet_nbhad_b, jet_nchad_b, jet_hflav_b;
    float jet_chf_b, jet_nhf_b, jet_phf_b, jet_elf_b, jet_muf_b;
    int jet_pflav_b, jet_tauflav_b, jet_muflav_b, jet_elflav_b, jet_lepflav_b;
    int jet_flav_2prong_partonjet_match_b, jet_flav_2prong_parton_match_b;

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

    float Z_pt;
    bool match_DR_res_jet;
    bool match_DR_dau_jet;
    int matched_res_decay_id;
    float R_ref;

}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupSkimming() {

    //======SETUP CUTFLOW==========================================================================
    _cutFlow.insert(pair<string,double>("NumBadGenEvent", 0) );
    _cutFlow.insert(pair<string,double>("00_Total", 0) );
    _cutFlow.insert(pair<string,double>("01_PassBaseCuts", 0) );
    _cutFlow.insert(pair<string,double>("02_SignalResCuts", 0) );
    //_cutFlow.insert(pair<string,double>("03_HasJetLooseId", 0) );
    //_cutFlow.insert(pair<string,double>("04_MassCut", 0) );

    //======SETUP HISTOGRAMS=======================================================================
    makeHist( "res_decay_id", 25, 0., 25., "res_decay_id", "jets" );
    //makeHist( "histogram2DName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP SYSTEMATIC HISTOGRAMS============================================================
    //sys_regions = { 0, 1, 2 }; [example] // Choose regions as defined in RegionID. Empty vector means that all events will be used.
    //makeSysHist( "histogram1DSysName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeSysHist( "histogram2DSysName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP OUTPUT BRANCHES==================================================================


    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    //HDF_insert("run",&Skimming::run_b);
    //HDF_insert("lumi",&Skimming::lumi_b);
    //HDF_insert("event",&Skimming::event_b);

    HDF_insert("npu",&Skimming::npu_b);
    HDF_insert("met",&Skimming::met_b);
    HDF_insert("jet_pt",&Skimming::jet_pt_b);
    HDF_insert("jet_eta",&Skimming::jet_eta_b);
    HDF_insert("jet_phi",&Skimming::jet_phi_b);
    HDF_insert("jet_mass",&Skimming::jet_mass_b);
    HDF_insert("jet_softdrop_mass",&Skimming::jet_softdrop_mass_b);


    /*
    HDF_insert("jet_chf",&Skimming::jet_chf_b);
    HDF_insert("jet_nhf",&Skimming::jet_nhf_b);
    HDF_insert("jet_phf",&Skimming::jet_phf_b);
    HDF_insert("jet_elf",&Skimming::jet_elf_b);
    HDF_insert("jet_muf",&Skimming::jet_muf_b);
    HDF_insert("jet_ncand",&Skimming::jet_ncand_b);
    HDF_insert("jet_nbhad",&Skimming::jet_nbhad_b);
    HDF_insert("jet_nchad",&Skimming::jet_nchad_b);
    HDF_insert("jet_hflav",&Skimming::jet_hflav_b);
    HDF_insert("jet_pflav",&Skimming::jet_pflav_b);
    HDF_insert("jet_muflav",&Skimming::jet_muflav_b);
    HDF_insert("jet_elflav",&Skimming::jet_elflav_b);
    HDF_insert("jet_lepflav",&Skimming::jet_lepflav_b);
    HDF_insert("jet_tauflav",&Skimming::jet_tauflav_b);
    HDF_insert("jet_flav_2prong_partonjet_match",&Skimming::jet_flav_2prong_partonjet_match_b);
    HDF_insert("jet_flav_2prong_parton_match",&Skimming::jet_flav_2prong_parton_match_b);

    HDF_insert("jet_genmatch_pt",&Skimming::jet_genmatch_pt_b);
    HDF_insert("jet_genmatch_eta",&Skimming::jet_genmatch_eta_b);
    HDF_insert("jet_genmatch_phi",&Skimming::jet_genmatch_phi_b);
    HDF_insert("jet_genmatch_mass",&Skimming::jet_genmatch_mass_b);
    HDF_insert("jet_genmatch_wnu_pt",&Skimming::jet_genmatch_wnu_pt_b);
    HDF_insert("jet_genmatch_wnu_eta",&Skimming::jet_genmatch_wnu_eta_b);
    HDF_insert("jet_genmatch_wnu_phi",&Skimming::jet_genmatch_wnu_phi_b);
    HDF_insert("jet_genmatch_wnu_mass",&Skimming::jet_genmatch_wnu_mass_b);
    HDF_insert("jet_genmatch_nu_pt",&Skimming::jet_genmatch_nu_pt_b);
    HDF_insert("jet_genmatch_nu_eta",&Skimming::jet_genmatch_nu_eta_b);
    HDF_insert("jet_genmatch_nu_phi",&Skimming::jet_genmatch_nu_phi_b);
    HDF_insert("jet_genmatch_nu_mass",&Skimming::jet_genmatch_nu_mass_b);
    HDF_insert("jet_genmatch_nu_energy",&Skimming::jet_genmatch_nu_energy_b);

    HDF_insert("jet_softdrop_pt",&Skimming::jet_softdrop_pt_b);
    HDF_insert("jet_softdrop_eta",&Skimming::jet_softdrop_eta_b);
    HDF_insert("jet_softdrop_phi",&Skimming::jet_softdrop_phi_b);
    HDF_insert("jet_softdrop_mass",&Skimming::jet_softdrop_mass_b);

    HDF_insert("jet_softdrop_genmatch_pt",&Skimming::jet_softdrop_genmatch_pt_b);
    HDF_insert("jet_softdrop_genmatch_eta",&Skimming::jet_softdrop_genmatch_eta_b);
    HDF_insert("jet_softdrop_genmatch_phi",&Skimming::jet_softdrop_genmatch_phi_b);
    HDF_insert("jet_softdrop_genmatch_mass",&Skimming::jet_softdrop_genmatch_mass_b);

    HDF_insert("jet_pt_truth_vis",&Skimming::jet_pt_truth_vis_b);
    HDF_insert("jet_eta_truth_vis",&Skimming::jet_eta_truth_vis_b);
    HDF_insert("jet_phi_truth_vis",&Skimming::jet_phi_truth_vis_b);
    HDF_insert("jet_mass_truth_vis",&Skimming::jet_mass_truth_vis_b);
    */

    HDF_insert("jet_pt_truth",&Skimming::jet_pt_truth_b);
    HDF_insert("jet_eta_truth",&Skimming::jet_eta_truth_b);
    HDF_insert("jet_phi_truth",&Skimming::jet_phi_truth_b);
    HDF_insert("jet_mass_truth",&Skimming::jet_mass_truth_b);

    HDF_insert("jetPFcand_pt",&Skimming::jet_pfcand_pt_b);
    HDF_insert("jetPFcand_eta",&Skimming::jet_pfcand_eta_b);
    HDF_insert("jetPFcand_abseta",&Skimming::jet_pfcand_abseta_b);
    HDF_insert("jetPFcand_phi",&Skimming::jet_pfcand_phi_b);
    HDF_insert("jetPFcand_mass",&Skimming::jet_pfcand_mass_b);
    HDF_insert("jetPFcand_energy",&Skimming::jet_pfcand_energy_b);
    HDF_insert("jetPFcand_pt_log",&Skimming::jet_pfcand_pt_log_b);
    HDF_insert("jetPFcand_energy_log",&Skimming::jet_pfcand_energy_log_b);
    HDF_insert("jetPFcand_calofraction",&Skimming::jet_pfcand_calofraction_b);
    HDF_insert("jetPFcand_hcalfraction",&Skimming::jet_pfcand_hcalfraction_b);
    HDF_insert("jetPFcand_dxy",&Skimming::jet_pfcand_dxy_b);
    HDF_insert("jetPFcand_dxysig",&Skimming::jet_pfcand_dxysig_b);
    HDF_insert("jetPFcand_dz",&Skimming::jet_pfcand_dz_b);
    HDF_insert("jetPFcand_dzsig",&Skimming::jet_pfcand_dzsig_b);
    HDF_insert("jetPFcand_pperp_ratio",&Skimming::jet_pfcand_pperp_ratio_b);
    HDF_insert("jetPFcand_ppara_ratio",&Skimming::jet_pfcand_ppara_ratio_b);
    HDF_insert("jetPFcand_deta",&Skimming::jet_pfcand_deta_b);
    HDF_insert("jetPFcand_dphi",&Skimming::jet_pfcand_dphi_b);
    HDF_insert("jetPFcand_etarel",&Skimming::jet_pfcand_etarel_b);
    HDF_insert("jetPFcand_puppiw",&Skimming::jet_pfcand_puppiw_b);

    HDF_insert("jetPFcand_frompv",&Skimming::jet_pfcand_frompv_b);
    HDF_insert("jetPFcand_id",&Skimming::jet_pfcand_id_b);
    HDF_insert("jetPFcand_charge",&Skimming::jet_pfcand_charge_b);
    HDF_insert("jetPFcand_track_qual",&Skimming::jet_pfcand_track_qual_b);
    HDF_insert("jetPFcand_track_chi2",&Skimming::jet_pfcand_track_chi2_b);
    HDF_insert("jetPFcand_track_algo",&Skimming::jet_pfcand_track_algo_b);
    HDF_insert("jetPFcand_track_pterr",&Skimming::jet_pfcand_track_pterr_b);
    HDF_insert("jetPFcand_track_etaerr",&Skimming::jet_pfcand_track_etaerr_b);
    HDF_insert("jetPFcand_track_phierr",&Skimming::jet_pfcand_track_phierr_b);
    HDF_insert("jetPFcand_nhits",&Skimming::jet_pfcand_nhits_b);
    HDF_insert("jetPFcand_npixhits",&Skimming::jet_pfcand_npixhits_b);
    HDF_insert("jetPFcand_nstriphits",&Skimming::jet_pfcand_nstriphits_b);
    HDF_insert("jetPFcand_nlosthits",&Skimming::jet_pfcand_nlosthits_b);
    HDF_insert("jetPFcand_npixlayers",&Skimming::jet_pfcand_npixlayers_b);
    HDF_insert("jetPFcand_nstriplayers",&Skimming::jet_pfcand_nstriplayers_b);

    HDF_insert("jetPFcand_tau_signal",&Skimming::jet_pfcand_tau_signal_b);
    //HDF_insert("jetPFcand_tau_boosted_signal",&Skimming::jet_pfcand_tau_boosted_signal_b);
    HDF_insert("jetPFcand_muon_id",&Skimming::jet_pfcand_muon_id_b);
    HDF_insert("jetPFcand_muon_chi2",&Skimming::jet_pfcand_muon_chi2_b);
    HDF_insert("jetPFcand_muon_segcomp",&Skimming::jet_pfcand_muon_segcomp_b);
    HDF_insert("jetPFcand_muon_isglobal",&Skimming::jet_pfcand_muon_isglobal_b);
    HDF_insert("jetPFcand_muon_nvalidhit",&Skimming::jet_pfcand_muon_nvalidhit_b);
    HDF_insert("jetPFcand_muon_nstation",&Skimming::jet_pfcand_muon_nstation_b);
    HDF_insert("jetPFcand_electron_eOverP",&Skimming::jet_pfcand_electron_eOverP_b);
    HDF_insert("jetPFcand_electron_detaIn",&Skimming::jet_pfcand_electron_detaIn_b);
    HDF_insert("jetPFcand_electron_dphiIn",&Skimming::jet_pfcand_electron_dphiIn_b);
    HDF_insert("jetPFcand_electron_r9",&Skimming::jet_pfcand_electron_r9_b);
    HDF_insert("jetPFcand_electron_sigIetaIeta",&Skimming::jet_pfcand_electron_sigIetaIeta_b);
    HDF_insert("jetPFcand_electron_sigIphiIphi",&Skimming::jet_pfcand_electron_sigIphiIphi_b);
    //HDF_insert("jetPFcand_electron_convProb",&Skimming::jet_pfcand_electron_convProb_b);

    HDF_insert("jetPFcand_photon_sigIetaIeta",&Skimming::jet_pfcand_photon_sigIetaIeta_b);
    HDF_insert("jetPFcand_photon_r9",&Skimming::jet_pfcand_photon_r9_b);
    HDF_insert("jetPFcand_photon_eVeto",&Skimming::jet_pfcand_photon_eVeto_b);

    HDF_insert("jetPFcand_trackjet_d3d",&Skimming::jet_pfcand_trackjet_d3d_b);
    HDF_insert("jetPFcand_trackjet_d3dsig",&Skimming::jet_pfcand_trackjet_d3dsig_b);
    HDF_insert("jetPFcand_trackjet_dist",&Skimming::jet_pfcand_trackjet_dist_b);
    HDF_insert("jetPFcand_trackjet_decayL",&Skimming::jet_pfcand_trackjet_decayL_b);

    HDF_insert("jetSV_pt",&Skimming::jet_sv_pt_b);
    HDF_insert("jetSV_pt_log",&Skimming::jet_sv_pt_log_b);
    HDF_insert("jetSV_eta",&Skimming::jet_sv_eta_b);
    HDF_insert("jetSV_abseta",&Skimming::jet_sv_abseta_b);
    HDF_insert("jetSV_phi",&Skimming::jet_sv_phi_b);
    HDF_insert("jetSV_mass",&Skimming::jet_sv_mass_b);
    HDF_insert("jetSV_energy",&Skimming::jet_sv_energy_b);
    HDF_insert("jetSV_energy_log",&Skimming::jet_sv_energy_log_b);
    HDF_insert("jetSV_deta",&Skimming::jet_sv_deta_b);
    HDF_insert("jetSV_dphi",&Skimming::jet_sv_dphi_b);
    HDF_insert("jetSV_chi2",&Skimming::jet_sv_chi2_b);
    HDF_insert("jetSV_dxy",&Skimming::jet_sv_dxy_b);
    HDF_insert("jetSV_dxysig",&Skimming::jet_sv_dxysig_b);
    HDF_insert("jetSV_d3d",&Skimming::jet_sv_d3d_b);
    HDF_insert("jetSV_d3dsig",&Skimming::jet_sv_d3dsig_b);
    HDF_insert("jetSV_ntrack",&Skimming::jet_sv_ntrack_b);

    HDF_insert("Z_pt", &Skimming::Z_pt );
    HDF_insert("matched_res_decay_id", &Skimming::matched_res_decay_id);

    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::SkimmingRegion() {

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
void HEPHero::SkimmingSelection() {

    /// Simple object to store resonance and daughter GEN kinematics
    class Resonance {
    public:
        Resonance(){};
        ~Resonance(){};
        TLorentzVector p4;
        int id;
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
    float jetPtMin = 200; // Min jet pT to apply
    float jetEtaMax = 2.5; // Max jet eta to apply
    float jetEtaMin = 0.; // Min jet eta to apply
    float jetMassTruthMin = 0; // Min mass selection to apply based on the truth definition given in the code
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
        resonances.back().id = gen_particle_id->at(igen);
        for(size_t idau = 0; idau < gen_particle_daughters_id->size(); idau++){
          if(gen_particle_daughters_igen->at(idau) == igen){
            resonances.back().daugid.push_back(gen_particle_daughters_id->at(idau));
            TLorentzVector daughter4V;
            daughter4V.SetPtEtaPhiM(gen_particle_daughters_pt->at(idau),gen_particle_daughters_eta->at(idau),gen_particle_daughters_phi->at(idau),gen_particle_daughters_mass->at(idau));
            resonances.back().daugp4.push_back(daughter4V);
          }
        }
        if(resonances.back().daugp4.size() != 2){
          std::cerr<<"Found more than two decay particles from Higgs or W or Z or top --> please check!!! --> rejecting the event"<<std::endl;
          badGenEvent = true;
        }
      }
    }

    /*
    cout << "resonances size " << resonances.size() << endl;
    for(size_t ires = 0; ires < resonances.size(); ires++){
      cout << "res id " << resonances.at(ires).id << endl;
      cout << "dau size " << resonances.at(ires).daugp4.size() << endl;
      for(size_t idau = 0; idau < resonances.at(ires).daugp4.size(); idau++){
        cout << "dau id " << resonances.at(ires).daugid.at(idau) << endl;
      }
    }
    cout << " " << endl;
    */

    if(dsName.substr(0,2) == "TT"){
      int W_ires;
      for(size_t ires = 0; ires < resonances.size(); ires++){
        for(size_t idau = 0; idau < resonances.at(ires).daugp4.size(); idau++){
          if((abs(resonances.at(ires).id) == 24) && (abs(resonances.at(ires).daugid.at(idau)) < 6)){
            W_ires = ires;
          }
        }
      }

      int W_sign = resonances.at(W_ires).id/abs(resonances.at(W_ires).id);
      for(size_t ires = 0; ires < resonances.size(); ires++){
        int res_sign = resonances.at(ires).id/abs(resonances.at(ires).id);
        if((abs(resonances.at(ires).id) == 6) && (res_sign == W_sign)){
          for(size_t idau = 0; idau < resonances.at(ires).daugp4.size(); idau++){
            if(abs(resonances.at(ires).daugid.at(idau)) == 24){
              resonances.at(ires).daugid.erase(resonances.at(ires).daugid.begin() + idau);
              resonances.at(ires).daugp4.erase(resonances.at(ires).daugp4.begin() + idau);
            }
          }
          resonances.at(ires).daugid.push_back(resonances.at(W_ires).daugid.at(0));
          resonances.at(ires).daugp4.push_back(resonances.at(W_ires).daugp4.at(0));
          resonances.at(ires).daugid.push_back(resonances.at(W_ires).daugid.at(1));
          resonances.at(ires).daugp4.push_back(resonances.at(W_ires).daugp4.at(1));
        }
      }

      for(size_t irm = 0; irm < 3; irm++){
        for(size_t ires = 0; ires < resonances.size(); ires++){
          int res_sign = resonances.at(ires).id/abs(resonances.at(ires).id);
          if((abs(resonances.at(ires).id) != 6) || (res_sign != W_sign)){
            resonances.erase(resonances.begin() + ires);
            break;
          }
        }
      }
    }

    /*
    cout << "resonances size " << resonances.size() << endl;
    for(size_t ires = 0; ires < resonances.size(); ires++){
      cout << "res id " << resonances.at(ires).id << endl;
      cout << "dau size " << resonances.at(ires).daugp4.size() << endl;
      for(size_t idau = 0; idau < resonances.at(ires).daugp4.size(); idau++){
        cout << "dau id " << resonances.at(ires).daugid.at(idau) << endl;
      }
    }
    cout << " " << endl;
    cout << " " << endl;
    */


    if(badGenEvent){
      _cutFlow.at("NumBadGenEvent") += 1;
      return;
    }


    //--------------------------------------------------------------------
    /// Loop over the main jet collection
    for(size_t ijet = 0; ijet < jet_pt->size(); ijet++){

      float dRCone;
      float dRMatchingDaughterJet;
      dRCone = 0.8;
      dRMatchingDaughterJet = 0.8;
      
      Skimming::R_ref = dRCone;

      _cutFlow.at("00_Total") += 1;

      // Base Selection
      if(jet_pt->at(ijet) < jetPtMin or jet_pt->at(ijet) > jetPtMax or fabs(jet_eta->at(ijet)) > jetEtaMax or fabs(jet_eta->at(ijet)) < jetEtaMin) continue;
      _cutFlow.at("01_PassBaseCuts") += 1;

      TLorentzVector jet4V;
      jet4V.SetPtEtaPhiM(jet_pt->at(ijet),jet_eta->at(ijet),jet_phi->at(ijet),jet_mass->at(ijet));

      // Matching with the resonance for signal jets using the kinematics
      int match_index_dR_res_jet = -1;
      float mindR_jetres = 1000;
      Skimming::match_DR_res_jet = false;
      Skimming::match_DR_dau_jet = false;
      for(size_t ires = 0; ires < resonances.size(); ires++){
        float dRjres = jet4V.DeltaR(resonances.at(ires).p4);
        if(dRjres < dRCone and dRjres < mindR_jetres){
          Skimming::match_DR_res_jet = true;
          match_index_dR_res_jet = ires;
          mindR_jetres = dRjres;
          if(resonances.at(ires).daugp4.size() == 2){
            float dR1 = resonances.at(ires).daugp4.at(0).DeltaR(jet4V);
            float dR2 = resonances.at(ires).daugp4.at(1).DeltaR(jet4V);
            float dR  = resonances.at(ires).daugp4.front().DeltaR(resonances.at(ires).daugp4.back());
            if(dR1 < dRMatchingDaughterJet and dR2 < dRMatchingDaughterJet){
              Skimming::match_DR_dau_jet = true;
            }
          }else if(resonances.at(ires).daugp4.size() == 3){
            float dR1 = resonances.at(ires).daugp4.at(0).DeltaR(jet4V);
            float dR2 = resonances.at(ires).daugp4.at(1).DeltaR(jet4V);
            float dR3 = resonances.at(ires).daugp4.at(2).DeltaR(jet4V);
            if(dR1 < dRMatchingDaughterJet and dR2 < dRMatchingDaughterJet and dR3 < dRMatchingDaughterJet){
              Skimming::match_DR_dau_jet = true;
            }
          }
        }
      }


      // matching based on dR parton-jet
      Skimming::matched_res_decay_id = -1; // only real QCD jets / not-matched resonances
      if(match_index_dR_res_jet != -1){
        if(resonances.at(match_index_dR_res_jet).daugid.size() == 2){
          if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) == 5 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) == 5) // X(bb)
            Skimming::matched_res_decay_id = 5;
          else if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) == 4 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) == 4) // X(cc)
            Skimming::matched_res_decay_id = 4;
          else if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) <= 3 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) <= 3) // X(qq)
            Skimming::matched_res_decay_id = 3;
          else if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) == 21 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) == 21) // X(gg)
            Skimming::matched_res_decay_id = 21;
          else
            Skimming::matched_res_decay_id = 0; // whatever remains
        }else if(resonances.at(match_index_dR_res_jet).daugid.size() == 3){
          if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) < 6 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) < 6  and abs(resonances.at(match_index_dR_res_jet).daugid.at(2)) < 6) // Top(qqb)
            Skimming::matched_res_decay_id = 1;
          else
            Skimming::matched_res_decay_id = 0; // whatever remains
        }
      }


      // for signal samples exclude all jets unmatched (if enabled) to avoid labelling as QCD signal jets that are not matched to a resonance
      if((dsName.substr(0,5) == "Zto2Q") || (dsName.substr(0,2) == "TT")){
        if(saveOnlyResonanceMatchedJets and Skimming::matched_res_decay_id <= 0) continue;
        _cutFlow.at("02_SignalResCuts") += 1;
      }

      //if( jet_id->at(ijet) == 0 ) continue;
      //_cutFlow.at("03_HasJetLooseId") += 1;


      // if found, take the truth kinematic of the resonance from its GEN level (neutrinos included) and blacklist the resonance
      if(match_index_dR_res_jet != -1){
        // truth corresponds to the pole resonance kinematic properties
        Skimming::jet_pt_truth_b   = resonances.at(match_index_dR_res_jet).p4.Pt();
        Skimming::jet_eta_truth_b  = resonances.at(match_index_dR_res_jet).p4.Eta();
        Skimming::jet_phi_truth_b  = resonances.at(match_index_dR_res_jet).p4.Phi();
        Skimming::jet_mass_truth_b = resonances.at(match_index_dR_res_jet).p4.M();
      }
      else{
        // take the gen soft drop in QCD jets or un-matched jets, no need for the neutrino correction, everything fixed to be soft-drop
        Skimming::jet_pt_truth_b   = jet_genmatch_wnu_pt->at(ijet);
        Skimming::jet_eta_truth_b  = jet_genmatch_wnu_eta->at(ijet);
        Skimming::jet_phi_truth_b  = jet_genmatch_wnu_phi->at(ijet);
        Skimming::jet_mass_truth_b = jet_genmatch_wnu_mass->at(ijet);
      }


      // selection on the truth mass
      //if((dsName.substr(0,5) == "Zto2Q") || (dsName.substr(0,2) == "TT")){
      //  if(Skimming::jet_mass_truth_b < jetMassTruthMin) continue;
      //  _cutFlow.at("04_MassCut") += 1;
      //}


      Skimming::Z_pt = 0;
      if( dsName.substr(0,14) == "Zto2Q_PTQQ-100" ) Skimming::Z_pt = 100;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-200" ) Skimming::Z_pt = 200;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-400" ) Skimming::Z_pt = 400;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-600" ) Skimming::Z_pt = 600;

      Skimming::npu_b = putrue;
      Skimming::met_b = met;

      // fill jet branches
      Skimming::jet_pt_b = jet_pt->at(ijet);
      Skimming::jet_eta_b = jet_eta->at(ijet);
      Skimming::jet_phi_b = jet_phi->at(ijet);
      Skimming::jet_mass_b = jet_mass->at(ijet);

      // soft drop
      //Skimming::jet_softdrop_pt_b = jet_softdrop_pt->at(ijet);
      //Skimming::jet_softdrop_eta_b = jet_softdrop_eta->at(ijet);
      //Skimming::jet_softdrop_phi_b = jet_softdrop_phi->at(ijet);
      Skimming::jet_softdrop_mass_b = jet_softdrop_mass->at(ijet);


      // SV
      Skimming::jet_sv_pt_b.clear(); Skimming::jet_sv_eta_b.clear(); Skimming::jet_sv_abseta_b.clear(); Skimming::jet_sv_phi_b.clear(); Skimming::jet_sv_mass_b.clear(); Skimming::jet_sv_energy_b.clear();
      Skimming::jet_sv_deta_b.clear(); Skimming::jet_sv_dphi_b.clear();
      Skimming::jet_sv_chi2_b.clear(); Skimming::jet_sv_dxy_b.clear(); Skimming::jet_sv_dxysig_b.clear();
      Skimming::jet_sv_d3d_b.clear(); Skimming::jet_sv_d3dsig_b.clear(); Skimming::jet_sv_ntrack_b.clear();
      Skimming::jet_sv_pt_log_b.clear(); Skimming::jet_sv_energy_log_b.clear();

      for(size_t isv = 0; isv < jet_sv_pt->size(); isv++){

        if(ijet != jet_sv_ijet->at(isv)) continue;

        Skimming::jet_sv_pt_b.push_back(jet_sv_pt->at(isv));
        Skimming::jet_sv_pt_log_b.push_back(std::isnan(std::log(jet_sv_pt->at(isv))) ? 0 : std::log(jet_sv_pt->at(isv)));
        Skimming::jet_sv_eta_b.push_back(jet_sv_eta->at(isv));
        Skimming::jet_sv_abseta_b.push_back(abs(jet_sv_eta->at(isv)));
        Skimming::jet_sv_phi_b.push_back(jet_sv_phi->at(isv));
        Skimming::jet_sv_energy_b.push_back(jet_sv_energy->at(isv));
        Skimming::jet_sv_energy_log_b.push_back(std::isnan(std::log(jet_sv_energy->at(isv))) ? 0 : std::log(jet_sv_energy->at(isv)));
        Skimming::jet_sv_mass_b.push_back(jet_sv_mass->at(isv));
        Skimming::jet_sv_deta_b.push_back(jet_sv_eta->at(isv)-jet_eta->at(ijet));
        Skimming::jet_sv_dphi_b.push_back(jet_sv_phi->at(isv)-jet_phi->at(ijet));
        Skimming::jet_sv_chi2_b.push_back(jet_sv_chi2->at(isv));
        Skimming::jet_sv_dxy_b.push_back(std::isnan(jet_sv_dxy->at(isv)) ? 0 : jet_sv_dxy->at(isv));
        Skimming::jet_sv_dxysig_b.push_back(std::isnan(jet_sv_dxysig->at(isv)) ? 0 : jet_sv_dxysig->at(isv));
        Skimming::jet_sv_d3d_b.push_back(std::isnan(jet_sv_d3d->at(isv)) ? 0 : jet_sv_d3d->at(isv));
        Skimming::jet_sv_d3dsig_b.push_back(std::isnan(jet_sv_d3dsig->at(isv)) ? 0 : jet_sv_d3dsig->at(isv));
        Skimming::jet_sv_ntrack_b.push_back(jet_sv_ntrack->at(isv));

        if( Skimming::jet_sv_pt_b.size() == sv_lenght ) break;
      }




      // PF candidates
      Skimming::jet_pfcand_pt_b.clear(); Skimming::jet_pfcand_eta_b.clear(); Skimming::jet_pfcand_abseta_b.clear(); Skimming::jet_pfcand_phi_b.clear(); Skimming::jet_pfcand_mass_b.clear(); Skimming::jet_pfcand_energy_b.clear(); Skimming::jet_pfcand_calofraction_b.clear();
      Skimming::jet_pfcand_hcalfraction_b.clear(); Skimming::jet_pfcand_dxy_b.clear(); Skimming::jet_pfcand_dz_b.clear(); Skimming::jet_pfcand_dxysig_b.clear(); Skimming::jet_pfcand_dzsig_b.clear();
      Skimming::jet_pfcand_pperp_ratio_b.clear(); Skimming::jet_pfcand_ppara_ratio_b.clear(); Skimming::jet_pfcand_deta_b.clear(); Skimming::jet_pfcand_dphi_b.clear();
      Skimming::jet_pfcand_pt_log_b.clear(); Skimming::jet_pfcand_energy_log_b.clear(); Skimming::jet_pfcand_etarel_b.clear(); Skimming::jet_pfcand_puppiw_b.clear();
      Skimming::jet_pfcand_charge_b.clear(); Skimming::jet_pfcand_frompv_b.clear(); Skimming::jet_pfcand_id_b.clear(); Skimming::jet_pfcand_track_qual_b.clear(); Skimming::jet_pfcand_track_chi2_b.clear();
      Skimming::jet_pfcand_trackjet_d3d_b.clear(); Skimming::jet_pfcand_trackjet_d3dsig_b.clear(); Skimming::jet_pfcand_trackjet_dist_b.clear(); Skimming::jet_pfcand_trackjet_decayL_b.clear();
      Skimming::jet_pfcand_track_pterr_b.clear(); Skimming::jet_pfcand_track_etaerr_b.clear(); Skimming::jet_pfcand_track_phierr_b.clear();
      Skimming::jet_pfcand_nhits_b.clear(); Skimming::jet_pfcand_npixhits_b.clear(); Skimming::jet_pfcand_nstriphits_b.clear(); Skimming::jet_pfcand_nlosthits_b.clear();
      Skimming::jet_pfcand_npixlayers_b.clear(); Skimming::jet_pfcand_nstriplayers_b.clear(), Skimming::jet_pfcand_track_algo_b.clear();
      Skimming::jet_pfcand_tau_signal_b.clear(); Skimming::jet_pfcand_tau_boosted_signal_b.clear();
      Skimming::jet_pfcand_muon_id_b.clear(); Skimming::jet_pfcand_muon_chi2_b.clear(); Skimming::jet_pfcand_muon_segcomp_b.clear(); Skimming::jet_pfcand_muon_isglobal_b.clear();
      Skimming::jet_pfcand_muon_nvalidhit_b.clear(); Skimming::jet_pfcand_muon_nstation_b.clear();
      Skimming::jet_pfcand_electron_eOverP_b.clear(); Skimming::jet_pfcand_electron_detaIn_b.clear(); Skimming::jet_pfcand_electron_dphiIn_b.clear(); Skimming::jet_pfcand_electron_r9_b.clear();
      Skimming::jet_pfcand_electron_convProb_b.clear(); Skimming::jet_pfcand_electron_sigIetaIeta_b.clear(); Skimming::jet_pfcand_electron_sigIphiIphi_b.clear();
      Skimming::jet_pfcand_photon_sigIetaIeta_b.clear(); Skimming::jet_pfcand_photon_r9_b.clear(); Skimming::jet_pfcand_photon_eVeto_b.clear();

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

        Skimming::jet_pfcand_pt_b.push_back(jet_pfcand_pt->at(icand));
        Skimming::jet_pfcand_pt_log_b.push_back(std::isnan(std::log(jet_pfcand_pt->at(icand))) ? 0 : std::log(jet_pfcand_pt->at(icand)));
        Skimming::jet_pfcand_eta_b.push_back(jet_pfcand_eta->at(icand));
        Skimming::jet_pfcand_abseta_b.push_back(abs(jet_pfcand_eta->at(icand)));
        Skimming::jet_pfcand_phi_b.push_back(jet_pfcand_phi->at(icand));
        Skimming::jet_pfcand_mass_b.push_back(jet_pfcand_mass->at(icand));
        Skimming::jet_pfcand_energy_b.push_back(jet_pfcand_energy->at(icand));
        Skimming::jet_pfcand_energy_log_b.push_back(std::isnan(std::log(jet_pfcand_energy->at(icand))) ? 0 : std::log(jet_pfcand_energy->at(icand)));
        Skimming::jet_pfcand_calofraction_b.push_back(std::isnan(jet_pfcand_calofraction->at(icand)) ? 0 : jet_pfcand_calofraction->at(icand));
        Skimming::jet_pfcand_hcalfraction_b.push_back(std::isnan(jet_pfcand_hcalfraction->at(icand)) ? 0 : jet_pfcand_hcalfraction->at(icand));
        Skimming::jet_pfcand_dxy_b.push_back(std::isnan(jet_pfcand_dxy->at(icand)) ? 0 : jet_pfcand_dxy->at(icand));
        Skimming::jet_pfcand_dz_b.push_back(std::isnan(jet_pfcand_dz->at(icand)) ? 0 : jet_pfcand_dz->at(icand));
        Skimming::jet_pfcand_dzsig_b.push_back(std::isnan(jet_pfcand_dzsig->at(icand)) ? 0 : jet_pfcand_dzsig->at(icand));
        Skimming::jet_pfcand_dxysig_b.push_back(std::isnan(jet_pfcand_dxysig->at(icand)) ? 0 : jet_pfcand_dxysig->at(icand));
        Skimming::jet_pfcand_pperp_ratio_b.push_back(std::isnan(jet_pfcand_pperp_ratio->at(icand)) ? 0 : jet_pfcand_pperp_ratio->at(icand));
        Skimming::jet_pfcand_ppara_ratio_b.push_back(std::isnan(jet_pfcand_ppara_ratio->at(icand)) ? 0 : jet_pfcand_ppara_ratio->at(icand));
        Skimming::jet_pfcand_deta_b.push_back(jet_pfcand_deta->at(icand));
        Skimming::jet_pfcand_dphi_b.push_back(jet_pfcand_dphi->at(icand));
        Skimming::jet_pfcand_etarel_b.push_back(std::isnan(jet_pfcand_etarel->at(icand)) ? 0 : jet_pfcand_etarel->at(icand));
        Skimming::jet_pfcand_frompv_b.push_back(jet_pfcand_frompv->at(icand));
        Skimming::jet_pfcand_charge_b.push_back(jet_pfcand_charge->at(icand));
        Skimming::jet_pfcand_puppiw_b.push_back(jet_pfcand_puppiw->at(icand));

        Skimming::jet_pfcand_track_qual_b.push_back(jet_pfcand_track_qual->at(icand));
        Skimming::jet_pfcand_track_chi2_b.push_back(jet_pfcand_track_chi2->at(icand));
        Skimming::jet_pfcand_track_algo_b.push_back(jet_pfcand_track_algo->at(icand));
        Skimming::jet_pfcand_track_pterr_b.push_back((std::isnan(jet_pfcand_track_pterr->at(icand)) ? 0 : jet_pfcand_track_pterr->at(icand)));
        Skimming::jet_pfcand_track_etaerr_b.push_back((std::isnan(jet_pfcand_track_etaerr->at(icand)) ? 0 : jet_pfcand_track_etaerr->at(icand)));
        Skimming::jet_pfcand_track_phierr_b.push_back((std::isnan(jet_pfcand_track_phierr->at(icand)) ? 0 : jet_pfcand_track_phierr->at(icand)));
        Skimming::jet_pfcand_nhits_b.push_back(jet_pfcand_nhits->at(icand));
        Skimming::jet_pfcand_npixhits_b.push_back(jet_pfcand_npixhits->at(icand));
        Skimming::jet_pfcand_nstriphits_b.push_back(jet_pfcand_nstriphits->at(icand));
        Skimming::jet_pfcand_nlosthits_b.push_back(jet_pfcand_nlosthits->at(icand));
        Skimming::jet_pfcand_npixlayers_b.push_back(jet_pfcand_npixlayers->at(icand));
        Skimming::jet_pfcand_nstriplayers_b.push_back(jet_pfcand_nstriplayers->at(icand));

        if(jet_pfcand_id->at(icand) == 11 and jet_pfcand_charge->at(icand) != 0)
          Skimming::jet_pfcand_id_b.push_back(0);
        else if(jet_pfcand_id->at(icand) == 13 and jet_pfcand_charge->at(icand) != 0)
          Skimming::jet_pfcand_id_b.push_back(1);
        else if(jet_pfcand_id->at(icand) == 22 and jet_pfcand_charge->at(icand) == 0)
          Skimming::jet_pfcand_id_b.push_back(2);
        else if(jet_pfcand_id->at(icand) != 22 and jet_pfcand_charge->at(icand) == 0 and jet_pfcand_id->at(icand) != 1 and jet_pfcand_id->at(icand) != 2)
          Skimming::jet_pfcand_id_b.push_back(3);
        else if(jet_pfcand_id->at(icand) != 11 and jet_pfcand_id->at(icand) != 13 and jet_pfcand_charge->at(icand) != 0)
          Skimming::jet_pfcand_id_b.push_back(4);
        else if(jet_pfcand_charge->at(icand) == 0  and jet_pfcand_id->at(icand) == 1)
          Skimming::jet_pfcand_id_b.push_back(5);
        else if(jet_pfcand_charge->at(icand) == 0  and jet_pfcand_id->at(icand) == 2)
          Skimming::jet_pfcand_id_b.push_back(6);
        else
          Skimming::jet_pfcand_id_b.push_back(-1);

        Skimming::jet_pfcand_trackjet_d3d_b.push_back(std::isnan(jet_pfcand_trackjet_d3d->at(icand)) ? 0 : jet_pfcand_trackjet_d3d->at(icand));
        Skimming::jet_pfcand_trackjet_d3dsig_b.push_back(std::isnan(jet_pfcand_trackjet_d3dsig->at(icand)) ? 0 : jet_pfcand_trackjet_d3dsig->at(icand));
        Skimming::jet_pfcand_trackjet_dist_b.push_back(std::isnan(jet_pfcand_trackjet_dist->at(icand)) ? 0 : jet_pfcand_trackjet_dist->at(icand));
        Skimming::jet_pfcand_trackjet_decayL_b.push_back(std::isnan(jet_pfcand_trackjet_decayL->at(icand)) ? 0 : jet_pfcand_trackjet_decayL->at(icand));

        Skimming::jet_pfcand_tau_signal_b.push_back(jet_pfcand_tau_signal->at(icand));
        Skimming::jet_pfcand_tau_boosted_signal_b.push_back(jet_pfcand_tau_boosted_signal->at(icand));

        Skimming::jet_pfcand_muon_id_b.push_back(jet_pfcand_muon_id->at(icand));
        Skimming::jet_pfcand_muon_chi2_b.push_back(jet_pfcand_muon_chi2->at(icand));
        Skimming::jet_pfcand_muon_segcomp_b.push_back(jet_pfcand_muon_segcomp->at(icand));
        Skimming::jet_pfcand_muon_isglobal_b.push_back(jet_pfcand_muon_isglobal->at(icand));
        Skimming::jet_pfcand_muon_nvalidhit_b.push_back(jet_pfcand_muon_nvalidhit->at(icand));
        Skimming::jet_pfcand_muon_nstation_b.push_back(jet_pfcand_muon_nstation->at(icand));

        Skimming::jet_pfcand_electron_eOverP_b.push_back(std::isnan(jet_pfcand_electron_eOverP->at(icand)) ? 0 : jet_pfcand_electron_eOverP->at(icand));
        Skimming::jet_pfcand_electron_detaIn_b.push_back(jet_pfcand_electron_detaIn->at(icand));
        Skimming::jet_pfcand_electron_dphiIn_b.push_back(jet_pfcand_electron_dphiIn->at(icand));
        Skimming::jet_pfcand_electron_r9_b.push_back(std::isnan(jet_pfcand_electron_r9->at(icand)) ? 0 : jet_pfcand_electron_r9->at(icand));
        Skimming::jet_pfcand_electron_sigIetaIeta_b.push_back(jet_pfcand_electron_sigIetaIeta->at(icand));
        Skimming::jet_pfcand_electron_convProb_b.push_back(std::isnan(jet_pfcand_electron_convProb->at(icand)) ? 0 : jet_pfcand_electron_convProb->at(icand));
        Skimming::jet_pfcand_electron_sigIphiIphi_b.push_back(std::isnan(jet_pfcand_electron_sigIphiIphi->at(icand)) ? 0 : jet_pfcand_electron_sigIphiIphi->at(icand));

        Skimming::jet_pfcand_photon_sigIetaIeta_b.push_back(std::isnan(jet_pfcand_photon_sigIetaIeta->at(icand)) ? 0 : jet_pfcand_photon_sigIetaIeta->at(icand));
        Skimming::jet_pfcand_photon_r9_b.push_back(std::isnan(jet_pfcand_photon_r9->at(icand)) ? 0 : jet_pfcand_photon_r9->at(icand));
        Skimming::jet_pfcand_photon_eVeto_b.push_back(std::isnan(jet_pfcand_photon_eVeto->at(icand)) ? 0 : jet_pfcand_photon_eVeto->at(icand));

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

        if( Skimming::jet_pfcand_pt_b.size() == pfcand_lenght ) break;
      }

      _histograms1D.at("res_decay_id").Fill( Skimming::matched_res_decay_id, 1 );

      HDF_fill();
      //_outputTree->Fill();

    }



    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //Skimming::variable1Name = 100;      [Example]

    //======FILL THE HISTOGRAMS====================================================================
    //_histograms1D.at("histogram1DName").Fill( var, evtWeight );               [Example]
    //_histograms2D.at("histogram2DName").Fill( var1, var2, evtWeight );        [Example]

    //======FILL THE OUTPUT TREE===================================================================
    //_outputTree->Fill();

    //======FILL THE OUTPUT HDF5 INFO===============================================================
    //HDF_fill();

    return;
}


//-------------------------------------------------------------------------------------------------
// Produce systematic histograms
//-------------------------------------------------------------------------------------------------
void HEPHero::SkimmingSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishSkimming() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
