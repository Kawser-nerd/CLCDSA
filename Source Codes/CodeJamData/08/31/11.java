import java.io.*;
import java.util.*;

public class Solution1
{
  static Scanner In;
  static int N;
  static int P, K, L;
  static int[] F;

  static void testCase(int num)
  {
    P = In.nextInt();
    K = In.nextInt();
    L = In.nextInt();
    F = new int[L];
    for (int i = 0; i < L; i++)
      F[i] = In.nextInt();
    long r = 0, times = 1, key = 0;
    Arrays.sort(F);
    for (int i = L - 1; i >= 0; i--)
    {
      assert (times <= P);
      r += times * F[i];
      if (++key >= K)
      {
        key = 0;
        times++;
      }
    }
    System.out.println(String.format("Case #%d: %d", num, r));
  }

  public static void main(final String[] args)
  {
    try
    {
      String filename = //
        // "A-test.in";
        // "A-small-attempt0.in";
        "A-large.in";
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
