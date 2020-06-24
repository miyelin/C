int * bubble(int lst[]){
  int *l = malloc(10 * sizeof(int *));
  for (int a = 0; a < 10; a++) l[a] = lst[a];
  int i, j, n=intlen(l);

  for (i = 0; i < n; i++){
    for(j = 0; j < n - i; j++){
      if(l[j] > l[j+1]){
        int x = l[j];
        l[j] = l[j + 1];
        l[j + 1] = x;
      }
    }
  }
  return l;
}
