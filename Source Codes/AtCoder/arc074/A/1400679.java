import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author zyc
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int h = in.nextInt(), w = in.nextInt();

            if (h % 3 == 0 || w % 3 == 0) {
                out.println(0);
            } else {
                int res = Integer.MAX_VALUE;

                if (h > 2) res = Math.min(res, w);
                if (w > 2) res = Math.min(res, h);
                int tmp = Math.min(gao(h, w), gao(w, h));
                out.println(Math.min(res, tmp));
            }
        }

        private int gao(int h, int w) {
            int base = h / 3, remain = h % 3;
            int res = Integer.MAX_VALUE;
            for (int i = 0; i <= remain; ++i) {
                int first = w * (base + i), second, third;
                if (w % 2 == 0) {
                    second = third = (h - base - i) * (w / 2);
                    res = Math.min(res, Math.abs(first - second));
                } else {
                    second = (h - base - i) * (w / 2);
                    third = (h - base - i) * w - second;
                    int lower = Math.min(first, second), upper = Math.max(first, third);
                    res = Math.min(res, upper - lower);
                }
            }
            return res;
        }

    }
}