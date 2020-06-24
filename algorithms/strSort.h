// this code applies selection sort in a list of strings
strcpy();
strlen();

int min(char l[10][20], int n){
  int i=n, x=n, m=0;

  while (i < 10){
    if(l[i][m] < l[x][m]) x = i;
    else if(l[i][m] == l[x][m]){
      m++;
      if(m >= strlen(l[i]) || m >= strlen(l[x])){
        m = 0;
        i++;
      }
    }
    else i++;
  }
  return x;
}

void sort(char l[10][20]){
  int i, m, c;
  char x[20];

  for (i=0; i < 10; i++){
    m = min(l, i);
    strcpy(x, l[i]);
    strcpy(l[i], l[m]);
    strcpy(l[m], x);
  }
}
