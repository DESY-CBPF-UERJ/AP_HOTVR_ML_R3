#--------------------------------------------------------------------------------------------------
# Dataset files
#--------------------------------------------------------------------------------------------------
selection = "Skimming"
analysis = "AP_HOTVR_ML_R3"
treeName = "dnntree/tree"
LumiWeights = 1

analysis_parameters = {   
}

corrections = {  # 0-don't apply, 1-apply
}

lateral_systematics = { 
"CV":          [0,  1, [], []],   # [sys_source, sys_universe, processes_ID (empty -> all), subsources] 
}

vertical_systematics = {
}


#--------------------------------------------------------------------------------------------------
# Jobs setup
#--------------------------------------------------------------------------------------------------
NumMaxEvents = -1
NumFilesPerJob_Data = 1   
NumFilesPerJob_Signal = 50 
NumFilesPerJob_Bkg = 5      


#--------------------------------------------------------------------------------------------------
# Dataset files
#--------------------------------------------------------------------------------------------------
periods = [
"0_22",
#"1_22",
#"0_23",
#"1_23",
]

datasets = [
"TTtoLNu2Q",
"Zto2Q",
"QCD",
]


#--------------------------------------------------------------------------------------------------
# Metadata
#--------------------------------------------------------------------------------------------------
metadata = {
"NN_prep_keras_X_XX         ": analysis+"/Metadata/ML/2022/HOTVR/model.onnx",
}

#--------------------------------------------------------------------------------------------------
# Plots
#--------------------------------------------------------------------------------------------------
Get_Image_in_EPS = 0
Get_Image_in_PNG = 1
Get_Image_in_PDF = 0
