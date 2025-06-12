analysis = "AP_HOTVR_ML_R3"
nano_version = 'v12'

#--------------------------------------------------------------------------------------------------
# Production ID:
# 00-09(Data), 10-19(MC-signal), 20-98(MC-bkg), 99(private sample)
#
# Data taking interval (DTI):
# 2022 DTIs = 0(preEE), 1(postEE)
# 2023 DTIs = 0(preBPix), 1(postBPix)
#--------------------------------------------------------------------------------------------------

paths = {}
paths["0_22"] = analysis+'/Datasets/Files/bkg_22/dti_0/'+nano_version+'/'
paths["1_22"] = analysis+'/Datasets/Files/bkg_22/dti_1/'+nano_version+'/'
paths["0_23"] = analysis+'/Datasets/Files/bkg_23/dti_0/'+nano_version+'/'
paths["1_23"] = analysis+'/Datasets/Files/bkg_23/dti_1/'+nano_version+'/'


# https://xsecdb-xsdb-official.app.cern.ch/
b_ds_info = { # [DatasetName, Production ID, PROC_XSEC[pb], XSEC_UNC[pb], XSEC_Accuracy]
"TTtoLNu2Q" : [
    ["TTtoLNu2Q",               '99',   762.1,               0.,             "unknown"],
],

"Zto2Q": [
    ["Zto2Q_PTQQ-100to200_1J",  '99',   302,                 0.,             "unknown"],
    ["Zto2Q_PTQQ-200to400_1J",  '99',   21.64,               0.,             "unknown"],
    ["Zto2Q_PTQQ-400to600_1J",  '99',   0.7376,              0.,             "unknown"],
    ["Zto2Q_PTQQ-600_1J",       '99',   0.08717,             0.,             "unknown"],
    ["Zto2Q_PTQQ-100to200_2J",  '99',   343.9,               0.,             "unknown"],
    ["Zto2Q_PTQQ-200to400_2J",  '99',   48.36,               0.,             "unknown"],
    ["Zto2Q_PTQQ-400to600_2J",  '99',   2.683,               0.,             "unknown"],
    ["Zto2Q_PTQQ-600_2J",       '99',   0.4459,              0.,             "unknown"],
],

"QCD": [
    ["QCD_PT-15to30",           '99',   1301000000,          0.,             "unknown"],
    ["QCD_PT-30to50",           '99',   113300000.0,         0.,             "unknown"],
    ["QCD_PT-50to80",           '99',   16760000,            0.,             "unknown"],
    ["QCD_PT-80to120",          '99',   2534000.0,           0.,             "unknown"],
    ["QCD_PT-120to170",         '99',   445800.0,            0.,             "unknown"],
    ["QCD_PT-170to300",         '99',   113700.0,            0.,             "unknown"],
    ["QCD_PT-300to470",         '99',   7559.0,              0.,             "unknown"],
    ["QCD_PT-470to600",         '99',   626.4,               0.,             "unknown"],
    ["QCD_PT-600to800",         '99',   178.6,               0.,             "unknown"],
    ["QCD_PT-800to1000",        '99',   30.57,               0.,             "unknown"],
    ["QCD_PT-1000to1400",       '99',   8.92,                0.,             "unknown"],
    ["QCD_PT-1400to1800",       '99',   0.8103,              0.,             "unknown"],
    ["QCD_PT-1800to2400",       '99',   0.1148,              0.,             "unknown"],
    ["QCD_PT-2400to3200",       '99',   0.007542,            0.,             "unknown"],
    ["QCD_PT-3200",             '99',   0.0002331,           0.,             "unknown"],
],
}


#----------------------------------------------------------------------------------------
# [DO NOT TOUCH THIS PART]
#----------------------------------------------------------------------------------------
b_ds = {}
for period in paths.keys():

    dti = period[0]
    year = period[-2:]

    for key in b_ds_info.keys():
        b_ds[key+"_"+period] = []
        for ds in b_ds_info[key]:
            list_temp = []
            list_temp.append(ds[0]+"_"+period)
            list_temp.append(ds[1]+year+dti)
            list_temp.append(paths[period]+ds[0]+".txt")
            list_temp.append(ds[2])
            list_temp.append(ds[3])
            b_ds[key+"_"+period].append(list_temp)

