#pragma once
#include <numbers>
#include <vector>
#include <eigen3/Eigen/Eigen>

class Activation
{
    public:
        float relu(float input);
        float leakyRelu(float input);
        float selu(float input);
        float parametricRelu(float input);
        float elu(float input);
        float binaryStep(float input);
        float linear(float input);
        float sigmoid(float input);
        float tanh(float input);
        float softmax(float nodeValue, std::vector<float>& inputs);
    private:

};
