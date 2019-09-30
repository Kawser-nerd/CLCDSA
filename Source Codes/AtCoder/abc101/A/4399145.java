import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s = br.readLine();
    br.close();
    int p = s.length() - s.replaceAll("\\+","").length();
    int m = s.length() - p;
    System.out.println(p-m);
  }

}