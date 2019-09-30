import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int r = in.nextInt (), c = in.nextInt (), f = in.nextInt ();
      char [][] D = new char[r][];
      for (int i = 0; i < r; i++) 
        D[i] = in.next ().toCharArray ();


      int [][][][] A = new int [r][c][c][c];

      for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
          for (int k = 0; k < c; k++)
            Arrays.fill (A[i][j][k], 30000);

      A[0][0][0][0] = 0;

      for (int i = 0; i < r - 1; i++)
        for (int x = 0; x < c; x++)
          for (int y = x; y < c; y++)
          for (int k = 0; k < c; k++) if (A[i][x][y][k] < 30000) {
            
            int lg = k;
            for (int l = k - 1; l >= 0; l--)
              if (D[i + 1][l] == '#' && 
                  (D[i][l] != '#' || (l >= x && l <= y))) lg = l; else break;

            int rg = k;
            for (int l = k + 1; l < c; l++)
              if (D[i + 1][l] == '#' && 
                  (D[i][l] != '#' || (l >= x && l <= y))) rg = l; else break;
           
            for (int l = Math.max (lg - 1, 0); l <= Math.min (rg + 1, c - 1); l++)
              if (D[i][l] != '#' || (l >= x && l <= y)) {
                for (int mx = Math.min (l, lg); mx <= l; mx++) {
                  int my = l;

                  int cnt = 0;
                  boolean ok = true;

                  cnt = my - mx + 1;
                  if (mx < lg || my > rg) --cnt;

                  if (l == lg - 1)
                    ok &= my == l;
                  else
                  if (l == lg)
                    ok &= (lg != rg) && my == l;
                  else
                  if (l == rg + 1)
                    ok &= mx == l;
                  else
                  if (l == rg)
                    ok &= (lg != rg) && (mx == l);
                  else
                    ok &= (my == l) || (mx == l);

                  if (ok) {
                    int fall = 1;
                    for (int a = i + 2; a < r; a++)
                      if (D[a][l] != '#') ++fall; else break;

                    if (fall <= f) {

                      int ni, nx, ny, nk;

                      if (fall == 1) {
                        ni = i + 1;
                        nx = mx;
                        ny = my;
                        nk = l;
                      } else {
                        ni = i + fall;
                        nx = l;
                        ny = l;
                        nk = l;
                      }

                      //System.out.println (i + " " + j + " " + k + " -> " + ni + " " + nj + " " + nk);
                      A[ni][nx][ny][nk] = Math.min (A[ni][nx][ny][nk], A[i][x][y][k] + cnt);
                    }
                  }
                }

                for (int my = l; my <= Math.max (l, rg); my++) {
                  int mx = l;

                  int cnt = 0;
                  boolean ok = true;

                  cnt = my - mx + 1;
                  if (mx < lg || my > rg) --cnt;

                  if (l == lg - 1)
                    ok &= my == l;
                  else
                  if (l == lg)
                    ok &= (lg != rg) && my == l;
                  else
                  if (l == rg + 1)
                    ok &= mx == l;
                  else
                  if (l == rg)
                    ok &= (lg != rg) && (mx == l);
                  else
                    ok &= (my == l) || (mx == l);

                  if (ok) {
                    int fall = 1;
                    for (int a = i + 2; a < r; a++)
                      if (D[a][l] != '#') ++fall; else break;

                    if (fall <= f) {

                      int ni, nx, ny, nk;

                      if (fall == 1) {
                        ni = i + 1;
                        nx = mx;
                        ny = my;
                        nk = l;
                      } else {
                        ni = i + fall;
                        nx = l;
                        ny = l;
                        nk = l;
                      }

                      //System.out.println (i + " " + j + " " + k + " -> " + ni + " " + nj + " " + nk);
                      A[ni][nx][ny][nk] = Math.min (A[ni][nx][ny][nk], A[i][x][y][k] + cnt);
                    }
                  }
                }
              }

          }

      int ans = 30000;

      for (int x = 0; x < c; x++)
        for (int y = x; y < c; y++)
          for (int k = 0; k < c; k++)
            ans = Math.min (ans, A[r - 1][x][y][k]);
        

      System.out.print ("Case #" + tt + ": ");
      if (ans == 30000) System.out.println ("No"); else
        System.out.println ("Yes " + ans);
    };
  };
};