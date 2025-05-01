#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <stdlib.h>
#include <TStyle.h>
#include <TH2D.h>
#include <TLegend.h>
#include <TColor.h>
#include <math.h>
#include <THnSparse.h>
#include <map>
#include <string>
#include <vector>
#include <random>
#include "THnSparse.h"
#include "TF1.h"
#include "TSystem.h"
#include "TLorentzVector.h"
#include "TGraphAsymmErrors.h"
#include <iomanip>
#include <sys/stat.h>
#include <time.h>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidcsv.h"

using namespace std;



//-------------------------------------------------------------------------
// NN Model (Torch)
//-------------------------------------------------------------------------
class NN_Torch {
    private:
        torch::jit::script::Module NN_model;
    public:
        void readFile( string model_file ){
            NN_model = torch::jit::load(model_file.c_str());
            torch::NoGradGuard no_grad; // ensures that autograd is off
            NN_model.eval();
        }
        
        float predict( vector<float> mlp_input, bool binary=true  ){
            std::vector<torch::jit::IValue> inputs;
            inputs.push_back(torch::tensor(mlp_input));
            at::Tensor result = NN_model.forward(inputs).toTensor();
            float prediction = result[0].item<float>();
            
            if( binary ){ 
                return 1-prediction;
            }else{
                return prediction;
            }
        }
};

/*
//-------------------------------------------------------------------------
// ONNX Model
//-------------------------------------------------------------------------
class ML_ONNX {
    private:
        Ort::Env env(OrtLoggingLevel::ORT_LOGGING_LEVEL_WARNING, "onnx_model");
        Ort::SessionOptions sessionOptions;
        sessionOptions.SetIntraOpNumThreads(1);
        sessionOptions.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);
        Ort::MemoryInfo memoryInfo = Ort::MemoryInfo::CreateCpu( OrtAllocatorType::OrtArenaAllocator, OrtMemType::OrtMemTypeDefault);
        Ort::Session session(env, "AP_HOTVR_ML_R3/include/start_model.onnx", sessionOptions);
        size_t numInputNodes;
        size_t numOutputNodes;
    public:
        void readFile( string model_file ){
            session = Ort::Session(env, model_file.c_str(), sessionOptions);
            numInputNodes = session.GetInputCount();
            numOutputNodes = session.GetOutputCount();
        }

        float predict( vector<float> mlp_input, bool binary=true  ){

            input_names
            inputTensorValues
            inputTensorDims

            output_names
            outputTensorValues
            outputTensorDims




            vector<Ort::Value> inputTensors;
            for (size_t i = 0; i < numInputNodes; i++){
                inputTensors.push_back(Ort::Value::CreateTensor<float>( memoryInfo, inputTensorValues[i].data(), inputTensorValues[i].size(), inputTensorDims[i].data(), inputTensorDims[i].size()));
            }

            vector<Ort::Value> outputTensors;
            for (size_t i = 0; i < numOutputNodes; i++){
                outputTensors.push_back(Ort::Value::CreateTensor<float>( memoryInfo, outputTensorValues[i].data(), outputTensorValues[i].size(), outputTensorDims[i].data(), outputTensorDims[i].size()));
            }

            session.Run(Ort::RunOptions{nullptr}, input_names, inputTensors.data(), numInputNodes,
                        output_names, outputTensors.data(), numOutputNodes);

            vector<float> prediction;
            if( numOutputNodes == 1 ){
                prediction.push_back(1-outputTensorValues.at(0).at(0));
            }else{
                for (size_t i = 0; i < numOutputNodes; i++){
                    prediction.push_back(outputTensorValues.at(0).at(i));
                }
            }

            return prediction;

        }
};
*/




