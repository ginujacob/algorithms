#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void assert(bool val){
  if (!val) printf("Asserted\n");
}

static void display(int* arrP, size_t sz){
  size_t cnt;

  for (cnt=0; cnt<sz; ++cnt)
    printf(" %d", arrP[cnt]);
  printf("\n");
}

static void swap(int* arrP, int idx1, int idx2){
  int tmp;
  assert(arrP!=NULL);
  assert(idx1>=0 && idx2>=0);
  tmp=arrP[idx1];
  arrP[idx1]=arrP[idx2];
  arrP[idx2]=tmp;
}

static int partition(int* arrP, int lo, int hi){
  int i=lo,j=hi+1;

  while (true){
    while (arrP[++i]<arrP[lo])
      if (i>=hi)
        break;
    while (arrP[--j]>arrP[lo])
      if (j<=lo)
        break;
    if (i>j)
      break;
    swap(arrP, i, j);
  }
  swap (arrP, lo, j);
  return j;
}

static void quicksort(int* arrP, int lo, int hi){
  if (lo>=hi)
    return;

  int p=partition(arrP, lo, hi);
  quicksort(arrP, 0, p);
  quicksort(arrP, p+1, hi);
}

int main(int argc, char** argv){
  size_t sz=argc-1;
  size_t cnt;
  assert(sz>0);
  int* arrP=malloc(sizeof(int)*sz);

  for (cnt=0; cnt<sz; ++cnt)
    arrP[cnt]=atoi(argv[cnt+1]);

  quicksort(arrP, 0, sz-1);
  display(arrP, sz);
  return 0;
}