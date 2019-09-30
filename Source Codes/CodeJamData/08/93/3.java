import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    PrintWriter out = new PrintWriter (System.out);

    int tcnt = in.nextInt ();

    for (int i = 1; i <= tcnt; i++) {
      int r = in.nextInt ();
      int c = in.nextInt ();

      int [][] F = new int [r + 2][c + 2];

      int [][] L1 = new int [r + 2][c + 2];
      int [][] L2 = new int [r + 2][c + 2];
      int [][] R1 = new int [r + 2][c + 2];
      int [][] R2 = new int [r + 2][c + 2];

      for (int a = 1; a <= r; a++)
        for (int b = 1; b <= c; b++)
          F[a][b] = in.nextInt ();

      for (int a = 3; a <= r; a += 3) {
        for (int j = 2; j <= c; j++)
          L1[a][j] = F[a - 1][j - 1] - F[a - 2][j - 1] + L1[a - 3][j];
        for (int j = c - 1; j >= 1; j--)
          L2[a][j] = F[a - 1][j + 1] - F[a - 2][j + 1] + L2[a - 3][j];

      };

      for (int a = r - 2; a >= 1; a -= 3) {
        for (int j = 2; j <= c; j++)
          R1[a][j] = F[a + 1][j - 1] - F[a + 2][j - 1] + R1[a + 3][j];
        for (int j = c - 1; j >= 1; j--)
          R2[a][j] = F[a + 1][j + 1] - F[a + 2][j + 1] + R2[a + 3][j];
      };

      int [] V1 = new int [c + 2], V2 = new int [c + 2];

      int m = (r + 1) / 2;

      if (r % 3 == 2) {
        for (int j = 1; j <= c; j++) {
          V1[j] = L1[m][j];
          V2[j] = L2[m][j];
          if (V1[j] != R1[m][j] || V2[j] != R2[m][j]) {
            for (int k = 1; k <= c; k++)
              System.out.println (V1[j] + " " + V2[j] + " " + R1[m][j] + " " + R2[m][j]);
            System.exit (0);
            throw new RuntimeException ("bug " + r + " " + j);
          };
        };
      } else {
        for (int j = 2; j <= c; j++)
          V1[j] = F[m][j - 1] - L1[m - 1][j] - L1[m + 1][j] - R1[m - 1][j] - R1[m + 1][j];
        for (int j = c - 1; j >= 1; j--)
          V2[j] = F[m][j + 1] - L2[m - 1][j] - L2[m + 1][j] - R2[m - 1][j] - R2[m + 1][j];
      };



      int [] LV = new int [c + 2];
      int [] RV = new int [c + 2];

      for (int a = 3; a <= c; a += 3) {
        LV[a] = V1[a] - V1[a - 1] + LV[a - 3];
      };

      for (int a = c - 2; a >= 1; a -= 3) {
        RV[a] = V2[a] - V2[a + 1] + RV[a + 3];
      };

      int [] V = new int [c + 2];
      int ans = 0;

      if (c % 3 == 0) {
        for (int a = 1; a <= c; a++)
          if (a % 3 == 1) {
            V[a] = RV[a];
          } else
          if (a % 3 == 0) {
            V[a] = LV[a];
          } else {
            V[a] = (a > 1) ? V2[a - 1] : V1[a + 1];
            V[a] -= RV[a - 1] + LV[a + 1];
          }
        for (int a = 1; a <= c; a++)
          ans += V[a];
      } else
      if (c % 3 == 1) {
        for (int a = 1; a <= c; a++)
          if (a % 3 == 2) {
            V[a] = RV[a];
          } else
          if (a % 3 == 0) {
            V[a] = LV[a];
          } else {
            V[a] = (a > 1) ? V2[a - 1] : V1[a + 1];
            V[a] -= LV[a - 1] + RV[a + 1];
          }
        for (int a = 1; a <= c; a++)
          ans += V[a];
      } else {
        for (int a = 1; a <= c; a++)
          if (LV[a] != RV[a]) throw new RuntimeException ("bug");
        ans = 0;
        V[1] = 0; V[2] = V1[2] - V[1];
        for (int a = 3; a <= c; a += 3) {
          V[a] = LV[a];
          V[a + 1] = V1[a + 1] - V[a] - V[a - 1];
          V[a + 2] = V1[a + 2] - V[a + 1] - V[a];
        };
        int cur = 0;
        for (int a = 1; a <= c; a++) {
          if (V[a] != 0 && V[a] != 1) cur -= (int)1e4;
          cur += V[a];
        };
        /*for (int k = 1; k <= c; k++)
          System.out.println (k + " " + V[k]);*/
        ans = Math.max (ans, cur);
        V[1] = 1; V[2] = V1[2] - V[1];
        for (int a = 3; a <= c; a += 3) {
          V[a] = LV[a];
          V[a + 1] = V1[a + 1] - V[a] - V[a - 1];
          V[a + 2] = V1[a + 2] - V[a + 1] - V[a];
        };
        cur = 0;
        for (int a = 1; a <= c; a++) {
          if (V[a] != 0 && V[a] != 1) cur -= (int)1e4;
          cur += V[a];
        };
        /*for (int k = 1; k <= c; k++)
          System.out.println (k + " " + V[k]);*/
        ans = Math.max (ans, cur);
      };

      out.println ("Case #" + i + ": " + ans);
    };

    out.close ();
  };
};