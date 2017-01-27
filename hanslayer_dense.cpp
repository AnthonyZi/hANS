#include "hanslayer_dense.h"

#ifndef DETAILEDOUTPUT

HansLayer_Dense::HansLayer_Dense(
        int pinputs_dim,
        int pneurons_dim,
        float pweigths_min_init,
        float pweights_max_init,
        float pbias_init,
        std::vector<float> (*pactivation)(std::vector<float>),
        std::vector<float> (*pactivation_derivative)(std::vector<float>),
        int pbackprop_type) :

        HansLayer(pinputs_dim,
        pneurons_dim,
        pweigths_min_init,
        pweights_max_init,
        pbias_init,
        pactivation,
        pactivation_derivative,
        pbackprop_type)
{
}


HansLayer_Dense::~HansLayer_Dense()
{
}


std::vector<float> HansLayer_Dense::feedforward(std::vector<float> pinput)
{
        in = pinput;
        float current_neuron;
        out1.clear();
        out2.clear();

        for(int i = 0; i < neurons_dim; i++)
        {
                /// one neuron is beeing calculated in dependence of the layer before
                current_neuron = 0;
                int j;
                //j from 0 to inputs_dim-1 (range of inputs_dim values)
                for(j = 0; j < inputs_dim; j++)
                {
                        current_neuron += pinput[j]*w[i][j];
                }
                /// one neuron is finished beeing calculated



                //the bias saved in the additional column (inputs_dim'th value)
                current_neuron += w[i][j];

                out1.push_back(current_neuron);
        }

        out2 = activation(out1);

        return out2;
}

//---//type1 is maybe a bit slower because derivations are more computationally expensive
//---//use this for activations like relu
//---std::vector<float> HansLayer_Dense::backprop_type1(std::vector<float> pinput_right)
//---{
//---        std::vector<float> tmp_backprop = activation_derivative(out1);
//---        std::vector<float> backproped;
//---
//---        for(int i = 0; i < pinput_right.size(); i++)
//---        {
//---                tmp_backprop[i] = activation_derivatives[i] * pinput_right[i];
//---        }
//---
//---        //calculation of the weight-derivatives dw
//---        for(int i = 0; i < neurons_dim; i++)
//---        {
//---                for(int j = 0; j< inputs_dim; j++)
//---                {
//---                        dw[i][j] = in[i]*tmp_backprop[j];
//---                }
//---        }
//---
//---        //calculation of the input_derivatives
//---        float current_input_neuron;
//---        for(int i = 0; i < inputs_dim; i++)
//---        {
//---                current_input_neuron = 0;
//---                for(int j = 0; j < neurons_dim; j++)
//---                {
//---                        current_input_neuron += w[i][j] * tmp_backprop[j]
//---                }
//---                backproped.push_back(current_input_neuron);
//---        }
//---
//---        return backproped;
//---}
//---
//---void HansLayer_Dense::backprop_type1_last(std::vector<float> pinput_right)
//---{
//---        std::vector<float> tmp_backprop = activation_derivative(out2);
//---        std::vector<float> backproped;
//---
//---        for(int i = 0; i < pinput_right.size(); i++)
//---        {
//---                tmp_backprop[i] = activation_derivatives[i] * pinput_right[i];
//---        }
//---
//---        //calculation of the weight-derivatives dw
//---        for(int i = 0; i < neurons_dim; i++)
//---        {
//---                for(int j = 0; j< inputs_dim; j++)
//---                {
//---                        dw[i][j] = in[i]*tmp_backprop[j];
//---                }
//---        }
//---
//---        //calculation of the input_derivatives is not needed -> no return
//---}
//---
//---//type2 is a bit faster because the derivation function is most likely actually easier to compute
//---//use this for activations: tanh, sigmoid, elu (activation_derivative gets "activation value" instead of the value that is passed to the activation function)
//---std::vector<float> HansLayer_Dense::backprop_type2(std::vector<float> pinput_right)
//---{
//---        std::vector<float> tmp_backprop = activation_derivative(out2);
//---        std::vector<float> backproped;
//---
//---        for(int i = 0; i < pinput_right.size(); i++)
//---        {
//---                tmp_backprop[i] = activation_derivatives[i] * pinput_right[i];
//---        }
//---
//---        //calculation of the weight-derivatives dw
//---        for(int i = 0; i < neurons_dim; i++)
//---        {
//---                for(int j = 0; j< inputs_dim; j++)
//---                {
//---                        dw[i][j] = in[i]*tmp_backprop[j];
//---                }
//---        }
//---
//---        //calculation of the input_derivatives
//---        float current_input_neuron;
//---        for(int i = 0; i < inputs_dim; i++)
//---        {
//---                current_input_neuron = 0;
//---                for(int j = 0; j < neurons_dim; j++)
//---                {
//---                        current_input_neuron += w[i][j] * tmp_backprop[j]
//---                }
//---                backproped.push_back(current_input_neuron);
//---        }
//---
//---        return backproped;
//---}
//---
//---void HansLayer_Dense::backprop_type2_last(std::vector<float> pinput_right)
//---{
//---        std::vector<float> tmp_backprop = activation_derivative(out2);
//---        std::vector<float> backproped;
//---
//---        for(int i = 0; i < pinput_right.size(); i++)
//---        {
//---                tmp_backprop[i] = activation_derivatives[i] * pinput_right[i];
//---        }
//---
//---        //calculation of the weight-derivatives dw
//---        for(int i = 0; i < neurons_dim; i++)
//---        {
//---                for(int j = 0; j< inputs_dim; j++)
//---                {
//---                        dw[i][j] = in[i]*tmp_backprop[j];
//---                }
//---        }
//---
//---        //calculation of the input_derivatives is not needed -> no return
//---}

