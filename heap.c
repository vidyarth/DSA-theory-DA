#include <stdio.h>
#include<string.h>
int size = 0;
char name[10][10];
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i) {
      char temp[10];
      swap(&array[i], &array[largest]);
      strcpy(temp,name[i]);
      strcpy(name[i],name[largest]);
      strcpy(name[largest],temp);
      heapify(array, size, largest);
    }
  }
}
void insert(int array[], int newNum) {
  if (size == 0) {
    array[0] = newNum;
    size += 1;
  } else {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num) {
  int i;
  for (i = 0; i < size; i++) {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main() {
  int n,n1;
  printf("Enter no of customers : ");
  scanf("%d",&n);
  int array[n];
  for(int i=0;i<n;i++)
  {
  	
	printf("Enter Name : ");
  	scanf("%s",name[i]);
  	printf("Enter No of products : ");
  	scanf("%d",&n1);
  	insert(array,n1);
  }
  int count=1;
  printf("The order in which the products to be packed are : ");
  for(int i=n-1;i>=0;i--)
  {
  	printf("\n %d) %s -> %d",count++,name[i],array[i]);
  }
  return 0;
  
}
