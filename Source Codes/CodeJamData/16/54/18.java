import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Go implements Runnable {
  private static final String NAME = "go";

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
      Scanner in = new Scanner(new File(NAME + ".in"));

      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      for (int test = 1; test <= tests; test++) {
        int n = in.nextInt();
        int l = in.nextInt();
        Set<String> s = new HashSet<String>();
        for (int i = 0; i < n; i++) {
          s.add(in.next());
        }
        String b = in.next();
        if (b.contains("0")) {
          throw new IllegalStateException();
        }
        if (s.contains(b)) {
          out.println("Case #" + test + ": IMPOSSIBLE");
        } else {
          String r1 = "";
          String r2 = "";
          for (int i = 0; i < l; i++) {
            r1 += "0?";
          }
          r2 += "0";
          for (int i = 0; i < l - 1; i++) {
            r2 += "01";
          }
          r2 += "0";
          out.println("Case #" + test + ": " + r1 + " " + r2);
        }
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Go()).start();
  }
}
