#include "activation.h"


float Activation::binaryStep(float input)
{
    if (input < 0)
        return 0;
    return 1;
}
