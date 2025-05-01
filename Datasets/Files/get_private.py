import os
import sys
import argparse

#find . -type d -print

#======SETUP=======================================================================================
parser = argparse.ArgumentParser()
parser.add_argument("-v", "--version")
parser.add_argument("-p", "--period")
args = parser.parse_args()


basedir = "bkg_"+args.period[-2:]+"/dti_"+args.period[0]+"/v"+args.version+"/"
if os.path.isdir(basedir) is False:
    os.makedirs(basedir)


datasets = [
["TTtoLNu2Q",               "/cms/store/user/gcorreia/CRAB_HOTVR/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/crab_20250423_160151/250423_140207/0000"],
["Zto2Q_PTQQ-100to200_1J",     "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233835/250423_213857/0000"],
["Zto2Q_PTQQ-200to400_1J",     "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233859/250423_213904/0000"],
["Zto2Q_PTQQ-400to600_1J",     "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233906/250423_213912/0000"],
["Zto2Q_PTQQ-600_1J",          "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233914/250423_213919/0000"],
["Zto2Q_PTQQ-100to200_2J",     "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233921/250423_213925/0000"],
["Zto2Q_PTQQ-200to400_2J",     "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233927/250423_213931/0000"],
["Zto2Q_PTQQ-400to600_2J",     "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233933/250423_213937/0000"],
["Zto2Q_PTQQ-600_2J",          "/cms/store/user/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250423_233939/250423_213944/0000"],
["QCD_PT-15to30",           "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-15to30_TuneCP5_13p6TeV_pythia8/crab_20250423_233946/250423_213951/0000"],
["QCD_PT-30to50",           "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-30to50_TuneCP5_13p6TeV_pythia8/crab_20250423_233953/250423_213959/0000"],
["QCD_PT-50to80",           "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-50to80_TuneCP5_13p6TeV_pythia8/crab_20250423_234001/250423_214006/0000"],
["QCD_PT-80to120",          "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-80to120_TuneCP5_13p6TeV_pythia8/crab_20250423_234009/250423_214014/0000"],
["QCD_PT-120to170",         "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-120to170_TuneCP5_13p6TeV_pythia8/crab_20250423_234016/250423_214023/0000"],
["QCD_PT-170to300",         "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-170to300_TuneCP5_13p6TeV_pythia8/crab_20250423_234025/250423_214030/0000"],
["QCD_PT-300to470",         "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-300to470_TuneCP5_13p6TeV_pythia8/crab_20250423_234032/250423_214037/0000"],
["QCD_PT-470to600",         "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-470to600_TuneCP5_13p6TeV_pythia8/crab_20250423_234040/250423_214045/0000"],
["QCD_PT-600to800",         "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-600to800_TuneCP5_13p6TeV_pythia8/crab_20250423_234047/250423_214052/0000"],
["QCD_PT-800to1000",        "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-800to1000_TuneCP5_13p6TeV_pythia8/crab_20250423_234054/250423_214100/0000"],
["QCD_PT-1000to1400",       "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-1000to1400_TuneCP5_13p6TeV_pythia8/crab_20250423_234102/250423_214107/0000"],
["QCD_PT-1400to1800",       "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-1400to1800_TuneCP5_13p6TeV_pythia8/crab_20250423_234110/250423_214115/0000"],
["QCD_PT-1800to2400",       "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-1800to2400_TuneCP5_13p6TeV_pythia8/crab_20250423_234117/250423_214122/0000"],
["QCD_PT-2400to3200",       "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-2400to3200_TuneCP5_13p6TeV_pythia8/crab_20250423_234125/250423_214130/0000"],
["QCD_PT-3200",             "/cms/store/user/gcorreia/CRAB_HOTVR/QCD_PT-3200_TuneCP5_13p6TeV_pythia8/crab_20250423_234132/250423_214138/0000"],
]

