#include "HEPHero.h"


//---------------------------------------------------------------------------------------------------------------
// FILL CONTROL VARIABLES WITH INPUT FILE LINES
//---------------------------------------------------------------------------------------------------------------
void HEPHero::FillControlVariables( string key, string value){

    //----CORRECTIONS------------------------------------------------------------------------------------


    //----METADATA FILES---------------------------------------------------------------------------------


    //----SELECTION--------------------------------------------------------------------------------------


}


//---------------------------------------------------------------------------------------------------------------
// Init
//---------------------------------------------------------------------------------------------------------------
bool HEPHero::Init() {
    
    //======SET HISTOGRAMS STYLE===================================================================
    setStyle(1.0,true,0.15);

    if( _ANALYSIS != "GEN" ){
        //======SET THE BRANCH ADDRESSES===============================================================
        _inputTree->SetBranchAddress("event", &event);
        _inputTree->SetBranchAddress("run", &run);
        _inputTree->SetBranchAddress("lumi", &lumi);
        _inputTree->SetBranchAddress("rho", &rho);

        _inputTree->SetBranchAddress("met", &met);
        _inputTree->SetBranchAddress("met_phi", &met_phi);
        _inputTree->SetBranchAddress("npv", &npv);
        _inputTree->SetBranchAddress("nsv", &nsv);

        _inputTree->SetBranchAddress("jet_pt", &jet_pt);
        _inputTree->SetBranchAddress("jet_eta", &jet_eta);
        _inputTree->SetBranchAddress("jet_phi", &jet_phi);
        _inputTree->SetBranchAddress("jet_mass", &jet_mass);
        //_inputTree->SetBranchAddress("jet_pt_raw", &jet_pt_raw);
        //_inputTree->SetBranchAddress("jet_mass_raw", &jet_mass_raw);
        //_inputTree->SetBranchAddress("jet_chf", &jet_chf);
        //_inputTree->SetBranchAddress("jet_nhf", &jet_nhf);
        //_inputTree->SetBranchAddress("jet_elf", &jet_elf);
        //_inputTree->SetBranchAddress("jet_phf", &jet_phf);
        //_inputTree->SetBranchAddress("jet_muf", &jet_muf);
        //_inputTree->SetBranchAddress("jet_id", &jet_id);
        //_inputTree->SetBranchAddress("jet_ncand", &jet_ncand);
        //_inputTree->SetBranchAddress("jet_nch", &jet_nch);
        //_inputTree->SetBranchAddress("jet_nnh", &jet_nnh);
        //_inputTree->SetBranchAddress("jet_nel", &jet_nel);
        //_inputTree->SetBranchAddress("jet_nph", &jet_nph);
        //_inputTree->SetBranchAddress("jet_nmu", &jet_nmu);
        //_inputTree->SetBranchAddress("jet_hflav", &jet_hflav);
        //_inputTree->SetBranchAddress("jet_pflav", &jet_pflav);
        //_inputTree->SetBranchAddress("jet_nbhad", &jet_nbhad);
        //_inputTree->SetBranchAddress("jet_nchad", &jet_nchad);
        //_inputTree->SetBranchAddress("jet_nsubjets", &jet_nsubjets);

        _inputTree->SetBranchAddress("jet_softdrop_pt", &jet_softdrop_pt);
        //_inputTree->SetBranchAddress("jet_softdrop_pt_raw", &jet_softdrop_pt_raw);
        _inputTree->SetBranchAddress("jet_softdrop_eta", &jet_softdrop_eta);
        _inputTree->SetBranchAddress("jet_softdrop_phi", &jet_softdrop_phi);
        _inputTree->SetBranchAddress("jet_softdrop_mass", &jet_softdrop_mass);
        //_inputTree->SetBranchAddress("jet_softdrop_mass_raw", &jet_softdrop_mass_raw);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_pt", &jet_softdrop_subjet_pt);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_pt_raw", &jet_softdrop_subjet_pt_raw);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_eta", &jet_softdrop_subjet_eta);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_phi", &jet_softdrop_subjet_phi);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_mass", &jet_softdrop_subjet_mass);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_mass_raw", &jet_softdrop_subjet_mass_raw);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_ijet", &jet_softdrop_subjet_ijet);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_nbhad", &jet_softdrop_subjet_nbhad);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_nchad", &jet_softdrop_subjet_nchad);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_hflav", &jet_softdrop_subjet_hflav);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_pflav", &jet_softdrop_subjet_pflav);
        //_inputTree->SetBranchAddress("jet_softdrop_genmatch_pt", &jet_softdrop_genmatch_pt);
        //_inputTree->SetBranchAddress("jet_softdrop_genmatch_eta", &jet_softdrop_genmatch_eta);
        //_inputTree->SetBranchAddress("jet_softdrop_genmatch_phi", &jet_softdrop_genmatch_phi);
        //_inputTree->SetBranchAddress("jet_softdrop_genmatch_mass", &jet_softdrop_genmatch_mass);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_genmatch_pt", &jet_softdrop_subjet_genmatch_pt);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_genmatch_eta", &jet_softdrop_subjet_genmatch_eta);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_genmatch_phi", &jet_softdrop_subjet_genmatch_phi);
        //_inputTree->SetBranchAddress("jet_softdrop_subjet_genmatch_mass", &jet_softdrop_subjet_genmatch_mass);

        _inputTree->SetBranchAddress("jet_sv_pt", &jet_sv_pt);
        _inputTree->SetBranchAddress("jet_sv_eta", &jet_sv_eta);
        _inputTree->SetBranchAddress("jet_sv_phi", &jet_sv_phi);
        _inputTree->SetBranchAddress("jet_sv_mass", &jet_sv_mass);
        _inputTree->SetBranchAddress("jet_sv_energy", &jet_sv_energy);
        _inputTree->SetBranchAddress("jet_sv_chi2", &jet_sv_chi2);
        _inputTree->SetBranchAddress("jet_sv_dxy", &jet_sv_dxy);
        _inputTree->SetBranchAddress("jet_sv_dxysig", &jet_sv_dxysig);
        _inputTree->SetBranchAddress("jet_sv_d3d", &jet_sv_d3d);
        _inputTree->SetBranchAddress("jet_sv_d3dsig", &jet_sv_d3dsig);
        _inputTree->SetBranchAddress("jet_sv_ntrack", &jet_sv_ntrack);
        _inputTree->SetBranchAddress("jet_sv_ijet", &jet_sv_ijet);

        _inputTree->SetBranchAddress("jet_pfcandidate_pt", &jet_pfcand_pt);
        _inputTree->SetBranchAddress("jet_pfcandidate_eta", &jet_pfcand_eta);
        _inputTree->SetBranchAddress("jet_pfcandidate_phi", &jet_pfcand_phi);
        _inputTree->SetBranchAddress("jet_pfcandidate_mass", &jet_pfcand_mass);
        _inputTree->SetBranchAddress("jet_pfcandidate_energy", &jet_pfcand_energy);
        _inputTree->SetBranchAddress("jet_pfcandidate_calofraction", &jet_pfcand_calofraction);
        _inputTree->SetBranchAddress("jet_pfcandidate_hcalfraction", &jet_pfcand_hcalfraction);
        _inputTree->SetBranchAddress("jet_pfcandidate_dz", &jet_pfcand_dz);
        _inputTree->SetBranchAddress("jet_pfcandidate_dzsig", &jet_pfcand_dzsig);
        _inputTree->SetBranchAddress("jet_pfcandidate_dxy", &jet_pfcand_dxy);
        _inputTree->SetBranchAddress("jet_pfcandidate_dxysig", &jet_pfcand_dxysig);
        _inputTree->SetBranchAddress("jet_pfcandidate_puppiw", &jet_pfcand_puppiw);
        _inputTree->SetBranchAddress("jet_pfcandidate_frompv", &jet_pfcand_frompv);
        _inputTree->SetBranchAddress("jet_pfcandidate_id", &jet_pfcand_id);
        _inputTree->SetBranchAddress("jet_pfcandidate_charge", &jet_pfcand_charge);
        _inputTree->SetBranchAddress("jet_pfcandidate_ijet", &jet_pfcand_ijet);
        _inputTree->SetBranchAddress("jet_pfcandidate_candjet_pperp_ratio", &jet_pfcand_pperp_ratio);
        _inputTree->SetBranchAddress("jet_pfcandidate_candjet_ppara_ratio", &jet_pfcand_ppara_ratio);
        _inputTree->SetBranchAddress("jet_pfcandidate_candjet_deta", &jet_pfcand_deta);
        _inputTree->SetBranchAddress("jet_pfcandidate_candjet_dphi", &jet_pfcand_dphi);
        _inputTree->SetBranchAddress("jet_pfcandidate_candjet_etarel", &jet_pfcand_etarel);
        _inputTree->SetBranchAddress("jet_pfcandidate_track_chi2", &jet_pfcand_track_chi2);
        _inputTree->SetBranchAddress("jet_pfcandidate_track_qual", &jet_pfcand_track_qual);
        _inputTree->SetBranchAddress("jet_pfcandidate_track_pterr", &jet_pfcand_track_pterr);
        _inputTree->SetBranchAddress("jet_pfcandidate_track_etaerr", &jet_pfcand_track_etaerr);
        _inputTree->SetBranchAddress("jet_pfcandidate_track_phierr", &jet_pfcand_track_phierr);
        _inputTree->SetBranchAddress("jet_pfcandidate_track_algo", &jet_pfcand_track_algo);
        _inputTree->SetBranchAddress("jet_pfcandidate_trackjet_d3d", &jet_pfcand_trackjet_d3d);
        _inputTree->SetBranchAddress("jet_pfcandidate_trackjet_d3dsig", &jet_pfcand_trackjet_d3dsig);
        _inputTree->SetBranchAddress("jet_pfcandidate_trackjet_dist", &jet_pfcand_trackjet_dist);
        _inputTree->SetBranchAddress("jet_pfcandidate_trackjet_decayL", &jet_pfcand_trackjet_decayL);
        _inputTree->SetBranchAddress("jet_pfcandidate_nhits", &jet_pfcand_nhits);
        _inputTree->SetBranchAddress("jet_pfcandidate_npixhits", &jet_pfcand_npixhits);
        _inputTree->SetBranchAddress("jet_pfcandidate_nstriphits", &jet_pfcand_nstriphits);
        _inputTree->SetBranchAddress("jet_pfcandidate_nlosthits", &jet_pfcand_nlosthits);
        _inputTree->SetBranchAddress("jet_pfcandidate_npixlayers", &jet_pfcand_npixlayers);
        _inputTree->SetBranchAddress("jet_pfcandidate_nstriplayers", &jet_pfcand_nstriplayers);
        _inputTree->SetBranchAddress("jet_pfcandidate_tau_signal", &jet_pfcand_tau_signal);
        _inputTree->SetBranchAddress("jet_pfcandidate_tau_boosted_signal", &jet_pfcand_tau_boosted_signal);
        _inputTree->SetBranchAddress("jet_pfcandidate_muon_id", &jet_pfcand_muon_id);
        _inputTree->SetBranchAddress("jet_pfcandidate_muon_isglobal", &jet_pfcand_muon_isglobal);
        _inputTree->SetBranchAddress("jet_pfcandidate_muon_chi2", &jet_pfcand_muon_chi2);
        _inputTree->SetBranchAddress("jet_pfcandidate_muon_nvalidhit", &jet_pfcand_muon_nvalidhit);
        _inputTree->SetBranchAddress("jet_pfcandidate_muon_nstation", &jet_pfcand_muon_nstation);
        _inputTree->SetBranchAddress("jet_pfcandidate_muon_segcomp", &jet_pfcand_muon_segcomp);
        _inputTree->SetBranchAddress("jet_pfcandidate_electron_eOverP", &jet_pfcand_electron_eOverP);
        _inputTree->SetBranchAddress("jet_pfcandidate_electron_detaIn", &jet_pfcand_electron_detaIn);
        _inputTree->SetBranchAddress("jet_pfcandidate_electron_dphiIn", &jet_pfcand_electron_dphiIn);
        _inputTree->SetBranchAddress("jet_pfcandidate_electron_r9", &jet_pfcand_electron_r9);
        _inputTree->SetBranchAddress("jet_pfcandidate_electron_sigIetaIeta", &jet_pfcand_electron_sigIetaIeta);
        _inputTree->SetBranchAddress("jet_pfcandidate_electron_sigIphiIphi", &jet_pfcand_electron_sigIphiIphi);
        _inputTree->SetBranchAddress("jet_pfcandidate_electron_convProb", &jet_pfcand_electron_convProb);
        _inputTree->SetBranchAddress("jet_pfcandidate_photon_sigIetaIeta", &jet_pfcand_photon_sigIetaIeta);
        _inputTree->SetBranchAddress("jet_pfcandidate_photon_eVeto", &jet_pfcand_photon_eVeto);
        _inputTree->SetBranchAddress("jet_pfcandidate_photon_r9", &jet_pfcand_photon_r9);
        

        
        //-----------------------------------------------------------------------------------------------------------------------
        if( dataset_group != "Data" ) {
            _inputTree->SetBranchAddress("xsec", &xsec);
            _inputTree->SetBranchAddress("wgt", &genWeight);
            _inputTree->SetBranchAddress("putrue", &putrue);

            _inputTree->SetBranchAddress("gen_particle_pt", &gen_particle_pt);
            _inputTree->SetBranchAddress("gen_particle_eta", &gen_particle_eta);
            _inputTree->SetBranchAddress("gen_particle_phi", &gen_particle_phi);
            _inputTree->SetBranchAddress("gen_particle_mass", &gen_particle_mass);
            _inputTree->SetBranchAddress("gen_particle_id", &gen_particle_id);
            _inputTree->SetBranchAddress("gen_particle_status", &gen_particle_status);
            _inputTree->SetBranchAddress("gen_particle_daughters_id", &gen_particle_daughters_id);
            _inputTree->SetBranchAddress("gen_particle_daughters_igen", &gen_particle_daughters_igen);
            _inputTree->SetBranchAddress("gen_particle_daughters_pt", &gen_particle_daughters_pt);
            _inputTree->SetBranchAddress("gen_particle_daughters_eta", &gen_particle_daughters_eta);
            _inputTree->SetBranchAddress("gen_particle_daughters_phi", &gen_particle_daughters_phi);
            _inputTree->SetBranchAddress("gen_particle_daughters_mass", &gen_particle_daughters_mass);
            _inputTree->SetBranchAddress("gen_particle_daughters_status", &gen_particle_daughters_status);
            _inputTree->SetBranchAddress("gen_particle_daughters_charge", &gen_particle_daughters_charge);

            //_inputTree->SetBranchAddress("jet_genmatch_pt", &jet_genmatch_pt);
            //_inputTree->SetBranchAddress("jet_genmatch_eta", &jet_genmatch_eta);
            //_inputTree->SetBranchAddress("jet_genmatch_phi", &jet_genmatch_phi);
            //_inputTree->SetBranchAddress("jet_genmatch_mass", &jet_genmatch_mass);
            _inputTree->SetBranchAddress("jet_genmatch_wnu_pt", &jet_genmatch_wnu_pt);
            _inputTree->SetBranchAddress("jet_genmatch_wnu_eta", &jet_genmatch_wnu_eta);
            _inputTree->SetBranchAddress("jet_genmatch_wnu_phi", &jet_genmatch_wnu_phi);
            _inputTree->SetBranchAddress("jet_genmatch_wnu_mass", &jet_genmatch_wnu_mass);
            

        }

    }

    return true;
}


