import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author prakharjain
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BTreeBurning2 solver = new BTreeBurning2();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTreeBurning2 {
        long ans = 0;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int l = in.nextInt();

            int n = in.nextInt();

            long[] a = new long[n + 1];

            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            a[n] = l;

            for (int i = n; i > 0; i--) {
                a[i] -= a[i - 1];
            }

            solve(a, n, in);
            a = in.reverse(a);
            solve(a, n, in);


            out.println(ans);
        }

        void solve(long[] a, int n, InputReader in) {
            long[] pre = in.calculatePrefixSum(a);
            long[] suf = in.calculateSuffixSum(a);

            int remp = n + 1 - 1;

            long remsum = 0;

            if (remp % 2 == 1) {
                int hp = remp / 2;
                int si = 2 * hp;
                for (int i = n; i > n - hp; i--) {
                    int coeff = si - (n - i) * 2;
                    remsum += coeff * a[i];
                }

                si = 1;
                for (int i = n - hp - 1; i > 0; i--) {
                    int coeff = si + (n - hp - 1 - i) * 2;
                    remsum += coeff * a[i];
                }
            } else {
                int hp = remp / 2;
                int si = 2 * hp - 1;
                for (int i = n; i > n - hp; i--) {
                    int coeff = si - (n - i) * 2;
                    remsum += coeff * a[i];
                }

                si = 2;
                for (int i = n - hp - 1; i > 0; i--) {
                    int coeff = si + (n - hp - 1 - i) * 2;
                    remsum += coeff * a[i];
                }
            }

            remsum += remp * a[0];
            ans = Math.max(ans, remsum);

            for (int i = 1; i < n; i++) {
                remp = n - i;

                remsum += (remp + 1) * a[i];
                remsum -= pre[i];

                if (remp % 2 == 1) {
                    int hp = remp / 2;
                    int i1 = n - hp;

                    remsum -= suf[i1];

                    long sufp = suf[i + 1];

                    sufp -= suf[i1];

                    remsum += sufp;

                    int li = i;

                    int coef = 2 * hp;

                    remsum -= coef * a[i];

                    ans = Math.max(ans, remsum);
                } else {
                    int hp = remp / 2;
                    int i1 = n - hp;

                    remsum -= suf[i1 + 1];

                    long sufp = suf[i + 1];

                    sufp -= suf[i1];

                    remsum += sufp;

                    int li = i;

                    int coef = 2 * hp - 1;

                    remsum -= coef * a[i];

                    ans = Math.max(ans, remsum);
                }
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public long[] calculatePrefixSum(long[] a) {
            int n = a.length;

            long[] prefixSum = new long[n];

            prefixSum[0] = a[0];

            for (int i = 1; i < n; i++) {
                prefixSum[i] = prefixSum[i - 1] + a[i];
            }

            return prefixSum;
        }

        public long[] calculateSuffixSum(long[] a) {
            int n = a.length;

            long[] suffixSum = new long[n];

            suffixSum[n - 1] = a[n - 1];

            for (int i = n - 2; i >= 0; i--) {
                suffixSum[i] = suffixSum[i + 1] + a[i];
            }

            return suffixSum;
        }

        public long[] reverse(long[] a) {
            int n = a.length;

            for (int i = 0, j = n - 1; i < j; i++, j--) {
                long temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

            return a;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}