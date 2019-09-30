#include <stdio.h>
#include <math.h>

long long int expo[28];

int arbol[20000][2];

int M, V; //nnodos

double bas;

int fila(int celda)
{
  return floor(log(celda)/bas) + 1;
}
/*
int celda_subarbol(int celda, int nivel, int subcelda)
{
  int nuevafila;
  int viejacelda;
  int viejafila;
  viejafila = fila(celda);
  nuevafila = viejafila + nivel;
  viejacelda = celda - expo[viejafila - 1];
  return expo[nuevafila - 1] + viejacelda * subcelda;
}
*/
int numero_movimientos(int celda, int deseado)
{
  int celda_s = celda - 1;
  int total = 0;
  int sub_a = 0;
  int sub_b = 0;
  if ((arbol[celda_s][0] == 2) && (arbol[celda_s][1] != deseado)) return 20000;
  if ((arbol[celda_s][0] == 2) && (arbol[celda_s][1] == deseado)) return 0;
  sub_a = numero_movimientos(celda * 2, deseado);
  sub_b = numero_movimientos(celda * 2 + 1, deseado);
  if ((arbol[celda_s][0] != deseado) || (((arbol[celda_s][0] == deseado) && arbol[celda_s][1] && ((sub_a > 0) || (sub_b > 0)))))
    total = (sub_a <= sub_b)?(sub_a):(sub_b);
  else total = sub_a + sub_b;
  if (total >= 20000) return 20000;
  if ((arbol[celda_s][0] == deseado) && arbol[celda_s][1] && ((sub_a > 0) || (sub_b > 0))) return total + 1;
  else return total;
}

int main(int argc, char *argv[])
{
  bas = log(2);
  int i, j;
  int cases;
  expo[0] = 1;
  for (i = 1; i < 28; i++) expo[i] = expo[i - 1] * 2;;
  scanf("%d\n", &cases);
//  celda_subarbol(3, 1, 1);
  for (i = 1; i <= cases; i++)
  {
    int resultado;
    scanf("%d %d\n", &M, &V);
    for (j = 0; j < (M - 1)/2; j++)
      scanf("%d %d\n", &(arbol[j][0]), &(arbol[j][1]));
    for (j = ((M - 1) / 2); j < M; j++) {
      arbol[j][0] = 2;
      scanf("%d\n", &(arbol[j][1]));
    }
    resultado = numero_movimientos(1, V); 
    if (resultado >= 20000) {
      printf("Case #%d: IMPOSSIBLE\n", i);
    } else {
      printf("Case #%d: %d\n", i, resultado);
    }
  }
  return 0;
}

