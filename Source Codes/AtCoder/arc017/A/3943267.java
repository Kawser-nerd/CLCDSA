import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.util.regex.Pattern;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        LightWriter out = new LightWriter(outputStream);
        A solver = new A();
        solver.solve(1, in, out);
        out.close();
    }

    static class A {
        private static final String YES = "YES";
        private static final String NO = "NO";

        public void solve(int testNumber, LightScanner in, LightWriter out) {
            out.ans(IntMath.isPrime(in.longs()) ? YES : NO).ln();
        }

    }

    static class ModMath {
        private static final int DEFAULT_MOD = 1_000_000_007;
        private final long mod;

        public ModMath(long mod) {
            this.mod = mod;
        }

        public ModMath() {
            this(DEFAULT_MOD);
        }

        public long pow(long x, long y) {
            if (y == 0) {
                return 1;
            } else if (y % 2 == 0) {
                long z = pow(x, y / 2);
                return (z * z) % mod;
            } else {
                return (x % mod) * pow(x, y - 1) % mod;
            }
        }

    }

    static final class IntMath {
        private IntMath() {
        }

        public static boolean isPrime(int n) {
            if (n == 2) {
                return true;
            } else if (n <= 1 || (n & 1) == 0) {
                return false;
            }
            int s = BitMath.lsb(n - 1);
            int d = (n - 1) >> s;
            ModMath m = new ModMath(n);
            outer:
            for (int a : new int[]{2, 7, 61}) {
                int r = (int) m.pow(a, d);
                if (r == 1 || r == n - 1) {
                    continue;
                }
                for (int j = 0; j < s; j++) {
                    r = (int) m.pow(r, 2);
                    if (r == n - 1) {
                        continue outer;
                    }
                }
                return false;
            }
            return true;
        }

        public static boolean isPrime(long n) {
            if (n < Integer.MAX_VALUE) {
                return isPrime((int) n);
            }
            int s = BitMath.lsb(n - 1);
            long d = (n - 1) >> s;
            ModMath m = new ModMath(n);
            outer:
            for (int a : new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
                long r = m.pow(a, d);
                if (r == 1 || r == n - 1) {
                    continue;
                }
                for (int j = 0; j < s; j++) {
                    r = m.pow(r, 2);
                    if (r == n - 1) {
                        continue outer;
                    }
                }
                return false;
            }
            return true;
        }

    }

    static final class BitMath {
        private BitMath() {
        }

        public static int count(int v) {
            v = (v & 0x55555555) + ((v >> 1) & 0x55555555);
            v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
            v = (v & 0x0f0f0f0f) + ((v >> 4) & 0x0f0f0f0f);
            v = (v & 0x00ff00ff) + ((v >> 8) & 0x00ff00ff);
            v = (v & 0x0000ffff) + ((v >> 16) & 0x0000ffff);
            return v;
        }

        public static int count(long v) {
            v = (v & 0x5555555555555555L) + ((v >> 1) & 0x5555555555555555L);
            v = (v & 0x3333333333333333L) + ((v >> 2) & 0x3333333333333333L);
            v = (v & 0x0f0f0f0f0f0f0f0fL) + ((v >> 4) & 0x0f0f0f0f0f0f0f0fL);
            v = (v & 0x00ff00ff00ff00ffL) + ((v >> 8) & 0x00ff00ff00ff00ffL);
            v = (v & 0x0000ffff0000ffffL) + ((v >> 16) & 0x0000ffff0000ffffL);
            v = (v & 0x00000000ffffffffL) + ((v >> 32) & 0x00000000ffffffffL);
            return (int) v;
        }

        public static int lsb(int v) {
            if (v == 0) {
                throw new IllegalArgumentException("Bit not found");
            }
            v |= (v << 1);
            v |= (v << 2);
            v |= (v << 4);
            v |= (v << 8);
            v |= (v << 16);
            return 32 - count(v);
        }

        public static int lsb(long v) {
            if (v == 0) {
                throw new IllegalArgumentException("Bit not found");
            }
            v |= (v << 1);
            v |= (v << 2);
            v |= (v << 4);
            v |= (v << 8);
            v |= (v << 16);
            v |= (v << 32);
            return 64 - count(v);
        }

    }

    static class LightWriter implements AutoCloseable {
        private static final String DEBUG_PROPERTY = "debug";
        private static final String DEBUG_CALL_PATTERN = "^.+\\.debug\\(([a-zA-Z0-9]+)\\);.*$";
        private static Pattern debugRegex;
        private final Writer out;
        private boolean autoflush = false;
        private boolean debug = false;
        private boolean breaked = true;
        private final String src;

        public LightWriter(Writer out) {
            this.out = out;
            src = System.getProperty(DEBUG_PROPERTY);
            if (src != null) {
                debug = true;
                if (debugRegex == null) {
                    debugRegex = Pattern.compile(DEBUG_CALL_PATTERN);
                }
            }
        }

        public LightWriter(OutputStream out) {
            this(new BufferedWriter(new OutputStreamWriter(out, Charset.defaultCharset())));
        }

        public LightWriter print(char c) {
            try {
                out.write(c);
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter print(String s) {
            try {
                out.write(s, 0, s.length());
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter ans(String s) {
            if (!breaked) {
                print(' ');
            }
            return print(s);
        }

        public LightWriter ln() {
            breaked = true;
            print(System.lineSeparator());
            if (autoflush) {
                try {
                    out.flush();
                } catch (IOException ex) {
                    throw new UncheckedIOException(ex);
                }
            }
            return this;
        }

        public void close() {
            try {
                out.close();
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public long longs() {
            return Long.parseLong(string());
        }

    }
}