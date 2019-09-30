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
        FManjuGame solver = new FManjuGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class FManjuGame {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n);

            int[] sum = new int[2];
            for (int i = 0; i < n; i++) {
                sum[i % 2] += a[i];
            }

            if (n % 2 == 0) {
                int sugim = Math.max(sum[0], sum[1]);
                int sigma = Math.min(sum[0], sum[1]);
                out.println(sugim + " " + sigma);

                return;
            }

            int max = Integer.MAX_VALUE / 2;
            int min = Integer.MIN_VALUE / 2;
            while (max - min > 1) {
                int x = (max + min) / 2;

                int[] b = a.clone();
                for (int i = 0; i < n - 2; i += 2) {
                    if (b[i] < x || b[i + 1] < b[i]) {
                        b[i + 2] += b[i] - b[i + 1];
                    }
                }

                if (b[n - 1] >= x) {
                    min = x;
                } else {
                    max = x;
                }
            }

            int sugim = Math.max(sum[0], sum[1] + min);
            int sigma = sum[0] + sum[1] - sugim;
            out.println(sugim + " " + sigma);
        }

    }

    static class InputReader {
        private BufferedReader br;
        private StringTokenizer st;

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
            st = new StringTokenizer("");
        }

        public String nextString() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return st.nextToken();
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

    }
}