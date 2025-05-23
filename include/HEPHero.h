#ifndef HEPHERO_H
#define HEPHERO_H

#include "HEPBase.h"
#include "CMS.h"
#include "ML.h"
#include "onnxruntime_cxx_api.h"
#include "onnx_model.h"


using namespace std;

class HEPHero : public HEPBase {
    public:
        static HEPHero* GetInstance( char* configFileName );
        ~HEPHero() {}
        
        bool Init();
        void RunEventLoop( int nEventsMax = -1);
        void FinishRun();
    
    private:
        static HEPHero* _instance;

        bool RunRoutines();
        void PreRoutines();
        
        HEPHero() {}
        HEPHero( char* configFileName );

        void FillControlVariables( string key, string value);
        void VerticalSysSizes();
        void VerticalSys();
        void Weight_corrections();
        bool MC_processing();
        void SetupAna();
        bool AnaRegion();
        void AnaSelection();
        void AnaSystematic();
        void FinishAna();


        void SetupTest();
        bool TestRegion();
        void TestSelection();
        void TestSystematic();
        void FinishTest();
        void SetupSkimming();
        bool SkimmingRegion();
        void SkimmingSelection();
        void SkimmingSystematic();
        void FinishSkimming();
        void SetupONNX();
        bool ONNXRegion();
        void ONNXSelection();
        void ONNXSystematic();
        void FinishONNX();
        void SetupEvaluate();
        bool EvaluateRegion();
        void EvaluateSelection();
        void EvaluateSystematic();
        void FinishEvaluate();
        void SetupPerformance();
        bool PerformanceRegion();
        void PerformanceSelection();
        void PerformanceSystematic();
        void FinishPerformance();
        void SetupPtLimits();
        bool PtLimitsRegion();
        void PtLimitsSelection();
        void PtLimitsSystematic();
        void FinishPtLimits();
        // INSERT YOUR SELECTION HERE



    //=============================================================================================
    // ANALYSIS SETUP
    //=============================================================================================
        string  selection_file;
        JSONSelection event_selection;

        Ort::Session session_{nullptr};
        //Ort::Env env_{nullptr};

        //Ort::Env env1(OrtLoggingLevel::ORT_LOGGING_LEVEL_WARNING, "onnx_model");
        //Ort::SessionOptions sessionOptions1;
        //Ort::Session session1(env1, "AP_HOTVR_ML_R3/include/onnx_initial_model.onnx", sessionOptions1);

        ONNX_MODEL ZtoQQxQCD_tagger;

    
    //=============================================================================================
    // INPUT TREE SETUP - NANOAOD
    //=============================================================================================
    private:

        UInt_t event;
        UInt_t run;
        UInt_t lumi;
        Float_t xsec;
        Float_t genWeight; //Float_t wgt;
        UInt_t putrue;
        Float_t rho;
        Float_t met;
        Float_t met_phi;
        UInt_t npv;
        UInt_t nsv;

        vector<float>* gen_particle_pt;
        vector<float>* gen_particle_eta;
        vector<float>* gen_particle_phi;
        vector<float>* gen_particle_mass;
        vector<int>* gen_particle_id;
        vector<unsigned int>* gen_particle_status;
        vector<int>* gen_particle_daughters_id;
        vector<unsigned int>* gen_particle_daughters_igen;
        vector<float>* gen_particle_daughters_pt;
        vector<float>* gen_particle_daughters_eta;
        vector<float>* gen_particle_daughters_phi;
        vector<float>* gen_particle_daughters_mass;
        vector<unsigned int>* gen_particle_daughters_status;
        vector<int>* gen_particle_daughters_charge;

        vector<float>* jet_pt;
        vector<float>* jet_eta;
        vector<float>* jet_phi;
        vector<float>* jet_mass;
        vector<float>* jet_pt_raw;
        vector<float>* jet_mass_raw;
        vector<float>* jet_chf;
        vector<float>* jet_nhf;
        vector<float>* jet_elf;
        vector<float>* jet_phf;
        vector<float>* jet_muf;
        vector<unsigned int>* jet_id;
        vector<unsigned int>* jet_ncand;
        vector<unsigned int>* jet_nch;
        vector<unsigned int>* jet_nnh;
        vector<unsigned int>* jet_nel;
        vector<unsigned int>* jet_nph;
        vector<unsigned int>* jet_nmu;
        vector<unsigned int>* jet_hflav;
        vector<int>* jet_pflav;
        vector<unsigned int>* jet_nbhad;
        vector<unsigned int>* jet_nchad;
        vector<float>* jet_genmatch_pt;
        vector<float>* jet_genmatch_eta;
        vector<float>* jet_genmatch_phi;
        vector<float>* jet_genmatch_mass;
        vector<float>* jet_genmatch_wnu_pt;
        vector<float>* jet_genmatch_wnu_eta;
        vector<float>* jet_genmatch_wnu_phi;
        vector<float>* jet_genmatch_wnu_mass;

