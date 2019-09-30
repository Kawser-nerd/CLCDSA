import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Erdos implements Runnable {
  private static final String NAME = "erd";

  String off = "";

  int[] find(int[] a, int[] b) {
//    System.out.println(off + "go to:");
//    System.out.println(off + Arrays.toString(a));
//    System.out.println(off + Arrays.toString(b));
    off += "  ";
    int n = a.length;
    if (a[0] != 1 || b[n - 1] != 1) return null;

    if (n == 1) return new int[]{1};

    int[] am = new int[n];
    am[0] = 0;
    for (int i = 1; i < n; i++) {
      am[i] = Math.max(a[i - 1], am[i - 1]);
    }
    int[] bm = new int[n];
    bm[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
      bm[i] = Math.max(b[i + 1], bm[i + 1]);
    }

    for(int i = n - 1; i >= 0; i--) {
      if (a[i] == am[i] + 1 && b[i] == bm[i] + 1) {
//        System.out.println(off + "found: " + i);
        int[] aa = new int[n - 1];
        int[] bb = new int[n - 1];
        int c = 0;
        for (int j = 0; j < n; j++) {
          if (i == j) continue;
          aa[c] = a[j];
          bb[c] = b[j];
          c++;
        }
        int[] res = find(aa, bb);
        if (res != null) {
          int[] r = new int[n];
          for (int j = 0; j < i; j++) r[j] = res[j];
          r[i] = n;
          for (int j = i; j < res.length; j++) r[j + 1] = res[j];

          return r;
        }

      }
    }
    off = off.substring(2);
    return null;
  }

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File(NAME + ".in"));
      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      for (int test = 1; test <= tests; test++) {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) a[i] = in.nextInt();
        for (int i = 0; i < n; i++) b[i] = in.nextInt();

        int[] res = find(a, b);
        if (res == null) throw new IllegalStateException();

        int[] aa = new int[n];
        aa[0] = 1;
        for (int i = 1; i < n; i++) {
          aa[i] = 1;
          for (int j = 0; j < i; j++) {
            if (res[i] > res[j]) aa[i] = Math.max(aa[i], aa[j] + 1);
          }
        }

        int[] bb = new int[n];
        bb[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
          bb[i] = 1;
          for (int j = i + 1; j < n; j++) {
            if (res[i] > res[j]) bb[i] = Math.max(bb[i], bb[j] + 1);
          }
        }
        if (!Arrays.equals(a, aa) || !Arrays.equals(b, bb)) {
          System.out.println("fail!!!" + test);
          throw new IllegalStateException();
        }
        out.print("Case #" + test + ":");
        for (int i = 0; i < n; i++) out.print(" " + res[i]);
        out.println();
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Erdos()).start();
  }

  private class P implements Comparable<P> {
    long d;
    long num;
    int in;

    private P(long d, long num, int in) {
      this.d = d;
      this.num = num;
      this.in = in;
    }

    @Override
    public int compareTo(P p) {
      if (d < p.d) return - 1;
      if (d > p.d) return 1;
      return in - p.in;
    }
  }
}
