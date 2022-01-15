#include <stdio.h>

//CHALLENGE 1
void func(int num1, int num2){
    int i, j, result;
    if (num2>num1){
        int n1, n2;
        n1 = num2, n2 = num1;
        num1 = n1, num2 = n2;
    }
    if (num1>num2){
        for (i=num2; i<=num1; i++){
            for (j=1; j<=i; j++){
                result = i*j;
                printf("%d \n", result);
            }
        }
    }
}
int CH1_1(void){
    func(3,5);
    return 0;
}

int CH1_2(void){
    int coin=3500, left, ssu, ccn, coke;
    const int ssu_cst=500, ccn_cst=700, coke_cst=400;
    for(coke=1;coke<(coin/coke_cst);coke++){
        for(ssu=1;ssu<(coin/ssu_cst);ssu++){
            for(ccn=1;ccn<(coin/ccn_cst);ccn++){
                if(coin == ssu*ssu_cst+ccn*ccn_cst+coke*coke_cst){
                    printf("%d %d %d \n", ssu, ccn, coke);
                }
            }
        }
    }
    return 0;
}

int resursive(int n){
    if (n==0)
        return 1;
    else {
        return 2*resursive(n-1);
    }
}
int CH1_3(void){
    printf("%d \n", resursive(4));
    return 0;
}


//CHALLENGE 2
void bubblesort(int arr[], int len){
    int i, j;
    int temp;
    for (i=0; i<len-1;i++){
        for (j=0; j<len-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void desort(int arr[], int len){
    int i, j;
    int temp;
    for (i=len; i>=0;i--){
        for (j=len; j>=len-i;j--){
            if (arr[j-1]<arr[j]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}
int CH2_1(void){
    int arr[] = {3,2,4,1,7,8,1};
    int i, len;
    len = sizeof(arr)/sizeof(int);
    bubblesort(arr, len);
    for (i=0;i<len; i++)
        printf("%d", arr[i]);
    printf("\n");
    desort(arr, len);
    for (i=0;i<len; i++)
        printf("%d", arr[i]);
    return 0;
}

//CHALLENGE 3
void Arr2Drot(int (*arr)[4],int (*arr2)[4], int column){
    int i, j;
    for(i=0; i<column; i++){
        for(j=0; j<4; j++){
            arr2[j][3-i] = arr[i][j];
        }
    }
}
void PrintArr(int (*arr)[4], int column){
    int i, j;
    for(i=0; i<column; i++){
        for(j=0; j<4; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}
int CH3_1(void){
    int arr2d[4][4] = {
        {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}
    };
    int arr2d2[4][4];
    Arr2Drot(arr2d, arr2d2, sizeof(arr2d)/sizeof(arr2d[0]));
    PrintArr(arr2d2, sizeof(arr2d)/sizeof(arr2d[0]));
    Arr2Drot(arr2d2, arr2d, sizeof(arr2d)/sizeof(arr2d[0]));
    PrintArr(arr2d, sizeof(arr2d)/sizeof(arr2d[0]));
    Arr2Drot(arr2d, arr2d2, sizeof(arr2d)/sizeof(arr2d[0]));
    PrintArr(arr2d2, sizeof(arr2d)/sizeof(arr2d[0]));
    return 0;
}
int CH3_2(void){
    int n = 6;
    int sum = n * n;
    int arr2d[n][n];
    int i, j;
    int k = 1;
    while(k<sum){ 
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                arr2d[i][j] = k;
            }
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            printf("%d ", arr2d[i][j]);
        printf("\n");
    }
    printf("\n");

    return 0;
}


//CHALLENGE 4



int main(void){
    int challenge_num;
    challenge_num = 3;
    switch(challenge_num){
        case 1:
            printf("CHALLENGE 1\n");
            CH1_1(); CH1_2(); CH1_3();
            break;
        case 2:
            printf("CHALLENGE 2\n");
            CH2_1();
            break;
        case 3:
            printf("CHALLENGE 3\n");
            // CH3_1();
            CH3_2();
            break;
        case 4:
            printf("CHALLENGE 4\n");
            break;
        default:
            printf("gogogo");
    }
    return 0;
}