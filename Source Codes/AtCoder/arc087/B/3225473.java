import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    InputStream is;

    int __t__ = 1;
    int __f__ = 0;
    int __FILE_DEBUG_FLAG__ = __f__;
    String __DEBUG_FILE_NAME__ = "src/D1";

    FastScanner in;
    PrintWriter out;

    public void solve() {
        String s = in.next();
        int x = in.nextInt(), y = in.nextInt();

        int n = s.length();
        int sy = 0, sx = 0;
        int idx = 0;
        while (idx < n && s.charAt(idx) == 'F') {
            sx++;
            idx++;
        }

        int r = 0;
        List<Integer> xs = new ArrayList<>();
        List<Integer> ys = new ArrayList<>();

        boolean isX = true;
        for (int i = idx; i < n; i++) {
            if (s.charAt(i) == 'T') {
                if (r != 0) {
                    if (isX) {
                        xs.add(r);
                    } else {
                        ys.add(r);
                    }
                }
                isX = !isX;
                r = 0;
            } else {
                r++;
            }
        }
        if (r != 0) {
            if (isX) {
                xs.add(r);
            } else {
                ys.add(r);
            }
        }

        if (isOk(xs, x - sx) && isOk(ys, y - sy)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private boolean isOk(List<Integer> xs, int gx) {
        int sum = 1;
        for (int x : xs) {
            sum += x;
        }
        final int MAX = sum * 2 + 1;
        final int CENTER = MAX / 2;
        boolean[] prev = new boolean[MAX];
        boolean[] next = new boolean[MAX];

        prev[CENTER] = true;

        for (int x : xs) {
            Arrays.fill(next, false);
            for (int i = 0; i < MAX; i++) {
                if (!prev[i]) continue;
                if (i + x < MAX) {
                    next[i+x] = true;
                }
                if (i - x >= 0) {
                    next[i-x] = true;
                }
            }
            boolean[] t = prev; prev = next; next = t;
        }
        return (CENTER + gx >= 0 && CENTER + gx < MAX && prev[CENTER+gx]);
    }

    public void run() {
        if (__FILE_DEBUG_FLAG__ == __t__) {
            try {
                is = new FileInputStream(__DEBUG_FILE_NAME__);
            } catch (FileNotFoundException e) {
                // TODO ??????? catch ????
                e.printStackTrace();
            }
            System.out.println("FILE_INPUT!");
        } else {
            is = System.in;
        }
        in = new FastScanner(is);
        out = new PrintWriter(System.out);

        solve();
    }

    public static void main(final String[] args) {
        new Main().run();
    }

    class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public FastScanner(InputStream stream) {
            this.stream = stream;
            // stream = new FileInputStream(new File("dec.in"));

        }

        int read() {
            if (numChars == -1)
                throw new InputMismatchException();
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

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        boolean isEndline(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; i++)
                array[i] = nextInt();

            return array;
        }

        int[][] nextIntMap(int n, int m) {
            int[][] map = new int[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextIntArray(m);
            }
            return map;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        long[] nextLongArray(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; i++)
                array[i] = nextLong();

            return array;
        }

        long[][] nextLongMap(int n, int m) {
            long[][] map = new long[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextLongArray(m);
            }
            return map;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        double[] nextDoubleArray(int n) {
            double[] array = new double[n];
            for (int i = 0; i < n; i++)
                array[i] = nextDouble();

            return array;
        }

        double[][] nextDoubleMap(int n, int m) {
            double[][] map = new double[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextDoubleArray(m);
            }
            return map;
        }

        String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        String[] nextStringArray(int n) {
            String[] array = new String[n];
            for (int i = 0; i < n; i++)
                array[i] = next();

            return array;
        }

        String nextLine() {
            int c = read();
            while (isEndline(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndline(c));
            return res.toString();
        }
    }
}