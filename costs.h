#ifndef COST_H
#define COST_H 

//#define DETAILEDOUTPUT

#include <vector>

class Costs
{
public:
        static std::vector<float> quadratic_derivative(std::vector<float> pnetwork_out, std::vector<float> pdesired_out);
};

#endif
