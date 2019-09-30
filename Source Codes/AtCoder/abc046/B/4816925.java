import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) {


    int n = 0;
    int k = 0;
    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      String[] tmp = br.readLine().split("\\s");
      n = Integer.parseInt(tmp[0]);
      k = Integer.parseInt(tmp[1]);
    } catch(IOException e) {
      e.printStackTrace();
      System.exit(1);
    }

    long quotient = k;
    quotient *= (long)Math.pow(k-1, n-1);
    System.out.print(quotient);
  }
}