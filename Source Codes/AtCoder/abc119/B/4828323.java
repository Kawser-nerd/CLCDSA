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
        TaskAtCoder19B solver = new TaskAtCoder19B();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskAtCoder19B {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int N = in.nextInt();
            double res = 0;
            for (int i = 0; i < N; i++) {
                double tmp = Double.parseDouble(in.next());
                if (in.next().equals("BTC"))
                    tmp *= 380000.0;
                res += tmp;
            }
            out.println(res);
        }

    }
}