import java.io.*;
import java.util.*;

public class Solution3
{
  static Scanner In;
  static int N;
  static long n, m, X, Y, Z;
  static long[] A;
  static long[] B;
  static long[] Mem;
  static final long MOD = 1000000007L;

  static long fx(int pos)
  {
    long r = Mem[pos];
    if (r > 0) return r - 1;
    r = 1;
    long x = B[pos];
    for (int i = pos + 1; i < n; i++)
    {
      if (B[i] <= x) continue;
      r = (r + fx(i)) % MOD;
    }
    r = r % MOD;
    Mem[pos] = r + 1;
    return r;
  }

  static void testCase(int num)
  {
    n = In.nextLong();
    m = In.nextLong();
    X = In.nextLong();
    Y = In.nextLong();
    Z = In.nextLong();
    A = new long[(int) m];
    for (int i = 0; i < m; i++)
      A[i] = In.nextLong();
    B = new long[(int) n];
    for (int i = 0; i < n; i++)
    {
      int j = (int) (i % m);
      B[i] = A[j];
      A[j] = (((X * A[j]) % Z) + ((Y * (i + 1)) % Z)) % Z;
    }
    Mem = new long[(int) n];
    long r = 0;
    for (int i = 0; i < n; i++)
      r = (r + fx(i)) % MOD;
    System.out.println(String.format("Case #%d: %d", num, r));
  }

  public static void main(final String[] args)
  {
    try
    {
      String filename = //
        // "C-test.in";
        "C-small-attempt0.in";
      // "C-large.in";
      In = new Scanner(new File("src/" + filename));
      try
      {
        N = In.nextInt();
        for (int num = 1; num <= N; num++)
          testCase(num);
        if (In.hasNext()) assert (false);
      }
      finally
      {
        In.close();
      }
    }
    catch (Exception e)
    {
      e.printStackTrace();
    }
  }
}
