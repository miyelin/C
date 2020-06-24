#include <stdio.h>

// posx e posy corrigem as posições das coordenadas de 'o' e 'x'
int posx(int x){
    if (x == 2) return 4;
    else if (x == 3) return 7;
    else return 1;
}
int posy(int y){
    if (y == 1) return 0;
    else if (y == 2) return 2;
    else return 4;
}
void tabuleiro(char t[3][5], int tu){
  int i, j, x, y;

  for (i = 0; i < 5; i++){
    printf("\n");
    for (j = 0; j < 9; j++){
      for (y = 1; y <= 3; y++){
        for(x = 1; x <= 3 ; x++){
          if(i == posy(y) && j == posx(x) ){
             printf(" %c ", t[x][y]);
           } else if (i == posy(y) && j == posx(x) && t[x][y] != 'o' && t[x][y] != 'x') printf("   ");
        }
      }
      if (i == 1 || i == 3) printf("-");
      else if(i != 0 && i != 2 && i != 4)  printf(" ");
      if (j == 2 || j == 5) printf("|");

    }
  }
  printf("\n%s\n", tu % 2 == 0 ? "p1: " : "p2: ");
}

void turno(int tu){
  static char t[3][5] = {{"    "}, {"    "}, {"    "}};
  int nx, ny;

  if (t[1][1] != ' ' && t[1][1] == t[2][2] && t[2][2] == t[3][3]||
      t[1][1] == t[1][2] && t[1][2] == t[1][3] && t[1][1] != ' '||
      t[1][1] != ' ' && t[2][1] == t[1][1] && t[2][1] == t[3][1]||
      t[2][2] == t[2][1] && t[2][2] == t[2][3] && t[2][2] != ' '||
      t[2][2] != ' ' && t[2][2] == t[1][2] && t[2][2] == t[3][2]||
      t[3][3] != ' ' && t[2][3] == t[1][3] && t[2][3] == t[3][3]||
      t[3][3] == t[3][1] && t[3][2] == t[3][3] && t[3][2]){
     printf("player %c venceu!", tu % 2 == 0 ? '1' : '2');
     return;
   }
  if (tu == 10) {
    printf("fim\n");
    return;
  }
  else {
    scanf("%d %d", &nx, &ny);
    if (t[nx][ny] != 'o' && t[nx][ny] != 'x' && ny < 5 && nx < 5 && ny > 0 && nx > 0){
      t[nx][ny] = tu % 2 == 0 ? 'o' : 'x';
      tabuleiro(t, tu++);
    }
    else if (nx > 3 || ny > 3 || nx < 0 || ny < 0) printf("fora de escala\n");
    else printf("posição ocupada\n");
  }
  return turno(tu++);
}

void main(){
  printf("~ jogo da velha ~\np1: ");
  turno(1);
  printf("\n");
}
