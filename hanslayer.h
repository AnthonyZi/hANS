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
protected:
        const int inputs_dim;
        const int neurons_dim;

        //weights for the forward pass (last column represents the bias)
        weights w;
        //variables holding the gradients/averaged gradients (last column bias)
        weights dw;

private:
        void init_weights(float pweights_min_init, float pweights_max_int, float pbias_init);



public:
        HansLayer(int pinputs_dim, int pneurons_dim, float pweights_min_init, float pweights_max_init, float pbias_init);
        virtual ~HansLayer();

        virtual std::vector<float> feedforward(std::vector<float> pinput) = 0;
        virtual std::vector<float> backprop(std::vector<float> pinput_right) = 0;
        virtual void update_vanilla() = 0;
};

#endif
