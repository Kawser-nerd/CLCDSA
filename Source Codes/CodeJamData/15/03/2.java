import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class C {

  static final String FILENAME = "C-large";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;

  static final int[][] MUL = new int[][] { {0, 0, 0, 0, 0}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3},
      {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};

  private int mul(int ijk1, int ijk2) {
    if (ijk1 * ijk2 > 0) {
      return MUL[Math.abs(ijk1)][Math.abs(ijk2)];
    } else {
      return -MUL[Math.abs(ijk1)][Math.abs(ijk2)];
    }
  }

  private int pow(int ijk, long p) {
    p %= 4;
    int cur = 1;
    for (int i = 0; i < p; i++) {
      cur = mul(cur, ijk);
    }
    return cur;
  }

  private int search(int[] list, int ijk) {
    int i;
    for (i = 0; i < list.length; i++) {
      if (list[i] == ijk) {
        break;
      }
    }
    if (i < list.length) {
      return i;
    } else {
      return -1;
    }
  }

  private boolean check(int[] left_m, int[] right_m, long x) {
    final int l = left_m.length;
    int cur = 1;
    int loc = 0;
    int pre = 0;
    for (pre = 0; pre < 4; pre++) {
      int aim;
      for (aim = -4; aim <= 4; aim++) {
        if (mul(cur, aim) == 2) {
          break;
        }
      }
      loc = search(left_m, aim);
      if (loc != -1) {
        break;
      }
      cur = mul(cur, left_m[l - 1]);
      x--;
    }
    if (pre >= 4) {
      return false;
    }
    if (loc == l - 1) {
      cur = 1;
      x--;
    } else {
      cur = right_m[loc + 1];
      int nloc = loc + 1;
      for (nloc = loc + 1; nloc < l; nloc++) {
        if (mul(3, right_m[nloc]) == cur) {
          break;
        }
      }
      if (nloc < l) {
        return true;
      }
      x--;
    }
    for (pre = 0; pre < 4; pre++) {
      int aim;
      for (aim = -4; aim <= 4; aim++) {
        if (mul(cur, aim) == 3) {
          break;
        }
      }
      loc = search(left_m, aim);
      if (loc != -1) {
        break;
      }
      cur = mul(cur, left_m[l - 1]);
      x--;
    }
    return pre < 4 && x >= 0;
  }

  private void solve() throws IOException {
    int l = sc.nextInt();
    long x = sc.nextLong();
    sc.nextLine();
    String ijk = sc.nextLine();
    int[] s = new int[l];
    int[] left_m = new int[l];
    int cur = 1;
    for (int i = 0; i < l; i++) {
      s[i] = (int) (ijk.charAt(i) - 'i' + 2);
      cur = mul(cur, s[i]);
      left_m[i] = cur;
    }
    cur = 1;
    int[] right_m = new int[l];
    for (int i = l - 1; i >= 0; i--) {
      cur = mul(s[i], cur);
      right_m[i] = cur;
    }
    if ((long) l * x < 3 || pow(left_m[l - 1], x) != MUL[MUL[2][3]][4]
        || !check(left_m, right_m, x)) {
      out.write("NO");
    } else {
      out.write("YES");
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
    new C().run();
  }
}
