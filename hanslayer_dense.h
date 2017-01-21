#ifndef HANSLAYER_DENSE_H
#define HANSLAYER_DENSE_H

#include "hanslayer.h"

#include <iostream>

class HansLayer_Dense : public HansLayer
{
private:

        virtual std::vector<float> feedforward(std::vector<float> pinput);
        virtual std::vector<float> backprop(std::vector<float> pinput_right);

        virtual void update_vanilla();



public:
        HansLayer_Dense(int pinputs_dim, int pneurons_dim, float pweights_min_init, float pweights_max_init, float pbias_init);
        virtual ~HansLayer_Dense();
};

#endif
