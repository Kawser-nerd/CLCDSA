import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{

  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
    String s = r.readLine();
    String[] sl = s.split("[\\s]+");
    long R = Long.parseLong(sl[0]);
    long B = Long.parseLong(sl[1]);

    s = r.readLine();
    sl = s.split("[\\s]+");
    long x = Long.parseLong(sl[0]);
    long y = Long.parseLong(sl[1]);

    long rl = 0;
    long rr = Math.min(R, B) + 1;

    while(rr - rl >= 2)
    {
      long rm = (rl + rr) / 2;

      if((R - rm) / (x - 1) + (B - rm) / (y - 1) < rm)
      {
        rr = rm;
      }
      else
      {
        rl = rm;
      }
    }
    System.out.println(rl);

  }

}