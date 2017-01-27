#include <cmath>
#include <math.h>
#include <iostream>


//implementation from https://www.math.utah.edu/~beebe/software/ieee/tanh.pdf
float mytanh(float pval)
{
        float tmp = 0.5 - (1/(1+exp(2*pval)));
        return tmp+tmp;
}

int main()
{

        float lambda = 0.001;

        float left_boundary = 0.00;

        float value = left_boundary;
        for(int i = 0; i < 100; i++)
        {
                std::cout << "tanh(" << value << ") = " << std::tanh(value) <<std::endl;
                std::cout << "tanh(" << value << ") = " << mytanh(value) <<std::endl;
                value +=lambda;
        }



        return 0;
}
