import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long a = in.nextLong(), b = in.nextLong();
            out.println(calc(b) - calc(a - 1));
        }

        private long calc(long n) { // 0??n??????
            char[] cs = Long.toString(n).toCharArray();
            boolean eight = false;
            for (int i = 0; i < cs.length; i++) {
                if (!eight && (cs[i] == '4' || cs[i] == '9')) {
                    eight = true;
                } else if (eight) {
                    cs[i] = '8';
                }
                if (cs[i] >= '9') {
                    cs[i] -= 2;
                } else if (cs[i] >= '4') {
                    cs[i]--;
                }
            }
            long wo8 = Long.parseLong(String.valueOf(cs), 8);
            return n - wo8;

        }

    }
}