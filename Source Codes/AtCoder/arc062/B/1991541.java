import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
    String s = r.readLine();
    int n = s.length();
    
    int[][] a = {{0, -1}, {1, 0}};
    int p = 0;
    
    for(int i = 0; i < n; i++)
    {
      p += a[i % 2][s.charAt(i) == 'g' ? 0 : 1];
    }

    System.out.println(p);

  }
}