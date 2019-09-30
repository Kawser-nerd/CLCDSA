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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        int[][] sum;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt();
            int K = in.nextInt();

            int[][] grid = new int[4 * K][4 * K];

            for (int i = 0; i < N; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                char c = in.next().charAt(0);

                if (c == 'B') {
                    grid[x % (2 * K)][y % (2 * K)]++;
                } else {
                    grid[(x + K) % (2 * K)][y % (2 * K)]++;
                }
            }

            for (int i = 0; i < 4 * K; i++) {
                for (int j = 0; j < 4 * K; j++) {
                    grid[i][j] = grid[i % (2 * K)][j % (2 * K)];
                }
            }

//        print(grid);

            sum = new int[4 * K][4 * K];

            for (int i = 0; i < 4 * K; i++) {
                for (int j = 0; j < 4 * K; j++) {
                    sum[i][j] = grid[i][j];
                    if (i > 0) sum[i][j] += sum[i - 1][j];
                    if (j > 0) sum[i][j] += sum[i][j - 1];
                    if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
                }
            }
//        print(sum);

            int ans = 0;

            for (int lx = 0; lx < 2 * K; lx++) {
                for (int ly = 0; ly < 2 * K; ly++) {
                    ans = Math.max(ans, count(lx, ly, lx + K - 1, ly + K - 1) + count(lx + K, ly + K, lx + K + K - 1, ly + K + K - 1));
                }
            }

            out.println(ans);
        }

        private int count(int lx, int ly, int rx, int ry) {
            return sum(rx, ry) - sum(lx - 1, ry) - sum(rx, ly - 1) + sum(lx - 1, ly - 1);
        }

        private int sum(int rx, int ry) {
            if (rx < 0 || ry < 0) return 0;
            return sum[rx][ry];
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