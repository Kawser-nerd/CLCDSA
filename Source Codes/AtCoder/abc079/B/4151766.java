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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            long lucas[] = new long[90];
            lucas[0] = 2;
            lucas[1] = 1;

            for (int i = 2; i <= n; i++) {
                lucas[i] = lucas[i - 2] + lucas[i - 1];
            }

            out.print(lucas[n]);
        }

    }
}