"""
datasets = [
["TTtoLNu2Q",               "/eos/user/g/gcorreia/CRAB_HOTVR/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/crab_20250410_021621/250410_001625/0000"],
["Zto2Q_PTQQ-100to200_1J",     "/eos/user/g/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250410_021334/250410_001341/0000"],
["Zto2Q_PTQQ-200to400_1J",     "/eos/user/g/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250410_021343/250410_001349/0000"],
["Zto2Q_PTQQ-400to600_1J",     "/eos/user/g/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250410_021351/250410_001357/0000"],
["Zto2Q_PTQQ-600_1J",          "/eos/user/g/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250410_021359/250410_001404/0000"],
["Zto2Q_PTQQ-100to200_2J",     "/eos/user/g/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250410_021406/250410_001410/0000"],
["Zto2Q_PTQQ-200to400_2J",     "/eos/user/g/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250410_021412/250410_001416/0000"],
["Zto2Q_PTQQ-400to600_2J",     "/eos/user/g/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250410_021418/250410_001422/0000"],
["Zto2Q_PTQQ-600_2J",          "/eos/user/g/gcorreia/CRAB_HOTVR/Zto2Q-2Jets_PTQQ-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/crab_20250410_021425/250410_001429/0000"],
["QCD_PT-15to30",           "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-15to30_TuneCP5_13p6TeV_pythia8/crab_20250410_021431/250410_001436/0000"],
["QCD_PT-30to50",           "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-30to50_TuneCP5_13p6TeV_pythia8/crab_20250410_021437/250410_001442/0000"],
["QCD_PT-50to80",           "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-50to80_TuneCP5_13p6TeV_pythia8/crab_20250410_021444/250410_001450/0000"],
["QCD_PT-80to120",          "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-80to120_TuneCP5_13p6TeV_pythia8/crab_20250410_021452/250410_001457/0000"],
["QCD_PT-120to170",         "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-120to170_TuneCP5_13p6TeV_pythia8/crab_20250410_021458/250410_001505/0000"],
["QCD_PT-170to300",         "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-170to300_TuneCP5_13p6TeV_pythia8/crab_20250410_021507/250410_001512/0000"],
["QCD_PT-300to470",         "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-300to470_TuneCP5_13p6TeV_pythia8/crab_20250410_021514/250410_001519/0000"],
["QCD_PT-470to600",         "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-470to600_TuneCP5_13p6TeV_pythia8/crab_20250410_021521/250410_001526/0000"],
["QCD_PT-600to800",         "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-600to800_TuneCP5_13p6TeV_pythia8/crab_20250410_021527/250410_001533/0000"],
["QCD_PT-800to1000",        "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-800to1000_TuneCP5_13p6TeV_pythia8/crab_20250410_021534/250410_001540/0000"],
["QCD_PT-1000to1400",       "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-1000to1400_TuneCP5_13p6TeV_pythia8/crab_20250410_021542/250410_001547/0000"],
["QCD_PT-1400to1800",       "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-1400to1800_TuneCP5_13p6TeV_pythia8/crab_20250410_021549/250410_001558/0000"],
["QCD_PT-1800to2400",       "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-1800to2400_TuneCP5_13p6TeV_pythia8/crab_20250410_021600/250410_001606/0000"],
["QCD_PT-2400to3200",       "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-2400to3200_TuneCP5_13p6TeV_pythia8/crab_20250410_021608/250410_001612/0000"],
["QCD_PT-3200",             "/eos/user/g/gcorreia/CRAB_HOTVR/QCD_PT-3200_TuneCP5_13p6TeV_pythia8/crab_20250410_021614/250410_001619/0000"],
]
"""


for i in range(len(datasets)):
    file_out = basedir + datasets[i][0] + ".txt"

    files_list = os.listdir(datasets[i][1])

    with open(file_out, "w") as file:
        for input_file in files_list:
            file.write(os.path.join(datasets[i][1],input_file+"\n"))

