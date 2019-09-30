import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
    String[] sl = r.readLine().split("[\\s]+");
    int n = Integer.parseInt(sl[0]);
    int m = Integer.parseInt(sl[1]);
    int c[] = new int[26];
    int k[] = new int[26];

    String s = r.readLine();
    for(int i = 0; i < n; i++)
    {
      c[(int)(s.charAt(i)) - (int)'A']++;
    }

    s = r.readLine();
    for(int i = 0; i < m; i++)
    {
      k[(int)(s.charAt(i)) - (int)'A']++;
    }

    int ans = 0;
    for(int i = 0; i < 26; i++)
    {
      if(k[i] == 0)
      {
        if(c[i] != 0)
        {
          System.out.println(-1);
          System.exit(0);
        }
      }
      else
      {
        ans = Math.max((c[i] + k[i] - 1) / k[i], ans);
      }
    }

    System.out.println(ans);
  }
}