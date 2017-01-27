#ifndef HANSLAYERH
#define HANSLAYERH


#define FW_1 //nested fw-propagation
//#define FW_2 //for loops for each instruction in fw-propagation


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
        std::vector<float> (*const activation)(std::vector<float>);
        std::vector<float> (*const activation_derivative)(std::vector<float>);

        const int backprop_type; //1: activation_derivate gets activations as parameter, 2: activation_derivative gets pre-activations as parameter

        //weights for the forward pass (last column represents the bias)
        weights w;

        //variables holding the gradients/averaged gradients (last column bias)
        weights dw;

        //input to this layer
        std::vector<float> in; //is needed to calculate dw
        //output before activation_function
        std::vector<float> out1; // is not needed if t_tanh or sigmoid is used because the derivation can be calculated with out2 in some e.g. that cases
        //output after activation_function
        std::vector<float> out2; // needed to calculate dw


private:
        void init_weights(float pweights_min_init, float pweights_max_int, float pbias_init);

//---        virtual std::vector<float> backprop_type1(std::vector<float> pinput_right) = 0;
//---        virtual void backprop_type1_last(std::vector<float> pinput_right) = 0;
//---
//---        virtual std::vector<float> backprop_type2(std::vector<float> pinput_right) = 0;
//---        virtual void backprop_type2_last(std::vector<float> pinput_right) = 0;



public:
        HansLayer(int pinputs_dim,
                int pneurons_dim,
                float pweights_min_init,
                float pweights_max_init,
                float pbias_init,
                std::vector<float> (*pactivation)(std::vector<float>),
                std::vector<float> (*pactivation_derivative)(std::vector<float>),
                int pbackprop_type);
        virtual ~HansLayer();


        virtual std::vector<float> feedforward(std::vector<float> pinput) = 0;

        virtual std::vector<float> backprop(std::vector<float> pinput_right) = 0;
        virtual void backprop_last(std::vector<float> pinput_right) = 0;
//---        std::vector<float> (*backprop)(std::vector<float>);
//---        std::vector<float> (*backprop_last)(std::vector<float>);


        virtual void update_vanilla(float plearning_rate) = 0;
};

#endif
