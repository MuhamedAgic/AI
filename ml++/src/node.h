#pragma once
#include <functional>
#include "activation.h"

class Node
{
    public:

        // Getters and setters
        void setValue(float newValue);
        float getValue();
        void setActivation(std::function<float (float)> newActivation);
        std::function<float (float)> getActivation();

    private:
        float value;
        std::function<float (float)> activation;
};
