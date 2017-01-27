#include "transferer.h"

std::vector<float> Transferer::t_tanh(std::vector<float> pinput)
{
        std::vector<float> out;
        for(std::vector<float>::iterator it = pinput.begin(); it != pinput.end(); it++)
        {
                out.push_back(std::tanh(*it));
        }
        return out;
}

std::vector<float> Transferer::t_bp_tanh(std::vector<float> pinput_right)
{
        std::vector<float> out;
        for(std::vector<float>::iterator it = pinput_right.begin(); it != pinput_right.end(); it++)
        {
                out.push_back( ( 1 - ((*it)*(*it)) ) );
        }
        return out;
}

std::vector<float> Transferer::t_pass(std::vector<float> pinput)
{
        return pinput;
}

std::vector<float> Transferer::t_bp_pass(std::vector<float> pinput_right)
{
        return pinput_right;
}
