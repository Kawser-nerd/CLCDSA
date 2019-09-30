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
            int m = in.nextInt();
            int q = in.nextInt();

            int[][] sum = new int[n + 1][n + 1];
            for (int i = 0; i < m; i++) {
                int l = in.nextInt();
                int r = in.nextInt();
                sum[l][r]++;
            }

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j < n; j++) {
                    sum[i][j + 1] += sum[i][j];
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= n; j++) {
                    sum[i + 1][j] += sum[i][j];
                }
            }

            for (int i = 0; i < q; i++) {
                int p = in.nextInt();
                int r = in.nextInt();

                out.println(sum[r][r] - sum[r][p - 1] - sum[p - 1][r] + sum[p - 1][p - 1]);
            }
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

    }
}