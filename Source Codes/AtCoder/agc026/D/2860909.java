// package agc.agc026;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    private static final long MOD = 1000000007;

    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] h = new int[n];
        for (int i = 0; i < n ; i++) {
            h[i] = in.nextInt();
        }
        Node root = composeTree(h);

        long[] r = dfs(root);
        out.println((r[0] + r[1]) % MOD);
        out.flush();
    }

    static long[] dfs(Node node) {
        if (node.children.size() == 0) {
            long AB = pow(2, node.height);
            long nonAB = (pow(2, node.width) + MOD - 2) % MOD;
            return new long[]{AB, nonAB};
        }

        int cn = node.children.size();

        long[][] cptn = new long[cn][];
        for (int i = 0; i < cn ; i++) {
            cptn[i] = dfs(node.children.get(i));
        }

        long AB = pow(2, node.height);
        for (int i = 0; i < cn ; i++) {
            AB *= cptn[i][0];
            AB %= MOD;
        }

        long upNonAB = 1;
        long allAB = 2;
        for (int i = 0; i < cn ; i++) {
            upNonAB *= (2 * cptn[i][0] % MOD + cptn[i][1]);
            upNonAB %= MOD;
            allAB *= cptn[i][0];
            allAB %= MOD;
        }

        long nonAB = pow(2, node.freeWidth) * upNonAB % MOD;
        nonAB += MOD - allAB;
        nonAB %= MOD;

        return new long[]{AB, nonAB};
    }

    static void traverse(Node node) {
        debug(node.width, node.height);
        for (Node c : node.children) {
            traverse(c);
        }
    }

    static class Node {
        int width;
        int freeWidth;
        int height;
        List<Node> children;


        Node(int w, int h, List<Node> c) {
            width = w;
            height = h;
            children = c;
            freeWidth = w;
            for (Node n : c) {
                freeWidth -= n.width;
            }
        }
    }

    static Node composeTree(int[] a) {
        int min = (int)1e9;
        for (int i = 0; i < a.length ; i++) {
            min = Math.min(min, a[i]);
        }
        for (int i = 0; i < a.length; i++) {
            a[i] -= min;
        }

        List<Node> children = new ArrayList<>();
        int last = 0;
        for (int i = 0; i <= a.length ; i++) {
            if (i == a.length || a[i] == 0) {
                // [last, i)
                if (last < i) {
                    int[] sub = Arrays.copyOfRange(a, last, i);
                    children.add(composeTree(sub));
                }
                last = i+1;
            }
        }
        return new Node(a.length, min, children);
    }

    static long pow(long a, long x) {
        long res = 1;
        while (x > 0) {
            if (x % 2 != 0) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            x /= 2;
        }
        return res;
    }

    static long inv(long a) {
        return pow(a, MOD - 2) % MOD;
    }

    static long[] _fact;
    static long[] _invfact;

    static long comb(long ln, long lr) {
        int n = (int) ln;
        int r = (int) lr;
        if (n < 0 || r < 0 || r > n) {
            return 0;
        }
        if (r > n / 2) {
            r = n - r;
        }
        return (((_fact[n] * _invfact[n - r]) % MOD) * _invfact[r]) % MOD;
    }

    static void prec(int n) {
        _fact = new long[n + 1];
        _invfact = new long[n + 1];
        _fact[0] = 1;
        _invfact[0] = 1;
        for (int i = 1; i <= n; i++) {
            _fact[i] = _fact[i - 1] * i % MOD;
            _invfact[i] = inv(_fact[i]);
        }
    }


    private static String[] key(int ptn, char[] c, int l, int r) {
        StringBuilder L = new StringBuilder();
        StringBuilder R = new StringBuilder();
        int n = r - l;
        for (int j = 0; j < n ; j++) {
            if ((ptn & (1<<j)) >= 1) {
                L.append(c[l+j]);
            } else {
                R.append(c[l+j]);
            }
        }
        return new String[]{L.toString(), R.reverse().toString()};
    }

    private static boolean solve(long a, long b, long c, long d) {
        if (d < b) {
            return false;
        }
        if (c >= b) {
            return true;
        }
        if (a < b) {
            return false;
        }
        long next0 = limit(a, b, c);
        long next1 = limit(next0 + d, b, c);
        if (next0 < 0 || next1 < 0) {
            return false;
        }
        long diff = next1 - next0;
        if (diff == 0) {
            return true;
        }

        

        return false;

    }

    private static long limit(long a, long b, long c) {
        return (a <= c) ? (a - b) : (a - ((a - c + b - 1) / b) * b);
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