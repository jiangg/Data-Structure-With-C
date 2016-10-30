#pragma once
#include <stdio.h>
#include <stdlib.h>

#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
#define Error( Str )        FatalError( Str )