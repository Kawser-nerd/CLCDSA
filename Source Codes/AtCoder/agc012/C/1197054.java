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
import java.util.ArrayList;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long n = in.nextLong();
            ArrayList<Integer> res = new ArrayList<>();
            int cnum = 1;

            int r = 60;
            long[][] comb = new long[r][r];
            for (int i = 0; i < r; i++) {
                comb[i][0] = 1;
                for (int j = 1; j <= i; j++) {
                    comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
                }
            }
            long[][] nways = new long[2][];
            nways[0] = new long[100];
            nways[1] = new long[60];
//        nways[2] = new long[35];
//        nways[3] = new long[30];
//        nways[4] = new long[25];
//        nways[5] = new long[18];
//        nways[6] = new long[15];
            for (int j = 1; j < nways.length; j++) {
                for (int i = 0; i < nways[j].length; i++) {
                    long mm = 1;
                    long sum = 0;
                    for (int k = 2; k <= i; k += 2) {
                        mm *= (1 << j) - 1;
                        sum += mm * comb[i][k];
                    }
                    nways[j][i] = sum;
                }
            }
            int xx = 18;
            long[][][][] ww = new long[xx][xx][xx][xx];
            for (int i = 0; i < xx; i++) {
                for (int j = 0; j < xx; j++) {
                    for (int k = 0; k < xx; k++) {
                        for (int m = 0; m < xx; m++) {
                            ww[i][j][k][m] = nways[1][i + k] + nways[1][j + m];
                            for (int r1 = 1; r1 <= i && r1 <= k; r1++) {
                                for (int r2 = 1; r2 <= j && r2 <= m; r2++) {
                                    ww[i][j][k][m] += comb[i][r1] * comb[k][r1] * comb[j][r2] * comb[m][r2];
                                }
                            }
                        }
                    }
                }
            }
            while (n > 0) {
                long best = 0;
                int a1 = -1, a2 = -1, a3 = -1, a4 = -1;
                for (int i = 0; i < xx; i++) {
                    for (int j = 0; j < xx; j++) {
                        for (int k = 0; k < xx; k++) {
                            for (int m = 0; m < xx; m++) {
                                if (ww[i][j][k][m] <= n && ww[i][j][k][m] > best) {
                                    best = ww[i][j][k][m];
                                    a1 = i;
                                    a2 = j;
                                    a3 = k;
                                    a4 = m;
                                }
                            }
                        }
                    }
                }
                if (best == 0) break;
                for (int i = 0; i < a1; i++) res.add(cnum);
                for (int i = 0; i < a2; i++) res.add(cnum + 1);
                for (int i = 0; i < a3; i++) res.add(cnum);
                for (int i = 0; i < a4; i++) res.add(cnum + 1);
                cnum += 2;
                n -= best;
            }
            int[] ptr = new int[nways.length];
            for (int i = 1; i < nways.length; i++) ptr[i] = nways[i].length - 1;
            while (n > 0) {
                for (int x = 1; x < nways.length; x++) {
                    while (ptr[x] >= 0 && nways[x][ptr[x]] > n) {
                        ptr[x]--;
                    }
                }
                boolean good = false;
                for (int x = 1; x < nways.length; x++) if (ptr[x] >= 0) good = true;
                if (!good) break;
                long best = 0;
                int which = -1;
                for (int x = 1; x < nways.length; x++) {
                    if (ptr[x] >= 0) {
                        if (nways[x][ptr[x]] >= best) {
                            best = nways[x][ptr[x]];
                            which = x;
                        }
                    }
                }
                for (int j = 0; j < ptr[which]; j++) {
                    for (int k = 0; k < which; k++) {
                        res.add(cnum + k);
                    }
                }
                cnum += which;
                n -= nways[which][ptr[which]];
            }
            while (n > 0) {
                long x = Long.highestOneBit(n + 1);
                long w = Long.numberOfTrailingZeros(x) + 1;
                for (int e = 0; e < w; e++) res.add(cnum);
                cnum++;
                n -= (1L << (w - 1)) - 1;
            }
            out.println(res.size());
            for (int x : res) {
                out.println(x);
            }
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

        public long nextLong() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            long res = 0L;

            while (c >= 48 && c <= 57) {
                res *= 10L;
                res += (long) (c - 48);
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * (long) sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}