import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {
    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long[][] lr = new long[n][2];
        for (int i = 0; i < n ; i++) {
            lr[i][0] = in.nextInt();
            lr[i][1] = in.nextInt();
        }

        Hoge hoge = new Hoge(lr[0][0]);
        for (int i = 1 ; i < n ; i++) {
            hoge.left.addAll(-lr[i][1]+lr[i][0]);
            hoge.right.addAll(lr[i-1][1]-lr[i-1][0]);

            long L = hoge.getLeftMost();
            long R = hoge.getRightMost();
            if (L > R) {
                throw new RuntimeException("L <= R must be hold");
            }

            if (L < lr[i][0] && lr[i][0] < R) {
                hoge.left.addPoint(lr[i][0]);
                hoge.right.addPoint(lr[i][0]);
            } else if (lr[i][0] <= L) {
                hoge.left.addPoint(lr[i][0]);
                hoge.left.addPoint(lr[i][0]);
                hoge.right.addPoint(hoge.left.removePoint(L));
                hoge.minValue += Math.abs(L - lr[i][0]);
            } else {
                hoge.right.addPoint(lr[i][0]);
                hoge.right.addPoint(lr[i][0]);
                hoge.left.addPoint(hoge.right.removePoint(R));
                hoge.minValue += Math.abs(R - lr[i][0]);
            }
        }

        out.println(hoge.minValue);
        out.flush();
    }


    static class Hoge {
        Lines left = new Lines();
        Lines right = new Lines();
        long minValue = 0;

        public Hoge(long x0) {
            left.addPoint(x0);
            right.addPoint(x0);
        }

        public long getLeftMost() {
            return left.positions.lastKey() + left.addAll;
        }

        public long getRightMost() {
            return right.positions.firstKey() + right.addAll;
        }

    }

    static class Lines {
        public TreeMap<Long, Integer> positions = new TreeMap<>();
        public long addAll = 0;

        public void addPoint(long x) {
            long ax = x - addAll;
            positions.put(ax, positions.getOrDefault(ax, 0)+1);
        }

        public long removePoint(long x) {
            long ax = x - addAll;
            if (!positions.containsKey(ax)) {
                throw new RuntimeException("key not exists");
            }
            if (positions.get(ax) == 1) {
                positions.remove(ax);
            } else {
                positions.put(ax, positions.get(ax)-1);
            }
            return x;
        }

        public void addAll(long d) {
            addAll += d;
        }


    }

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