std::vector<float> HansLayer_Dense::backprop(std::vector<float> pinput_right)
{
        std::vector<float> tmp_backprop;
        std::vector<float> backproped(inputs_dim);

        switch(backprop_type)
        {
        case 1:
                tmp_backprop = activation_derivative(out1);
                break; 
        case 2:
                tmp_backprop = activation_derivative(out2);
                break;
        default:
                break;
        }

        for(int i = 0; i < neurons_dim; i++)
        {
                tmp_backprop[i] *= pinput_right[i];
        }


        //calculation of the weight-derivatives dw
        {
                int j;
                for(int i = 0; i < neurons_dim; i++)
                {
                        for(j = 0; j< inputs_dim; j++)
                        {
                                dw[i][j] = in[i]*tmp_backprop[j];
                        }
                }
        }


        //calculation of the input_derivatives

        for(int i = 0; i < neurons_dim; i++)
        {
                for(int j = 0; j < inputs_dim; j++)
                {
                        backproped[j] += w[i][j] * tmp_backprop[i];
                }
        }

        return backproped;
}

void HansLayer_Dense::backprop_last(std::vector<float> pinput_right)
{
        std::vector<float> tmp_backprop;
        std::vector<float> backproped;

        switch(backprop_type)
        {
        case 1:
                tmp_backprop = activation_derivative(out1);
                break; 
        case 2:
                tmp_backprop = activation_derivative(out2);
                break;
        default:
                break;
        }

        for(int i = 0; i < neurons_dim; i++)
        {
                tmp_backprop[i] *=  pinput_right[i];
        }

        //calculation of the weight-derivatives dw
        {
                int j;
                for(int i = 0; i < neurons_dim; i++)
                {
                        for(j = 0; j< inputs_dim; j++)
                        {
                                dw[i][j] = tmp_backprop[i]*in[j];
                        }
                }
        }


        //calculation of the input_derivatives is not needed -> no return
}

