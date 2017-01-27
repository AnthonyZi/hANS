#include "hanslayer.h"

HansLayer::HansLayer(
        int pinputs_dim,
        int pneurons_dim,
        float pweights_min_init,
        float pweights_max_init,
        float pbias_init,
        std::vector<float> (*pactivation)(std::vector<float>),
        std::vector<float> (*pactivation_derivative)(std::vector<float>),
        int pbackprop_type) :

        inputs_dim(pinputs_dim),
        neurons_dim(pneurons_dim),
        activation(pactivation),
        activation_derivative(pactivation_derivative),
        backprop_type(pbackprop_type),
        w(pneurons_dim, std::vector<float>(pinputs_dim+1)),
        dw(pneurons_dim, std::vector<float>(pinputs_dim+1))
{       
        init_weights(pweights_min_init, pweights_max_init, pbias_init);
}

HansLayer::~HansLayer()
{
        //erase all pointers here
}

void HansLayer::init_weights(float pweights_min_init, float pweights_max_init, float pbias_init)
{
        //initialization of the weights
        std::random_device rd;
//        std::mt19937 gen(rd());
        std::mt19937 gen(6);
        std::uniform_real_distribution<float> dis(pweights_min_init, pweights_max_init);
        for(int row = 0; row<neurons_dim; row++)
        {
                for(int col = 0; col<inputs_dim; col++)
                {
                        w[row][col] = dis(gen);
                }
                w[row][inputs_dim] = pbias_init;
        }
}
