#pragma once

#include <functional>
#include <vector>
#include "node.h"

class Layer
{
    public:

        // Getters and setters
        std::vector<Node> getNodes();
        void setNodes(std::vector<Node> nodes);

        void appendNodes(int amount, std::function<float (float)> activation);
        void prependNodes(int amount, std::function<float (float)> activation);

    private:
        std::vector<Node> nodes;
};
