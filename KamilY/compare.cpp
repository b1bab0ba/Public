#include <iostream>

int main(){
    int num1 = 0, num2 = 0;

    std::cout << "Enter the first number : ";
    std::cin >> num1;

    std::cout << "Enter the second number : ";
    std::cin >> num2;

    std::cout << (num1 > num2 ? "First is bigger than second\n" : "");
    std::cout << (num1 == num2 ? "Numbers are equal\n" : "");
    std::cout << (num1 < num2 ? "First is less than second\n" : "");

}
