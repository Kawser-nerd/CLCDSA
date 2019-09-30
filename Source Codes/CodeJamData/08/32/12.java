import static java.lang.Math.*;
import java.io.*;
import java.util.*;

public class Solution2
{
  static Scanner In;
  static int N;
  static int M;
  static int[] D;
  static long[][][] Mem;
  static final int MOD = 2 * 3 * 5 * 7;
  static final int[] T = new int[MOD];

  static int gx(int sum)
  {
    if (sum % 2 == 0) return 1;
    if (sum % 3 == 0) return 1;
    if (sum % 5 == 0) return 1;
    if (sum % 7 == 0) return 1;
    return 0;
  }

  static long fx(int delta, int sum, int pos)
  {
    if (pos >= M) return T[abs(delta + sum) % MOD];
    long r = Mem[delta + MOD][sum][pos];
    if (r > 0) return r - 1;
    int sum2 = (sum * 10 + D[pos]) % MOD;
    r = fx(delta, sum2, pos + 1);
    if (pos < M - 1)
    {
      r += fx((delta + sum2) % MOD, 0, pos + 1);
      r += fx((delta - sum2) % MOD, 0, pos + 1);
    }
    Mem[delta + MOD][sum][pos] = r + 1;
    return r;
  }

  static void testCase(int num)
  {
    String s = In.next();
    M = s.length();
    D = new int[M];
    for (int i = 0; i < M; i++)
    {
      D[i] = s.charAt(i) - '0';
      assert (D[i] >= 0 && D[i] <= 9);
    }
    Mem = new long[MOD * 2][MOD][M];
    for (int i = 0; i < MOD; i++)
      T[i] = gx(i);
    long r = fx(0, 0, 0);
    System.out.println(String.format("Case #%d: %d", num, r));
  }

  public static void main(final String[] args)
  {
    try
    {
      String filename = //
        // "B-test.in";
        // "B-small-attempt0.in";
        "B-large.in";
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
