import java.util.*;

class Lawnmower
{
  public static void main(String... args)
  {
    Scanner sc = new Scanner(System.in);

    int tests = sc.nextInt();
    for (int test = 1; test <= tests; ++test)
    {
      int n = sc.nextInt();
      int m = sc.nextInt();
      int[][] lawn = new int[n][m];
      int[] rowMaxes = new int[n];
      int[] colMaxes = new int[m];
      boolean possible = true;
      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < m; ++j)
        {
          int a = sc.nextInt();
          lawn[i][j] = a;
          rowMaxes[i] = Math.max(a, rowMaxes[i]);
          colMaxes[j] = Math.max(a, colMaxes[j]);
          if (a > 100)
          {
            possible = false;
          }
        }
      }
      for (int i = 0; i < n & possible; ++i)
      {
        for (int j = 0; j < m & possible; ++j)
        {
          if (lawn[i][j] < rowMaxes[i] && lawn[i][j] < colMaxes[j])
          {
            possible = false;
          }
        }
      }
      System.out.println("Case #" + test + ": " + (possible ? "YES" : "NO"));
    }
  }
}
