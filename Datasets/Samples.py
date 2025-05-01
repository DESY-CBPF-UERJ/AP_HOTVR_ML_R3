import os


def get_samples( basedir, period ):

    list_basedir = os.listdir(basedir)
    periodTag = period + "_files"

    samples = {
        'TTtoLNu2Q':                    [i for i in list_basedir if 'TTtoLNu2Q' == i.split("_"+periodTag)[0]],
        'Zto2Q_PTQQ-100to200_1J':          [i for i in list_basedir if 'Zto2Q_PTQQ-100to200_1J' == i.split("_"+periodTag)[0]],
        'Zto2Q_PTQQ-200to400_1J':          [i for i in list_basedir if 'Zto2Q_PTQQ-200to400_1J' == i.split("_"+periodTag)[0]],
        'Zto2Q_PTQQ-400to600_1J':          [i for i in list_basedir if 'Zto2Q_PTQQ-400to600_1J' == i.split("_"+periodTag)[0]],
        'Zto2Q_PTQQ-600_1J':               [i for i in list_basedir if 'Zto2Q_PTQQ-600_1J' == i.split("_"+periodTag)[0]],
        'Zto2Q_PTQQ-100to200_2J':          [i for i in list_basedir if 'Zto2Q_PTQQ-100to200_2J' == i.split("_"+periodTag)[0]],
        'Zto2Q_PTQQ-200to400_2J':          [i for i in list_basedir if 'Zto2Q_PTQQ-200to400_2J' == i.split("_"+periodTag)[0]],
        'Zto2Q_PTQQ-400to600_2J':          [i for i in list_basedir if 'Zto2Q_PTQQ-400to600_2J' == i.split("_"+periodTag)[0]],
        'Zto2Q_PTQQ-600_2J':               [i for i in list_basedir if 'Zto2Q_PTQQ-600_2J' == i.split("_"+periodTag)[0]],
        'QCD_PT-15to30':                [i for i in list_basedir if 'QCD_PT-15to30' == i.split("_"+periodTag)[0]],
        'QCD_PT-30to50':                [i for i in list_basedir if 'QCD_PT-30to50' == i.split("_"+periodTag)[0]],
        'QCD_PT-50to80':                [i for i in list_basedir if 'QCD_PT-50to80' == i.split("_"+periodTag)[0]],
        'QCD_PT-80to120':               [i for i in list_basedir if 'QCD_PT-80to120' == i.split("_"+periodTag)[0]],
        'QCD_PT-120to170':              [i for i in list_basedir if 'QCD_PT-120to170' == i.split("_"+periodTag)[0]],
        'QCD_PT-170to300':              [i for i in list_basedir if 'QCD_PT-170to300' == i.split("_"+periodTag)[0]],
        'QCD_PT-300to470':              [i for i in list_basedir if 'QCD_PT-300to470' == i.split("_"+periodTag)[0]],
        'QCD_PT-470to600':              [i for i in list_basedir if 'QCD_PT-470to600' == i.split("_"+periodTag)[0]],
        'QCD_PT-600to800':              [i for i in list_basedir if 'QCD_PT-600to800' == i.split("_"+periodTag)[0]],
        'QCD_PT-800to1000':             [i for i in list_basedir if 'QCD_PT-800to1000' == i.split("_"+periodTag)[0]],
        'QCD_PT-1000to1400':            [i for i in list_basedir if 'QCD_PT-1000to1400' == i.split("_"+periodTag)[0]],
        'QCD_PT-1400to1800':            [i for i in list_basedir if 'QCD_PT-1400to1800' == i.split("_"+periodTag)[0]],
        'QCD_PT-1800to2400':            [i for i in list_basedir if 'QCD_PT-1800to2400' == i.split("_"+periodTag)[0]],
        'QCD_PT-2400to3200':            [i for i in list_basedir if 'QCD_PT-2400to3200' == i.split("_"+periodTag)[0]],
        'QCD_PT-3200':                  [i for i in list_basedir if 'QCD_PT-3200' == i.split("_"+periodTag)[0]],
        'Data_A':                   [i for i in list_basedir if 'Data' in i and '_A_' in i and periodTag in i],
        'Data_B':                   [i for i in list_basedir if 'Data' in i and '_B_' in i and periodTag in i],
        'Data_C':                   [i for i in list_basedir if 'Data' in i and '_C_' in i and periodTag in i],
        'Data_D':                   [i for i in list_basedir if 'Data' in i and '_D_' in i and periodTag in i],
        'Data_E':                   [i for i in list_basedir if 'Data' in i and '_E_' in i and periodTag in i],
        'Data_F':                   [i for i in list_basedir if 'Data' in i and '_F_' in i and periodTag in i],
        'Data_G':                   [i for i in list_basedir if 'Data' in i and '_G_' in i and periodTag in i],
        'Data_H':                   [i for i in list_basedir if 'Data' in i and '_H_' in i and periodTag in i],
    }
    
    empty_samples = []
    for sample in samples:
        if len(samples[sample]) == 0:
            empty_samples.append(sample)

    for sample in empty_samples:
        del samples[sample]

    return samples


