import java.util.*;

public class B {
  static int a, b, k;

  static long doit()
  {
    int i, j;
    long l = 0;
    if (a < 1001 && b < 1001 && k < 1001)
    {
      for (i = 0; i < a; i++)
        for (j = 0; j < b; j++)
          if ((i & j) < k) l++;
    }
    return l;
  }

  public static void main(String arg[]) throws Exception
  {
    int tc, t;
    long ans;
    Scanner s = new Scanner(System.in);
    String line = s.nextLine();
    tc = Integer.parseInt(line);
    for (t = 1; t <= tc; t++)
    {
      line = s.nextLine();
      String ss[] = line.split(" +");
      a = Integer.parseInt(ss[0]);
      b = Integer.parseInt(ss[1]);
      k = Integer.parseInt(ss[2]);
      ans = doit();

      System.out.println("Case #" + t + ": " + ans);
    }
  }
}
