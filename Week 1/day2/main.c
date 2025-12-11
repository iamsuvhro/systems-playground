#include <stdio.h>

int add(int, int);
int sub(int, int);
int mul(int, int);
int divide(int, int);

int main(){
   int a = 10, b = 10;
   printf("Add: %d\n", add(a,b));
   printf("Sub: %d\n", sub(a,b));
   printf("Mul: %d\n", mul(a,b));
   printf("Divide: %d\n", divide(a,b));
   return 0;
}

