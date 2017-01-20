#include "hanslayer.h"

HansLayer::HansLayer(
        int pinputs_dim,
        int pneurons_dim,
        float pweights_min_init,
        float pweights_max_init,
        float pbias_init) :
        inputs_dim(pinputs_dim),
        neurons_dim(pneurons_dim),
        w(pneurons_dim, std::vector<float>(pinputs_dim+1))
{       
}
