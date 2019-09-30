import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int q = in.nextInt();
        while (--q >= 0) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt()-1;
            int d = in.nextInt();
            out.println(solve(a, b, c, d));
        }

        out.flush();
    }

    private static String solve(int a, int b, int L, int R) {
        if (a == 0 || b == 0) {
            char[] res = new char[R-L];
            for (int i = 0; i <  res.length; i++) {
                res[i] = a == 0 ? 'B' : 'A';
            }
            return String.valueOf(res);
        }
        if (a == b) {
            char[] res = new char[R-L];
            for (int i = 0; i < res.length ; i++) {
                res[i] = (L+i)%2 == 0 ? 'A' : 'B';
            }
            return String.valueOf(res);
        }
        if (b > a) {
            char[] r = solve(b, a, a+b-R, a+b-L).toCharArray();
            char[] r2 = r.clone();
            for (int i = 0; i < r.length; i++) {
                r2[i] = r[r.length-1-i] == 'A' ? 'B' : 'A';
            }
            return String.valueOf(r2);
        }

        int maxRep = a / (b + 1) + ((a % (b + 1)) == 0 ? 0 : 1);
        List<long[]> patterns = new ArrayList<>();
        long leftA = a;
        long leftB = b;
        {
            long min = 0;
            long max = a+b;
            while (max - min > 1) {
                long med = (max + min) / 2;
                if (canMake(leftA - med * maxRep, leftB - med, maxRep)) {
                    min = med;
                } else {
                    max = med;
                }
            }
            if (min >= 1) {
                leftA -= maxRep * min;
                leftB -= min;
                patterns.add(new long[]{maxRep, 1, min});
            }
        }

        // small A, large B
        if (leftB >= 1) {
            long reqminA = leftB / maxRep;
            if (leftB % maxRep == 0) {
                reqminA--;
            }
            long appendA = leftA - reqminA;
            if (appendA > maxRep) {
                throw new RuntimeException("ng");
            }
            if (appendA >= 2) {
                patterns.add(new long[]{appendA - 1, 0, 1});
            }
            long fullB = leftB / maxRep;
            if (leftB % maxRep >= 1) {
                patterns.add(new long[]{1, leftB % maxRep, 1});
            }
            patterns.add(new long[]{1, maxRep, fullB});
        } else {
            if (leftA > maxRep) {
                throw new RuntimeException("ng2");
            }
            patterns.add(new long[]{leftA, 0, 1});
        }

        long all = 0;
        for (long[] p : patterns) {
            all += (p[0] + p[1]) * p[2];
        }
        if (all != a + b) {
            throw new RuntimeException("ng3");
        }

        return makeIt(patterns, L, R);
    }

    static String makeIt(List<long[]> ptn, long L, long R) {
        StringBuilder ln = new StringBuilder();
        for (long pos = L ; pos < R ; pos++) {
            long head = 0;
            for (long[] k : ptn) {
                long to = head + (k[0] + k[1]) * k[2];
                if (head <= pos && pos < to) {
                    long offset = (pos - head) % (k[0] + k[1]);
                    if (offset < k[0]) {
                        ln.append('A');
                    } else {
                        ln.append('B');
                    }
                    break;
                }
                head = to;
            }
        }
        return ln.toString();
    }

    static boolean canMake(long leftA, long leftB, long maxRep) {
        if (leftA <= 0 || leftB < 0) {
            return false;
        }
        long p = leftA / (leftB + 1);
        if (leftA % (leftB + 1) > 0) {
            p++;
        }
        long q = leftB / leftA;
        if (leftB  % leftA > 0) {
            q++;
        }
        return Math.max(p, q) <= maxRep;
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