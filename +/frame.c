// this code builds a frame based on user input
#include <stdio.h>
#define n "."

void mold(int li,int le, int bi, int be){
  int i, j;
  for (i = 0; i < le; i++){
    printf("\n");
    for (j = 0; j < be; j++){
      if ( i == le - li || i == 0 || i == le -1 || i == li-1 ) printf(n);
      if(j == bi - 1 || j == be - bi || j == 0 || j == be -1
        && i != li - 1 && i != 0 && i != le - 1 && i != le - li) printf(n);
      if ( i!=0 && i != le - li && i != le-1 && i != li - 1) printf(" ");
    }
  }
  printf("\n");
}

void main(){
  int li, le, bi, be;
  printf("~frame maker~\n");
  printf("input, respectively, the following measures: external side, external base, internal side and internal base\n");
  printf("  example: 10 10 2 2: ");
  scanf("%d%d%d%d", &le, &be, &li, &bi);
  mold(li, le, bi, be);
}
