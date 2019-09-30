import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        out.println(solve(in.nextToken()));
        out.flush();
    }

    private static long solve(String _s) {
        char[] s = _s.toCharArray();
        int n = s.length;
        List<Integer>[] chars = new List[26];
        for (int i = 0; i < 26; i++) {
            chars[i] = new ArrayList<>();
        }
        for (int i = 0; i < s.length; i++) {
            int idx = s[i]-'a';
            chars[idx].add(i+1);
        }

        // 1-indexed, inclusive-inclusive
        List<int[]> ranges = new ArrayList<>();
        int center = -1;
        for (int i = 0; i < chars.length; i++) {
            int cn = chars[i].size();
            for (int j = 0; j < cn/2 ; j++) {
                ranges.add(new int[]{  chars[i].get(j), chars[i].get(cn-1-j) });
            }
            if (cn % 2 == 1) {
                if (center != -1) {
                    return -1;
                }
                center = chars[i].get(cn/2);
            }
        }



        FenwickTree left = new FenwickTree(n+10);
        FenwickTree right = new FenwickTree(n+10);
        for (int[] r : ranges) {
            left.add(r[0], 1);
            right.add(r[1], 1);
        }

        // aabb pattern
        long total2 = 0;
        for (int[] r : ranges) {
            total2 += right.range(1, r[0]-1);
            total2 += left.range(r[1]+1, n);
        }
        if (center != -1) {
            total2 += right.range(1, center-1);
            total2 += left.range(center+1, n);
        }

        FenwickTree isIn = new FenwickTree(n+10);
        int[] begin = new int[n+1];
        for (int[] r : ranges) {
            begin[r[0]] = -1;
            begin[r[1]] = r[0];
        }

        debug(begin);

        // abab pattern
        long total1 = 0;
        for (int i = 1 ; i <= n ; i++) {
            if (i == center) {
                continue;
            }

            if (begin[i] == -1) {
                isIn.add(i, 1);
            } else {
                total1 += isIn.range(begin[i]+1, i-1);
                isIn.add(begin[i], -1);
            }
        }
        return total2 + total1;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.