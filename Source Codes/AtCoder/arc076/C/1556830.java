// package arc.arc076;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int r = in.nextInt();
        int c = in.nextInt();
        int n = in.nextInt();
        List<int[]> points = new ArrayList<>();
        for (int i = 0; i < n ; i++) {
            int[] ho = new int[4];
            for (int j = 0; j < 4 ; j++) {
                ho[j] = in.nextInt();
            }

            int from = encode(r, c, ho[0], ho[1]);
            int to = encode(r, c, ho[2], ho[3]);
            if (from == -1 || to == -1) {
                continue;
            }
            points.add(new int[]{from, to});
        }

        out.println(solve(points) ? "YES" : "NO");
        out.flush();
    }

    private static boolean solve(List<int[]> points) {
        int n = points.size();
        if (n <= 1) {
            return true;
        }

        Set<Integer> set = new HashSet<>();
        for (int[] p : points) {
            set.add(p[0]);
            set.add(p[1]);
        }
        List<Integer> arr = new ArrayList<>(set);
        Collections.sort(arr);
        Map<Integer,Integer> mp = new HashMap<>();
        for (int i = 0 ; i < arr.size() ; i++) {
            mp.put(arr.get(i), i);
        }

        int M = mp.size();
        int[] io = new int[M];
        int[][] ranges = new int[n][2];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 2 ; j++) {
                ranges[i][j] = mp.get(points.get(i)[j]);
                io[ranges[i][j]] = i;
            }
        }

        int from = Math.min(ranges[0][0], ranges[0][1]);
        int to = Math.max(ranges[0][0], ranges[0][1]);

        if (!check(new int[][]{{from+1, to-1}}, io)) {
            return false;
        }
        if (!check(new int[][]{{to+1, M-1}, {0, from-1}}, io)) {
            return false;
        }
        return true;
    }

    private static boolean check(int[][] ranges, int[] io) {
        Stack<Integer> stk = new Stack<>();
        for (int[] r : ranges) {
            if (!dostk(stk, r[0], r[1], io)) {
                return false;
            }
        }
        return stk.size() == 0;
    }

    private static boolean dostk(Stack<Integer> stk, int from, int to, int[] io) {
        for (int f = from ; f <= to ; f++) {
            int x = io[f];
            if (stk.size() >= 1 && stk.peek() == x) {
                stk.pop();
            } else {
                stk.push(x);
            }
        }
        return true;
    }

    private static int encode(int R, int C, int y, int x) {
        if (y == 0) {
            return x;
        } else if (x == C) {
            return C + y;
        } else if (y == R) {
            return C + R + (C - x);
        } else if (x == 0) {
            return 2 * C + R + (R - y);
        } else {
            return -1;
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