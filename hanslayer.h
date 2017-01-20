#ifndef HANSLAYERH
#define HANSLAYERH

#include <vector>
#include <random>

/*
 * a1 a2 a3 a4 | arrangement in the ram
 * b1 b2 b3 b4 | ram --> (row-wise)
 * c1 c2 c3 c4 | 
 * d1 d2 d3 d4 |
 *
 * letters name the neurons, which get a weighted sum over all
 * inputs of an input-vector which is numbered
 *
 * one inner vector holds one row
 *
 */
typedef std::vector<std::vector<float> > weights;

class HansLayer
{
private:
        const int inputs_dim;
        const int neurons_dim;

        //weights for the forward pass (last column represents the bias)
        weights w;
        //variables holding the gradients/averaged gradients (last column bias)
        weights dw;

        void init_weights();

        virtual void feedforward() = 0;
        virtual void backprop() = 0;

        virtual void update_vanilla() = 0;

public:
        HansLayer(int pinputs_dim, int pneurons_dim, float pweights_min_init, float pweights_max_init, float pbias_init);
        virtual ~HansLayer();

};

#endif
