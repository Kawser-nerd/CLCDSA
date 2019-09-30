import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author amotoma3
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long s = in.nextLong();

            if (n < s) {
                out.println(-1);
                return;
            }

            if (n == s) {
                out.println(n + 1);
                return;
            }

            for (long i = 2; i <= 1000000; i++) {
                long tmp = n;
                long sum = 0;
                while (tmp > 0) {
                    sum += tmp % i;
                    tmp /= i;
                }
                if (sum == s) {
                    out.println(i);
                    return;
                }
            }

            long sqrt = (long) Math.sqrt(n);
            if (sqrt * sqrt >= n) sqrt--;
            for (long i = sqrt; i > 0; i--) {
                long b = (n - s) / i + 1;
                if (n / b + n % b == s) {
                    out.println(b);
                    return;
                }
            }

            out.println(-1);
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(nextString());
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
}