int min(int l[], int i){
  int n, x=i;
  for(n = i; n < 10; n++){
    if (l[n] < l[x]) x = n;
  }
  return x;
}

int * selec(int lst[]){
  int *l = malloc(10 * sizeof(int *));
  for (int a = 0; a < 10; a++) l[a] = lst[a];
  int i, x, m;
  for (i = 0; i < intlen(l)-1; i++){
    m = min(l, i);
    x = l[i];
    l[i] = l[m];
    l[m] = x;
  }
  return l;
}
