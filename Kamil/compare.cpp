#include <stdio.h>

int main(){
    int num1 = 0, num2 = 0;

    printf("Enter the first number : ");
    scanf("%d", &num1);

    printf("Enter the second number : ");
    scanf("%d", &num2);

    printf("%s", num1 > num2 ? "First is bigger than second" : "");
    printf("%s", num1 == num2 ? "Numbers are equal" : "");
    printf("%s", num1 < num2 ? "First is less than second" : "");

}
