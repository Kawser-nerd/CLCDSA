import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        if (n == 1) {
            out.println(0);
            out.flush();
            return;
        }

        int[][] xy = new int[n][2];
        for (int i = 0; i < n ; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            xy[i][0] = Math.min(a, b);
            xy[i][1] = Math.max(a, b);
        }


        long best = (long)1e18;

        {
            // Rmin = min
            // Bmax = max
            long rmin = (long)1e18;
            long rmax = 0;
            long bmin = (long)1e18;
            long bmax = 0;
            for (int i = 0; i < n ; i++) {
                rmin = Math.min(rmin, xy[i][0]);
                rmax = Math.max(rmax, xy[i][0]);
                bmin = Math.min(bmin, xy[i][1]);
                bmax = Math.max(bmax, xy[i][1]);
            }
            best = Math.min(best, (rmax-rmin)*(bmax-bmin));
        }


        {
            // Rmin = min
            // Rmax = max
            long rmin = (long)1e18;
            long rmax = 0;
            long bmin = (long)1e18;
            long bmax = 0;
            Arrays.sort(xy, Comparator.comparingInt(u -> u[0]));

            int maxIdx = 1;
            for (int i = 1 ; i < n ; i++) {
                if (xy[maxIdx][1]< xy[i][1]) {
                    maxIdx = i;
                }
            }
            for (int i : new int[]{0, maxIdx}) {
                int w = i == 0 ? 0 : 1;
                rmin = Math.min(rmin, xy[i][w]);
                rmax = Math.max(rmax, xy[i][w]);
                bmin = Math.min(bmin, xy[i][w^1]);
                bmax = Math.max(bmax, xy[i][w^1]);
            }


            List<int[]> ord = new ArrayList<>();
            for (int i = 1 ; i < n ; i++) {
                if (i != maxIdx) {
                    ord.add(xy[i]);
                }
            }
            long[][] takeRight = new long[ord.size()+1][2];
            long[][] takeLeft = new long[ord.size()+1][2];
            for (int i = 0; i <= ord.size() ; i++) {
                takeLeft[i][0] = (long)1e18;
                takeLeft[i][1] = 0;
                takeRight[i][0] = (long)1e18;
                takeRight[i][1] = 0;
            }

            for (int i = 0; i < ord.size() ; i++) {
                int[] lr = ord.get(i);
                takeRight[i+1][0] = takeRight[i][0];
                takeRight[i+1][1] = takeRight[i][1];
                takeRight[i+1][0] = Math.min(takeRight[i+1][0], lr[1]);
                takeRight[i+1][1] = Math.max(takeRight[i+1][1], lr[1]);
            }
            for (int _i = ord.size()-1 ; _i >= 0 ; _i--) {
                int[] lr = ord.get(_i);
                int i = ord.size()-1-_i;
                takeLeft[i+1][0] = takeLeft[i][0];
                takeLeft[i+1][1] = takeLeft[i][1];
                takeLeft[i+1][0] = Math.min(takeLeft[i+1][0], lr[0]);
                takeLeft[i+1][1] = Math.max(takeLeft[i+1][1], lr[0]);
            }

            for (int i = 0; i <= ord.size(); i++) {
                long tbmin = Math.min(bmin, Math.min(takeLeft[i][0], takeRight[ord.size()-i][0]));
                long tbmax = Math.max(bmax, Math.max(takeLeft[i][1], takeRight[ord.size()-i][1]));
                best = Math.min(best, (rmax-rmin)*(tbmax-tbmin));
            }
        }
        out.println(best);
        out.flush();
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