#pragma once
#ifndef Fata_H
#define Fata_H
#include<stdio.h>
#include<stdlib.h>

#define FataError( Str ) fprintf(stderr, "%s\n", Str), exit(1)
#define Error(Str) FataError( Str )

#endif // !Fata_H

