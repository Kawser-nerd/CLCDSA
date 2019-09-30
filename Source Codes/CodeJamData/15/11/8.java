import java.io.*;
import java.util.*;

public class mushroom {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "A-large";

  private static void main2() throws IOException {
    int N = in.nextInt();
    int[] m = new int[N];
    for (int i = 0; i < N; i++) {
      m[i] = in.nextInt();
    }
    int ans1 = 0;
    for (int i = 1; i < N; i++) {
      ans1 += Math.max(0, m[i-1] - m[i]);
    }
    int maxchange = 0;
    for (int i = 1; i < N; i++) {
      maxchange = Math.max(maxchange, m[i-1] - m[i]);
    }
    
    int ans2 = 0;
    for (int i = 1; i < N; i++) {
      ans2 += Math.min(m[i-1], maxchange);
    }
    
    out.println(ans1+" "+ans2);
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
