import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.LinkedList;

public class Teaching implements Runnable {
  private static final String NAME = "teach";

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
      BufferedReader in = new BufferedReader(new FileReader(new File(NAME + ".in")));

      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = Integer.parseInt(in.readLine());

      for (int test = 1; test <= tests; test++) {
        //put solution here
        String s = in.readLine();
        int res = 0;
        int num = 0;
        LinkedList<Character> a = new LinkedList<Character>();
        for (int i = 0; i < s.length(); i++) {
          char ss = s.charAt(i);
          if (a.isEmpty()) {
            a.addLast(ss);
            num++;
            continue;
          }
          Character c = a.getLast();
          if (c != ss && num < s.length() / 2) {
            a.addLast(ss);
            num++;
          } else {
            a.removeLast();
            res += c == ss ? 10 : 5;
          }
        }
        out.println("Case #" + test + ": " + res);
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Teaching()).start();
  }
}
