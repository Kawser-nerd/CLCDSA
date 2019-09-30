import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author nik
 */
public class A {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("A-large.in"));
    PrintWriter out = new PrintWriter("a.out");

    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int min = Integer.MAX_VALUE;
      int k = in.nextInt();
      in.nextLine();
      int n = 2*k-1;
      char[][] ds = new char[n][n];
      for (int i = 0; i < n; i++) {
        String s = in.nextLine();
        Arrays.fill(ds[i], ' ');
        System.arraycopy(s.toCharArray(), 0, ds[i], 0, s.length());
      }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          int z = 1;
          boolean sym = true;
          while (0 <= i-z && i+z < n && sym) {
            for (int q = 0; q < n; q++) {
              if (ds[i-z][q] != ds[i+z][q] && ds[i-z][q] != ' ' && ds[i+z][q] != ' ') {
                sym = false; break;
              }
            }
            z++;
          }
          z = 1;
          while (0 <= j-z && j+z < n && sym) {
            for (int q = 0; q < n; q++) {
              if (ds[q][j-z] != ds[q][j+z] && ds[q][j-z] != ' ' && ds[q][j+z] != ' ') {
                sym = false; break;
              }
            }
            z++;
          }
          if (sym) {
            int di = Math.max(Math.max(Math.abs(i+j-(k-1)), Math.abs(i+j-(3*k-3))),
                              Math.max(Math.abs(i-j-(k-1)), Math.abs(i-j-(1-k))));
            int r = (di+1)*(di+1)-k*k;
            if (r < min) {
              min = r;
            }
          }
        }
      }

      out.println("Case #" + t + ": " + min);
    }

    in.close();
    out.close();
  }
}
