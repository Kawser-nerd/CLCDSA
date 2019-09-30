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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int height = in.nextInt();
            int width = in.nextInt();
            long k = in.nextLong();
            if (k <= 1) {
                out.println(1);
                return;
            }
            String[] field = new String[height];
            for (int r = 0; r < height; ++r) {
                field[r] = in.next();
            }
            boolean horz = false;
            boolean vert = false;
            for (int r = 0; r < height; ++r) {
                if (field[r].charAt(0) == '#' && field[r].charAt(width - 1) == '#') {
                    horz = true;
                }
            }
            for (int c = 0; c < width; ++c) {
                if (field[0].charAt(c) == '#' && field[height - 1].charAt(c) == '#') {
                    vert = true;
                }
            }
            if (horz && vert) {
                out.println(1);
                return;
            }
            if (!horz && !vert) {
                long cells = 0;
                for (int r = 0; r < height; ++r) {
                    for (int c = 0; c < width; ++c) {
                        if (field[r].charAt(c) == '#')
                            ++cells;
                    }
                }
                out.println(pow(cells, k - 1));
                return;
            }
            if (!horz) {
                String[] flipped = new String[width];
                for (int c = 0; c < width; ++c) {
                    StringBuilder b = new StringBuilder();
                    for (int r = 0; r < height; ++r) {
                        b.append(field[r].charAt(c));
                    }
                    flipped[c] = b.toString();
                }
                field = flipped;
                int tmp = height;
                height = width;
                width = tmp;
            }
            long[] start = new long[2];
            for (int r = 0; r < height; ++r) {
                for (int c = 0; c < width; ++c)
                    if (field[r].charAt(c) == '#') {
                        if (c > 0 && field[r].charAt(c - 1) == '#')
                            ++start[1];
                        else
                            ++start[0];
                    }
            }
            long[][] a = new long[2][2];
            for (int r = 0; r < height; ++r) {
                for (int c = 0; c < width; ++c)
                    if (field[r].charAt(c) == '#') {
                        if (c > 0) {
                            int have = field[r].charAt(c - 1) == '#' ? 1 : 0;
                            ++a[have][0];
                            ++a[have][1];
                        } else {
                            ++a[0][0];
                            int have = field[r].charAt(width - 1) == '#' ? 1 : 0;
                            ++a[have][1];
                        }
                    }
            }
            long[] fin = mul(pow(a, k - 2), start);
            out.println(fin[0]);
        }

        private long[][] pow(long[][] a, long k) {
            if (k == 0) {
                long[][] res = new long[a.length][a.length];
                for (int i = 0; i < res.length; ++i) {
                    res[i][i] = 1;
                }
                return res;
            }
            if (k % 2 == 0) {
                return pow(mul(a, a), k / 2);
            }
            return mul(a, pow(a, k - 1));
        }

        private long[][] mul(long[][] a, long[][] b) {
            int n = a.length;
            long[][] c = new long[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    long s = 0;
                    for (int k = 0; k < n; ++k) {
                        s += a[i][k] * b[k][j];
                    }
                    c[i][j] = s % MODULO;
                }
            }
            return c;
        }

        private long[] mul(long[][] a, long[] b) {
            int n = a.length;
            long[] c = new long[n];
            for (int i = 0; i < n; ++i) {
                long s = 0;
                for (int k = 0; k < n; ++k) {
                    s += a[i][k] * b[k];
                }
                c[i] = s % MODULO;
            }
            return c;
        }

        private long pow(long a, long k) {
            if (k == 0) {
                return 1;
            }
            if (k % 2 == 0) {
                return pow(a * a % MODULO, k / 2);
            }
            return a * pow(a, k - 1) % MODULO;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}