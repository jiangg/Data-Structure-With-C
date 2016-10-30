#pragma once
#include<stdlib.h>
#include<stdio.h>

#define FatalError(Str) fprintf(stderr,"%s\n",Str), system("pause"), exit(1)
#define Error(Str) FatalError(Str)
