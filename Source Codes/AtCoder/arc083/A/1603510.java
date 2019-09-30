import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ZYCSwing
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
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            int d = in.nextInt();
            int e = in.nextInt();
            int f = in.nextInt();

            int res = 0, sugar = 0;

            for (int va = 0; va <= f; va += 100 * a) {
                for (int vb = 0; va + vb <= f; vb += 100 * b) {
                    int water = va + vb;
                    int upper = water / 100 * e;
                    for (int vc = 0; water + vc <= f && vc <= upper; vc += c) {
                        for (int vd = 0; water + vc + vd <= f && vc + vd <= upper; vd += d) {
                            if (sugar == 0) {
                                sugar = vc + vd;
                                res = water + sugar;
                            } else {
                                if ((vc + vd) * res > sugar * (water + vc + vd)) {
                                    sugar = vc + vd;
                                    res = water + sugar;
                                }
                            }
                        }
                    }
                }
            }

            System.out.println(res + " " + sugar);
        }

    }
}