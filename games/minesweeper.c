#include <stdio.h>
#include <stdlib.h>

void main ();
void continue_game ();
// This function counts the number of bombs that surround a spot in the matrix
int counter (int b[10][10], int x, int y) {
  int i, j, c=0;
  if (b[x + 1][y + 1] == 9) c++;
  if (b[x + 1][y] == 9)     c++;
  if (b[x][y + 1] == 9)     c++;
  if (b[x - 1][y - 1] == 9) c++;
  if (b[x - 1][y] == 9)     c++;
  if (b[x][y - 1] == 9)     c++;
  if (b[x + 1][y - 1] == 9) c++;
  if (b[x - 1][y + 1] == 9) c++;
  return c;
}

void mark (int b[10][10], int x, int y, int count) {
  int i, j, r, nx, ny;

  for (i = 0; i < 11; i++) {
    printf("\n");
    for (j = 0; j < 10; j++) {
      if(b[x][y] != 9) b[x][y] = 1;
      if (i == 10 && j != 0 && j < 9) printf("%d ", j);
      if (j == 0 && i < 9) printf("%d ", i);
      if (i > 8 && j < 1) printf("  ");
      if (i == 0 || j == 0 || i == 9 || j == 9) printf("%s", i == 0 || i == 9 ? "=-" : "| ");
      else if (b[i][j] == 9 && b[x][y] == 9) printf("* ");
      else if (b[i][j] == 1 && b[i][j] != 9) printf("%d ", counter(b, i, j));
      else if (i != 10) printf("o ");
    }
  }
  if (b[x][y] == 9) {
    printf("\n  BOOOM!");
    continue_game();
  }
  if(count > 0) printf("\n\nRemaining spots: %d\n", count);
  if (count == 0){
    printf("\n  You win!!\n\t♥~");
    continue_game();
  }

  while (nx > 8 || ny > 8 || nx < 0 || ny < 0) {
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("New coordinate: ");
    scanf("%d%d", &nx, &ny);
    if(nx > 8 || ny > 8 || nx < 0 || ny < 0) printf("out of range");
    if (b[nx][ny] == 1) {
      printf("Error, try other coordinates.\n");
      mark(b, nx, ny, count);
    }
    else continue;
  }
  mark(b, nx, ny, count-1);
}

// This function creates the board with bombs in random places according to the selected level
// l gives the number of spots without bombs, it has to be counted since the random coordinates might be repeated
void show_board(int lvl) {
  int b[10][10], l=0, i, j;

    while (lvl >= 0) {
      b[1 + rand() % 8][1 + rand() % 10] = 9;
      lvl--;
    }
    for (i = 1; i < 9; i++){
      for (j = 1; j < 9; j++){
        if (b[i][j] == 9) l++;
      }
    }
  mark(b, 0, 0, 64-l);
}

void continue_game () {
  char resp;

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Try again? [Y/N]\n");

  do {
    scanf("%c", &resp);
    if (resp == 'Y' || resp == 'y') main();
    else if (resp == 'N' || resp == 'n') exit(0);
    else continue;
  } while (resp != 'N' || resp != 'n');
}


void level_selector () {
  int lvl;

  printf("~ Minesweeper game ~\n[levels: 1- easy 2- medium 3- difficult]\n\n");
  printf("select your level: \n");
  while (lvl < 1 || lvl > 3) {
    scanf("%d", &lvl);
    if (lvl < 1 || lvl > 3) printf("level not selected\n");
  }
  show_board(lvl*20);
}

void main () {
  level_selector();
}
