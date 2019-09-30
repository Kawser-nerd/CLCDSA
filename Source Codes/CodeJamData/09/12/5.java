import java.util.*;
import java.io.*;

public class x {
  static final long inf = (long)1e18;

  static final int [] dx = {0, 1, 0, -1};
  static final int [] dy = {1, 0, -1, 0};
  
  static long [][] S;
  static long [][] W;
  static long [][] T;

  static long edgelen (int j, int k, int nj, int nk, long Start) {
    if (j != nj) {
      if (j / 2 != nj / 2) return 2;
      j /= 2;
      k /= 2;
      long ofs = (Start - T[j][k]) % (S[j][k] + W[j][k]);
      if (ofs < 0) ofs += S[j][k] + W[j][k];
      if (ofs < S[j][k]) return 1; else return S[j][k] + W[j][k] - ofs + 1;
    } else {
      if (k / 2 != nk / 2) return 2;
      //System.err.println (j + " " + nj + " " + k + " " + nk);
      j /= 2;
      k /= 2;
      long ofs = (Start - T[j][k]) % (S[j][k] + W[j][k]);
      if (ofs < 0) ofs += S[j][k] + W[j][k];
      if (ofs >= S[j][k]) return 1; else return S[j][k] - ofs + 1;
    }
  }



  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int N = in.nextInt (), M = in.nextInt ();
      long [][] D = new long [2 * N][2 * M];
      boolean [][] F = new boolean [2 * N][2 * M];
      S = new long [N][M];
      W = new long [N][M];
      T = new long [N][M];

      for (int j = 0; j < N; j++)
        for (int k = 0; k < M; k++) {
          S[j][k] = in.nextInt ();
          W[j][k] = in.nextInt ();
          T[j][k] = in.nextInt ();
        }

      for (int j = 0; j < 2 * N; j++)
        for (int k = 0; k < 2 * M; k++)
          D[j][k] = inf;

      D[2 * N - 1][0] = 0;

      while (true) {
        long MN = inf;
        int mj = -1, mk = -1;
        for (int j = 0; j < 2 * N; j++)
          for (int k = 0; k < 2 * M; k++)
            if (D[j][k] < MN && !F[j][k]) {
              MN = D[j][k];
              mj = j;
              mk = k;
            }
        if (MN == inf) break;
        F[mj][mk] = true;
        for (int i = 0; i < 4; i++) {
          if (mj + dx[i] < 0 || mj + dx[i] >= 2 * N ||
              mk + dy[i] < 0 || mk + dy[i] >= 2 * M) continue;
          long l = edgelen (mj, mk, mj + dx[i], mk + dy[i], MN);
          if (MN + l < D[mj + dx[i]][mk + dy[i]])
            D[mj + dx[i]][mk + dy[i]] = MN + l;
        }
      } 

      //System.out.println (D[0][0] + " " + D[1][1]);

      System.out.println ("Case #" + tt + ": " + D[0][2 * M - 1]);
    };
  };
};