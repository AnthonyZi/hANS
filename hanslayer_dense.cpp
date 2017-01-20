#include "hanslayer_dense.h"

HansLayer_Dense::HansLayer_Dense(
        int pinputs_dim
        int pneurons_dim,
        float pweigths_min_init,
        float pweights_max_init,
        float pbias_init) :
        HansLayer(pinputs_dim, pneurons_dim, pweights_min_init, pweights_max_init, pbias_init)
{
}
