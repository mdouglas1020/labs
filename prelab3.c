
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int factorial(int num);
int costFunction(int num2);

int main()
{
  int num;
  int num2;
  int cost;
  printf("Please enter in number to get factorial\n");
  scanf("%d",&num);

  int fact = factorial(num);

  printf("The factorial of %d is %d\n", num, fact);

  printf("Enter in number of steps\n");
  scanf("%d", &num2);
  cost = costFunction(num2);

  printf("Cost of that task is %d\n", cost);
  return 0;
}

int factorial(int num)
{
  if(num >= 1)
  {
    return num*factorial(num - 1);
  }
  else
  return 1;
}
int costFunction(int num2)
{
  if(num2 >= 0)
  {
    return costFunction(num2 - 1) +(4 * num2);
  }
  else
  return 0;
}
