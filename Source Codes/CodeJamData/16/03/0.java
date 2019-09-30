import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class coinjam {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "C-large";
  
  private static void main2() throws IOException {
    int n = in.nextInt(), j = in.nextInt();
    char[] s1 = new char[n];
    Arrays.fill(s1, '0');
    s1[n-1] = '1';
    s1[n/2-1] = '1';
    BigInteger[] mult = new BigInteger[11];
    for (int i = 2; i <= 10; i++) {
      mult[i] = new BigInteger(new String(s1), i);
    }
    char[] s2 = new char[n];
    Arrays.fill(s2, '0');
    s2[n/2] = '1';
    BigInteger a1 = mult[2];
    int count = 0;
    for (int i = 1; count < j; i += 2) {
      BigInteger add = new BigInteger(new String(s2), 2);
      add = add.add(new BigInteger(""+i));
      BigInteger result = add.multiply(a1);
      out.print(result.toString(2));
      for (int k = 2; k <= 10; k++) out.print(" "+mult[k]);
      count++;
      out.println();
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
      out.println("Case #" + test + ":");
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
