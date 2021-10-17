
#include "tus.h"

int main()
{   
    int error = 0;
    error += tu_readeof();
    error += tu_readchar();
    error += tu_readrange();
    error += tu_readtext();
    error += tu_readint();
    error += tu_readid();
    error += tu_readfloat();

    return error > 0 ? 0 : 1;
}
