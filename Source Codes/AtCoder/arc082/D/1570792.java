// package arc.arc082;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int X = in.nextInt();
        int n = in.nextInt();
        long[] k = new long[n+1];
        for (int i = 0; i < n ; i++) {
            k[i] = in.nextInt();
        }
        k[n] = 1000000000 + 100;

        int q = in.nextInt();
        int[][] query = new int[q][3];
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < 2 ; j++) {
                query[i][j] = in.nextInt();
            }
            query[i][2] = i;
        }
        Arrays.sort(query, Comparator.comparingInt(u -> u[0]));

        long[] answer = new long[q];
        long[] min = new long[]{0, 0};
        long[] max = new long[]{X, X};

        int fr = 0;
        boolean dec = true;
        for (int i = 0; i <= n ; i++) {
            while (fr < q && query[fr][0] <= k[i]) {
                long since = query[fr][0] - (i == 0 ? 0 : k[i-1]);
                long last = 0;
                if (min[1] <= query[fr][1] && query[fr][1] <= max[1]) {
                    last = min[0] + query[fr][1] - min[1];
                } else if (query[fr][1] < min[1]) {
                    last = min[0];
                } else if (max[1] < query[fr][1]) {
                    last = max[0];
                }
                answer[query[fr][2]] = Math.max(0, Math.min(X, last + since * (dec ? -1 : 1)));
                fr++;
            }

            // upd
            long time = k[i] - (i == 0 ? 0 : k[i-1]);

            long toMin = min[0] + time * (dec ? -1 : 1);
            long toMax = max[0] + time * (dec ? -1 : 1);

            if (dec) {
                if (0 <= toMin && toMax <= X) {
                    min[0] = toMin;
                    max[0] = toMax;
                } else if (toMax >= 0) {
                    min[0] = 0;
                    max[0] = toMax;
                    min[1] += Math.abs(toMin);
                } else {
                    min[0] = max[0] = 0;
                }
            } else {
                if (0 <= toMin && toMax <= X) {
                    min[0] = toMin;
                    max[0] = toMax;
                } else if (toMin <= X) {
                    min[0] = toMin;
                    max[0] = X;
                    max[1] -= Math.abs(toMax - X);
                } else {
                    min[0] = max[0] = X;
                }
            }
            if (min[0] == max[0]) {
                min[1] = max[1] = -1;
            }
            dec = !dec;
        }

        for (int i = 0; i < q ; i++) {
            out.println(answer[i]);
        }
        out.flush();
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
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
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}