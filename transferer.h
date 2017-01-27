#ifndef TRANSFERER_H
#define TRANSFERER_H

#include <cmath>
#include <vector>

class Transferer
{
public:
        static std::vector<float> t_tanh(std::vector<float> pinput);
        static std::vector<float> t_bp_tanh(std::vector<float> pinput_right);

        static std::vector<float> t_pass(std::vector<float> pinput);
        static std::vector<float> t_bp_pass(std::vector<float> pinput_right);
};

#endif
