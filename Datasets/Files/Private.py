#==================================================================================================
# Datasets setup
#==================================================================================================
datasets = {}
datasets["0_22"] = [
["TTtoLNu2Q",                   "/cms/store/user/gcorreia/CRAB_HOTVR/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/crab_20250423_160151/250423_140207/0000"],
["Zto2Q_PTQQ-100to200_1J",      "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233835/250423_213857/0000"],
["Zto2Q_PTQQ-200to400_1J",      "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233859/250423_213904/0000"],
["Zto2Q_PTQQ-400to600_1J",      "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233906/250423_213912/0000"],
["Zto2Q_PTQQ-600_1J",           "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233914/250423_213919/0000"],
["Zto2Q_PTQQ-100to200_2J",      "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233921/250423_213925/0000"],
["Zto2Q_PTQQ-200to400_2J",      "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233927/250423_213931/0000"],
["Zto2Q_PTQQ-400to600_2J",      "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233933/250423_213937/0000"],
["Zto2Q_PTQQ-600_2J",           "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233939/250423_213944/0000"],
["QCD_PT-15to30",               "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-15to30_TuneCP5_13p6TeV_pythia8/crab_20250423_233946/250423_213951/0000"],
["QCD_PT-30to50",               "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-30to50_TuneCP5_13p6TeV_pythia8/crab_20250423_233953/250423_213959/0000"],
["QCD_PT-50to80",               "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-50to80_TuneCP5_13p6TeV_pythia8/crab_20250423_234001/250423_214006/0000"],
["QCD_PT-80to120",              "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-80to120_TuneCP5_13p6TeV_pythia8/crab_20250423_234009/250423_214014/0000"],
["QCD_PT-120to170",             "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-120to170_TuneCP5_13p6TeV_pythia8/crab_20250423_234016/250423_214023/0000"],
["QCD_PT-170to300",             "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-170to300_TuneCP5_13p6TeV_pythia8/crab_20250423_234025/250423_214030/0000"],
["QCD_PT-300to470",             "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-300to470_TuneCP5_13p6TeV_pythia8/crab_20250423_234032/250423_214037/0000"],
["QCD_PT-470to600",             "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-470to600_TuneCP5_13p6TeV_pythia8/crab_20250423_234040/250423_214045/0000"],
["QCD_PT-600to800",             "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-600to800_TuneCP5_13p6TeV_pythia8/crab_20250423_234047/250423_214052/0000"],
["QCD_PT-800to1000",            "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-800to1000_TuneCP5_13p6TeV_pythia8/crab_20250423_234054/250423_214100/0000"],
["QCD_PT-1000to1400",           "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-1000to1400_TuneCP5_13p6TeV_pythia8/crab_20250423_234102/250423_214107/0000"],
["QCD_PT-1400to1800",           "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-1400to1800_TuneCP5_13p6TeV_pythia8/crab_20250423_234110/250423_214115/0000"],
["QCD_PT-1800to2400",           "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-1800to2400_TuneCP5_13p6TeV_pythia8/crab_20250423_234117/250423_214122/0000"],
["QCD_PT-2400to3200",           "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-2400to3200_TuneCP5_13p6TeV_pythia8/crab_20250423_234125/250423_214130/0000"],
["QCD_PT-3200",                 "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-3200_TuneCP5_13p6TeV_pythia8/crab_20250423_234132/250423_214138/0000"],
]
