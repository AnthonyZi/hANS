#ifndef HANSH
#define HANSH

#include <vector>

#include "hanslayer.h"
//---#include "hans_defs.h"


typedef std::vector<HansLayer*> layer_v;

typedef struct training_data{
        std::vector<float> netinput;
        std::vector<float> netoutput_desired;
} training_data_s;

class Hans
{
private:
        layer_v layers;
//---        std::vector<float> layerinput;
//---        std::vector<float> layeroutput;

//---        void init_net(layer_v);

        //calls backpropagation-methods of the layers and saves the gradients
        //in the corresponding layer-class
//---        void backpropagation(training_data_s* ptraining_data_s);
        //calculate (1/m)*sum(m_gradients) - average over m gradients
//---        void batch_backprop(std::vector<training_data_s>* ptraining_data_s_batch);
public:
        Hans();

        std::vector<float> feednet(std::vector<float> pinput);

        void add_layer(HansLayer* pHansP);
};

#endif
