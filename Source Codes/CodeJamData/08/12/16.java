// naive bruteforce

import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class b {
  static final int INF = 10000;
  public static void main(String[] args) throws Throwable {
    Scanner s = new Scanner(new BufferedReader(new FileReader("b.in")));
    PrintStream p = new PrintStream(new FileOutputStream("b.out"));
    int C = s.nextInt();

    for (int i = 1; i <= C; i++) {
      int N = s.nextInt();
      int M = s.nextInt();
      int[][] c = new int[M][N];
      for (int k = 0; k < M; k++) 
        for (int j = 0; j < N; j++)
          c[k][j] = -1;
      for (int j = 0; j < M; j++) {
        int T = s.nextInt();
        for (int k = 0; k < T; k++) {
          int X = s.nextInt(); // one-based
          c[j][X-1] = s.nextInt(); // Y
        }
      }
      int malts = INF;
      String solution = "";
      for (int j = 0; j < pow(2,N); j++) {
        if (isPossible(c,j)) {
          if (numberMalted(j) < malts) {
            malts = numberMalted(j);
            solution = extractSolution(j,N);
          }
        }
      }
      p.println("Case #" + i + ": " + ((malts == INF) ? "IMPOSSIBLE" : solution));
    }
  }
  
  static boolean isPossible(int[][] c, int bin) {
    boolean[] cust = new boolean[c.length];
    Arrays.fill(cust, false);
    for (int i = 0; i < c.length; i++) {
      for (int j = 0; j < c[0].length; j++) {
        if (c[i][j] == (bin >> j) % 2) {
          cust[i] = true;
        }
      }
    }
    for (int i = 0; i < cust.length; i++) {
      if (!cust[i]) return false;
    }
    return true;
  }
  
  static int numberMalted(int j) {
    int res = 0;
    do {
      res += (j % 2);
      j >>= 1;
    } while (j != 0);
    return res;
  }
  
  static String extractSolution(int j, int n) {
    StringBuffer sb = new StringBuffer(""); 
    for (int i = 0; i < n; i++) {
      sb.append((j >> i) % 2);
      if (i != n-1) sb.append(" ");
    }
    return sb.toString();
  }
}