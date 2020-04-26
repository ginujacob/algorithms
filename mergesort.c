#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

static void assert(bool val){
  if (!val) printf("Asserted\n");
}

static void display(int* arrP, size_t sz, const char* strP){
  size_t cnt;
  printf("%s", strP);

  for (cnt=0; cnt<sz; ++cnt)
    printf(" %d", arrP[cnt]);
  printf("\n");
}

static void merge(int* arrP, int* auxP, int lo, int mid, int hi){
  int cnt, i=lo, j=mid+1;

  for (cnt=lo; cnt<=hi; ++cnt)
    auxP[cnt]=arrP[cnt];

  for (cnt=lo; cnt<=hi; ++cnt){
    if (i>mid)                arrP[cnt]=auxP[j++];
    else if (j>hi)            arrP[cnt]=auxP[i++];
    else if (auxP[i]<auxP[j]) arrP[cnt]=auxP[i++];
    else                      arrP[cnt]=auxP[j++];
  }
}

static void sort(int* arrP, int*auxP, int lo, int hi){
  int mid=lo+(hi-lo)/2;

  if (lo>=hi) return;
  sort(arrP, auxP, lo, mid);
  sort(arrP, auxP, mid+1, hi);
  merge(arrP, auxP, lo, mid, hi);
}

static void mergesort(int* arrP, int sz){
  assert(arrP!=NULL);
  int* auxP=malloc(sizeof(int)*sz);
  sort(arrP, auxP, 0, sz-1);
}

int main(int argc, char** argv){
  int sz=argc-1;
  int cnt;
  assert(sz>0);
  int* arrP=malloc(sizeof(int)*sz);
  assert(arrP!=NULL);

  for (cnt=0; cnt<sz; ++cnt)
    arrP[cnt]=atoi(argv[cnt+1]);

  display(arrP, sz, "unsorted:");
  mergesort(arrP, sz);
  display(arrP, sz, "merge sorted:");
  return 0;
}