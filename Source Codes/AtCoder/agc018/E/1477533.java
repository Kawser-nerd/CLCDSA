import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.IOException;
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
        final int MOD = (int) 1e9 + 7;
        int[] fact;
        int[] invFact;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] x = new int[6];
            for (int i = 0; i < 6; ++i) {
                x[i] = in.nextInt();
            }
            int[] y = new int[6];
            for (int i = 0; i < 6; ++i) {
                y[i] = in.nextInt();
            }

            precalc(5_000_000);

            int v = x[3] - x[2] + 1;
            int ans = 0;
            for (int i = 0; i < v; ++i) {
                int vx = x[2] + i;
                int vy = y[3];
                int add = solve(x[1] - x[0], vy - y[0], vx - x[1], vy - y[1]);
                add = (int) ((long) add * (y[3] - y[2] + 1 + i) % MOD);
                vy++;
                add = (int) ((long) add * solve(x[5] - x[4], y[5] - vy, x[4] - vx, y[4] - vy) % MOD);
                ans += add;
                ans %= MOD;
            }
            for (int i = 0; i < v; ++i) {
                int vx = x[2] + i;
                int vy = y[2] - 1;
                int add = solve(x[1] - x[0], vy - y[0], vx - x[1], vy - y[1]);
                add = (int) ((long) add * i % MOD);
                vy++;
                add = (int) ((long) add * solve(x[5] - x[4], y[5] - vy, x[4] - vx, y[4] - vy) % MOD);
                ans -= add;
                ans %= MOD;
            }
            v = y[3] - y[2] + 1;
            for (int i = 0; i < v; ++i) {
                int vx = x[3];
                int vy = y[2] + i;
                int add = solve(x[1] - x[0], vy - y[0], vx - x[1], vy - y[1]);
                add = (int) ((long) add * (x[3] - x[2] + 1 + i) % MOD);
                vx++;
                add = (int) ((long) add * solve(x[5] - x[4], y[5] - vy, x[4] - vx, y[4] - vy) % MOD);
                ans += add;
                ans %= MOD;
            }

            for (int i = 0; i < v; ++i) {
                int vx = x[2] - 1;
                int vy = y[2] + i;
                int add = solve(x[1] - x[0], vy - y[0], vx - x[1], vy - y[1]);
                add = (int) ((long) add * i % MOD);
                vx++;
                add = (int) ((long) add * solve(x[5] - x[4], y[5] - vy, x[4] - vx, y[4] - vy) % MOD);
                ans -= add;
                ans %= MOD;
            }
//        int ans = 0;
//        for (int vx = x[2]; vx <= x[3]; ++vx) {
//            for (int vy = y[2]; vy <= y[3]; ++vy) {
//                ans += (long) solve(x[1] - x[0], vy - y[0], vx - x[1], vy - y[1]) *
//                        solve(x[5] - x[4], y[5] - vy, x[4] - vx, y[4] - vy) % MOD;
//                ans %= MOD;
//            }
//        }

            ans %= MOD;
            if (ans < 0) {
                ans += MOD;
            }
            out.println(ans);
            System.err.flush();
        }

        int comb(int n, int k) {
            if (k < 0 || n < 0 || k > n) {
                return 0;
            }
            return (int) ((long) fact[n] * invFact[k] % MOD * invFact[n - k] % MOD);
        }

        int solve(int x, int y, int l) {
            return (comb(l + x + y + 2, y + 1) - comb(l + y + 1, y + 1)) % MOD;
        }

        int solve(int x, int y, int l, int l1) {
            int ans = solve(x, y, l);
            if (l1 > 0) {
                ans -= solve(x, l1 - 1, l);
                ans %= MOD;
            }
            return ans;
        }

        void precalc(int n) {
            fact = new int[n];
            fact[0] = 1;
            for (int i = 1; i < n; ++i) {
                fact[i] = (int) ((long) fact[i - 1] * i % MOD);
            }
            invFact = new int[n];
            invFact[n - 1] = NumberUtils.invMod(fact[n - 1], MOD, MOD - 1);
            for (int i = n - 2; i >= 0; --i) {
                invFact[i] = (int) ((long) invFact[i + 1] * (i + 1) % MOD);
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class NumberUtils {
        public static int modPow(int x, int y, int Mod) {
            int res = 1;
            for (; y > 0; y /= 2) {
                if ((y & 1) != 0) {
                    res = (int) ((long) res * x % Mod);
                }
                x = (int) ((long) x * x % Mod);
            }
            return res;
        }

        public static int invMod(int value, int Mod, int phi) {
            return modPow(value, phi - 1, Mod);
        }

    }
}