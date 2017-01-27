#include "hans.h"


Hans::Hans(std::vector<float> (*pcost_derivative)(std::vector<float>, std::vector<float>) ) :
       cost_derivative(pcost_derivative)
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

void Hans::backpropagate(std::vector<float> pnetwork_out, std::vector<float> pdesired_out)
{
        std::vector<float> current_vector = cost_derivative(pnetwork_out, pdesired_out);
        for(layer_v::reverse_iterator it = layers.rbegin(); it != layers.rend()-1; it++)
        {
                current_vector = (*it)->backprop(current_vector);
        }
        //no need to calculate the input-derivatives
        layers[0]->backprop_last(current_vector);
}

void Hans::update_vanilla(float plearning_rate)
{
        for(layer_v::iterator it = layers.begin(); it != layers.end(); it++)
        {
                (*it)->update_vanilla(plearning_rate);
        }
}
