import java.io.*;
import java.util.StringTokenizer;

/**
 * @author nik
 */
public class A {
  public static void main(String[] args) throws Exception {
    BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
    PrintWriter out = new PrintWriter("a.out");

    int N = Integer.parseInt(in.readLine());
    for (int i = 1; i <= N; i++) {
      StringTokenizer tz = new StringTokenizer(in.readLine());
      int n = Integer.parseInt(tz.nextToken());
      long A = Integer.parseInt(tz.nextToken());
      long B = Integer.parseInt(tz.nextToken());
      long C = Integer.parseInt(tz.nextToken());
      long D = Integer.parseInt(tz.nextToken());
      int x0 = Integer.parseInt(tz.nextToken());
      int y0 = Integer.parseInt(tz.nextToken());
      long M = Integer.parseInt(tz.nextToken());
      long x = x0, y = y0;
      long[][] cs = new long[3][3];
      while (n-- > 0) {
        cs[(int) (x % 3)][(int) (y % 3)]++;
        x = (A*x + B) % M;
        y = (C*y + D) % M;
      }

      long r = 0;
      for (int j = 0; j < 3; j++) {
        for (int l = 0; l < 3; l++) {
          long c = cs[j][l];
          r += c * (c - 1) * (c - 2) / 6;
        }
      }
      for (int k1 = 0; k1 < 9; k1++) {
        for (int k2 = k1 + 1; k2 < 9; k2++) {
          for (int k3 = k2 + 1; k3 < 9; k3++) {
            if ((k1 % 3 + k2 % 3 + k3 % 3) % 3 == 0 && (k1 / 3 + k2 / 3 + k3 / 3) % 3 == 0) {
              r += cs[k1 % 3][k1 / 3] * cs[k2 % 3][k2 / 3] * cs[k3 % 3][k3 / 3];
            }
          }
        }
      }
      out.println("Case #" + i + ": " + r);
      }

    in.close();
    out.close();
  }
}
