// package arc.arc087;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        int n = in.nextInt();
        long L = in.nextLong();
        char[][] s = new char[n][];
        for (int i = 0; i < n ; i++) {
            s[i] = in.nextToken().toCharArray();
        }

        zero  = new int[SIZE];
        one   = new int[SIZE];
        depth = new int[SIZE];
        flg   = new int[SIZE];
        Arrays.fill(zero, -1);
        Arrays.fill(one, -1);
        Arrays.fill(flg, -1);
        ID = 1;
        depth[0] = 0;
        flg[0] = 1;

        for (char[] si : s) {
            dfs(si, 0, 0);
        }

        long xor = 0;
        for (int i = 0 ; i < ID ; i++) {
            if (flg[i] == 0) {
                long D = L - depth[i] + 1;
                xor ^= solve(D);
            }
        }

        out.println(xor == 0 ? "Bob" : "Alice");
        out.flush();
    }

    private static long solve(long D) {
        if (D == 0) {
            return 0;
        }
        long a = 1;
        while ((D & 1) == 0) {
            a *= 2;
            D >>= 1;
        }
        return a;
    }

    static void dfs(char[] s, int idx, int node) {
        flg[node] = 1;
        if (idx >= s.length) {
            return;
        }
        if (zero[node] == -1) {
            int L = ID++;
            int R = ID++;
            zero[node] = L;
            one[node] = R;
            depth[L] = idx+1;
            depth[R] = idx+1;
            flg[L] = flg[R] = 0;
        }
        int next = s[idx] == '0' ? zero[node] : one[node];
        dfs(s, idx+1, next);
    }



    static int SIZE = 400000;
    static int ID;
    static int[] flg;
    static int[] zero;
    static int[] one;
    static int[] depth;

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