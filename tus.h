#ifndef __TUS_H
#define __TUS_H

#include <stdlib.h> // malloc / free
#include <stdio.h> // printf

#include "../my_parser.h"

// TUs
int tu_clean_captures();
int tu_readrange();
int tu_readeof();
int tu_readchar();
int tu_readtext();
int tu_readint();
int tu_readid();
int tu_readfloat();


#endif
