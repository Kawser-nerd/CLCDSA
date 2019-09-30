import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class A {

    final static boolean DEBUG = true;

    final void solve() throws Exception {
        for (int testCount = nextInt(), testId = 1; testCount > 0; --testCount, ++testId) {
            int n = nextInt();
            int k = nextInt();
            long[][] a = new long[n][3];

            for (int i = 0; i < n; ++i) {
                a[i][0] = nextLong();
                a[i][1] = nextLong();
                a[i][2] = 2 * a[i][0] * a[i][1];
            }

            long result = 0;

            for (int i = 0; i < n; ++i) {
                long[][] b = new long[n][];
                int count = 0;

                for (int j = 0; j < n; ++j) {
                    if (a[j][0] <= a[i][0] && i != j) {
                        b[count++] = a[j];
                    }
                }

                if (count < k - 1) {
                    continue;
                }

                Arrays.sort(b, 0, count, new Comparator<long[]>() {
                    @Override
                    public int compare(long[] a, long[] b) {
                        return -Long.compare(a[2], b[2]);
                    }
                });

                long size = a[i][0] * a[i][0] + 2 * a[i][0] * a[i][1];
                for (int j = 0; j < k - 1; ++j) {
                    size += b[j][2];
                }

                result = Math.max(result, size);
            }

            print(String.format("Case #%d: %.12f", testId, Math.PI * result));
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
                String fileName = A.class.getSimpleName();
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
        new A().solve();
        out.close();
    }
}
