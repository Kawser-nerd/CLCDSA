// package agc.agc020;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class Main {
    private static final long MOD = 998244353;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        String s = in.nextToken();
        memoFree = new HashMap<>();
        memoGroup = new HashMap<>();

        out.println(dfsFree(s));
        out.flush();
    }
    
    static Map<String,Long> memoFree;
    static Map<String,Long> memoGroup;

    static long dfsFree(String s) {
        if (s.length() == 0) {
            return 1;
        }
        if (memoFree.containsKey(s)) {
            return memoFree.get(s);
        }
        int n = s.length();
        long ret = 0;
        for (int tg = 2 ; tg <= n ; tg++) {
            long part = dfsGroup(s.substring(0, tg)) * dfsFree(s.substring(tg, n)) % MOD;
            ret += part;
        }
        ret += dfsFree(s.substring(1)) * (s.charAt(0) - '0' + 1) % MOD;
        ret %= MOD;
        memoFree.put(s, ret);
        return ret;
    }


    static long dfsGroup(String s) {
        if (s.length() < 2) {
            return 0;
        }
        if (memoGroup.containsKey(s)) {
            return memoGroup.get(s);
        }

        long ret = 0;
        int L = s.length();
        for (int k = 2 ; k <= L ; k++) {
            if (L % k == 0) {
                int p = L / k;
                char[] c = new char[p];
                for (int i = 0; i < p ; i++) {
                    c[i] = '1';
                    for (int j = i; j < L ; j += p) {
                        if (s.charAt(j) == '0') {
                            c[i] = '0';
                            break;
                        }
                    }
                }
                String ss = String.valueOf(c);
                ret += dfsFree(ss);
                ret %= MOD;
            }
        }
        memoGroup.put(s, ret);
        return ret;
    }

    static int n;
    static char[] s;

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