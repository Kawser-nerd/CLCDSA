// D.c
//  C_Grid_Repainting_2
//    - https://abc096.contest.atcoder.jp/tasks/abc096_c#


# include <stdio.h>


#define HSIZE 50
#define WSIZE 50


void solve(int H, int W, char s[HSIZE][WSIZE]);

int main()
{
  //----------------------------------------
  //  Parameter Declaration
  //----------------------------------------
  int H, W;
  char s[HSIZE][WSIZE];
  char output[3];  // "yes" or "no"

  //----------------------------------------
  //  Input Data
  //----------------------------------------
  scanf("%d %d", &H, &W);
  for (int i=0; i<H; i++){
    scanf("%s", s[i]);
  }

  //----------------------------------------
  //  Run Algorithm
  //----------------------------------------
  solve(H, W, s);
  return 0;
}


//--------------------------------------------------------------------------------
//  solve()
//--------------------------------------------------------------------------------
void solve(int H, int W, char s[HSIZE][WSIZE])
{
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      if (s[i][j] == '#'){

        // ?????????
        if ( ( i > 0 ) && (s[i-1][j] == '#') ){
            continue;
        }
        // ?????????
        if ( ( i < H-1 ) && (s[i+1][j] == '#') ){
            continue;
        }

        // ?????????
        if ( ( j > 0 ) && (s[i][j-1] == '#') ){
            continue;
        }
        // ?????????
        if ( (j < W-1) && (s[i][j+1] == '#') ){
            continue;
        }

        printf("%s\n", "No");
        return;
      }
    }
  }
  printf("%s\n", "Yes");
  return;
} ./Main.c: In function ‘main’:
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &H, &W);
   ^
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s[i]);
     ^