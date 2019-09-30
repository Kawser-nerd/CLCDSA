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
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int length = in.nextInt();
            if (in.nextInt() > 0) {
                System.out.println(-1);
                return;
            }
            long ans = 0;
            int prev = 0;
            for (int i = 1; i < length; i++) {
                int n = in.nextInt();
                if (n == 0) {
                } else if (n - prev > 1) {
                    System.out.println(-1);
                    return;
                } else if (n - prev == 1) {
                    ans++;
                } else if (n - prev <= 0) {
                    ans += n;
                }
                prev = n;
            }
            System.out.println(ans);
        }

    }
}