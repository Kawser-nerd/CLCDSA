import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class D {

  static final String FILENAME = "D-large";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;

  private void solve() throws IOException {
    int x = sc.nextInt();
    int r = sc.nextInt();
    int c = sc.nextInt();
    if (x >= 7 || x > Math.max(r, c) || (x + 1) / 2 > Math.min(r, c) || (r * c) % x != 0
        || ((x + 1) / 2 == Math.min(r, c) && (x == 4 || (x == 5 && Math.max(r, c) < 6) || x == 6))) {
      out.write("RICHARD");
    } else {
      out.write("GABRIEL");
    }
    out.newLine();
    out.flush();
  }

  private void run() throws IOException {
    sc = new Scanner(new File(IN));
    out = new BufferedWriter(new FileWriter(OUT));
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      out.write("Case #" + i + ": ");
      solve();
    }
    sc.close();
    out.close();
  }

  public static void main(String args[]) throws Exception {
    new D().run();
  }
}