        vector<float>* jet_softdrop_pt;
        vector<float>* jet_softdrop_pt_raw;
        vector<float>* jet_softdrop_eta;
        vector<float>* jet_softdrop_phi;
        vector<float>* jet_softdrop_mass;
        vector<float>* jet_softdrop_mass_raw;
        vector<float>* jet_softdrop_subjet_pt;
        vector<float>* jet_softdrop_subjet_pt_raw;
        vector<float>* jet_softdrop_subjet_eta;
        vector<float>* jet_softdrop_subjet_phi;
        vector<float>* jet_softdrop_subjet_mass;
        vector<float>* jet_softdrop_subjet_mass_raw;
        vector<unsigned int>* jet_softdrop_subjet_ijet;
        vector<unsigned int>* jet_softdrop_subjet_nbhad;
        vector<unsigned int>* jet_softdrop_subjet_nchad;
        vector<unsigned int>* jet_softdrop_subjet_hflav;
        vector<int>* jet_softdrop_subjet_pflav;
        vector<float>* jet_softdrop_genmatch_pt;
        vector<float>* jet_softdrop_genmatch_eta;
        vector<float>* jet_softdrop_genmatch_phi;
        vector<float>* jet_softdrop_genmatch_mass;
        vector<float>* jet_softdrop_subjet_genmatch_pt;
        vector<float>* jet_softdrop_subjet_genmatch_eta;
        vector<float>* jet_softdrop_subjet_genmatch_phi;
        vector<float>* jet_softdrop_subjet_genmatch_mass;

        vector<float>* jet_sv_pt;
        vector<float>* jet_sv_eta;
        vector<float>* jet_sv_phi;
        vector<float>* jet_sv_mass;
        vector<float>* jet_sv_energy;
        vector<float>* jet_sv_chi2;
        vector<float>* jet_sv_dxy;
        vector<float>* jet_sv_dxysig;
        vector<float>* jet_sv_d3d;
        vector<float>* jet_sv_d3dsig;
        vector<unsigned int>* jet_sv_ntrack;
        vector<unsigned int>* jet_sv_ijet;

        vector<float>* jet_pfcand_pt;
        vector<float>* jet_pfcand_eta;
        vector<float>* jet_pfcand_phi;
        vector<float>* jet_pfcand_mass;
        vector<float>* jet_pfcand_energy;
        vector<float>* jet_pfcand_calofraction;
        vector<float>* jet_pfcand_hcalfraction;
        vector<float>* jet_pfcand_dz;
        vector<float>* jet_pfcand_dzsig;
        vector<float>* jet_pfcand_dxy;
        vector<float>* jet_pfcand_dxysig;
        vector<float>* jet_pfcand_puppiw;
        vector<unsigned int>* jet_pfcand_frompv;
        vector<unsigned int>* jet_pfcand_id;
        vector<int>* jet_pfcand_charge;
        vector<unsigned int>* jet_pfcand_ijet;
        vector<float>* jet_pfcand_pperp_ratio;
        vector<float>* jet_pfcand_ppara_ratio;
        vector<float>* jet_pfcand_deta;
        vector<float>* jet_pfcand_dphi;
        vector<float>* jet_pfcand_etarel;
        vector<unsigned int>* jet_pfcand_track_chi2;
        vector<unsigned int>* jet_pfcand_track_qual;
        vector<float>* jet_pfcand_track_pterr;
        vector<float>* jet_pfcand_track_etaerr;
        vector<float>* jet_pfcand_track_phierr;
        vector<unsigned int>* jet_pfcand_track_algo;
        vector<float>* jet_pfcand_trackjet_d3d;
        vector<float>* jet_pfcand_trackjet_d3dsig;
        vector<float>* jet_pfcand_trackjet_dist;
        vector<float>* jet_pfcand_trackjet_decayL;
        vector<unsigned int>* jet_pfcand_nhits;
        vector<unsigned int>* jet_pfcand_npixhits;
        vector<unsigned int>* jet_pfcand_nstriphits;
        vector<unsigned int>* jet_pfcand_nlosthits;
        vector<unsigned int>* jet_pfcand_npixlayers;
        vector<unsigned int>* jet_pfcand_nstriplayers;
        vector<unsigned int>* jet_pfcand_tau_signal;
        vector<unsigned int>* jet_pfcand_tau_boosted_signal;
        vector<unsigned int>* jet_pfcand_muon_id;
        vector<unsigned int>* jet_pfcand_muon_isglobal;
        vector<float>* jet_pfcand_muon_chi2;
        vector<unsigned int>* jet_pfcand_muon_nvalidhit;
        vector<unsigned int>* jet_pfcand_muon_nstation;
        vector<float>* jet_pfcand_muon_segcomp;
        vector<float>* jet_pfcand_electron_eOverP;
        vector<float>* jet_pfcand_electron_detaIn;
        vector<float>* jet_pfcand_electron_dphiIn;
        vector<float>* jet_pfcand_electron_r9;
        vector<float>* jet_pfcand_electron_sigIetaIeta;
        vector<float>* jet_pfcand_electron_sigIphiIphi;
        vector<float>* jet_pfcand_electron_convProb;
        vector<float>* jet_pfcand_photon_sigIetaIeta;
        vector<float>* jet_pfcand_photon_eVeto;
        vector<float>* jet_pfcand_photon_r9;