//---------------------------------------------------------------------------------------------------------------
// Weight corrections
//---------------------------------------------------------------------------------------------------------------
void HEPHero::Weight_corrections(){

    //pileup_wgt = 1.;

    if(dataset_group != "Data"){

        /*
        if( apply_pileup_wgt ){
            pileup_wgt = GetPileupWeight(Pileup_nTrueInt, "nominal");
            evtWeight *= pileup_wgt;
        }
        */
    }
}


//---------------------------------------------------------------------------------------------------------------
// Get size of vertical systematic weights
// Keep the same order used in runSelection.py
//---------------------------------------------------------------------------------------------------------------
void HEPHero::VerticalSysSizes( ){
    if( (_sysID_lateral == 0) && (dataset_group != "Data") ) {
        sys_vertical_size.clear();
        _inputTree->GetEntry(0);

        //get_Pileup_sfs = false;

        for( int ivert = 0; ivert < _sysNames_vertical.size(); ++ivert ){
            string sysName = _sysNames_vertical.at(ivert);

            /*
            if( sysName == "Pileup" ){
                sys_vertical_size.push_back(2);
                get_Pileup_sfs = true;
            }
            */
        }
    }
}


//---------------------------------------------------------------------------------------------------------------
// Vertical systematics
// Keep the same order used in runSelection.py
//---------------------------------------------------------------------------------------------------------------
void HEPHero::VerticalSys(){
    if( (_sysID_lateral == 0) && (dataset_group != "Data") ) {
        sys_vertical_sfs.clear();

        //-----------------------------------------------------------------------------------
        /*
        if( get_Pileup_sfs ){
            vector<float> Pileup_sfs;
            double pileup_wgt_down = GetPileupWeight(Pileup_nTrueInt, "down");
            double pileup_wgt_up = GetPileupWeight(Pileup_nTrueInt, "up");
            Pileup_sfs.push_back(pileup_wgt_down/pileup_wgt);
            Pileup_sfs.push_back(pileup_wgt_up/pileup_wgt);
            sys_vertical_sfs.insert(pair<string, vector<float>>("Pileup", Pileup_sfs));
        }
        */
    }
}



