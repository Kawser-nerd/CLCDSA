import java.util.*;
import java.lang.*;
import java.math.*;


class box {
  private static BigInteger[] a = new BigInteger[100];
  private static BigInteger[] b = new BigInteger[100];
  private static int[] A = new int[100];
  private static int[] B = new int[100];
  private static BigInteger[][] dp = new BigInteger[100][100];
  private static boolean ZDEBUG = false;

  public static BigInteger do_dp(int i, int j) {
    if (i < 0 || j < 0)
      return BigInteger.ZERO;
    else if (dp[i][j].compareTo(BigInteger.ZERO) >= 0)
      return dp[i][j];

    BigInteger m = do_dp(i - 1, j).max(do_dp(i, j - 1));

  if (A[i] == B[j]) {
    if (ZDEBUG) {
      System.out.println(i + " " + j);
    }
    int k = A[i], ii = i, jj = j;
    BigInteger ci = a[ii], cj = b[jj], t = BigInteger.ZERO, tt;
    while (ii >= 0 && jj >= 0) {
      if (A[ii] == k && B[jj] == k) {
        tt = ci.min(cj).min(a[ii].min(b[jj]));
        t = t.add(tt);
        ci = ci.subtract(tt);
        cj = cj.subtract(tt);
        m = m.max(do_dp(ii - 1, jj - 1).add(t));
        if (ZDEBUG) {
          System.out.println(" " + ii + " " + jj + " " + ci + " " + cj + " " + t + " " + m);
        }
        if (ci.equals(BigInteger.ZERO))
          if (--ii >= 0 && A[ii] == k)
            ci = ci.add(a[ii]);
        if (cj.equals(BigInteger.ZERO))
          if (--jj >= 0 && B[jj] == k)
            cj = cj.add(b[jj]);
      }
      else if (A[ii] != k)
      {
        if (--ii >= 0 && A[ii] == k)
          ci = ci.add(a[ii]);
      }
      else if (B[jj] != k) 
      {
        if (--jj >= 0 && B[jj] == k)
          cj = cj.add(b[jj]);
      }
    }
  }

  dp[i][j] = m;
  if (ZDEBUG) {
    System.out.println("dp[" + i + "][" + j + "] = " + m);
  }
  return m;
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n, m;

    int ncases = in.nextInt();

    for (int caseno = 1; caseno <= ncases; caseno++) {
      for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
          dp[i][j] = BigInteger.ONE.negate();

      n = in.nextInt();
      m = in.nextInt();
      for (int i = 0; i < n; i++) {
        a[i] = in.nextBigInteger();
        A[i] = in.nextInt();
      }
      for (int i = 0; i < m; i++) {
        b[i] = in.nextBigInteger();
        B[i] = in.nextInt();
      }

      System.out.println("Case #" + caseno + ": " + do_dp(n - 1, m - 1));
    }
  }
}
