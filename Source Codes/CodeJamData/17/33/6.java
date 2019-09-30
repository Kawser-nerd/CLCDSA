import java.io.*;

public class C {

    final static boolean DEBUG = true;

    final void solve() throws Exception {
        for (int testCount = nextInt(), testId = 1; testCount > 0; --testCount, ++testId) {
            int n = nextInt();
            int k = nextInt();
            int u = Math.round(10_000 * Float.valueOf(nextString()));

            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = Math.round(10_000 * Float.valueOf(nextString()));
            }

            for (int i = 0; i < u; ++i) {
                int min = -1;
                int minIndex = -1;

                for (int j = 0; j < n; ++j) {
                    if (min == -1 || min > a[j]) {
                        min = a[j];
                        minIndex = j;
                    }
                }

                if (a[minIndex] < 10_000) {
                    ++a[minIndex];
                }
            }

            double result = 1;
            for (int i = 0; i < n; ++i) {
                result *= 0.0001 * a[i];
            }

            print(String.format("Case #%d: %.12f", testId, result));
            println();
        }
    }

    final static BufferedReader in;
    final static PrintWriter out;

    static final boolean isWhiteSpace(final int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == -1;
    }

    static final int read() throws Exception {
        return in.read();
    }

    static final int nextInt() throws Exception {
        int result = 0;
        boolean negative = false;
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c == '-') {
            negative = true;
            c = read();
        }
        while (!isWhiteSpace(c)) {
            result = result * 10 + (c - '0');
            c = read();
        }
        return negative ? -result : result;
    }

    static final long nextLong() throws Exception {
        long result = 0;
        boolean negative = false;
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c == '-') {
            negative = true;
            c = read();
        }
        while (!isWhiteSpace(c)) {
            result = result * 10 + (c - '0');
            c = read();
        }
        return negative ? -result : result;
    }

    static final StringBuilder tmpString = new StringBuilder(1 << 20);

    static final String nextString() throws Exception {
        tmpString.setLength(0);
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        while (!isWhiteSpace(c)) {
            tmpString.append((char) c);
            c = read();
        }
        return tmpString.toString();
    }

    static final void print(final int i) {
        out.print(i);
    }

    static final void print(final long l) {
        out.print(l);
    }

    static final void print(final String s) {
        out.print(s);
    }

    static final void println() {
        out.println();
    }

    static {
        try {
            if (DEBUG) {
                String fileName = C.class.getSimpleName();
                in = new BufferedReader(new FileReader(fileName + ".in"));
                out = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
            } else {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
            }
        } catch (Exception ex) {
            throw new RuntimeException(ex);
        }
    }

    public static void main(String[] args) throws Exception {
        new C().solve();
        out.close();
    }
}
