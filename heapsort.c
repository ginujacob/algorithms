#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  size_t nxt;
  size_t sz;
  int*   arrP;
}heap_t;

static void assert(bool val){
  if (!val) printf("asserted\n");
}

static void swap(int* a, int*b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

static void heapify(heap_t* heapP, size_t idx){
  while (idx){
    if (heapP->arrP[idx]>heapP->arrP[idx/2]){
      swap(&(heapP->arrP[idx]), &(heapP->arrP[idx/2]));
      idx/=2;
    }
    else
     break;
  }
}

static bool ins_in_heap(heap_t* heapP, int val){
  bool stat=false;
  if (heapP->nxt<=heapP->sz){
    heapP->arrP[heapP->nxt]=val;
    heapify(heapP, heapP->nxt);
    heapP->nxt++;
    stat=true;
  }
  return stat;
}

static void heapify_from_top(heap_t* heapP, size_t idx){
  while (idx){
    if ((2*idx+1)<heapP->nxt){
      if (heapP->arrP[2*idx+1]>heapP->arrP[2*idx]){
         if (heapP->arrP[2*idx+1]>heapP->arrP[idx]){
           swap(&heapP->arrP[2*idx+1], &heapP->arrP[idx]);
           idx=2*idx+1;
         }
         else
           break;
      }
      else{
         if (heapP->arrP[2*idx]>heapP->arrP[idx]){
           swap(&heapP->arrP[2*idx], &heapP->arrP[idx]);
           idx=2*idx;
         }
         else
           break;
      }
    }
    else if (2*idx<heapP->nxt){
      if (heapP->arrP[2*idx]>heapP->arrP[idx]){
        swap(&heapP->arrP[2*idx], &heapP->arrP[idx]);
        idx=2*idx;
      }
      else
        break;
    }
    else
      break;
  }
}

static bool delete_from_heap(heap_t* heapP, int* valP){
  bool stat=false;

  if (heapP->nxt>1){
    *valP=heapP->arrP[1];
    //swap and heapify
    swap(&heapP->arrP[1], &heapP->arrP[heapP->nxt-1]);
    heapP->nxt--;
    heapify_from_top(heapP, 1);
    stat=true;
  }
  return stat;
}

int main(int argc, char** argv){
  size_t cnt;
  int val;
  heap_t heap;
  heap.nxt=1;
  heap.sz=argc-1;
  heap.arrP=malloc(sizeof(int)*(heap.sz+1));
  assert(heap.arrP!=NULL);

  for (cnt=0; cnt<heap.sz; ++cnt)
    assert(ins_in_heap(&heap, atoi(argv[cnt+1]))==true);

  while (true){
    if (!delete_from_heap(&heap, &val))
      break;
    printf(" %d", val);
  }
  return 0;
}
