#include "hans.h"

Hans::Hans()
{
}

void Hans::add_layer(HansLayer* pHansP)
{
        layers.push_back(pHansP);
}

std::vector<float> Hans::feednet(std::vector<float> pinput)
{
        std::vector<float> current_vector = pinput;
        for(layer_v::iterator it = layers.begin(); it != layers.end(); it++)
        {
                current_vector = (*it)->feedforward(current_vector);
        }
        return current_vector;
}
