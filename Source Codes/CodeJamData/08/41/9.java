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
      int m = Integer.parseInt(tz.nextToken());
      int v = Integer.parseInt(tz.nextToken());

      int[] g = new int[(m-1)/2];
      boolean [] c = new boolean[(m-1)/2];
      for (int j = 0; j < g.length; j++) {
        StringTokenizer tz2 = new StringTokenizer(in.readLine());
        g[j] = Integer.parseInt(tz2.nextToken());
        c[j] = Integer.parseInt(tz2.nextToken()) == 1;
      }
      int inf = 10000000; 
      int[][] tr = new int[m][2];
      for (int j = g.length; j < m; j++) {
        int l = Integer.parseInt(in.readLine());
        tr[j][l] = 0;
        tr[j][1-l] = inf;
      }

      for (int j = g.length - 1; j >= 0; j--) {
        tr[j][0] = tr[j][1] = inf;
        for (int l = 0; l <= 1; l++) {
          for (int r = 0; r <= 1; r++) {
            int z = tr[2*j+1][l] + tr[2*j+2][r];
            int and = l&r, or = l|r;
            if (g[j] == 1) {
              tr[j][and] = Math.min(tr[j][and], z);
            }
            else {
              tr[j][or] = Math.min(tr[j][or], z);
            }
            if (c[j]) {
              tr[j][and] = Math.min(tr[j][and], z+1);
              tr[j][or] = Math.min(tr[j][or], z+1);
            }
          }
        }
        tr[j][0] = Math.min(tr[j][0], inf);
        tr[j][1] = Math.min(tr[j][1], inf);
      }

      int rr = tr[0][v];
      out.println("Case #" + i + ": " + (rr >= inf ? "IMPOSSIBLE" : "" + rr));
    }

    in.close();
    out.close();
  }
}
