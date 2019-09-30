import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {

  static final String FILENAME = "A-large";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;

  private void solve() throws IOException {
    int ans = 0;
    String[] tmp = sc.nextLine().split(" ");
    int n = Integer.parseInt(tmp[0]);
    int[] p = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
      p[i] = Character.getNumericValue(tmp[1].charAt(i));
    }

    int now = 0;
    for (int i = 0; i < n + 1; i++) {
      if (now >= i) {
        now += p[i];
      } else {
        ans += i - now;
        now = i + p[i];
      }
    }

    out.write(Integer.toString(ans));
    out.newLine();
    out.flush();
  }

  private void run() throws IOException {
    sc = new Scanner(new File(IN));
    out = new BufferedWriter(new FileWriter(OUT));
    int t = Integer.parseInt(sc.nextLine());
    for (int i = 1; i <= t; i++) {
      out.write("Case #" + i + ": ");
      solve();
    }
    sc.close();
    out.close();
  }

  public static void main(String args[]) throws Exception {
    new A().run();
  }
}
