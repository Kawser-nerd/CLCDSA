import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main
{
  static int a;
  static int b;
  static int c;

  static int n;
  static int l[];

  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
    PrintWriter out = new PrintWriter(System.out);

    String s;
    String sl[];

    s = r.readLine();
    sl = s.split(" ");

    n = Integer.parseInt(sl[0]);

    s = r.readLine();
    sl = s.split(" ");
    int v = 0;
    for(int i = 0; i < n; i++)
    {
      v += Integer.parseInt(sl[i]) - 1;
    }
    out.println(v);
    out.flush();
  }

}