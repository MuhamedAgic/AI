#include "node_edge.h"

Node* NodeEdge::getNextNode()
{
    return this->nextNode;
}

void NodeEdge::setNextNode(Node *newNode)
{
    this->nextNode = newNode;
}

float NodeEdge::getBias()
{
    return this->bias;
}

void NodeEdge::setBias(float newBias)
{
    this->bias = newBias;
}
