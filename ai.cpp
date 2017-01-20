#include <iostream>

#include <vector>

#include "hans.h"
#include "hanslayer_dense.h"



int main(int argc, char* argv[])
{

        HansLayer_Dense h1 = new HansLayer_Dense(5, 3, -0.001, 0.001, 0);
        HansLayer_Dense o = new HansLayer_Dense(3, 1, -0.001, 0.001, 0);

        layers.push_back(h1);
        layers.push_back(o);

        Hans net = Hans();
        
        net.add_layer(new HansLayer_Dense(5, 3, -0.001, 0.001, 0);
        net.add_layer(new HansLayer_Dense(3, 1, -0.001, 0.001, 0);
        
        
        std::vector<float> input;
        input.push_back(0);
        input.push_back(1);
        input.push_back(0);
        input.push_back(1);
        input.push_back(1);

        std::vector<float> output;
        std::cout << "feedforward-start" << std::endl;
        result = net.feedforward(input);
        std::cout << "feedforward-end" << std::endl;

        for( int i = 0; i < output.size(); i++)
        {
                std::cout << output[i] << ' ';
        }
        std::cout << std::endl;

        return ok;
}
