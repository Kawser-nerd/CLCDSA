import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.MathContext;
import java.math.RoundingMode;

public class Main {

  private static final long DIVIDER =  (long)Math.pow(10, 9) + 7;

  private static final MathContext MC = new MathContext(0, RoundingMode.HALF_DOWN);


  public static void main(String[] args) {

    int n = 0;
    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      n = Integer.parseInt(br.readLine());
    } catch(IOException e) {
      e.printStackTrace();
      System.exit(1);
    }

    long quotient = 1;
    for (int i = 1; i <= n; i++) {
      quotient = (quotient * i) % DIVIDER;
    }

    System.out.print(quotient);
  }
}