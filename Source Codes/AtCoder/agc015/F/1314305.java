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
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskF {
        long x;
        long y;
        long[][] twooneprods;
        long[][] oneoneprods;
        static final long MODULO = (long) (1e9 + 7);

        public TaskF() {
            twooneprods = new long[87][4];
            oneoneprods = new long[86][4];
            long[] one = new long[]{0, 1, 1, 1};
            long[] two = new long[]{0, 1, 1, 2};
            for (int i = 0; i < twooneprods.length; ++i) {
                if (i > 0) {
                    two = mul(one, two);
                }
                twooneprods[i] = two;
            }
            long[] p = new long[]{1, 0, 0, 1};
            for (int i = 0; i < oneoneprods.length; ++i) {
                if (i > 0) {
                    p = mul(one, p);
                }
                oneoneprods[i] = p;
            }
        }

        long[] mul(long[] a, long[] b) {
            long[] c = new long[4];
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    for (int k = 0; k < 2; ++k) {
                        c[i * 2 + j] += a[i * 2 + k] * b[k * 2 + j];
                    }
                }
            }
            return c;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            x = in.nextLong();
            y = in.nextLong();
            if (x > y) {
                long t = x;
                x = y;
                y = t;
            }
            long p = 0;
            long q = 1;
            int steps = 0;
            long ways = 0;
            while (true) {
                int t = (p == 0) ? 2 : 1;
                long np = q;
                long nq = p + t * q;
                if (np > x || nq > y) {
                    if (q <= x) {
                        ways = 2;
                    } else {
                        ways = 1;
                    }
                    break;
                }
                ++steps;
                p = np;
                q = nq;
            }
            if (steps <= 1) {
                steps = 1;
                ways = x % MODULO * (y % MODULO) % MODULO;
            } else {
                p = 0;
                q = 1;
                for (int i = 0; i < steps; ++i) {
                    long mint = (p == 0) ? 2 : 1;

                    long[] extra = oneoneprods[steps - 1 - i];
                    long c = q * extra[1];
                    long d = q * extra[0] + p * extra[1];
                    // c * t + d <= x
                    long maxt = c == 0 ? Long.MAX_VALUE : (x - d) / c;
                    long a = q * extra[3];
                    long b = q * extra[2] + p * extra[3];
                    // a * t + b <= y
                    maxt = Math.min(maxt, (y - b) / a);
                    if (i == steps - 1) {
                        ways += maxt - mint;
                        ways %= MODULO;
                    } else {
                        for (long t = mint + 1; t <= maxt; ++t) {
                            long v1 = c * t + d;
                            long v2 = a * t + b;
                            ways += (y - v2) / v1 + 1;
                            ways %= MODULO;
                        }
                    }
                    if (a * mint + b <= x) {
                        maxt = Math.min(maxt, (x - b) / a);
                        ways += maxt - mint;
                        ways %= MODULO;
                    }

                    long np = q;
                    long nq = p + mint * q;
                    if (np > x || nq > y) throw new RuntimeException();
                    p = np;
                    q = nq;
                }
                ways %= MODULO;
            }
            out.println(steps + " " + ways);
        /*Pair p = rec(0, 1, -1);
        out.println(p.steps + " " + p.ways);*/
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}