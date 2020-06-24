int * insert(int lst[]){
  int *l = malloc(10 * sizeof(int *));
  for (int a = 0; a < 10; a++) l[a] = lst[a];
  int n, i, j, x;

  for(i = 1; i < intlen(l); i++){
    x = l[i];
    for(j = i -1; j >= 0 && x < l[j]; j--) l[j+1] = l[j];
    l[j+1] = x;
  }
  return l;
}
