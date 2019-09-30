import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long L = in.nextLong();

        zero = new int[1000000];
        one = new int[1000000];
        depth = new int[1000000];
        Arrays.fill(zero, -1);
        Arrays.fill(one, -1);
        Arrays.fill(depth, -1);
        depth[0] = 0;
        nidx = 1;

        for (int i = 0 ; i < n ; i++) {
            char[] c = in.nextToken().toCharArray();
            add(c);
        }

        long xor = 0;
        for (int i = 0 ; i < nidx ; i++) {
            if (depth[i] == -1) {
                continue;
            }
            if (zero[i] == -1 ^ one[i] == -1) {
                long level =  L - depth[i];
                // debug(i, level, computeXor(level));
                xor ^= computeXor(level);
            }
        }
//        debug(xor);

//        memo = new int[100];
//        Arrays.fill(memo, -1);
//        memo[0] = 0;
//        memo[1] = 1;
//        for (int lv = 0 ; lv < memo.length  ; lv++) {
//            debug(lv, grundy(lv));
//        }

        out.println(xor == 0 ? "Bob" : "Alice");
        out.flush();
    }

    static long computeXor(long level) {
        long now = 1;
        while (level % 2 == 0) {
            now *= 2;
            level /= 2;
        }
        return now;
    }

    static void add(char[] c, int idx, int now) {
        if (c.length == idx) {
            return;
        }
        if (c[idx] == '0') {
            if (zero[now] == -1) {
                zero[now] = addNode(now);
            }
            add(c, idx+1, zero[now]);
        } else {
            if (one[now] == -1) {
                one[now] = addNode(now);
            }
            add(c, idx+1, one[now]);
        }
    }

    static void add(char[] c) {
        add(c, 0, 0);
    }

    static int addNode(int par) {
        int ni = nidx;
        depth[ni] = depth[par]+1;
        nidx++;
        return ni;
    }


    static int nidx;
    static int[] zero;
    static int[] one;
    static int[] depth;

    static int[] memo;

    static int grundy(int level) {
        if (memo[level] != -1) {
            return memo[level];
        }
        Set<Integer> num = new HashSet<>();
        for (int take = 1 ; take < level ; take++) {
            int xor = 0;
            for (int left = take ; left <= level-1 ; left++) {
                xor ^= grundy(left);
            }
            num.add(xor);
        }
        for (int i = 1 ; i <= 114514 ; i++) {
            if (!num.contains(i)) {
                memo[level] = i;
                break;
            }
        }
        return memo[level];
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