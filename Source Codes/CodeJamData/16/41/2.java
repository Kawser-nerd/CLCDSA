import java.io.*;
import java.util.*;

public class A {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "A-large";

  private static void main2() throws IOException {
    int n = in.nextInt();
    int w = 1 << n;
    int r = in.nextInt();
    int p = in.nextInt();
    int s = in.nextInt();
    for (int i = n; i >= 1; i--) {
      int a23 = p-r;
      int a2 = (a23 + s);
      if (a2 % 2 != 0) {
        out.println("IMPOSSIBLE");
        return;
      }
      a2 /= 2;
      
      int a1 = p - a2;
      int a3 = r - a1;
      
      if (a2 < 0 || a1 < 0 || a3 < 0) {
        out.println("IMPOSSIBLE");
        return;
      }
      
      p = a1;
      s = a2;
      r = a3;
    }
    int[] arr = new int[1];
    if (p == 1) arr[0] = 0;
    if (r == 1) arr[0] = 1;
    if (s == 1) arr[0] = 2;
    out.println(construct(arr[0], n));
  }
  
  
  public static char[] xx = {'P', 'R', 'S'};
  public static char[] construct(int winner, int left) {
    if (left == 0) {
      return new char[] {xx[winner]};
    }
    char[] a1 = construct(winner, left-1);
    char[] a2 = construct((winner+1)%3, left-1);
    boolean first = true;
    for (int i = 0; i < a1.length; i++) {
      if (a1[i] != a2[i]) {
        first = a1[i] < a2[i];
        break;
      }
    }
    if (first) {
      char[] ret = new char[1<<left];
      System.arraycopy(a1, 0, ret, 0, a1.length);
      System.arraycopy(a2, 0, ret, a1.length, a1.length);
      return ret;
    } else {
      char[] ret = new char[1<<left];
      System.arraycopy(a2, 0, ret, 0, a1.length);
      System.arraycopy(a1, 0, ret, a1.length, a1.length);
      return ret;
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
