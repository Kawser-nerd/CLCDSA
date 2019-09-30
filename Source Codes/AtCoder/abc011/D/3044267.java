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
            int n = in.nextInt(), d = in.nextInt();
            int x = Math.abs(in.nextInt()), y = Math.abs(in.nextInt());
            if (x % d != 0 || y % d != 0) {//??????????
                out.println(0.0);
                return;
            }
            x /= d;
            y /= d;

            double[][] comb = new double[1001][];
            comb[0] = new double[]{1.0};
            for (int i = 1; i <= 1000; i++) {
                comb[i] = new double[i + 1];
                comb[i][0] = comb[i][i] = comb[i - 1][0] / 2.0;
                for (int j = 1; j < i; j++) {
                    comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) / 2.0;
                }
            }

            double ans = 0.0;
            for (int i = 0; i <= n; i++) {
                //System.out.println("THIS IS "+i);
                //System.out.println("x dir: "+(i - x));
                //System.out.println("y dir: "+(n - i - y));
                if (x <= i && y <= (n - i) && (i - x) % 2 == 0 && (n - i - y) % 2 == 0) {
                    //System.out.println("==MATCH==");
                    ans += comb[n][i] * comb[i][(i + x) / 2] * comb[n - i][(n - i + y) / 2];
                }
            }
            out.println(ans);
        }

    }
}