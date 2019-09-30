import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

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

    s = r.readLine();
    int n = Integer.parseInt(s);

    HashMap<Long, Long> m = new HashMap<>();
    m.put(0L, 1L);

    long a = 0;
    long v = 0;
    s = r.readLine();
    sl = s.split(" ");
    for(int i = 0; i < n; i++)
    {
      v += Long.parseLong(sl[i]);
      Long z = m.get(v);
      if(z != null && z > 0)
      {
        a += z;
      }
      z = m.getOrDefault(v, 0L);
      m.put(v, z + 1);
    }

    System.out.println(a);
  }

}