        vector<float>* jetAK8_pt;
        vector<float>* jetAK8_eta;
        vector<float>* jetAK8_phi;
        vector<float>* jetAK8_mass;
        vector<float>* jetAK8_pt_raw;
        vector<float>* jetAK8_mass_raw;
        vector<float>* jetAK8_chf;
        vector<float>* jetAK8_nhf;
        vector<float>* jetAK8_elf;
        vector<float>* jetAK8_phf;
        vector<float>* jetAK8_muf;
        vector<unsigned int>* jetAK8_id;
        vector<unsigned int>* jetAK8_ncand;
        vector<unsigned int>* jetAK8_nch;
        vector<unsigned int>* jetAK8_nnh;
        vector<unsigned int>* jetAK8_nel;
        vector<unsigned int>* jetAK8_nph;
        vector<unsigned int>* jetAK8_nmu;
        vector<unsigned int>* jetAK8_hflav;
        vector<int>* jetAK8_pflav;
        vector<unsigned int>* jetAK8_nbhad;
        vector<unsigned int>* jetAK8_nchad;
        vector<float>* jetAK8_genmatch_pt;
        vector<float>* jetAK8_genmatch_eta;
        vector<float>* jetAK8_genmatch_phi;
        vector<float>* jetAK8_genmatch_mass;
        vector<float>* jetAK8_genmatch_wnu_pt;
        vector<float>* jetAK8_genmatch_wnu_eta;
        vector<float>* jetAK8_genmatch_wnu_phi;
        vector<float>* jetAK8_genmatch_wnu_mass;

        vector<float>* jetAK8_softdrop_pt;
        vector<float>* jetAK8_softdrop_pt_raw;
        vector<float>* jetAK8_softdrop_eta;
        vector<float>* jetAK8_softdrop_phi;
        vector<float>* jetAK8_softdrop_mass;
        vector<float>* jetAK8_softdrop_mass_raw;
        vector<float>* jetAK8_softdrop_subjet_pt;
        vector<float>* jetAK8_softdrop_subjet_pt_raw;
        vector<float>* jetAK8_softdrop_subjet_eta;
        vector<float>* jetAK8_softdrop_subjet_phi;
        vector<float>* jetAK8_softdrop_subjet_mass;
        vector<float>* jetAK8_softdrop_subjet_mass_raw;
        vector<unsigned int>* jetAK8_softdrop_subjet_ijet;
        vector<unsigned int>* jetAK8_softdrop_subjet_nbhad;
        vector<unsigned int>* jetAK8_softdrop_subjet_nchad;
        vector<unsigned int>* jetAK8_softdrop_subjet_hflav;
        vector<int>* jetAK8_softdrop_subjet_pflav;
        vector<float>* jetAK8_softdrop_genmatch_pt;
        vector<float>* jetAK8_softdrop_genmatch_eta;
        vector<float>* jetAK8_softdrop_genmatch_phi;
        vector<float>* jetAK8_softdrop_genmatch_mass;
        vector<float>* jetAK8_softdrop_subjet_genmatch_pt;
        vector<float>* jetAK8_softdrop_subjet_genmatch_eta;
        vector<float>* jetAK8_softdrop_subjet_genmatch_phi;
        vector<float>* jetAK8_softdrop_subjet_genmatch_mass;

