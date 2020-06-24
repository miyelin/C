// this code implements different sorting algorithms in a list of integers
// and displays the time taken by each algorithm.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"

void main();

int list[10];
void lst(){
  int i;

  printf("Default list: ");
  for (i = 0; i < 10; i++) {
    list[i] = rand() % 100;
    printf("%d ", list[i]);
  }
  putchar('\n');
}

void timer(int l[]){
  clock_t start, end, total;

  printf("time used by each algorithm: \n");
  start = clock();
  bubble(l);
  end = clock();
  printf("Bubble: %ld\n", end - start);
  start = clock();
  insert(l);
  end = clock();
  printf("insertion: %ld\n", end - start);
  start = clock();
  selec(l);
  end = clock();
  printf("selection: %ld\n", end - start);

}

void view(int list[]){
  int a;
  printf("~ select:\n[ 1-bubble sort 2-insertion sort 3-selection sort 0-all 5-quit ]\n");
  while(1){
  scanf("%d", &a);
  switch(a){
    case 1: print(bubble(list)); break;
    case 2: print(insert(list)); break;
    case 3: print(selec(list)); break;
    case 0: timer(list); break;
    default: printf("please insert a valid option\n"); break;
    case 5: exit(0);
}}
}

void main(){
  lst();
  view(list);
}
