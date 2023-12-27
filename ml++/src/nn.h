#include <iostream>
#include <vector>
#include "node.h"
#include "layer.h"

class Nn
{
public:
    void addLayer(int position, int size);
    void removeLayer(int position);
private:
    std::vector<Layer> layers;

};
