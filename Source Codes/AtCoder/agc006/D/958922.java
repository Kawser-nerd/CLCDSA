import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
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
            int N = in.nextInt();
            int A[] = new int[2 * N - 1];
            for (int i = 0; i < 2 * N - 1; i++) {
                A[i] = in.nextInt();
            }

            int lo = 0, hi = 2 * N;

            while (lo + 1 < hi) {
                int mid = lo + (hi - lo) / 2;

                if (onTopAtLeast(mid, A)) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            out.println(lo);
        }

        private boolean onTopAtLeast(int x, int[] a) {
            int LEN = a.length; // LEN = 2*N-1
            int[] b = new int[LEN];
            for (int i = 0; i < LEN; i++) {
                b[i] = a[i] < x ? 0 : 1;
            }
            int[] c = new int[LEN - 2];
            for (int i = 1; i < LEN - 1; i++) {
                c[i - 1] = b[i - 1] + b[i] + b[i + 1] < 2 ? 0 : 1;
            }

            int MID = c.length / 2;
            int left = MID;
            int right = MID;

            while (left > 0 && c[left - 1] != c[left]) left--;
            while (right < c.length - 1 && c[right] != c[right + 1]) right++;//C[1, 2*N-3]

            int ANS = (MID - left < right - MID) ? c[left] : c[right];

            return ANS == 1;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}