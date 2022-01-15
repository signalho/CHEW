#include <stdio.h>

// Make name with capital letters
// be careful with ()
#define PI 3.14
#define PRODUCT(X,Y)   ( (X) * (Y) )
#define CIRCLE_AREA(R) ( PRODUCT ( (R) , (R) ) * PI )
#define DIFF_ABS(X,Y)  ( (X)>(Y) ? (X)-(Y) : (Y)-(X) )

// String Macro
// Simply add # infront of variable
#define STRING_JOB(A, B) #A "'s job is" #B "Right?"

// Add
// Simply add ## between
#define PUT(A, B) A ## B

// Conditional Compilation
#define ADD     1
#define MIN     0
#define HIT_NUM 5

int main(void){
    
#if ADD // if ADD is TRUE?
    // Blablabla
#endif

#ifdef ADD // if ADD is defined?
    // Blablabla
#endif

#ifndef BLA // if BLA is defined?
    // Blablabla
#endif

#if HIT_NUM == 5
    // Blablabla
#elif HIT_NUM == 6
    // Blablabla
#else 
    // Blablabla
#endif

    return 0;
}