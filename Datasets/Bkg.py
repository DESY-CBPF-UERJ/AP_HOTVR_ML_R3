analysis = "AP_HOTVR_ML_R3"
nano_version = 'v12'
path_0_22 = analysis+'/Datasets/Files/bkg_22/dti_0/'+nano_version+'/'
path_1_22 = analysis+'/Datasets/Files/bkg_22/dti_1/'+nano_version+'/'
path_0_23 = analysis+'/Datasets/Files/bkg_23/dti_0/'+nano_version+'/'
path_1_23 = analysis+'/Datasets/Files/bkg_23/dti_1/'+nano_version+'/'

#--------------------------------------------------------------------------------------------------
# ID digits:
# 1st-2nd = 16(2016),17(2017),18(2018)                              # Year
# 3th-4th = 00(Data),01(MC-signal),02-13(MC-bkg),99(private sample) # Group
# 5th-6th = 00(none),...                                            # Bkg -> Process
# 5th-6th = 00(none),11(250_30),12(250_40),55(1250_100)             # Signal -> Signal point
# 5th-6th = 00(none),01(A),02(B),03(C)                              # Data -> Era
# 7th     = 0,1,2,...                                               # Data taking interval (DTI)

# 2022 DTIs = 0(preEE), 1(postEE)
# 2023 DTIs = 0(preBPix), 1(postBPix)
#--------------------------------------------------------------------------------------------------


periods = ["0_22", "1_22", "0_23", "1_23"]
paths = [path_0_22, path_1_22, path_0_23, path_1_23]

for period,path in zip(periods,paths):

    dti = period[0]
    year = period[-2:]
    

    TTtoLNu2Q_HOTVR = [
        ["TTtoLNu2Q_"+period]             + [year+'9900'+dti, path+"TTtoLNu2Q.txt"],
    ]

    Zto2Q_HOTVR = [
        ["Zto2Q_PTQQ-100to200_1J_"+period]             + [year+'9900'+dti, path+"Zto2Q_PTQQ-100to200_1J.txt"],
        ["Zto2Q_PTQQ-200to400_1J_"+period]             + [year+'9901'+dti, path+"Zto2Q_PTQQ-200to400_1J.txt"],
        ["Zto2Q_PTQQ-400to600_1J_"+period]             + [year+'9902'+dti, path+"Zto2Q_PTQQ-400to600_1J.txt"],
        ["Zto2Q_PTQQ-600_1J_"+period]                  + [year+'9903'+dti, path+"Zto2Q_PTQQ-600_1J.txt"],
        ["Zto2Q_PTQQ-100to200_2J_"+period]             + [year+'9900'+dti, path+"Zto2Q_PTQQ-100to200_2J.txt"],
        ["Zto2Q_PTQQ-200to400_2J_"+period]             + [year+'9901'+dti, path+"Zto2Q_PTQQ-200to400_2J.txt"],
        ["Zto2Q_PTQQ-400to600_2J_"+period]             + [year+'9902'+dti, path+"Zto2Q_PTQQ-400to600_2J.txt"],
        ["Zto2Q_PTQQ-600_2J_"+period]                  + [year+'9903'+dti, path+"Zto2Q_PTQQ-600_2J.txt"],
    ]

    QCD_HOTVR = [
        ["QCD_PT-15to30_"+period]                   + [year+'9900'+dti, path+"QCD_PT-15to30.txt"],
        ["QCD_PT-30to50_"+period]                   + [year+'9901'+dti, path+"QCD_PT-30to50.txt"],
        ["QCD_PT-50to80_"+period]                   + [year+'9902'+dti, path+"QCD_PT-50to80.txt"],
        ["QCD_PT-80to120_"+period]                  + [year+'9903'+dti, path+"QCD_PT-80to120.txt"],
        ["QCD_PT-120to170_"+period]                 + [year+'9904'+dti, path+"QCD_PT-120to170.txt"],
        ["QCD_PT-170to300_"+period]                 + [year+'9905'+dti, path+"QCD_PT-170to300.txt"],
        ["QCD_PT-300to470_"+period]                 + [year+'9906'+dti, path+"QCD_PT-300to470.txt"],
        ["QCD_PT-470to600_"+period]                 + [year+'9907'+dti, path+"QCD_PT-470to600.txt"],
        ["QCD_PT-600to800_"+period]                 + [year+'9908'+dti, path+"QCD_PT-600to800.txt"],
        ["QCD_PT-800to1000_"+period]                + [year+'9909'+dti, path+"QCD_PT-800to1000.txt"],
        ["QCD_PT-1000to1400_"+period]               + [year+'9910'+dti, path+"QCD_PT-1000to1400.txt"],
        ["QCD_PT-1400to1800_"+period]               + [year+'9911'+dti, path+"QCD_PT-1400to1800.txt"],
        ["QCD_PT-1800to2400_"+period]               + [year+'9912'+dti, path+"QCD_PT-1800to2400.txt"],
        ["QCD_PT-2400to3200_"+period]               + [year+'9913'+dti, path+"QCD_PT-2400to3200.txt"],
        ["QCD_PT-3200_"+period]                     + [year+'9914'+dti, path+"QCD_PT-3200.txt"],
    ]


    if period == "0_22":
        TTtoLNu2Q_HOTVR_0_22 = TTtoLNu2Q_HOTVR
        Zto2Q_HOTVR_0_22 = Zto2Q_HOTVR
        QCD_HOTVR_0_22 = QCD_HOTVR
    elif period == "1_22":
        TTtoLNu2Q_HOTVR_1_22 = TTtoLNu2Q_HOTVR
        Zto2Q_HOTVR_1_22 = Zto2Q_HOTVR
        QCD_HOTVR_1_22 = QCD_HOTVR
    elif period == "0_23":
        TTtoLNu2Q_HOTVR_0_23 = TTtoLNu2Q_HOTVR
        Zto2Q_HOTVR_0_23 = Zto2Q_HOTVR
        QCD_HOTVR_0_23 = QCD_HOTVR
    elif period == "1_23":
        TTtoLNu2Q_HOTVR_1_23 = TTtoLNu2Q_HOTVR
        Zto2Q_HOTVR_1_23 = Zto2Q_HOTVR
        QCD_HOTVR_1_23 = QCD_HOTVR
