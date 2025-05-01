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
    float ZtoQQxQCD_tag;


}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupEvaluate() {


    //======SETUP CUTFLOW==========================================================================
    _cutFlow.insert(pair<string,double>("NumBadGenEvent", 0) );
    _cutFlow.insert(pair<string,double>("00_Total", 0) );
    _cutFlow.insert(pair<string,double>("01_PassBaseCuts", 0) );
    //_cutFlow.insert(pair<string,double>("02_SignalResCuts", 0) );
    //_cutFlow.insert(pair<string,double>("03_HasJetLooseId", 0) );
    //_cutFlow.insert(pair<string,double>("04_MassCut", 0) );

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
    //HDF_insert("run",&Evaluate::run_b);
    //HDF_insert("lumi",&Evaluate::lumi_b);
    //HDF_insert("event",&Evaluate::event_b);
    HDF_insert("npv",&Evaluate::npv_b);
    //HDF_insert("nsv",&Evaluate::nsv_b);
    HDF_insert("npu",&Evaluate::npu_b);
    //HDF_insert("rho",&Evaluate::rho_b);
    HDF_insert("met",&Evaluate::met_b);
    //HDF_insert("ijet",&Evaluate::ijet_b);
    //HDF_insert("sample",&Evaluate::sample_b);

    HDF_insert("jet_pt",&Evaluate::jet_pt_b);
    HDF_insert("jet_eta",&Evaluate::jet_eta_b);
    HDF_insert("jet_abseta",&Evaluate::jet_abseta_b);
    //HDF_insert("jet_phi",&Evaluate::jet_phi_b);
    HDF_insert("jet_mass",&Evaluate::jet_mass_b);
    //HDF_insert("jet_pt_raw",&Evaluate::jet_pt_raw_b);
    //HDF_insert("jet_mass_raw",&Evaluate::jet_mass_raw_b);
    HDF_insert("jet_softdrop_mass",&Evaluate::jet_softdrop_mass_b);
    HDF_insert("jet_pt_truth",&Evaluate::jet_pt_truth_b);

    HDF_insert("matched_res_decay_id", &Evaluate::matched_res_decay_id);
    HDF_insert("match_DR_res_jet", &Evaluate::match_DR_res_jet);
    HDF_insert("match_DR_dau_jet", &Evaluate::match_DR_dau_jet);

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
      Evaluate::R_ref = dRCone;

      _cutFlow.at("00_Total") += 1;

      // Base Selection
      if(jet_pt->at(ijet) < jetPtMin or jet_pt->at(ijet) > jetPtMax or fabs(jet_eta->at(ijet)) > jetEtaMax or fabs(jet_eta->at(ijet)) < jetEtaMin) continue;
      _cutFlow.at("01_PassBaseCuts") += 1;

      TLorentzVector jet4V;
      jet4V.SetPtEtaPhiM(jet_pt->at(ijet),jet_eta->at(ijet),jet_phi->at(ijet),jet_mass->at(ijet));

      // Matching with the resonance for signal jets using the kinematics
      int match_index_dR_res_jet = -1;
      float mindR_jetres = 1000;
      Evaluate::match_DR_res_jet = false;
      Evaluate::match_DR_dau_jet = false;
      for(size_t ires = 0; ires < resonances.size(); ires++){
        float dRjres = jet4V.DeltaR(resonances.at(ires).p4);
        if(dRjres < dRCone and dRjres < mindR_jetres){
          Evaluate::match_DR_res_jet = true;
          match_index_dR_res_jet = ires;
          mindR_jetres = dRjres;
          if(resonances.at(ires).daugp4.size() == 2){
            float dR1 = resonances.at(ires).daugp4.at(0).DeltaR(jet4V);
            float dR2 = resonances.at(ires).daugp4.at(1).DeltaR(jet4V);
            float dR  = resonances.at(ires).daugp4.front().DeltaR(resonances.at(ires).daugp4.back());
            if(dR1 < dRMatchingDaughterJet and dR2 < dRMatchingDaughterJet){
              Evaluate::match_DR_dau_jet = true;
            }
          }else if(resonances.at(ires).daugp4.size() == 3){
            float dR1 = resonances.at(ires).daugp4.at(0).DeltaR(jet4V);
            float dR2 = resonances.at(ires).daugp4.at(1).DeltaR(jet4V);
            float dR3 = resonances.at(ires).daugp4.at(2).DeltaR(jet4V);
            if(dR1 < dRMatchingDaughterJet and dR2 < dRMatchingDaughterJet and dR3 < dRMatchingDaughterJet){
              Evaluate::match_DR_dau_jet = true;
            }
          }
        }
      }


      // matching based on dR parton-jet
      Evaluate::matched_res_decay_id = -1; // only real QCD jets / not-matched resonances
      if(match_index_dR_res_jet != -1){
        if(resonances.at(match_index_dR_res_jet).daugid.size() == 2){
          if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) == 5 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) == 5) // X(bb)
            Evaluate::matched_res_decay_id = 5;
          else if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) == 4 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) == 4) // X(cc)
            Evaluate::matched_res_decay_id = 4;
          else if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) <= 3 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) <= 3) // X(qq)
            Evaluate::matched_res_decay_id = 3;
          else if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) == 21 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) == 21) // X(gg)
            Evaluate::matched_res_decay_id = 21;
          else
            Evaluate::matched_res_decay_id = 0; // whatever remains
        }else if(resonances.at(match_index_dR_res_jet).daugid.size() == 3){
          if(abs(resonances.at(match_index_dR_res_jet).daugid.at(0)) < 6 and abs(resonances.at(match_index_dR_res_jet).daugid.at(1)) < 6  and abs(resonances.at(match_index_dR_res_jet).daugid.at(2)) < 6) // Top(qqb)
            Evaluate::matched_res_decay_id = 1;
          else
            Evaluate::matched_res_decay_id = 0; // whatever remains
        }
      }


      // for signal samples exclude all jets unmatched (if enabled) to avoid labelling as QCD signal jets that are not matched to a resonance
      //if((dsName.substr(0,5) == "Zto2Q") || (dsName.substr(0,2) == "TT")){
      //  if(saveOnlyResonanceMatchedJets and Evaluate::matched_res_decay_id <= 0) continue;
      //  _cutFlow.at("02_SignalResCuts") += 1;
      //}

      //if( jet_id->at(ijet) == 0 ) continue;
      //_cutFlow.at("03_HasJetLooseId") += 1;



      // if found, take the truth kinematic of the resonance from its GEN level (neutrinos included) and blacklist the resonance
      if(match_index_dR_res_jet != -1){
        // truth corresponds to the pole resonance kinematic properties
        Evaluate::jet_pt_truth_b   = resonances.at(match_index_dR_res_jet).p4.Pt();
        Evaluate::jet_eta_truth_b  = resonances.at(match_index_dR_res_jet).p4.Eta();
        Evaluate::jet_phi_truth_b  = resonances.at(match_index_dR_res_jet).p4.Phi();
        Evaluate::jet_mass_truth_b = resonances.at(match_index_dR_res_jet).p4.M();
      }
      else{
        // take the gen soft drop in QCD jets or un-matched jets, no need for the neutrino correction, everything fixed to be soft-drop
        Evaluate::jet_pt_truth_b   = jet_genmatch_wnu_pt->at(ijet);
        Evaluate::jet_eta_truth_b  = jet_genmatch_wnu_eta->at(ijet);
        Evaluate::jet_phi_truth_b  = jet_genmatch_wnu_phi->at(ijet);
        Evaluate::jet_mass_truth_b = jet_genmatch_wnu_mass->at(ijet);
      }



      // selection on the truth mass
      //if((dsName.substr(0,5) == "Zto2Q") || (dsName.substr(0,2) == "TT")){
      //  if(Evaluate::jet_mass_truth_b < jetMassTruthMin) continue;
      //  _cutFlow.at("04_MassCut") += 1;
      //}


      Evaluate::Z_pt = 0;
      if( dsName.substr(0,14) == "Zto2Q_PTQQ-100" ) Evaluate::Z_pt = 100;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-200" ) Evaluate::Z_pt = 200;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-400" ) Evaluate::Z_pt = 400;
      else if( dsName.substr(0,14) == "Zto2Q_PTQQ-600" ) Evaluate::Z_pt = 600;

      Evaluate::npu_b = putrue;
      Evaluate::met_b = met;

      // fill jet branches
      Evaluate::jet_pt_b = jet_pt->at(ijet);
      Evaluate::jet_eta_b = jet_eta->at(ijet);
      Evaluate::jet_phi_b = jet_phi->at(ijet);
      Evaluate::jet_mass_b = jet_mass->at(ijet);

      // soft drop
      //Evaluate::jet_softdrop_pt_b = jet_softdrop_pt->at(ijet);
      //Evaluate::jet_softdrop_eta_b = jet_softdrop_eta->at(ijet);
      //Evaluate::jet_softdrop_phi_b = jet_softdrop_phi->at(ijet);
      Evaluate::jet_softdrop_mass_b = jet_softdrop_mass->at(ijet);







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
      //sv_features.insert( sv_features.end(), Evaluate::jet_sv_dxysig_b.begin(), Evaluate::jet_sv_dxysig_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_d3d_b.begin(), Evaluate::jet_sv_d3d_b.end() );
      //sv_features.insert( sv_features.end(), Evaluate::jet_sv_d3dsig_b.begin(), Evaluate::jet_sv_d3dsig_b.end() );
      sv_features.insert( sv_features.end(), Evaluate::jet_sv_ntrack_b.begin(), Evaluate::jet_sv_ntrack_b.end() );
      //cout << "sv_features_size " << sv_features.size() << endl;

      vector<float> sv_mask;
      for(int i = 0; i < sv_lenght; i++){
          float mask_i = 0;
          for(int j = 0; j < 9; j++){
              if(sv_features.at(i+j*sv_lenght) != 0) mask_i = 1;
          }
          sv_mask.push_back(mask_i);
      }
      //cout << "sv_mask " << sv_mask << endl;


      vector<vector<float>> inputTensorValues = {pf_points, pf_features, pf_mask, sv_points, sv_features, sv_mask};
      vector<vector<int64_t>> inputTensorDims = {{1, 2, 100}, {1, 15, 100}, {1, 1, 100}, {1, 2, 10}, {1, 9, 10}, {1, 1, 10}};
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
