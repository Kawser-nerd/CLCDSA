import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B {

  static final String FILENAME = "B-large";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;

  static final int MAXP = 1000;

  private int divideTime(int[] num, int limit) {
    int time = 0;
    for (int i = limit + 1; i <= MAXP; i++) {
      time += num[i] * ((i - 1) / limit);
    }
    return time;
  }

  private void solve() throws IOException {
    int ans = Integer.MAX_VALUE;
    int d = sc.nextInt();
    int[] num = new int[MAXP + 1];
    for (int i = 0; i < d; i++) {
      num[sc.nextInt()]++;
    }
    for (int limit = 1; limit <= MAXP; limit++) {
      int cur = divideTime(num, limit) + limit;
      if (ans > cur) {
        ans = cur;
      }
    }
    out.write(Integer.toString(ans));
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
    new B().run();
  }
}
