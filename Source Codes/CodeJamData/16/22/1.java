import java.io.*;
import java.util.*;

public class closematch {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "B-large";
  
  public static long bestdiff = 1l<<60;
  public static String b1, b2;
  public static long n1, n2;
  public static void test1(String s1, String s2) {
    String w1 = s1.replaceAll("\\?", "0");
    String w2 = s2.replaceAll("\\?", "9");
    long x1 = Long.parseLong(w1);
    long x2 = Long.parseLong(w2);
    if (Math.abs(x1-x2) < bestdiff) {
      bestdiff = Math.abs(x1-x2);
      b1 = w1;
      b2 = w2;
      n1 = x1;
      n2 = x2;
    } else if (Math.abs(x1-x2) == bestdiff) {
      if (x1 < n1 || (x1 == n1 && x2 < n2)) {
        b1 = w1;
        b2 = w2;
        n1 = x1;
        n2 = x2;
      }
    }
  }
  public static void test2(String s1, String s2) {
    String w1 = s1.replaceAll("\\?", "9");
    String w2 = s2.replaceAll("\\?", "0");
    long x1 = Long.parseLong(w1);
    long x2 = Long.parseLong(w2);
    if (Math.abs(x1-x2) < bestdiff) {
      bestdiff = Math.abs(x1-x2);
      b1 = w1;
      b2 = w2;
      n1 = x1;
      n2 = x2;
    } else if (Math.abs(x1-x2) == bestdiff) {
      if (x1 < n1 || (x1 == n1 && x2 < n2)) {
        b1 = w1;
        b2 = w2;
        n1 = x1;
        n2 = x2;
      }
    }
  }
  
  public static void test(String s1, String s2) {
    test1(s1,s2);
    test2(s1,s2);
  }


  private static void main2() throws IOException {
    char[] a1 = in.next().toCharArray(), a2 = in.next().toCharArray();
    int n = a1.length;
    bestdiff = 1l<<60;
    String s1 = new String(a1), s2 = new String(a2);
    test(s1,s2);
    for (int pref = 0; pref <= n; pref++) {
      boolean ok = true;
      for (int j = 0; j < pref; j++) {
        if (a1[j] != a2[j] && a1[j] != '?' && a2[j] != '?') {
          ok = false;
          break;
        }
      }
      if (!ok) continue;
      char[] x1 = Arrays.copyOf(a1, n);
      char[] x2 = Arrays.copyOf(a2, n);
      for (int i = 0; i < pref; i++) {
        if (a1[i] == '?' && a2[i] == '?') {
          x1[i] = '0';
          x2[i] = '0';
        } else if (a1[i] == '?') {
          x1[i] = a2[i];
        } else if (a2[i] == '?') {
          x2[i] = a1[i];
        }
      }
      if (pref == n) {
        test(new String(x1), new String(x2));
        continue;
      }
      for (int n1 = 0; n1 <= 9; n1++) {
        if (a1[pref] != '?' && a1[pref]-'0' != n1) continue;
        x1[pref] = (char)('0'+n1);
        for (int n2 = 0; n2 <= 9; n2++) {
          if (a2[pref] != '?' && a2[pref]-'0' != n2) continue;
          x2[pref] = (char)('0'+n2);
          test(new String(x1), new String(x2));
        }
      }
    }
    out.println(b1+" "+b2);
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
