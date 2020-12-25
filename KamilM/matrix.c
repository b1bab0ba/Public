#include <stdio.h>
#include <stdlib.h>

double average(int* matrix, size_t size);
int sumOfDiagonals(int* matrix, size_t size);

int main(){
    size_t N = 0;

// invite    
    printf("Please enter SIZE of matrix: ");
    scanf("%zu", &N);

    int* data = (int*) calloc(N, sizeof(*data));
    
    printf("Your matrix has the form: \n");
    for(int index1 = 1; index1 <= N; index1++){
        printf("\t");
        for(int index2 = 1; index2 <= N; index2++){
            printf("A%d%d ", index1, index2);
        }
        printf("\n");
    }
//input 
    for(int index1 = 0; index1 < N; index1++){
        for(int index2 = 0; index2 < N; index2++){
            printf("Enter A%d%d element: ", index1+1, index2+1);
            scanf("%d", data + index1*N + index2);
        }
    }
//processing
    printf("Average is : %.2lf\n", average(data, N));
    printf("Sum of main diagonal elements is : %d\n", sumOfDiagonals(data, N));
}

double average(int* matrix, size_t size){
    long long int sum = 0;
    int nElements = 0;
    for(size_t index1 = 0; index1 < size; index1++){
        for(int index2 = 0; index2 < size; index2++){
           if(*(matrix + index1*size + index2) > *(matrix + index1*size + index1)){
                sum += *(matrix + index1*size + index2);
                ++nElements; 
           }
        }
    }
    return (double)sum / nElements;

}

int sumOfDiagonals(int* matrix, size_t size){
    long long int sum = 0;
    for(size_t index1 = 0; index1 < size; index1++){
        sum += *(matrix + index1*size + index1);
    }
    return sum;
}