//---------------------------------------------------------------------------------------------------------------
// MCsamples processing
//---------------------------------------------------------------------------------------------------------------
bool HEPHero::MC_processing(){

    bool pass_cut = true;
    string dsName = _datasetName.substr(0,_datasetName.length()-5);



    return pass_cut;
}


//---------------------------------------------------------------------------------------------------------------
// ANAFILES' ROUTINES
//---------------------------------------------------------------------------------------------------------------
void HEPHero::SetupAna(){
    if( false );
    else if( _SELECTION == "Test" ) SetupTest();
    else if( _SELECTION == "Skimming" ) SetupSkimming();
    else if( _SELECTION == "ONNX" ) SetupONNX();
    else if( _SELECTION == "Evaluate" ) SetupEvaluate();
    else if( _SELECTION == "Performance" ) SetupPerformance();
    else if( _SELECTION == "PtLimits" ) SetupPtLimits();
    // SETUP YOUR SELECTION HERE
    else {
      cout << "Unknown selection requested. Exiting. " << endl;
      return;
    }
}

bool HEPHero::AnaRegion(){
    bool Selected = true;
    if( _SELECTION == "Test" && !TestRegion() ) Selected = false;
    if( _SELECTION == "Skimming" && !SkimmingRegion() ) Selected = false;
    if( _SELECTION == "ONNX" && !ONNXRegion() ) Selected = false;
    if( _SELECTION == "Evaluate" && !EvaluateRegion() ) Selected = false;
    if( _SELECTION == "Performance" && !PerformanceRegion() ) Selected = false;
    if( _SELECTION == "PtLimits" && !PtLimitsRegion() ) Selected = false;
    // SET THE REGION OF YOUR SELECTION HERE

    return Selected;
}

