#include <iostream>
#include <cstdlib>

double average(int** matrix, size_t size);
int sumOfDiagonals(int** matrix, size_t size);

int main(){
    size_t N = 0;

// invite    
    std::cout << "Please enter SIZE of matrix: ";
    std::cin >> N;

    int** data  = new int* [N];
    for(int index = 0; index < N; index++)
        data[index] = new int [N];
    
    std::cout << "Your matrix has the form: \n";
    for(int index1 = 1; index1 <= N; index1++){
        std::cout << "\t";
        for(int index2 = 1; index2 <= N; index2++){
            std::cout << "A" << index1 << index2 << " ";
        }
        std::cout << "\n";
    }
//input 
    for(int index1 = 0; index1 < N; index1++){
        for(int index2 = 0; index2 < N; index2++){
            std::cout << "Enter A" <<  index1+1 << index2+1 << "element: ";
            std::cin  >> data[index1][index2];
        }
    }
//processing
    std::cout << "Average is : " << average(data, N) << "\n";
    std::cout << "Sum of main diagonal elements is : " << sumOfDiagonals(data, N) << "\n";

    return 0;
}

double average(int** matrix, size_t size){
    long long int sum = 0;
    int nElements = 0;
    for(size_t index1 = 0; index1 < size; index1++){
        for(int index2 = 0; index2 < size; index2++){
           if(matrix[index1][index2] > matrix[index1][index1]){
                sum += matrix[index1][index2];
                ++nElements; 
           }
        }
    }
    return (double)sum / nElements;

}

int sumOfDiagonals(int** matrix, size_t size){
    long long int sum = 0;
    for(size_t index1 = 0; index1 < size; index1++){
        sum += matrix[index1][index1];
    }
    return sum;
}
