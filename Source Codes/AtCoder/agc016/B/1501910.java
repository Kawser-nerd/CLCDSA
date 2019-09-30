import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.util.OptionalInt;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n);

            int max = Arrays.stream(a).max().getAsInt();

            int cntMax = 0;
            int cntMaxMinus1 = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == max) {
                    cntMax++;
                } else if (a[i] == max - 1) {
                    cntMaxMinus1++;
                } else {
                    out.println("No");
                    return;
                }
            }

            if (cntMaxMinus1 == 0) {
                if (max == n - 1 || 2 * max <= n) {
                    out.println("Yes");
                    return;
                }
            } else {
                if (cntMaxMinus1 < max && 2 * (max - cntMaxMinus1) <= cntMax) {
                    out.println("Yes");
                    return;
                }
            }

            out.println("No");
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

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public int[] nextIntArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
}