void HansLayer_Dense::update_vanilla(float plearning_rate)
{
        for(int i = 0; i<neurons_dim; i++)
        {
                for(int j = 0; j<inputs_dim+1; j++)
                {
                        w[i][j] -= dw[i][j] * plearning_rate;
                }
        }
}


#else

#include <iostream>

HansLayer_Dense::HansLayer_Dense(
        int pinputs_dim,
        int pneurons_dim,
        float pweigths_min_init,
        float pweights_max_init,
        float pbias_init,
        std::vector<float> (*pactivation)(std::vector<float>),
        std::vector<float> (*pactivation_derivative)(std::vector<float>),
        int pbackprop_type) :

        HansLayer(pinputs_dim,
        pneurons_dim,
        pweigths_min_init,
        pweights_max_init,
        pbias_init,
        pactivation,
        pactivation_derivative,
        pbackprop_type)
{
}


HansLayer_Dense::~HansLayer_Dense()
{
}


std::vector<float> HansLayer_Dense::feedforward(std::vector<float> pinput)
{
        in = pinput;
        float current_neuron;
        out1.clear();
        out2.clear();

        std::cout << "feedforward-in:" << std::endl;
        for(unsigned int i = 0; i < pinput.size(); i++)
                std::cout << pinput[i] << " ";
        std::cout << std::endl;

        std::cout << "weights:" << std::endl;
        for(int i = 0; i< neurons_dim; i++)
        {
                for(int j = 0; j < inputs_dim; j++)
                {
                        std::cout << w[i][j] << " ";
                }
                std::cout << std::endl;
        }

        for(int i = 0; i < neurons_dim; i++)
        {
                /// one neuron is beeing calculated in dependence of the layer before
                current_neuron = 0;
                int j;
                //j from 0 to inputs_dim-1 (range of inputs_dim values)
                for(j = 0; j < inputs_dim; j++)
                {
                        current_neuron += pinput[j]*w[i][j];
                }
                /// one neuron is finished beeing calculated



                //the bias saved in the additional column (inputs_dim'th value)
                current_neuron += w[i][j];

                out1.push_back(current_neuron);
        }

        out2 = activation(out1);

        std::cout << "feedforward-out:" << std::endl;
        for(unsigned int i = 0; i < out2.size(); i++)
                std::cout << out2[i] << " ";
        std::cout << std::endl << std::endl;

        return out2;
}

