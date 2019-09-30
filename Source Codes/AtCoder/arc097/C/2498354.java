import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] posW = new int[n], posB = new int[n];
            for (int i = 0; i < 2 * n; i++) {
                char c = in.next().charAt(0);
                if (c == 'W') {
                    posW[in.nextInt() - 1] = i;
                } else {
                    posB[in.nextInt() - 1] = i;
                }
            }

            int INF = Integer.MAX_VALUE / 3;
            int[][] dp = new int[n + 1][n + 1];
            for (int[] i : dp) {
                Arrays.fill(i, INF);
            }
            System.err.println(Arrays.toString(posW));

            System.err.println(Arrays.toString(posB));

            BITSum tree = new BITSum(2 * n);
            dp[0][0] = 0;
            for (int i = 0; i <= n; i++) {
                tree.clear();
                for (int j = 0; j < i; j++) {
                    tree.add(posW[j], 1);
                }
                for (int j = 0; j <= n; j++) {
                    if (i + 1 <= n) {
                        int cur = tree.sum(posW[i] + 1, 2 * n - 1);
                        dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j] + cur);
                    }
                    if (j + 1 <= n) {
                        int cur = tree.sum(posB[j] + 1, 2 * n - 1);
                        dp[i][j + 1] = Math.min(dp[i][j + 1], dp[i][j] + cur);
                        tree.add(posB[j], 1);
                    }
                }
            }
            out.println(dp[n][n]);
        }

    }

    static class BITSum {
        int[] tree;

        public BITSum(int size) {
            tree = new int[size];
        }

        public BITSum(int[] a) {
            tree = a.clone();
            for (int i = 1; i < tree.length; i++) {
                tree[i] += tree[i - 1];
            }
            for (int i = tree.length - 1; i >= 0; i--) {
                int prev = (i & (i + 1)) - 1;
                if (prev >= 0) {
                    tree[i] -= tree[prev];
                }
            }
        }

        public int sum(int pos) {
            int result = 0;
            while (pos >= 0) {
                result += tree[pos];
                pos = (pos & (pos + 1)) - 1;
            }
            return result;
        }

        public int sum(int l, int r) {
            int result = sum(r);
            if (l - 1 >= 0) {
                result -= sum(l - 1);
            }
            return result;
        }

        public void add(int pos, int val) {
            while (pos < tree.length) {
                tree[pos] += val;
                pos |= pos + 1;
            }
        }

        public void clear() {
            Arrays.fill(tree, 0);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}