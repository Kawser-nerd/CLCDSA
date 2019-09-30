// package atcoder.arc.arc060;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

/**
 * Created by hama_du on 2016/08/28.
 */
public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        char[] w = in.nextToken().toCharArray();
        int n = w.length;
        int[] err = errorFunction(w);
        int cur = n-err[err.length-1];

        int cnt = -1;
        if (n % cur == 0) {
            cnt = n / cur;
        } else {
            cnt = 1;
        }

        if (cnt == n) {
            out.println(n);
            out.println(1);
        } else if (cnt == 1) {
            out.println(1);
            out.println(1);
        } else {
            int ptn = n-1;
            boolean[] visited = new boolean[n+1];
            char[] part = w.clone();
            char[] revPart = w.clone();
            for (int i = 0; i < part.length / 2 ; i++) {
                int j = part.length-1-i;
                char c = revPart[i];
                revPart[i] = revPart[j];
                revPart[j] = c;
            }
            int[] errLeft = errorFunction(part);
            int[] errRight = errorFunction(revPart);
            for (int x = 1 ; x <= errLeft.length-2 ; x++) {
                if (errLeft[x] >= 1 && x%(x-errLeft[x]) == 0) {
                    if (!visited[x]) {
                        ptn--;
                        visited[x] = true;
                    }
                }
            }

            for (int x = 1 ; x <= errRight.length-2 ; x++) {
                if (errRight[x] >= 1 && x%(x-errRight[x]) == 0) {
                    if (!visited[n-x]) {
                        ptn--;
                        visited[n-x] = true;
                    }
                }
            }
            out.println(2);
            out.println(ptn);
        }
        out.flush();
    }

    public static int[] errorFunction(char[] carr) {
        int len = carr.length;
        int[] err = new int[len+1];
        err[0] = -1;
        for (int i = 2 ; i <= len ; i++) {
            int now = err[i-1];
            while (now > 0 && carr[i-1] != carr[now]) {
                now = err[now];
            }
            if (carr[i-1] == carr[now]) {
                now++;
            } else {
                now = 0;
            }
            err[i] = now;
        }
        return err;
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int[] nextInts(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }


        private int[][] nextIntTable(int n, int m) {
            int[][] ret = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextInt();
                }
            }
            return ret;
        }

        private long[] nextLongs(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }

        private long[][] nextLongTable(int n, int m) {
            long[][] ret = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextLong();
                }
            }
            return ret;
        }

        private double[] nextDoubles(int n) {
            double[] ret = new double[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextDouble();
            }
            return ret;
        }

        private int next() {
            if (numChars == -1)
                throw new InputMismatchException();
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
            int c = next();
            while (isSpaceChar(c))
                c = next();
            if ('a' <= c && c <= 'z') {
                return (char) c;
            }
            if ('A' <= c && c <= 'Z') {
                return (char) c;
            }
            throw new InputMismatchException();
        }

        public String nextToken() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public long nextLong() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}