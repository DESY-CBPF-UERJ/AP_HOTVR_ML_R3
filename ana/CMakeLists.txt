set(ANALYSIS "AP_HOTVR_ML_R3")

target_sources(RunAnalysis PRIVATE ${ANALYSIS}/ana/PtLimits.cpp ${ANALYSIS}/ana/Performance.cpp ${ANALYSIS}/ana/Evaluate.cpp ${ANALYSIS}/ana/ONNX.cpp ${ANALYSIS}/ana/Skimming.cpp ${ANALYSIS}/ana/Test.cpp)
