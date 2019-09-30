import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int k = s.nextInt();
    int[] as = new int[n];
    long[] asum = new long[n+1];
    asum[0] = 0;
    for (int i = 1; i <= n; i++) {
      long a = s.nextLong();
      asum[i] = asum[i-1] + a;
    }
    if (asum[n] == k) {
      System.out.println(1);
      return;
    }

    long[][] dptable = new long[n+1][n+1];
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        dptable[i][j] = Long.MAX_VALUE;
      }
    }
    dptable[0][0] = 0;
    dptable[1][0] = 0;
    dptable[1][1] = 1;
    for (int i = 2; i <= n; i++) {
      dptable[i][0] = 0;
      for (int j = 1; j <= i; j++) {
        dptable[i][j] = dptable[i-1][j];
        if (dptable[i-1][j-1] < Long.MAX_VALUE) {
          long temp = dptable[i-1][j-1] * asum[i] / asum[i-1] + 1;
          if (temp - dptable[i-1][j-1] <= asum[i] - asum[i-1]) {
            dptable[i][j] = Math.min(dptable[i][j], temp);
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (dptable[n][i+1] > k) {
        System.out.println(i);
        return;
      }
    }
    System.out.println(n);
  }
}