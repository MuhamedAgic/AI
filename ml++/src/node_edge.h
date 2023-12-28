#pragma once

class Node;

class NodeEdge
{
    public:
        Node* getNextNode();
        void setNextNode(Node* newNode);
        float getBias();
        void setBias(float newBias);
    private:
        Node* nextNode = nullptr;
        float bias = 0.0f;
};
