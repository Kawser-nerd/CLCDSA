import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);

    int n = Integer.parseInt(r.readLine());
    int a[] = new int[200001];
    int x[] = new int[200001];

    for(int i = 0; i < n; i++)
    {
      a[i] = Integer.parseInt(r.readLine());
    }

    if(a[0] > 0)
    {
      System.out.println(-1);
      System.exit(0);
    }

    for(int i = 0; i < n; i++)
    {
      if(a[i + 1] - a[i] > 1)
      {
        System.out.println(-1);
        System.exit(0);
      }
    }

    long v = 0;
    for(int i = 1; i <= n; i++)
    {
      if(a[i - 1] + 1 == a[i])
      {
        v++;
      }
      else
      {
        v += a[i];
      }
    }
    System.out.println(v);

  }
}