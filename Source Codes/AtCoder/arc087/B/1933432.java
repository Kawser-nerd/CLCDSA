// package arc.arc087;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        char[] s = in.nextToken().toCharArray();
        int x = in.nextInt();
        int y = in.nextInt();


        int n = s.length;
        List<Integer> xs = new ArrayList<>();
        List<Integer> ys = new ArrayList<>();

        int ti = 0;
        while (ti < n && s[ti] == 'F') {
            ti++;
        }
        x -= ti;


        boolean flg = true;
        for (int i = ti; i < n ; ) {
            if (s[i] == 'T') {
                flg = !flg;
                i++;
                continue;
            }

            int j = i;
            while (j < n && s[j] == 'F') {
                j++;
            }
            if (flg) {
                xs.add(j-i);
            } else {
                ys.add(j-i);
            }
            i = j;
        }

        out.println(solve(x, xs) && solve(y, ys) ? "Yes" : "No");
        out.flush();
    }

    private static boolean solve(int L, List<Integer> xs) {
        int n = xs.size();

        Collections.sort(xs);

        int s = 0;
        for (int xi : xs) {
            s += xi;
        }
        int GETA = (s+10);
        int MAX = GETA*2;

        int[][] dp = new int[2][MAX];
        dp[0][GETA] = 1;
        for (int i = 0; i < n ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            int d = xs.get(i);
            Arrays.fill(dp[to], 0);
            for (int j = 0; j < MAX ; j++) {
                if (dp[fr][j] == 1) {
                    if (j - d >= 0) {
                        dp[to][j-d] = 1;
                    }
                    if (j + d < MAX) {
                        dp[to][j+d] = 1;
                    }
                }
            }
        }
        return GETA+L >= 0 && GETA+L < MAX && dp[n%2][GETA+L] == 1;
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