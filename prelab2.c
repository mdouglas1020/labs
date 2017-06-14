#include <stdio.h>
#include <stdlib.h>

struct data {
  int x;
  int y;
};

struct data* read_data(int size);
void divide_numbers(struct data *array, int size);
struct data* sort(struct data *array, int size);
void print_data(struct data *array, int size);

int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    printf("Incorrect number of arguments\n");
    return 0;
  }

  int i;
  int size = atoi(argv[2], argv[1]);

  struct data* input = read_data(size);

  for(i=0; i < size; i++)
  {
    printf("Enter a data set\n");
    scanf("%d %d", &input[i].x, &input[i].y);
  }

  for(i = 0; i < size; i++)
  {
    printf("data stored in struct is %d and %d\n",input[i].x, input[i].y);
  }

  divide_numbers(input, size);

  struct data* sorted = sort(input, size);

  printf("Sorted data sets I think\n");

  for(i = 0; i < size; i++)
  {
    printf("%d %d\n",sorted[i].x, sorted[i].y);
  }

  free(sorted);
  return 0;
}

struct data* read_data(int size)
{
  struct data* input;

  input = malloc(sizeof(struct data)*size);

  return input;
}

void divide_numbers(struct data* input, int size)
{
  printf("Data Sets divided\n");
  int i;
  for(i = 0; i < size; i++)
  {
    float dif = (float) input[i].x / (float) input[i].y;
    printf("%d / %d = %.2f\n",input[i].x, input[i].y, dif);
  }
}
void swap(int* x, int* y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
struct data* sort(struct data* input, int size)
{
  int i, key, j;
  for(i=0; i < size -1; i++)
  {
    key = i;
    for(j = i+1; j < size; j++)
    {
      if(input[j].x < input[key].x)
      {
        key = j;
      }
    }
    swap(&input[key].x, &input[i].x);
    swap(&input[key].y, &input[i].y);
  }

  return input;
}
