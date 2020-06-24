int intlen(int l[]){
  int i=0;
  for(i; l[i] < 65535; i++);
  return i;
}

void print(int l[]){
  int n;
  printf("[ ");
  for (n = 0; n < intlen(l); n++) {
    if (l[n] > 0) printf("%d ", l[n]);
  }
  printf("]\n");
}
