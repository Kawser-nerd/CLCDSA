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
        D1 solver = new D1();
        solver.solve(1, in, out);
        out.close();
    }

    static class D1 {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int ans = 0;
            for (int i = 1; i <= 100000000; i *= 10) {
                if (n / i % 10 == 1) {
                    ans += n % i + 1;
                    // System.out.println(i + ": " + (n % i + 1));
                }
                ans += (n + 8 * i) / (10 * i) * i;
                // System.out.println(i + ": " + ((n + 8 * i) / (10 * i) * i));
            }
            out.println(ans);
        }

    }
}