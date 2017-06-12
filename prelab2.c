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
  int size = atoi(argv[1]);

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

struct data* sort(struct data* input, int size)
{
  int i, key, j;
  for(i=1; i < size; i++)
  {
      key = input[i].x; // 0
      j = i - 1; // 2
      while(j >= 0 && input[j].x > key)
      {
        input[j+1] = input[j];

        j = j-1;
      }

      input[j+1].x = key;
  }

  return input;
}
