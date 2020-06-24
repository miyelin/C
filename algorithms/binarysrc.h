strcmp();
int srch(char l[10][20], char x[]){
  int i=0, m=4, f=9, t=0;

  while (i <= f){
    if (x[t] == l[m][t]) t++;
    else {
      m = (i + f)/2;
      if(strcmp(x, l[m]) == 0) return m;
      else if (x[t] < l[m][t]) f = m - 1;
      else i = m + 1;
    }
  }
  return -1;
}
