import java.io.*;
import java.util.*;

public class fractiles {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "D-large";

  private static void main2() throws IOException {
    long k = in.nextInt(), c = in.nextInt(), s = in.nextInt();
    if (s*c < k) {
      out.println("IMPOSSIBLE");
      return;
    }
    
    ArrayList<Long> ans = new ArrayList<>();
    for (int i = 0; i < k; i += c) {
      long cur = 0;
      int amt = 0;
      for (int j = i; j < i + c && j < k; j++) {
        cur = cur * k + j;
        amt++;
      }
      while (amt < c) {
        cur *= k;
        amt++;
      }
      ans.add(cur+1);
    }
    for (int i = 0; i < ans.size(); i++) {
      if (i != 0) out.print(" ");
      out.print(ans.get(i));
    }
    out.println();
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
