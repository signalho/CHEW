#include <stdio.h>
#include "stdiv2.h" // just for fun
#include "intdiv4.h"

int main(void){
    Div val = IntDiv(5,2);
    printf("%d \n", val.quotient);
    printf("%d \n", val.remainder);
    return 0;
}