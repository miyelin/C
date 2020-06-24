// this code takes a file and creates an alphabetically ordered linked list for
// employees in a company and their salary and uses binary search to find an
// employee by name and display their salary.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int tolower();
void show();
void main();
typedef struct f{
  char name[20];
  char pay[5];
}  f;

typedef struct l{
  f emp;
  struct l *nxt;
} *l;
l company = NULL;
// determines if a word comes before another in alphabetical order
int alpha(char x[], char y[]){
char xi[20], yi[20];
int i, n, l;
for(n = 0; n < 20; n++){xi[n] = x[n]; yi[n] = y[n];}

  for(i = 0; i < 20; i++){
    if(xi[i] != yi[i]) return xi[i] < yi[i] ? 1 : 0;
    else if (xi[i] == '\0' && yi[i] == '\0') return 2;
    else {
      xi[i] = xi[i+1];
      yi[i] = yi[i+1];
    }
  }
}

int count(l p){
  if(p == NULL) return 0;
  else return 1 + count(p -> nxt);
}

void add(l *p, f nm){
  l new = malloc(sizeof(struct l));
  l c = *p;
  assert(new != NULL);
  new -> emp = nm;
  if(c == NULL || alpha(nm.name, c -> emp.name) == 1){
    new -> nxt = *p;
    *p = new;
  }
   else if(c -> nxt == NULL) c -> nxt = new;
   else add(&c -> nxt, nm);
}

l acc(l p, int n){
  if(n == 0 || p -> nxt == NULL) return p;
  else return acc(p -> nxt, n - 1);
}

void search(l p){
  l a = malloc(sizeof(l));
  char *nm;
  puts("enter 'q' to quit\n");

  do{
    int i=0, m, n = count(p)-1;
    printf("search for a name: ");
    scanf("%s", nm);
    for(int i =0; i < 20; i++) nm[i] = tolower(nm[i]);
    while(i <= n ){
      m = (i + n)/2;
      a = acc(p, m);
      if(alpha(nm, a -> emp.name) == 2) {
        printf("name: %s - salary: %s\n", a -> emp.name, a -> emp.pay);
        break;
      }
      else if(alpha(nm, a -> emp.name) == 1) n = m-1;
      else i = m+1;
    }
    if(i > n && alpha(nm, "q") != 2) printf("not found\n");
  } while(alpha(nm, "q") != 2);
}

void show(l p){
  if(p == NULL)  return;
  else {
    printf("-%s:\t%s.00\n", p -> emp.name, p -> emp.pay);
    return show(p -> nxt);
  }
}

l set(){
  FILE *employees = fopen("employs.txt", "rt");
  int i=0, l=0, n=0;
  char c;
  f fc;

  printf("name\tsalary\n");
  puts("---------------");

  while(!feof(employees)){
    c = fgetc(employees);
  // checks if the char is a number or letter
    if(c < 144 && c > 64) {fc.name[i] = c; i++;}
    else if(c < 58 && c > 47) {fc.pay[n] = c; n++;}
    if(c == '\n') {
      fc.name[i] = '\0';
      fc.pay[n] = '\0';
      l++; i = 0; n = 0;
      add(&company, fc);
    }
  }
  return company;
}

void main(){
  show(set());
  search(company);
}
