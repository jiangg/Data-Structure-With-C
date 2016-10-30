#pragma once
#ifndef Fatal_H
#define Fatal_H
#include<stdio.h>
#include<stdlib.h>

#define FatalError(str) fprintf(stderr, "%s\n",str), exit(1)
#define Error(str) FatalError(str)
#endif // !Fatal_H
