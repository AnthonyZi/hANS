#include <iostream>

#include <vector>

#include "hans.h"
#include "hanslayer_dense.h"



int main(int argc, char* argv[])
{
        Hans net = Hans();
        
        net.add_layer(new HansLayer_Dense(5, 10, -10, 10, 0));
        net.add_layer(new HansLayer_Dense(10, 1, -10, 10, 0));
        
        
        std::vector<float> input;
        input.push_back(0);
        input.push_back(1);
        input.push_back(0);
        input.push_back(1);
        input.push_back(1);

        std::vector<float> result;
        std::cout << "feedforward-start" << std::endl;
        result = net.feednet(input);
        std::cout << "feedforward-end" << std::endl;

        for( int i = 0; i < result.size(); i++)
        {
                std::cout << result[i] << ' ';
        }
        std::cout << std::endl;

        return 0;
}
