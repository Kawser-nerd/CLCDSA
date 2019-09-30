// package agc.agc028;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[][] edges = new int[n*2][];
        int[][] tbl = new int[n][2];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 2 ; j++) {
                int[] e = new int[]{i, j, in.nextInt()};
                edges[i*2+j] = e;
                tbl[i][j] = e[2];
            }
        }
        Arrays.sort(edges, Comparator.comparingInt(u -> u[2]));


        long total = 0;
        int[] flg = new int[n];
        for (int i = 0; i < n ; i++) {
            int idx = edges[i][0];
            flg[idx] |= 1<<edges[i][1];
            total += edges[i][2];
        }

        int alls = 0;
        int zeros = 0;
        int left = 0;
        int right = 0;
        for (int i = 0; i < n ; i++) {
            if (flg[i] == 3) {
                alls++;
            } else if (flg[i] == 0) {
                zeros++;
            } else if (flg[i] == 1) {
                left++;
            } else {
                right++;
            }
        }
        assert alls == zeros;

        if (alls >= 1 || left == n || right == n) {
            out.println(total);
            out.flush();
            return;
        }

        int[] add = new int[n];
        int[] dec = new int[n];
        for (int i = 0; i < n ; i++) {
            int j = flg[i] == 1 ? 0 : 1;
            dec[i] = tbl[i][j];
            add[i] = tbl[i][j^1];
        }

        int[] dleft = new int[n];
        dleft[0] = dec[0];
        for (int i = 1 ; i < n ; i++) {
            dleft[i] = Math.max(dleft[i-1], dec[i]);
        }

        int[] dright = new int[n];
        dright[n-1] = dec[n-1];
        for (int i = n-2 ; i >= 0 ; i--) {
            dright[i] = Math.max(dright[i+1], dec[i]);
        }

        long bestDiff = Long.MAX_VALUE;
        for (int i = 0; i < n ; i++) {
            long ld = 0;
            if (i >= 1) {
                ld = Math.max(ld, dleft[i-1]);
            }
            if (i+1 < n) {
                ld = Math.max(ld, dright[i+1]);
            }
            bestDiff = Math.min(bestDiff, add[i]-ld);
        }
        out.println(total + bestDiff);
        out.flush();
    }

    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
    }

    private static void debug(Object... o) {
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