        vector<float>* jetAK8_sv_pt;
        vector<float>* jetAK8_sv_eta;
        vector<float>* jetAK8_sv_phi;
        vector<float>* jetAK8_sv_mass;
        vector<float>* jetAK8_sv_energy;
        vector<float>* jetAK8_sv_chi2;
        vector<float>* jetAK8_sv_dxy;
        vector<float>* jetAK8_sv_dxysig;
        vector<float>* jetAK8_sv_d3d;
        vector<float>* jetAK8_sv_d3dsig;
        vector<unsigned int>* jetAK8_sv_ntrack;
        vector<unsigned int>* jetAK8_sv_ijet;

        vector<float>* jetAK8_pfcand_pt;
        vector<float>* jetAK8_pfcand_eta;
        vector<float>* jetAK8_pfcand_phi;
        vector<float>* jetAK8_pfcand_mass;
        vector<float>* jetAK8_pfcand_energy;
        vector<float>* jetAK8_pfcand_calofraction;
        vector<float>* jetAK8_pfcand_hcalfraction;
        vector<float>* jetAK8_pfcand_dz;
        vector<float>* jetAK8_pfcand_dzsig;
        vector<float>* jetAK8_pfcand_dxy;
        vector<float>* jetAK8_pfcand_dxysig;
        vector<float>* jetAK8_pfcand_puppiw;
        vector<unsigned int>* jetAK8_pfcand_frompv;
        vector<unsigned int>* jetAK8_pfcand_id;
        vector<int>* jetAK8_pfcand_charge;
        vector<unsigned int>* jetAK8_pfcand_ijet;
        vector<float>* jetAK8_pfcand_pperp_ratio;
        vector<float>* jetAK8_pfcand_ppara_ratio;
        vector<float>* jetAK8_pfcand_deta;
        vector<float>* jetAK8_pfcand_dphi;
        vector<float>* jetAK8_pfcand_etarel;
        vector<unsigned int>* jetAK8_pfcand_track_chi2;
        vector<unsigned int>* jetAK8_pfcand_track_qual;
        vector<float>* jetAK8_pfcand_track_pterr;
        vector<float>* jetAK8_pfcand_track_etaerr;
        vector<float>* jetAK8_pfcand_track_phierr;
        vector<unsigned int>* jetAK8_pfcand_track_algo;
        vector<float>* jetAK8_pfcand_trackjet_d3d;
        vector<float>* jetAK8_pfcand_trackjet_d3dsig;
        vector<float>* jetAK8_pfcand_trackjet_dist;
        vector<float>* jetAK8_pfcand_trackjet_decayL;
        vector<unsigned int>* jetAK8_pfcand_nhits;
        vector<unsigned int>* jetAK8_pfcand_npixhits;
        vector<unsigned int>* jetAK8_pfcand_nstriphits;
        vector<unsigned int>* jetAK8_pfcand_nlosthits;
        vector<unsigned int>* jetAK8_pfcand_npixlayers;
        vector<unsigned int>* jetAK8_pfcand_nstriplayers;
        vector<unsigned int>* jetAK8_pfcand_tau_signal;
        vector<unsigned int>* jetAK8_pfcand_tau_boosted_signal;
        vector<unsigned int>* jetAK8_pfcand_muon_id;
        vector<unsigned int>* jetAK8_pfcand_muon_isglobal;
        vector<float>* jetAK8_pfcand_muon_chi2;
        vector<unsigned int>* jetAK8_pfcand_muon_nvalidhit;
        vector<unsigned int>* jetAK8_pfcand_muon_nstation;
        vector<float>* jetAK8_pfcand_muon_segcomp;
        vector<float>* jetAK8_pfcand_electron_eOverP;
        vector<float>* jetAK8_pfcand_electron_detaIn;
        vector<float>* jetAK8_pfcand_electron_dphiIn;
        vector<float>* jetAK8_pfcand_electron_r9;
        vector<float>* jetAK8_pfcand_electron_sigIetaIeta;
        vector<float>* jetAK8_pfcand_electron_sigIphiIphi;
        vector<float>* jetAK8_pfcand_electron_convProb;
        vector<float>* jetAK8_pfcand_photon_sigIetaIeta;
        vector<float>* jetAK8_pfcand_photon_eVeto;
        vector<float>* jetAK8_pfcand_photon_r9;
        
};

#endif
