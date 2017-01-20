#ifndef HANSLAYER_DENSE_H
#define HANSLAYER_DENSE_H

class HansLayer_Dense : public HansLayer
{
private:

        virtual void feedforward();
        virtual void backprop();

        virtual void update_vanilla();



public:
        HansLayer_Dense(int pinputs_dim, int pneurons_dim, float pweights_min_init, float pweights_max_init, float pbias_init);
        virtual ~HansLayer_Dense();
};

#endif
