#include "hanslayer_dense.h"

HansLayer_Dense::HansLayer_Dense(
        int pinputs_dim,
        int pneurons_dim,
        float pweigths_min_init,
        float pweights_max_init,
        float pbias_init) :
        HansLayer(pinputs_dim, pneurons_dim, pweigths_min_init, pweights_max_init, pbias_init)
{
}


HansLayer_Dense::~HansLayer_Dense()
{
}


std::vector<float> HansLayer_Dense::feedforward(std::vector<float> pinput)
{
        std::vector<float> out;
        float current_neuron;

        std::cout << "input = np.array([ ";
        for(int i = 0; i < pinput.size(); i++)
        {
                std::cout << pinput[i] << ", ";
        }
        std::cout << "1]);" << std::endl;

        std::cout << "w_ = np.array([";
        for(int i = 0; i < w.size(); i++)
        {
                std::cout << "[ ";
                for(int j = 0; j < this->w[0].size(); j++)
                {
                        std::cout << w[i][j] << ", ";
                }
                std::cout << "],";
//                if(i < w.size()-1)
//                        std::cout << std::endl;
//                else
//                        std::cout << "]" << std::endl;
                if(i == w.size()-1)
                        std::cout << "]);" << std::endl;
        }

        for(int i = 0; i < neurons_dim; i++)
        {
                current_neuron = 0;
                int j;
                //j from 0 to inputs_dim-1 (range of inputs_dim values)
                for(j = 0; j < inputs_dim; j++)
                {
                        current_neuron += pinput[j]*w[i][j];
                }
                //the bias saved in the additional column (inputs_dim'th value)
                current_neuron += 1*w[i][j];
                out.push_back(current_neuron);
                std::cout << "run ok" << std::endl;
        }
        return out;
}


std::vector<float> HansLayer_Dense::backprop(std::vector<float> pinput_right)
{
        std::vector<float> backproped_inputs;
        return backproped_inputs;
}


void HansLayer_Dense::update_vanilla()
{
        for(int i = 0; i<neurons_dim; i++)
        {
                for(int j = 0; j<inputs_dim+1; j++)
                {
                        w[i][j] += dw[i][j];
                }
        }
}
