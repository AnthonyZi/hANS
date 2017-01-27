#include "costs.h"

#ifndef DETAILEDOUTPUT

std::vector<float> Costs::quadratic_derivative(std::vector<float> pnetwork_out, std::vector<float> pdesired_out)
{
        std::vector<float> righthand_input;
        for(unsigned int i = 0; i < pnetwork_out.size(); i++)
        {
                righthand_input.push_back(pnetwork_out[i]-pdesired_out[i]);
        }
        return righthand_input;
}

#else
#include <iostream>

std::vector<float> Costs::quadratic_derivative(std::vector<float> pnetwork_out, std::vector<float> pdesired_out)
{
        std::vector<float> righthand_input;
        std::cout << "cost_derivative:" << std::endl;
        for(unsigned int i = 0; i < pnetwork_out.size(); i++)
        {
                righthand_input.push_back(pnetwork_out[i]-pdesired_out[i]);
                std::cout << righthand_input[i] << " ";
        }
        std::cout << std::endl << std::endl;
        return righthand_input;
}

#endif
