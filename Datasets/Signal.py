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
paths["0_22"] = analysis+'/Datasets/Files/signal_22/dti_0/'+nano_version+'/'
paths["1_22"] = analysis+'/Datasets/Files/signal_22/dti_1/'+nano_version+'/'
paths["0_23"] = analysis+'/Datasets/Files/signal_23/dti_0/'+nano_version+'/'
paths["1_23"] = analysis+'/Datasets/Files/signal_23/dti_1/'+nano_version+'/'


s_ds_info = { # [DatasetName, Production ID, PROC_XSEC[pb], XSEC_UNC[pb], XSEC_Accuracy]
#"Signal": [
#    ["Signal_H400_a100",                '99',       0.01803526,          0.,                'unknown'],
#],
}


#----------------------------------------------------------------------------------------
# [DO NOT TOUCH THIS PART]
#----------------------------------------------------------------------------------------
s_ds = {}
for period in paths.keys():

    dti = period[0]
    year = period[-2:]

    for key in s_ds_info.keys():
        s_ds[key+"_"+period] = []
        for ds in s_ds_info[key]:
            list_temp = []
            list_temp.append(ds[0]+"_"+period)
            list_temp.append(ds[1]+year+dti)
            list_temp.append(paths[period]+ds[0]+".txt")
            list_temp.append(ds[2])
            list_temp.append(ds[3])
            s_ds[key+"_"+period].append(list_temp)

