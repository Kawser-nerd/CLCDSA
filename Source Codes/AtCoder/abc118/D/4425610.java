import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
  static long t[];
  static long l[];
  static long h[];

  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);

    String s;
    String sl[];

    int d[] = new int[10];
    int c[] = {999999, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for(int i = 0; i <= 9; i++)
    {
      d[i] = 999999;
    }

    s = r.readLine();
    sl = s.split(" ");
    int n = Integer.parseInt(sl[0]);
    int m = Integer.parseInt(sl[1]);

    s = r.readLine();
    sl = s.split(" ");
    for(int i = 0; i < m; i++)
    {
      int v = Integer.parseInt(sl[i]);
      d[v] = c[v];
    }

    int dp[] = new int[n + 1];
    for(int i = 1; i <= n; i++)
    {
      dp[i] = -999999;
      for(int j = 1; j <= 9; j++)
      {
        if(i - d[j] >= 0 && dp[i - d[j]] >= 0)
        {
          dp[i] = Math.max(dp[i], dp[i - d[j]] + 1);
        }
      }
    }

    int z = dp[n];
    int q = n;
    while(q > 0)
    {
      for(int i = 9; 1 <= i; i--)
      {
        if(q - d[i] >= 0 && dp[q - d[i]] == dp[q] - 1)
        {
          System.out.print(i);
          q -= d[i];
          break;
        }
      }
    }

  }

}