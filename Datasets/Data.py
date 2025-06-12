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
paths["0_22"] = analysis+'/Datasets/Files/data_22/'+nano_version+'/'
paths["1_22"] = analysis+'/Datasets/Files/data_22/'+nano_version+'/'
paths["0_23"] = analysis+'/Datasets/Files/data_23/'+nano_version+'/'
paths["1_23"] = analysis+'/Datasets/Files/data_23/'+nano_version+'/'


eras = {}
eras["0_22"] = ['C', 'D']
eras["1_22"] = ['E', 'F', 'G']
eras["0_23"] = ['C']
eras["1_23"] = ['D']


# https://twiki.cern.ch/twiki/bin/view/CMS/TWikiLUM
lumis = {} # [Luminosity[pb-1], Unc_total[%], Unc_uncorr[%], Unc_fullcorr[%]]
lumis["tags"] = ["Luminosity", "Unc_total", "uncorr", "fullcorr"]
lumis["0_22"] = [7980.4,    0,  0,  0]
lumis["1_22"] = [26671.7,   0,  0,  0]
lumis["0_23"] = [17794,     0,  0,  0]
lumis["1_23"] = [9451,      0,  0,  0]


d_ds_info = {}
"""
d_ds_info["0_22"] = { # [DatasetName, Production ID]
"Data_Lep": [
    ["Data_SingleEle",      '00'],
    ["Data_SingleMu",       '00'],
],
"Data_MET": [
    ["Data_MET",            '01'],
],
}
d_ds_info["1_22"] = d_ds_info["0_22"].copy()
d_ds_info["0_23"] = d_ds_info["0_22"].copy()
d_ds_info["1_23"] = d_ds_info["0_22"].copy()
"""

#----------------------------------------------------------------------------------------
# [DO NOT TOUCH THIS PART]
#----------------------------------------------------------------------------------------
d_ds = {}
for period in paths.keys():

    dti = period[0]
    year = period[-2:]

    for key in d_ds_info[period].keys():
        d_ds[key+"_"+period] = []
        for ds in d_ds_info[period][key]:
            for era in eras[period]:
                list_temp = []
                list_temp.append(ds[0]+"_"+era+"_"+period)
                list_temp.append(ds[1]+year+dti)
                list_temp.append(paths[period]+ds[0]+"_"+era+".txt")
                list_temp.append(None)
                list_temp.append(None)
                d_ds[key+"_"+period].append(list_temp)

