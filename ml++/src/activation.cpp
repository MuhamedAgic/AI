#include "activation.h"
#include <algorithm>
#include <cmath>
#include <math.h>

float Activation::binaryStep(float input)
{
    if (input < 0)
        return 0;
    return 1;
}


float Activation::elu(float input)
{

}

float Activation::leakyRelu(float input)
{
    return std::fmax((0.1 * input), input);
}

float Activation::linear(float input)
{
    return input;
}

float Activation::parametricRelu(float input)
{

}

float Activation::relu(float input)
{
    if (input < 0)
        return 0;
    return input;
}

float Activation::selu(float input)
{

}

float Activation::sigmoid(float input)
{
    return 1 / (1 + std::pow(M_E, -input));
}

float Activation::softmax(float nodeValue, std::vector<float>& inputs)
{
    // e^input / every e^thing summed
    float total = 0;
    for (size_t i = 0; i < inputs.size(); i++)
    {
        total = total + std::pow(M_E, inputs[i]);
    }
    return std::pow(M_E, nodeValue) / total;
}

float Activation::tanh(float input)
{
    return (std::pow(M_E, input) - std::pow(M_E, -input)) /  (std::pow(M_E, input) + std::pow(M_E, -input));
}