//---//type1 is maybe a bit slower because derivations are more computationally expensive
//---//use this for activations like relu
//---std::vector<float> HansLayer_Dense::backprop_type1(std::vector<float> pinput_right)
//---{
//---        std::vector<float> tmp_backprop = activation_derivative(out1);
//---        std::vector<float> backproped;
//---
//---        for(int i = 0; i < pinput_right.size(); i++)
//---        {
//---                tmp_backprop[i] = activation_derivatives[i] * pinput_right[i];
//---        }
//---
//---        //calculation of the weight-derivatives dw
//---        for(int i = 0; i < neurons_dim; i++)
//---        {
//---                for(int j = 0; j< inputs_dim; j++)
//---                {
//---                        dw[i][j] = in[i]*tmp_backprop[j];
//---                }
//---        }
//---
//---        //calculation of the input_derivatives
//---        float current_input_neuron;
//---        for(int i = 0; i < inputs_dim; i++)
//---        {
//---                current_input_neuron = 0;
//---                for(int j = 0; j < neurons_dim; j++)
//---                {
//---                        current_input_neuron += w[i][j] * tmp_backprop[j]
//---                }
//---                backproped.push_back(current_input_neuron);
//---        }
//---
//---        return backproped;
//---}
//---
//---void HansLayer_Dense::backprop_type1_last(std::vector<float> pinput_right)
//---{
//---        std::vector<float> tmp_backprop = activation_derivative(out2);
//---        std::vector<float> backproped;
//---
//---        for(int i = 0; i < pinput_right.size(); i++)
//---        {
//---                tmp_backprop[i] = activation_derivatives[i] * pinput_right[i];
//---        }
//---
//---        //calculation of the weight-derivatives dw
//---        for(int i = 0; i < neurons_dim; i++)
//---        {
//---                for(int j = 0; j< inputs_dim; j++)
//---                {
//---                        dw[i][j] = in[i]*tmp_backprop[j];
//---                }
//---        }
//---
//---        //calculation of the input_derivatives is not needed -> no return
//---}
//---
//---//type2 is a bit faster because the derivation function is most likely actually easier to compute
//---//use this for activations: tanh, sigmoid, elu (activation_derivative gets "activation value" instead of the value that is passed to the activation function)
//---std::vector<float> HansLayer_Dense::backprop_type2(std::vector<float> pinput_right)
//---{
//---        std::vector<float> tmp_backprop = activation_derivative(out2);
//---        std::vector<float> backproped;
//---
//---        for(int i = 0; i < pinput_right.size(); i++)
//---        {
//---                tmp_backprop[i] = activation_derivatives[i] * pinput_right[i];
//---        }
//---
//---        //calculation of the weight-derivatives dw
//---        for(int i = 0; i < neurons_dim; i++)
//---        {
//---                for(int j = 0; j< inputs_dim; j++)
//---                {
//---                        dw[i][j] = in[i]*tmp_backprop[j];
//---                }
//---        }
//---
//---        //calculation of the input_derivatives
//---        float current_input_neuron;
//---        for(int i = 0; i < inputs_dim; i++)
//---        {
//---                current_input_neuron = 0;
//---                for(int j = 0; j < neurons_dim; j++)
//---                {
//---                        current_input_neuron += w[i][j] * tmp_backprop[j]
//---                }
//---                backproped.push_back(current_input_neuron);
//---        }
//---
//---        return backproped;
//---}
//---
//---void HansLayer_Dense::backprop_type2_last(std::vector<float> pinput_right)
//---{
//---        std::vector<float> tmp_backprop = activation_derivative(out2);
//---        std::vector<float> backproped;
//---
//---        for(int i = 0; i < pinput_right.size(); i++)
//---        {
//---                tmp_backprop[i] = activation_derivatives[i] * pinput_right[i];
//---        }
//---
//---        //calculation of the weight-derivatives dw
//---        for(int i = 0; i < neurons_dim; i++)
//---        {
//---                for(int j = 0; j< inputs_dim; j++)
//---                {
//---                        dw[i][j] = in[i]*tmp_backprop[j];
//---                }
//---        }
//---
//---        //calculation of the input_derivatives is not needed -> no return
//---}

std::vector<float> HansLayer_Dense::backprop(std::vector<float> pinput_right)
{
        std::vector<float> tmp_backprop;
        std::vector<float> backproped(inputs_dim);

        
        std::cout << "backpropagation: inputs_dim: " << inputs_dim << " ; neurons_dim: " << neurons_dim << std::endl;

        std::cout << "in:" << std::endl;
        for(unsigned int i = 0; i < in.size(); i++)
                std::cout << in[i] << " ";
        std::cout << std::endl;

        std::cout << "out1:" << std::endl;
        for(unsigned int i = 0; i < out1.size(); i++)
                std::cout << out1[i] << " ";
        std::cout << std::endl;

        std::cout << "out2:" << std::endl;
        for(unsigned int i = 0; i < out2.size(); i++)
                std::cout << out2[i] << " ";
        std::cout << std::endl;

        std::cout << "<-:" << std::endl;
        for(unsigned int i = 0; i < pinput_right.size(); i++)
                std::cout << pinput_right[i] << " ";
        std::cout << std::endl;

        switch(backprop_type)
        {
        case 1:
                tmp_backprop = activation_derivative(out1);
                break; 
        case 2:
                tmp_backprop = activation_derivative(out2);
                break;
        default:
                break;
        }

        std::cout << "z_part1:" << std::endl;;
        for(unsigned int i = 0; i < tmp_backprop.size(); i++)
                std::cout << tmp_backprop[i] << " ";
        std::cout << std::endl;

        for(int i = 0; i < neurons_dim; i++)
        {
                tmp_backprop[i] *= pinput_right[i];
        }

        std::cout << "z:" << std::endl;
        for(unsigned int i = 0; i < tmp_backprop.size(); i++)
                std::cout << tmp_backprop[i] << " ";
        std::cout << std::endl;

        //calculation of the weight-derivatives dw
        {
                std::cout << "dw:" << std::endl;
                int j;
                for(int i = 0; i < neurons_dim; i++)
                {
                        for(j = 0; j< inputs_dim; j++)
                        {
                                dw[i][j] = in[i]*tmp_backprop[j];
                                std::cout << dw[i][j] << " ";
                        }
                        std::cout << std::endl;
                }
                std::cout << std::endl;
        }

        //calculation of the input_derivatives
        for(int i = 0; i < neurons_dim; i++)
        {
                for(int j = 0; j < inputs_dim; j++)
                {
                        backproped[j] += w[i][j] * tmp_backprop[i];
                }
        }

        std::cout << "a[0]-a[i]:" << std::endl;
        for(unsigned int i = 0; i < backproped.size(); i++)
                std::cout << backproped[i] << " ";
        std::cout << std::endl << std::endl;


        return backproped;
}

