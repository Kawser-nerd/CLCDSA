import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
            int n = in.nextInt();
            long time = in.nextLong();
            long[] t = new long[n];
            long ans = time;
            for (int i = 0; i < n; ++i)
                t[i] = in.nextLong();
            for (int i = 1; i < n; ++i) {
                if (t[i] - t[i - 1] > time)
                    ans += time;
                else
                    ans += t[i] - t[i - 1];
            }
            out.println(ans);
        }

    }
}