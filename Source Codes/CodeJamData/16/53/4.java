import java.io.*;
import java.util.*;

public class rebel {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "C-small-attempt1";
  
  public static long[] x,y,z;

  private static void main2() throws IOException {
    int n = in.nextInt(), s = in.nextInt();
    x = new long[n];
    y = new long[n];
    z = new long[n];
    for (int i = 0; i < n; i++) {
      x[i] = in.nextInt();
      y[i] = in.nextInt();
      z[i] = in.nextInt();
      in.nextInt();
      in.nextInt();
      in.nextInt();
    }
    double[][] dist = new double[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = 
            Math.sqrt(
                (x[i]-x[j])*(x[i]-x[j])+
                (y[i]-y[j])*(y[i]-y[j])+
                (z[i]-z[j])*(z[i]-z[j]));
      }
    }
    
    double lo = 0, hi = 10000;
    for (int iter = 0; iter < 100; iter++) {
      double mid = (lo+hi) / 2;
      int[] queue = new int[n];
      boolean[] vis = new boolean[n];
      int front = 0, back = 0;
      queue[back++] = 0;
      vis[0] = true;
      while (front < back) {
        int cur = queue[front++];
        for (int next = 0; next < n; next++) {
          if (!vis[next] & dist[cur][next] <= mid) {
            vis[next] = true;
            queue[back++] = next;
          }
        }
      }
      if (vis[1]) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    
    out.printf("%.6f\n", lo);
  }

  public static void main(String[] args) throws IOException {
    if (SUBMIT) {
      in = new InputReader(new FileInputStream(new File(NAME + ".in")));
      out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
    } else {
      in = new InputReader(System.in);
      out = new PrintWriter(System.out, true);
    }

    int numCases = in.nextInt();
    for (int test = 1; test <= numCases; test++) {
      out.print("Case #" + test + ": ");
      main2();
    }

    out.close();
    System.exit(0);
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
