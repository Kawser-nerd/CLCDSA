// package arc.arc075;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int k = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt() - k;
        }
        long[] imos = new long[n+1];
        for (int i = 0; i < n ; i++) {
            imos[i+1] = imos[i] + a[i];
        }

        Set<Long> set = new HashSet<>();
        for (int i = 0; i <= n; i++) {
            set.add(imos[i]);
        }
        List<Long> arr = new ArrayList<>(set);
        Collections.sort(arr);
        Map<Long,Integer> mp = new HashMap<>();
        for (int i = 0; i < arr.size() ; i++) {
            mp.put(arr.get(i), i);
        }

        FenwickTree fen = new FenwickTree(mp.size() + 10);

        long ans = 0;
        for (int r = 0 ; r <= n ; r++) {
            int lessOrEq = mp.get(imos[r]);
            ans += fen.range(1, lessOrEq+1);
            fen.add(lessOrEq+1, 1);
        }

        out.println(ans);
        out.flush();
    }

    public static class FenwickTree {
        long N;
        long[] data;

        public FenwickTree(int n) {
            N = n;
            data = new long[n + 1];
        }

        /**
         * Computes value of [1, i].
         * <p>
         * O(logn)
         *
         * @param i
         * @return
         */
        public long sum(int i) {
            long s = 0;
            while (i > 0) {
                s += data[i];
                i -= i & (-i);
            }
            return s;
        }

        /**
         * Computes value of [i, j].
         * <p>
         * O(logn)
         *
         * @param i
         * @param j
         * @return
         */
        public long range(int i, int j) {
            return sum(j) - sum(i - 1);
        }

        /**
         * Sets value x into i-th position.
         * <p>
         * O(logn)
         *
         * @param i
         * @param x
         */
        public void set(int i, long x) {
            add(i, x - range(i, i));
        }

        /**
         * Adds value x into i-th position.
         * <p>
         * O(logn)
         *
         * @param i
         * @param x
         */
        public void add(int i, long x) {
            while (i <= N) {
                data[i] += x;
                i += i & (-i);
            }
        }
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