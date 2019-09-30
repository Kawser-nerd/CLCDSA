import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
        OutputWriter out = new OutputWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            char[][] s = new char[n][m];
            for (int i = 0; i < n; i++) s[i] = in.next().toCharArray();
//        for (int i = 0; i < n; i++) {
//            if (s[i][0] == '.') {
//                for (int j = 0; j < m; j++) {
//                    s[i][j] = (char)('#' + '.' - s[i][j]);
//                }
//            }
//        }
//        for (int i = 0; i < m; i++) {
//            if (s[0][i] == '.') {
//                for (int j = 0; j < n; j++) {
//                    s[j][i] = (char)('#' + '.' - s[j][i]);
//                }
//            }
//        }
            int ans = Math.max(n, m);
            int[][] dp = new int[n][m];
            int[][] pr = new int[n][m];
            for (int col = 1; col < m; col++) {
                dp[0][col] = 1;
                pr[0][col] = (s[0][col] == s[0][col - 1]) ? 1 : 0;
                for (int row = 1; row < n; row++) {
                    pr[row][col] = (s[row][col] == s[row][col - 1]) ? 1 : 0;
                    if (pr[row][col] == pr[row - 1][col]) dp[row][col] = dp[row - 1][col] + 1;
                    else dp[row][col] = 1;
                }
            }
            int[][] imos = new int[n + 3][m + 3];
            for (int i = 0; i < n; i++) {
                paint(dp[i], imos);
            }


            long count = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m + 1; j++) {
                    imos[i][j] += imos[i][j - 1];
                }
                for (int j = 1; j <= m + 1; j++) {
                    imos[i][j] += imos[i][j - 1];
                }
            }
            for (int j = 1; j <= m; j++) {
                for (int i = n; i >= 1; i--) {
                    imos[i][j] += imos[i + 1][j];
                }
            }
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++) {
                    if (imos[i][j] > 0) ans = Math.max(ans, i * (j + 1));
                }
            out.println(ans);
        }

        static void paint(int[] up, int[][] imos) {
            int m = up.length;
            int[][] ups = new int[m][];
            for (int i = 0; i < m; i++) ups[i] = new int[]{up[i], i};
            Arrays.sort(ups, new Comparator<int[]>() {
                public int compare(int[] a, int[] b) {
                    if (a[0] != b[0]) return a[0] - b[0];
                    return a[1] - b[1];
                }
            });
            TaskF.LST lst = new TaskF.LST(m);
            for (int[] u : ups) {
                if (u[0] > 0) {
                    int bef = lst.prev(u[1]);
                    int aft = lst.next(u[1]);
                    if (aft == -1) aft = m;
                    int bd = u[1] - bef - 1;
                    int ad = aft - u[1] - 1;
//				tr(u, bef, aft, bd, ad);

                    imos[u[0]][1]++;
                    imos[u[0]][bd + ad + 1 + 2]--;
                    imos[u[0]][bd + 1 + 1]--;
                    imos[u[0]][bd + ad + 1 + 2]++;
                    imos[u[0]][ad + 1 + 1]--;
                    imos[u[0]][bd + ad + 1 + 2]++;
                }
                lst.set(u[1]);
            }
        }

        public static class LST {
            public long[][] set;
            public int n;

            public LST(int n) {
                this.n = n;
                int d = 1;
                for (int m = n; m > 1; m >>>= 6, d++) ;

                set = new long[d][];
                for (int i = 0, m = n >>> 6; i < d; i++, m >>>= 6) {
                    set[i] = new long[m + 1];
                }
//			size = 0;
            }

            public TaskF.LST set(int pos) {
                if (pos >= 0 && pos < n) {
//				if(!get(pos))size++;
                    for (int i = 0; i < set.length; i++, pos >>>= 6) {
                        set[i][pos >>> 6] |= 1L << pos;
                    }
                }
                return this;
            }

            public int prev(int pos) {
                for (int i = 0; i < set.length && pos >= 0; i++, pos >>>= 6, pos--) {
                    int pre = prev(set[i][pos >>> 6], pos & 63);
                    if (pre != -1) {
                        pos = pos >>> 6 << 6 | pre;
                        while (i > 0) pos = pos << 6 | 63 - Long.numberOfLeadingZeros(set[--i][pos]);
                        return pos;
                    }
                }
                return -1;
            }

            public int next(int pos) {
                for (int i = 0; i < set.length && pos >>> 6 < set[i].length; i++, pos >>>= 6, pos++) {
                    int nex = next(set[i][pos >>> 6], pos & 63);
                    if (nex != -1) {
                        pos = pos >>> 6 << 6 | nex;
                        while (i > 0) pos = pos << 6 | Long.numberOfTrailingZeros(set[--i][pos]);
                        return pos;
                    }
                }
                return -1;
            }

            private static int prev(long set, int n) {
                long h = Long.highestOneBit(set << ~n);
                if (h == 0L) return -1;
                return Long.numberOfTrailingZeros(h) - (63 - n);
            }

            private static int next(long set, int n) {
                long h = Long.lowestOneBit(set >>> n);
                if (h == 0L) return -1;
                return Long.numberOfTrailingZeros(h) + n;
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
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
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

        public void println(int i) {
            writer.println(i);
        }

    }
}