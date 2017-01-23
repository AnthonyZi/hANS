#include <iostream>

#include <vector>

#include "hans.h"
#include "hanslayer_dense.h"

#include <time.h>


int main(int argc, char* argv[])
{
        Hans net = Hans();
        
        HansLayer_Dense a1 = HansLayer_Dense(5, 10, -10, 10, 0.1);
        HansLayer_Dense a2 = HansLayer_Dense(10, 1000, -10, 10, 0.1);
        HansLayer_Dense a3 = HansLayer_Dense(1000, 40, -10, 10, 0.1);
        HansLayer_Dense a4 = HansLayer_Dense(40, 3000, -10, 10, 0.1);
        HansLayer_Dense a5 = HansLayer_Dense(3000, 2000, -10, 10, 0.1);
        HansLayer_Dense a6 = HansLayer_Dense(2000, 1000, -10, 10, 0.1);
        HansLayer_Dense a7 = HansLayer_Dense(1000, 1, -10, 10, 0.1);


        net.add_layer(&a1);
        net.add_layer(&a2);
        net.add_layer(&a3);
        net.add_layer(&a4);
        net.add_layer(&a5);
        net.add_layer(&a6);
        net.add_layer(&a7);
        
        
        std::vector<float> input;
        input.push_back(0);
        input.push_back(1);
        input.push_back(0);
        input.push_back(1);
        input.push_back(1);

        std::vector<float> result;
        std::cout << "feedforward-start" << std::endl;
        int iend = 5000;
        std::cout << "iterations: " << iend << std::endl;
        time_t start = time(NULL);
        for(int i = 0; i<iend; i++)
        {
                result = net.feednet(input);
        }
        time_t end = time(NULL);
        std::cout << "feedforward-end" << std::endl;
        std::cout << difftime(end,start) << std::endl;

        for(unsigned int i = 0; i < result.size(); i++)
        {
                std::cout << result[i] << ' ';
        }
        std::cout << std::endl;

        return 0;
}
