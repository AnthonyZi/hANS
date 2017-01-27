#include <iostream>

#include <vector>

#include "hans.h"
#include "hanslayer_dense.h"
#include "transferer.h"
#include "costs.h"

#include <time.h>


int main(int argc, char* argv[])
{
        Hans net = Hans(Costs::quadratic_derivative);
        

        HansLayer_Dense a1 = HansLayer_Dense(5    , 10   , -0.00001 , 0.00001 , 0 , Transferer::t_tanh , Transferer::t_bp_tanh , 2);
        HansLayer_Dense a2 = HansLayer_Dense(10   , 1000 , -0.00001 , 0.00001 , 0 , Transferer::t_tanh , Transferer::t_bp_tanh , 2);
        HansLayer_Dense a3 = HansLayer_Dense(1000 , 40   , -0.00001 , 0.00001 , 0 , Transferer::t_tanh , Transferer::t_bp_tanh , 2);
        HansLayer_Dense a4 = HansLayer_Dense(40   , 3000 , -0.00001 , 0.00001 , 0 , Transferer::t_tanh , Transferer::t_bp_tanh , 2);
        HansLayer_Dense a5 = HansLayer_Dense(3000 , 2000 , -0.00001 , 0.00001 , 0 , Transferer::t_tanh , Transferer::t_bp_tanh , 2);
        HansLayer_Dense a6 = HansLayer_Dense(2000 , 1000 , -0.00001 , 0.00001 , 0 , Transferer::t_tanh , Transferer::t_bp_tanh , 2);
        HansLayer_Dense a7 = HansLayer_Dense(1000 , 1    , -0.00001 , 0.00001 , 0 , Transferer::t_tanh , Transferer::t_bp_tanh , 2);


        net.add_layer(&a1);
        net.add_layer(&a2);
        net.add_layer(&a3);
        net.add_layer(&a4);
        net.add_layer(&a5);
        net.add_layer(&a6);
        net.add_layer(&a7);
        
        std::vector<float> input;
        input.push_back(-1);
        input.push_back(-1);
        input.push_back(-1);
        input.push_back(1);
        input.push_back(1);

        std::vector<float> result;
//---        std::cout << "feedforward-start" << std::endl;
//---        int iend = 5000;
//---        std::cout << "iterations: " << iend << std::endl;
//---        time_t start = time(NULL);
//---        for(int i = 0; i<iend; i++)
//---        {
//---                result = net.feednet(input);
//---        }
//---        time_t end = time(NULL);
//---        std::cout << difftime(end,start) << std::endl;
//---
//---        result = net.feednet(input);
//---
//---        std::cout << "feedforward-end" << std::endl;
//---
//---        for(unsigned int i = 0; i < result.size(); i++)
//---        {
//---                std::cout << result[i] << ' ';
//---        }
//---        std::cout << std::endl;


        std::vector<float> desired;
        desired.push_back(1);

        int jend = 5000;
        std::cout << "backpropagation-start [ " << jend << " iterations ]" << std::endl;
        time_t start = time(NULL);
        for(int j = 0; j < jend; j++)
        {
                result = net.feednet(input);
                net.backpropagate(result, desired);
                net.update_vanilla(0.0);
//                std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        }
        time_t end = time(NULL);

        std::cout << "last feedforward: " << std::endl;
        result = net.feednet(input);

//
        std::cout << "feedback" << std::endl;
        for(std::vector<float>::iterator it = result.begin(); it != result.end(); it++)
        {
                std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "backpropagation-end" << std::endl;
        std::cout << "backprop needed " << difftime(end,start) << " seconds" << std::endl;
//

        return 0;
}
