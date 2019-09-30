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
            int n = in.nextInt();
            int z = in.nextInt();
            int w = in.nextInt();
            int[] a = in.nextIntArray(n);

            int[] d = new int[n];
            for (int i = 0; i < n; i++) {
                d[i] = Math.abs(a[i] - a[n - 1]);
            }

            int[] dp1 = new int[n];
            int[] dp2 = new int[n];
            for (int i = n - 2; i >= 0; i--) {
                dp1[i] = d[i];
                dp2[i] = d[i];
                for (int j = i + 1; j < n - 1; j++) {
                    dp1[i] = Math.max(dp1[i], dp2[j]);
                    dp2[i] = Math.min(dp2[i], dp1[j]);
                }
            }

            int ans = Math.abs(w - a[n - 1]);
            for (int i = 0; i < n; i++) {
                ans = Math.max(ans, dp2[i]);
            }
            out.println(ans);
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