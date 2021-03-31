#include <iostream>
#include <cassert> 
using namespace std;
 
int CountMax(int* array, int dimension);

int main(){
    int n = 0; 
    
    cout << "Please insert:\n";
    cout << "\n\tdimension n: ";
    cin >> n;
    
    int* matrix = (int*) calloc(n*n, sizeof(*matrix));
    
    assert(matrix);
    
    //cout << "\tArray pointer is:" << matrix << "\n";
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cout << "a" << i + 1 << j + 1 << ": ";
            cin >> *(matrix + i*n + j);
        }
    cout << "\n" << "Output:\n";
    cout << "\n\tYour matrix is: \n";    
    
    cout << "\n";
    for(int i = 0; i < n; i++){
        cout << "\t";
        for(int j = 0; j < n; j++)
            cout << *(matrix + i*n + j) << " ";
        cout << "\n";
    }

    int nMaxes = CountMax(matrix, n);

    cout << "\n\tCount of X elements, that greater than max of Y : " << nMaxes << "\n";
    
    return 0;
}    

int CountMax(int* array, int dimension){
    int result = 0; 
    int maxY = *(array + dimension*dimension/2);
    
    cout << "\n\tY is : ";
    
    for(int index = dimension*dimension/2; index < dimension*dimension; index++){
        cout << *(array + index) << " "; 
        if(*(array + index) > maxY)
            maxY = *(array + index);
    }
    cout << "\n";
    cout << "\n\tMax of Y is : " <<  maxY << "\n";
    cout << "\n\tX is : ";
    
    for(int index = 0; index < dimension*dimension/2; index++){
        cout << *(array + index) << " "; 
        if(*(array + index) > maxY)
            result++;
    }
    cout << "\n";
    return result;
}
