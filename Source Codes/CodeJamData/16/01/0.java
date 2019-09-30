import java.io.*;
import java.util.*;

public class countingsheep {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "A-large";

  private static void main2() throws IOException {
    int n = in.nextInt();
    if (n == 0) {
      out.println("INSOMNIA");
      return;
    }
    HashSet<Integer> seen = new HashSet<>();
    int cur = n;
    while (true) {
      int m = cur;
      while (m > 0) {
        seen.add(m%10);
        m /= 10;
      }
      boolean ok = true;
      for (int i = 0; i <= 9; i++) {
        if (!seen.contains(i)) {
          ok = false;
        }
      }
      if (ok) break;
      cur += n;
    }
    
    out.println(cur);
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
