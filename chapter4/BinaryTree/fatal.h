#pragma once
#include<stdlib.h>
#include<stdio.h>

#define FatalError(str)  fprintf(stderr, "%s\n",str), exit(1)
#define Error(str) FatalError(str)
