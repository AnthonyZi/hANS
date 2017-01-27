#ifndef HANSLAYER_DENSE_H
#define HANSLAYER_DENSE_H

//#define DETAILEDOUTPUT

#include "hanslayer.h"

class HansLayer_Dense : public HansLayer
{
private:
//---        virtual std::vector<float> backprop_type1(std::vector<float> pinput_right);
//---        virtual void backprop_type1_last(std::vector<float> pinput_right);
//---
//---        virtual std::vector<float> backprop_type2(std::vector<float> pinput_right);
//---        virtual void backprop_type2_last(std::vector<float> pinput_right);

public:
        HansLayer_Dense(int pinputs_dim,
        int pneurons_dim,
        float pweights_min_init,
        float pweights_max_init,
        float pbias_init,
        std::vector<float> (*pactivation)(std::vector<float>),
        std::vector<float> (*pactivation_derivative)(std::vector<float>),
        int pbackprop_type);

        virtual ~HansLayer_Dense();


        virtual std::vector<float> feedforward(std::vector<float> pinput);

        virtual std::vector<float> backprop(std::vector<float> pinput_right);
        virtual void backprop_last(std::vector<float> pinput_right);

        virtual void update_vanilla(float plearning_rate);

};

#endif
