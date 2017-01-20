#include "hanslayer.h"

HansLayer::HansLayer(
        int pinputs_dim,
        int pneurons_dim,
        float pweights_min_init,
        float pweights_max_init,
        float pbias_init) :
        inputs_dim(pinputs_dim),
        neurons_dim(pneurons_dim),
        w(pneurons_dim, std::vector<float>(pinputs_dim+1)),
        dw(pneurons_dim, std::vector<float>(pinputs_dim+1))
{       
        init_weights(pweights_min_init, pweights_max_init, pbias_init);
}

void HansLayer::init_weights(float pweights_min_init, float pweights_max_init, float pbias_init)
{
        //initialization of the weights
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dis(pweights_min_init, weights_max_init);
        for(int row = 0; row<neurons_dim; row++)
        {
                for(int col = 0; col<inputs_dim; col++)
                {
                        w[row][col] = dis(gen);
                }
                w[row][inputs_dim+1] = pbias_init;
        }
}
