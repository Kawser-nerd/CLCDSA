import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        String s = in.nextToken();
        memo.put("", 1L);
        memo.put("0", 1L);
        memo.put("1", 2L);

        out.println(dfs(s));
        out.flush();
    }

    static Map<String,Long> memo = new HashMap<>();

    static long MOD = 998244353;

    static long dfs(String s) {
        if (memo.containsKey(s)) {
            return memo.get(s);
        }
        int n = s.length();
        long total = 0;

        for (int take = 2 ; take <= n ; take++) {
            long leftWay = dfs(s.substring(take));
            long makeWay = 0;
            for (int k = 1; k < take; k++) {
                if (take % k != 0) {
                    continue;
                }
                char[] pl = new char[k];
                for (int i = 0; i < k; i++) {
                    int one = 1;
                    for (int j = i; j < take; j += k) {
                        if (s.charAt(j) == '0') {
                            one = 0;
                            break;
                        }
                    }
                    pl[i] = one == 1 ? '1' : '0';
                }
                makeWay += dfs(String.valueOf(pl));
            }
            makeWay %= MOD;
            total += leftWay * makeWay % MOD;
        }

        long w = s.charAt(0) == '1' ? 2 : 1;
        total += w * dfs(s.substring(1)) % MOD;
        total %= MOD;

        memo.put(s, total);
        return total;
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