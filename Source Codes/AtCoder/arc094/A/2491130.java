import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);

    String[] sl = r.readLine().split("[\\s]+");
    
    int a = Integer.parseInt(sl[0]);
    int b = Integer.parseInt(sl[1]);
    int c = Integer.parseInt(sl[2]);

    if(a > b)
    {
      int t = a;
      a = b;
      b = t;
    }
    
    if(b > c)
    {
      int t = b;
      b = c;
      c = t;
    }
    
    if(a > b)
    {
      int t = a;
      a = b;
      b = t;
    }
    
    if(a == b && b == c)
    {
      System.out.println(0);
      System.exit(0);
    }
    
    if(b == c)
    {
      if((b - a) % 2 == 0)
      {
        System.out.println((b - a) / 2);
        System.exit(0);
      }
      else
      {
        System.out.println((b - a + 1) / 2 + 1);
        System.exit(0);
      }
    }
    
    if(a == b)
    {
      System.out.println(c - a);
      System.exit(0);
    }

    // a < b < c
    
   int v = 0;
   v += c - b;
   a += c - b;
   b += c - b;
   
   if((b - a) % 2 == 0)
   {
     System.out.println(v + (b - a) / 2);
     System.exit(0);
   }
   else
   {
     System.out.println(v + (b - a + 1) / 2 + 1);
     System.exit(0);
   }

  }
}