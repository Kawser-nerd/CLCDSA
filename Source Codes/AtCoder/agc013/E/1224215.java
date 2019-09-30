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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static final long MODULO = (long) (1e9 + 7);
        long[][] soltmp1 = new long[3][3];
        long[][] soltmp2 = new long[3][3];
        long[] soltmp3 = new long[3];
        long[][] soltmp4 = new long[3][3];
        long[][] powtmp1 = new long[3][3];
        long[][] powtmp2 = new long[3][3];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            //                 long z2 = 4 * w[i - 1] - 2 * w[i - 2] + w[i - 3];
            int n = in.nextInt();
            int m = in.nextInt();
            long[][] a = new long[3][3];
            a[0][0] = 4;
            a[0][1] = MODULO - 2;
            a[0][2] = 1;
            a[1][0] = 1;
            a[2][1] = 1;
            long[] b = new long[]{18, 5, 1};
            long[][] ainv = new long[3][3];
            ainv[0][1] = 1;
            ainv[1][2] = 1;
            ainv[2][0] = 1;
            ainv[2][1] = MODULO - 4;
            ainv[2][2] = 2;
            long[][] extra = new long[3][3];
            for (int i = 0; i < 3; ++i) extra[i][i] = 1;
            for (int i = 0; i < m; ++i) {
                int x = in.nextInt();
                pow(a, x - 1, soltmp1);
                mul(extra, soltmp1, soltmp2);
                mul(soltmp2, b, soltmp3);
                long y = (MODULO - soltmp3[2]) % MODULO;
                pow(ainv, x, soltmp1);
                mul(y, soltmp1, soltmp2);
                add(extra, soltmp2, soltmp4);
                copy(soltmp4, extra);
            }
            pow(a, n - 1, soltmp1);
            mul(extra, soltmp1, soltmp2);
            mul(soltmp2, b, soltmp3);
            out.println(soltmp3[2]);
        }

        private void add(long[][] a, long[][] b, long[][] c) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    c[i][j] = (a[i][j] + b[i][j]) % MODULO;
                }
            }
        }

        private void pow(long[][] a, int k, long[][] res) {
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    res[i][j] = (i == j) ? 1 : 0;
            copy(a, powtmp1);
            while (k > 0) {
                if (k % 2 != 0) {
                    mul(res, powtmp1, powtmp2);
                    copy(powtmp2, res);
                }
                k /= 2;
                mul(powtmp1, powtmp1, powtmp2);
                copy(powtmp2, powtmp1);
            }
        }

        private void mul(long[][] a, long[][] b, long[][] c) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    long s = 0;
                    for (int k = 0; k < 3; ++k) {
                        s += a[i][k] * b[k][j];
                    }
                    c[i][j] = s % MODULO;
                }
            }
        }

        private void mul(long[][] a, long[] b, long[] c) {
            for (int i = 0; i < 3; ++i) {
                long s = 0;
                for (int k = 0; k < 3; ++k) {
                    s += a[i][k] * b[k];
                }
                c[i] = s % MODULO;
            }
        }

        private void mul(long a, long[][] b, long[][] c) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    c[i][j] = a * b[i][j] % MODULO;
                }
            }
        }

        private void copy(long[][] b, long[][] c) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    c[i][j] = b[i][j];
                }
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