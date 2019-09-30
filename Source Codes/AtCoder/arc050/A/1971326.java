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
    String a = sl[0];
    String b = sl[1];

    System.out.println(a.toLowerCase().equals(b) ? "Yes" : "No");
  }

}