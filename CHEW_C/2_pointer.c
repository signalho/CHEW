#include <stdio.h>

////////POINTER, POINTER ARRAY////////////////////////
int basic_pointer(){
    int a; int b;
    const int* const pa = &a; // make pa const & address of pa const
    //*pa = 3;
    //pa = &b;
    return 0;
}

int change_pointer_array(void){
    int arr[6] = {1,2,3,4,5,6};
    int *ptr = &arr[0]; int *ptr2 = &arr[5];
    int change, change2;
    for (int i=0; i<3; i++){
        change = *(ptr+i); change2 = *(ptr2-i);
        *(ptr2-i) = change; *(ptr+i) = change2;
    }
    for (int j=0; j<6; j++){
        printf("%d \n", arr[j]);
    }
    return 0;
}
///////////////////////////////////////////////////////

//////////DOUBLE POINTER///////////////////////////////
void SwapIntPtr(int **dp1, int **dp2){
    int *temp = *dp1;
    *dp1 = *dp2;
    *dp2 = temp;
}
int SwapIntPrtmain(void){
    int num1=10, num2=20;
    int *ptr1, *ptr2;
    ptr1 = &num1, ptr2 = &num2;
    printf("%d %d \n", *ptr1, *ptr2);
    SwapIntPtr(&ptr1, &ptr2);
    printf("%d %d", *ptr1, *ptr2);
    return 0;
}

void MaxandMin(int *arr, int size, int **mxptr, int **mnptr){
    int *max, *min;
    int i;
    max = min = &arr[0];
    for(i=0;i<size;i++){
        if(*max<arr[i])
            max = &arr[i];
        if(*min>arr[i])
            min = &arr[i];
    }
    *mxptr=max; *mnptr=min;
}
int MaxandMinmain(void){
    int *maxptr, *minptr;
    int arr[5] = {7,1,47,24,3};
    int i;
    int size = sizeof(arr)/sizeof(int);
    MaxandMin(arr, size, &maxptr, &minptr);
    printf("%d %d \n", *maxptr, *minptr);
    return 0;
}
//////////////////////////////////////////////////////////

///////////////ARRAY POINTER VARIABLES////////////////////
int ArrayPointerVariables(void){
    int arr1[2][2]={
        {1,2},{3,4}
    };
    int arr2[3][2]={
        {1,2},{3,4},{5,6}
    };
    printf("%d %d\n", arr2[2][1],(*(arr2+2))[1]);
    printf("%d %d\n", arr2[2][1],*(arr2[2]+1));
    printf("%d %d\n", arr2[2][1],*(*(arr2+2)+1));
    int (*ptr)[2];
    int i;
    ptr = arr1;
    printf("**Show 2,2 arr1 **\n");
    for (i=0;i<2;i++)
        printf("%d %d\n", ptr[i][0],ptr[i][1]);
    ptr = arr2;
    printf("**Show 3,2 arr2 **\n");
    for (i=0;i<3;i++)
        printf("%d %d\n", ptr[i][0],ptr[i][1]);
    return 0;
}
//////////////////////////////////////////////////////////
// various arr[1][0][1]
// 1. (*(arr+1))[0][1]
// 2. (*(*(arr+1)+0))[1]
// 3. *(*(*(arr+1)+0)+1)
// 4. (*(arr[1]+0))[1] ,,, and so on

int main(void){
    basic_pointer();
    change_pointer_array();
    SwapIntPrtmain();
    MaxandMinmain();
    ArrayPointerVariables();
    return 0;
}

