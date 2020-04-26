#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

static void assert(bool val){
  if (!val) printf("Asserted");
}

static void selection_sort(int* arrP, size_t sz){
  size_t i,j,pos,tmp;

  for (i=0; i<sz; ++i){
    pos=i;
    for (j=i+1; j<sz; ++j){
      if (arrP[pos]>arrP[j])
        pos=j;
    }
    tmp=arrP[i];
    arrP[i]=arrP[pos];
    arrP[pos]=tmp;
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
  
  selection_sort(str, sz);
  display_arr(str, sz);
  return 0;
}
