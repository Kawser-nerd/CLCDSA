import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{

  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
    
    String s = r.readLine();
    //String[] sl = s.split("[\\s]+");
    int n = s.length();
    
    for(int i = 0; i < n; i++)
    {
      if(s.charAt(i) != '*' && s.charAt(n - 1 - i) != '*' && s.charAt(i) != s.charAt(n - 1 - i))
      {
        System.out.println("NO");
        System.exit(0);
      }
    }

    System.out.println("YES");

  }

}