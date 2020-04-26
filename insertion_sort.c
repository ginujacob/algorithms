#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

static void assert(bool val){
  if (!val)
    printf("asserted\n");
}

static void insertion_sort(int* arrP, int sz){
  int i,j,key;

  for (i=1; i<sz; ++i){
    key=arrP[i];
    j=i-1;
    while (j>=0 && arrP[j]>key){
      arrP[j+1]=arrP[j];
      --j;
    }
    arrP[j+1]=key;
  }
}

int main(int argc, char** argv){
  size_t cnt;
  int* arrP=malloc(sizeof(int)*(argc-1));
  assert(arrP!=NULL);

  for (cnt=0; cnt<argc-1; ++cnt){
    arrP[cnt]=atoi(argv[cnt+1]);
  }

  insertion_sort(arrP, argc-1);

  for (cnt=0; cnt<argc-1; ++cnt){
    printf(" %d", arrP[cnt]);
  }
}

