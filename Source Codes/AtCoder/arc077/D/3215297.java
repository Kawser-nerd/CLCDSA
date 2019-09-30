import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);


        String s = in.nextToken();
        String c0 = next(s);
        String c1 = next(c0);
        String c0half = c0.substring(0, c0.length()/2);
        String c1half = c1.substring(0, c1.length()/2);

        parts = new Parts[500];
        parts[0] = new Parts(c0half);
        parts[1] = new Parts(c1half);
        for (int i = 2 ; i < parts.length ; i++) {
            parts[i] = new Parts(parts[i-2], parts[i-1]);
        }

        long l = in.nextLong();
        long r = in.nextLong();


        long[] a = solve(l-1);
        long[] b = solve(r);
        for (int i = 0; i < a.length ; i++) {
            if (i >= 1) {
                out.print(' ');
            }
            out.print(b[i]-a[i]);
        }
        out.println();
        out.flush();
    }

    static class Parts {
        String C;
        long[] degree;
        long length;

        public Parts(String c0) {
            C = c0;
            length = c0.length();
            degree = new long[26];
            for (int i = 0; i < length ; i++) {
                degree[c0.charAt(i)-'a']++;
            }
        }

        public Parts(Parts left, Parts right) {
            length = left.length + right.length;
            degree = new long[26];
            for (int i = 0; i < degree.length; i++) {
                degree[i] = left.degree[i] + right.degree[i];
            }
        }
    }

    static Parts[] parts;

    private static long[] solve(long l) {
        for (int i = 0; i < parts.length; i++) {
            if (parts[i].length > l) {
                return doit(i, l);
            }
        }
        throw new RuntimeException("not enough:" + l);
    }

    private static long[] doit(int level, long L) {
        long[] ret = new long[26];
        if (L == 0) {
            return ret;
        }

        if (level <= 1) {
            int ln = parts[level].C.length();
            if (ln < L) {
                throw new RuntimeException("not enough length base case:" + level + "/" + L);
            }
            for (int i = 0; i < L ; i++) {
                ret[parts[level].C.charAt(i)-'a']++;
            }
            return ret;
        }

        long a = parts[level-1].length;
        long b = parts[level-2].length;
        if (a + b < L) {
            throw new RuntimeException("not enough length:" + level + "/" + L + "vs" + (a + b));
        } else if (a + b == L) {
            return parts[level].degree;
        }

        if (L <= a) {
            return doit(level-1, L);
        } else {
            long[] r = doit(level-2, L-a);
            for (int i = 0; i < 26; i++) {
                ret[i] = parts[level-1].degree[i] + r[i];
            }
            return ret;
        }
    }

    private static String next(String a) {
        int n = a.length();

        long[] prefix = new long[2];
        long[] suffix = new long[2];

        long[] mulPow = {1, 1};

        int longestMatch = 0;
        for (int x = 0; x < (n+1)/2-1 ; x++) {
            int h = a.charAt(x)-'a';
            int t = a.charAt(n-1-x)-'a';

            boolean same = true;
            for (int w = 0; w < 2 ; w++) {
                prefix[w] = (prefix[w] * mul[w] + h) % mod[w];
                suffix[w] = (suffix[w] + mulPow[w] * t) % mod[w];
                mulPow[w] = mulPow[w] * mul[w] % mod[w];
                same &= prefix[w] == suffix[w];
            }
            if (same) {
                longestMatch = x+1;
            }
        }
        String pair = a.substring(0, a.length()-longestMatch);
        return pair + pair;
    }

    static long[] mul = new long[]{31, 1009};
    static long[] mod = new long[]{(long)1e9+7, (long)1e9+9};


    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
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