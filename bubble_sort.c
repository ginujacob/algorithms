#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static void assert(bool val){
  if (!val) printf("Asserted");
}

static void bubble_sort(int* arrP, size_t sz){
  int i,j,tmp;

  for (i=0; i<sz; ++i){
    for (j=0; j<(sz-i-1); ++j){
      if (arrP[j]>arrP[j+1]){
        tmp=arrP[j];
        arrP[j]=arrP[j+1];
        arrP[j+1]=tmp;
      }
    }
  }
}

static void display_arr(int* arrP, size_t sz){
  size_t cnt;

  for (cnt=0; cnt<sz; ++cnt)
    printf("%d ", arrP[cnt]);
}

int main(int argc, char** argv){
  size_t cnt, sz=argc-1;
  assert(argc>1);
  int* str=malloc(sizeof(int)*sz);
  assert(str!=NULL);

  for (cnt=0; cnt<sz; ++cnt)
    str[cnt]=atoi(argv[cnt+1]);

  bubble_sort(str, sz);
  display_arr(str, sz);
  return 0;
}