// package agc.agc020;

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

        int q  = in.nextInt();
        while (--q >= 0) {
            long a = in.nextLong();
            long b = in.nextLong();
            int c = in.nextInt();
            int d = in.nextInt();
            String ret = solve(a, b, c-1, d);
            out.println(ret);
        }
        out.flush();
    }

    private static boolean canMakeA(long leftA, long leftB, long maxLength) {
        if (leftA < 0 || leftB < 0) {
            return false;
        }
        if (leftA + leftB == 0) {
            return true;
        }
        if (leftA == 0) {
            return false;
        }
        long contA = (leftA + leftB) / (leftB + 1);
        if (contA > maxLength) {
            return false;
        }
        long contB = (leftB + leftA - 1) / leftA;
        if (contB > maxLength) {
            return false;
        }
        return true;
    }

    private static boolean canMakeB(long leftA, long leftB, long maxLength) {
        if (leftA < 0 || leftB < 0) {
            return false;
        }
        if (leftA + leftB == 0) {
            return true;
        }
        if (leftB == 0) {
            return false;
        }
        long contA = (leftA + leftB - 1) / leftB;
        if (contA > maxLength) {
            return false;
        }
        long contB = (leftB + leftA) / (leftA + 1);
        if (contB > maxLength) {
            return false;
        }
        return true;
    }

    private static String solveSmall(long a, long b, int c, int d) {
        long min = Math.min(a, b);
        long max = Math.max(a, b);
        long maxlen = (max + min) / (min + 1);
        long total = a + b;
        long cont = 0;
        char last = '-';

        StringBuilder line = new StringBuilder();

        for (int i = 0; i < total ; i++) {
            boolean useA = false;
            long nc = (last == 'A') ? cont + 1 : 1;
            if (a >= 1 && nc <= maxlen && (canMakeA(a-1, b, maxlen) || canMakeB(a-1, b, maxlen))) {
                useA = true;
            }
            if (useA) {
                cont = (last == 'A') ? cont + 1 : 1;
                line.append('A');
                a--;
                last = 'A';
            } else {
                cont = (last == 'B') ? cont + 1 : 1;
                line.append('B');
                b--;
                last = 'B';
            }
        }
        char[] cc = line.toString().toCharArray();

        StringBuilder ans = new StringBuilder();
        for (int i = c; i < d; i++) {
            ans.append(cc[i]);
        }
        return ans.toString();
    }

    private static String solve(long a, long b, int c, int d) {
        long maxlen = (Math.max(a, b) + Math.min(a, b)) / (Math.min(a, b) + 1);
        if (maxlen == 1) {
            StringBuilder line = new StringBuilder();
            for (int i = c ; i < d ; i++) {
                line.append((i % 2 == 0) ^ (a < b) ? 'A' : 'B');
            }
            return line.toString();
        }
        if (a < b) {
            char[] ret = solveAB(b, a, a+b-1-d+1, a+b-c).toCharArray();
            StringBuilder line = new StringBuilder();
            for (int i = ret.length-1 ; i >= 0; i--) {
                line.append(ret[i] == 'A' ? 'B' : 'A');
            }
            return line.toString();
        } else {
            return solveAB(a, b, c, d);
        }
    }

    private static String solveAB(long a, long b, long c, long d) {
        long maxlen = (Math.max(a, b) + Math.min(a, b)) / (Math.min(a, b) + 1);
        List<long[]> ptn = new ArrayList<>();

        {
            long min = 1;
            long max = 10000000000L;
            while (max - min > 1) {
                long med = (max + min) / 2;
                long ua = maxlen * med;
                long ub = med;
                if (canMakeA(a-ua, b-ub, maxlen)) {
                    min = med;
                } else {
                    max = med;
                }
            }
            a -= min * maxlen;
            b -= min;
            ptn.add(new long[]{maxlen, 1, min});
        }

        if (b >= 1) {
            long minA = 0;
            long maxA = Math.min(a, maxlen) + 1;
            while (maxA - minA > 1) {
                long med = (maxA + minA) / 2;
                if (canMakeB(a-med, b, maxlen)) {
                    minA = med;
                } else {
                    maxA = med;
                }
            }
            ptn.add(new long[]{minA, 0, 1});
            a -= minA;
        } else {
            ptn.add(new long[]{a, 0, 1});
            a = 0;
        }

        if (b >= 1) {
            if (a == 0) {
                ptn.add(new long[]{0, b, 1});
                b = 0;
            } else {
                debug(a, b, maxlen);
                long amari = (b % maxlen == 0) ? maxlen : b % maxlen;
                ptn.add(new long[]{0, amari, 1});
                b -= amari;
                debug(a, b, maxlen);


                ptn.add(new long[]{1, maxlen, a});
                b -= a * maxlen;
                a = 0;
            }
        }
        return composeString(c, d, ptn);
    }

    public static String composeString(long c, long d, List<long[]> ptn) {
        StringBuilder line = new StringBuilder();
        for (long i = c ; i < d ; i++) {
            long head = 0;
            for (long[] x : ptn) {
                long to = head + (x[0] + x[1]) * x[2];
                if (head <= i && i < to) {
                    long offset = (i - head) % (x[0] + x[1]);
                    if (offset < x[0]) {
                        line.append('A');
                    } else {
                        line.append('B');
                    }
                    break;
                } else {
                    head = to;
                }
            }
        }
        return line.toString();
    }

    public static void debugL(List<long[]> a) {
        String x = "";
        for (long[] f : a) {
            x += " ";
            x += "[";
            for (long ff : f) {
                x += ff;
                x += ",";
            }
            x += "]";
            x += ",";
        }
        debug(x);
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