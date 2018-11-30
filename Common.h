#pragma once
#include <stdlib.h>

#define SWAP(TYPE,X,Y) {TYPE temp=X;X=Y;Y=temp;}
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)

typedef int Boolean;
#define TRUE 1
#define FALSE 0
