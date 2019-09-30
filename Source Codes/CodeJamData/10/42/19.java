import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author nik
 */
public class B {
  private static final int inf = 1000000000;
  private int[] tr;
  private int[] co;
  private int[][] cache;

  public B(int[] tr, int[] co, int p) {
    this.tr = tr;
    this.co = co;
    cache = new int[tr.length][p];
    for (int[] ar : cache) {
      Arrays.fill(ar, -1);
    }
  }

  public int sol(int i, int k) {
    if (tr[i] <= k) {
      return 0;
    }
    int i1 = 2*i, i2 = 2*i+1;
    if (i2 >= tr.length) {
      if (tr[i] == k+1) {
        return co[i];
      }
      return inf;
    }
    if (cache[i][k] != -1) return cache[i][k];
    int r1 = co[i]+sol(i1, k+1)+sol(i2, k+1);
    int r2 = sol(i1, k)+sol(i2, k);
    int r = Math.min(r1, r2);
    if (r > inf) {
      r = inf;
    }
    cache[i][k] = r;
    return r;
  }

  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("B-large.in"));
    PrintWriter out = new PrintWriter("b.out");

    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int p = in.nextInt();
      int n = 1 << p;
      int[] m = new int[n];
      for (int i = 0; i < m.length; i++) {
        m[i] = in.nextInt();
      }

      int[] co = new int[n];
      for (int i = 0; i < p; i++) {
        for (int j = 0; j < 1 << (p-i-1); j++) {
          co[(1 << (p-i-1)) + j] = in.nextInt();
        }
      }
      int[] tr = new int[n];
      for (int i = n-1; i >= 1; i--) {
        int i1 = 2*i, i2 = 2*i+1;
        if (i1 >= n) {
          tr[i] = Math.max(p-m[i1-n], p-m[i2-n]);
        }
        else {
          tr[i] = Math.max(tr[i1], tr[i2]);
        }
      }

      int r = new B(tr, co, p).sol(1, 0);
      out.println("Case #" + t + ": " + r);
    }

    in.close();
    out.close();
  }
}
