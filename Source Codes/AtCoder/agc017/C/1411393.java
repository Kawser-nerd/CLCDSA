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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int[] delta;
        int[] numZero;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] v = new int[n + 1];
            int[] a = new int[n];
            delta = new int[4 * n];
            numZero = new int[4 * n];
            initTree(0, 0, n - 1);
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                ++v[a[i]];
            }
            for (int i = 1; i <= n; ++i)
                if (v[i] > 0) {
                    updTree(0, 0, n - 1, i - v[i], i - 1, 1);
                }
            for (int i = 0; i < m; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt();
                updTree(0, 0, n - 1, a[x] - v[a[x]], a[x] - 1, -1);
                --v[a[x]];
                updTree(0, 0, n - 1, a[x] - v[a[x]], a[x] - 1, 1);
                a[x] = y;
                updTree(0, 0, n - 1, a[x] - v[a[x]], a[x] - 1, -1);
                ++v[a[x]];
                updTree(0, 0, n - 1, a[x] - v[a[x]], a[x] - 1, 1);
                out.println(numZero[0]);
            }
        }

        private void updTree(int root, int rl, int rr, int left, int right, int by) {
            if (left < 0) left = 0;
            if (left > right) return;
            if (rl == left && rr == right) {
                delta[root] += by;
            } else {
                int rm = (rl + rr) >> 1;
                updTree(root * 2 + 1, rl, rm, left, Math.min(right, rm), by);
                updTree(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right, by);
            }
            if (delta[root] > 0) {
                numZero[root] = 0;
            } else {
                if (rl == rr) {
                    numZero[root] = 1;
                } else {
                    numZero[root] = numZero[root * 2 + 1] + numZero[root * 2 + 2];
                }
            }
        }

        private void initTree(int root, int rl, int rr) {
            numZero[root] = rr - rl + 1;
            if (rl < rr) {
                int rm = (rl + rr) >> 1;
                initTree(root * 2 + 1, rl, rm);
                initTree(root * 2 + 2, rm + 1, rr);
            }
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