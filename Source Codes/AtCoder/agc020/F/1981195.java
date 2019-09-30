import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int fullCircle = in.nextInt();
            double[] len = new double[n];
            for (int i = 0; i < n; ++i) {
                len[i] = in.nextInt() / (double) fullCircle;
            }
            Arrays.sort(len);
            int[] pos = new int[n];
            boolean[] used = new boolean[n];
            pos[n - 1] = 0;
            used[0] = true;
            out.println(rec(pos, used, n - 2, len));
        }

        private double rec(int[] pos, boolean[] used, int at, double[] len) {
            if (at < 0) {
                return doit(pos, len);
            }
            double res = 0;
            for (int i = 0; i < pos.length; ++i)
                if (!used[i]) {
                    pos[at] = i;
                    used[i] = true;
                    res += rec(pos, used, at - 1, len);
                    used[i] = false;
                }
            return res;
        }

        private double doit(int[] pos, double[] len) {
            double res = 0;
            int n = pos.length;
            for (int bads = 0; bads < (1 << n); ++bads) {
                double[][] maxDelta = new double[n][n];
                for (double[] x : maxDelta) Arrays.fill(x, 1);
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (pos[i] < pos[j]) {
                            maxDelta[i][j] = 0;
                        }
                    }
                }
                for (int i = 0; i < n; ++i)
                    if ((bads & (1 << i)) != 0) {
                        if (i != n - 1) maxDelta[i][n - 1] = Math.min(maxDelta[i][n - 1], 1.0 - len[n - 1]);
                        for (int j = 0; j < n; ++j)
                            if (pos[j] > pos[i]) {
                                maxDelta[i][j] = -len[j];
                            }
                    }
                double cur = integrate(n, maxDelta, -1, 0);
                if (Integer.bitCount(bads) % 2 == 0) res += cur;
                else res -= cur;
            }
            return res;
        }

        private double integrate(int n, double[][] maxDelta, int which, int pow) {
            if (which == n - 1) {
                throw new RuntimeException();
            }
            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        maxDelta[i][j] = Math.min(maxDelta[i][j], maxDelta[i][k] + maxDelta[k][j]);
                    }
                }
            }
            if (n == 1) {
                if (pow != 0) throw new RuntimeException();
                return 1;
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (maxDelta[i][j] + maxDelta[j][i] <= 0) return 0;
                }
            }
            if (which > 0) {
                double[][] d = new double[n][n];
                for (int i = 0; i < n; ++i) {
                    int ii = (i == 0) ? which : (i == which) ? 0 : i;
                    for (int j = 0; j < n; ++j) {
                        int jj = (j == 0) ? which : (j == which) ? 0 : j;
                        d[ii][jj] = maxDelta[i][j];
                    }
                }
                maxDelta = d;
                which = 0;
            }
            double res = 0;
            for (int upper = 1; upper < n; ++upper) {
                for (int lower = 1; lower < n; ++lower) {
                    double upperDelta = maxDelta[0][upper];
                    double lowerDelta = -maxDelta[lower][0];
                    double[][] d = new double[n - 1][n - 1];
                    for (int i = 1; i < n; ++i) {
                        for (int j = 1; j < n; ++j) {
                            d[i - 1][j - 1] = maxDelta[i][j];
                        }
                    }
                    for (int i = 1; i < n; ++i)
                        if (i != upper) {
                            d[upper - 1][i - 1] = Math.min(d[upper - 1][i - 1], maxDelta[0][i] - maxDelta[0][upper]);
                        }
                    for (int i = 1; i < n; ++i)
                        if (i != lower) {
                            d[i - 1][lower - 1] = Math.min(d[i - 1][lower - 1], -maxDelta[lower][0] + maxDelta[i][0]);
                        }
                    if (upper == n - 1) {
                        res += integrate(n - 1, d, -1, 0) * Math.pow(upperDelta, pow + 1);
                    } else {
                        res += integrate(n - 1, shift(n - 1, d, upper - 1, upperDelta), upper - 1, pow + 1);
                    }
                    if (lower == n - 1) {
                        res -= integrate(n - 1, d, -1, 0) * Math.pow(lowerDelta, pow + 1);
                    } else {
                        res -= integrate(n - 1, shift(n - 1, d, lower - 1, lowerDelta), lower - 1, pow + 1);
                    }
                }
            }
            return res / (pow + 1);
        }

        private double[][] shift(int n, double[][] d, int what, double by) {
            double[][] nd = new double[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    nd[i][j] = d[i][j];
                    if (i == what) nd[i][j] += by;
                    if (j == what) nd[i][j] -= by;
                }
            }
            return nd;
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