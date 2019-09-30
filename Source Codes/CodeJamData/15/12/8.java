import java.io.*;
import java.util.*;

public class haircut {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "B-large";

  public static long N;
  public static int B;
  public static long[] M;
  private static void main2() throws IOException {
    B = in.nextInt();
    N = in.nextInt();
    M = new long[B];
    for (int i = 0; i < B; i++) {
      M[i] = in.nextInt();
    }
    
    // what time will I get to cut my hair????
    long lo = 0, hi = (long)1e18;
    while (lo < hi) {
      long mid = (lo + hi) / 2;
      long sum = 0;
      for (int i = 0; i < B; i++) {
        sum += mid / M[i] + 1;
      }
      
      if (sum < N) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    
    long cuttime = lo;
    if (cuttime == 0) {
      out.println(N);
      return;
    }
    long left = N;
    for (int i = 0; i < B; i++) {
      left -= (Math.max(0, cuttime - 1)) / M[i] + 1;
    }
    for (int i = 0; i < B; i++) {
      if (cuttime % M[i] == 0) {
        left--;
        if (left == 0) {
          out.println(i+1);
          return;
        }
      }
    }
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