void HEPHero::AnaSelection(){
    if( _SELECTION == "Test" ) TestSelection();
    if( _SELECTION == "Skimming" ) SkimmingSelection();
    if( _SELECTION == "ONNX" ) ONNXSelection();
    if( _SELECTION == "Evaluate" ) EvaluateSelection();
    if( _SELECTION == "Performance" ) PerformanceSelection();
    if( _SELECTION == "PtLimits" ) PtLimitsSelection();
    // CALL YOUR SELECTION HERE
}

void HEPHero::AnaSystematic(){
    if( _SELECTION == "Test" ) TestSystematic();
    if( _SELECTION == "Skimming" ) SkimmingSystematic();
    if( _SELECTION == "ONNX" ) ONNXSystematic();
    if( _SELECTION == "Evaluate" ) EvaluateSystematic();
    if( _SELECTION == "Performance" ) PerformanceSystematic();
    if( _SELECTION == "PtLimits" ) PtLimitsSystematic();
    // PRODUCE THE SYSTEMATIC OF YOUR SELECTION HERE
}

void HEPHero::FinishAna(){
    if( _SELECTION == "Test" ) FinishTest();
    if( _SELECTION == "Skimming" ) FinishSkimming();
    if( _SELECTION == "ONNX" ) FinishONNX();
    if( _SELECTION == "Evaluate" ) FinishEvaluate();
    if( _SELECTION == "Performance" ) FinishPerformance();
    if( _SELECTION == "PtLimits" ) FinishPtLimits();
    // FINISH YOUR SELECTION HERE
}
   




