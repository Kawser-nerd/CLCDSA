import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.Comparator;

public class Syrup implements Runnable {
  private static final String NAME = "syrup";

  private  StreamTokenizer in;

  int nextInt() throws Exception {
    in.nextToken();
    return (int) in.nval;
  }

  long nextLong() throws Exception {
    in.nextToken();
    return (long) in.nval;
  }

  @Override
  public void run() {
    try {
      //Scanner in = new Scanner(new File(NAME + ".in"));
      //BufferedReader in = new BufferedReader(new FileReader(new File(NAME + ".in")));
      in = new StreamTokenizer(new BufferedReader(new FileReader(new File(NAME + ".in"))));

      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = nextInt();

      for (int test = 1; test <= tests; test++) {
        //put solution here
        int n = nextInt();
        int k = nextInt();
        P[] p = new P[n];
        for (int i = 0; i < n; i++) {
          p[i] = new P(nextInt(), nextInt());
        }
        Arrays.sort(p);

        long res = 0;
        for (int i = k - 1; i < n; i++) {
          P[] q = new P[i];
          for (int j = 0; j < i; j++) {
            q[j] = p[j];
          }
          Arrays.sort(q, new Comparator<P>() {
            @Override
            public int compare(P o1, P o2) {
              return Long.compare(o2.h * o2.r, o1.h * o1.r);
            }
          });
          long cr = 0;
          for (int j = 0; j < k - 1; j++) {
            cr += 2 * q[j].h * q[j].r;
          }
          cr += 2 * p[i].h * p[i].r + p[i].r * p[i].r;
          if (cr > res) {
            res = cr;
          }
        }
        out.println("Case #" + test + ": " + Math.PI * res);
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  private static class P implements Comparable<P> {
    long r;
    long h;

    public P(long r, long h) {
      this.r = r;
      this.h = h;
    }

    @Override
    public int compareTo(P o) {
      return Long.compare(r, o.r);
    }
  }

  public static void main(String[] args) {
    new Thread(new Syrup()).start();
  }
}