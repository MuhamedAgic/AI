#pragma once
#include <functional>
#include "activation.h"
#include "node_edge.h"

class NodeEdge;

class Node
{
    public:
        void setValue(float newValue);
        float getValue();
        void setActivation(std::function<float (float)> newActivation);
        std::function<float (float)> getActivation();

    private:
        float value;
        std::function<float (float)> activation;
        NodeEdge edgeToNextNode; // Last layer does not have next node (= null)
};
