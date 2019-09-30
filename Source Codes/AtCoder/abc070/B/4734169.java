import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) {

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    String[] tmp = null;
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      tmp = br.readLine().split("\\s");
      a = Integer.parseInt(tmp[0]);
      b = Integer.parseInt(tmp[1]);
      c = Integer.parseInt(tmp[2]);
      d = Integer.parseInt(tmp[3]);
    } catch (IOException e) {
      e.printStackTrace();
      System.exit(1);
    }

    int start = 0;
    int end = 0;

    if (a < c) {
      start = c;
    } else {
      start = a;
    }

    if (b < d) {
      end = b;
    } else {
      end = d;
    }

    int result = end - start;
    if (result < 0) {
      result = 0;
    }
    System.out.print(result);

  }
}