void HansLayer_Dense::backprop_last(std::vector<float> pinput_right)
{
        std::vector<float> tmp_backprop;
        std::vector<float> backproped;

        std::cout << "backpropagation_last: inputs_dim: " << inputs_dim << " ; neurons_dim: " << neurons_dim << std::endl;

        std::cout << "in:" << std::endl;
        for(unsigned int i = 0; i < in.size(); i++)
                std::cout << in[i] << " ";
        std::cout << std::endl;

        std::cout << "out1:" << std::endl;
        for(unsigned int i = 0; i < out1.size(); i++)
                std::cout << out1[i] << " ";
        std::cout << std::endl;

        std::cout << "out2:" << std::endl;
        for(unsigned int i = 0; i < out2.size(); i++)
                std::cout << out2[i] << " ";
        std::cout << std::endl;

        std::cout << "<- backprop_type: " << backprop_type << std::endl;
        for(unsigned int i = 0; i < pinput_right.size(); i++)
                std::cout << pinput_right[i] << " ";
        std::cout << std::endl;

        switch(backprop_type)
        {
        case 1:
                tmp_backprop = activation_derivative(out1);
                break; 
        case 2:
                tmp_backprop = activation_derivative(out2);
                break;
        default:
                break;
        }

        std::cout << "z_part1:" << std::endl;
        for(unsigned int i = 0; i < tmp_backprop.size(); i++)
                std::cout << tmp_backprop[i] << " ";
        std::cout << std::endl;

        for(int i = 0; i < neurons_dim; i++)
        {
                tmp_backprop[i] *=  pinput_right[i];
        }

        std::cout << "z:" << std::endl;
        for(unsigned int i = 0; i < tmp_backprop.size(); i++)
                std::cout << tmp_backprop[i] << " ";
        std::cout << std::endl;

        //calculation of the weight-derivatives dw
        {
                std::cout << "dw:" << std::endl;
                int j;
                for(int i = 0; i < neurons_dim; i++)
                {
                        for(j = 0; j< inputs_dim; j++)
                        {
                                dw[i][j] = tmp_backprop[i]*in[j];
                                std::cout << dw[i][j] << " ";
                        }
                        std::cout << std::endl;
                }
        }
        std::cout << std::endl << std::endl;

        //calculation of the input_derivatives is not needed -> no return
}

void HansLayer_Dense::update_vanilla(float plearning_rate)
{
        for(int i = 0; i<neurons_dim; i++)
        {
                for(int j = 0; j<inputs_dim+1; j++)
                {
                        w[i][j] -= dw[i][j] * plearning_rate;
                }
        }
}

#endif
