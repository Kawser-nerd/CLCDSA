import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Stack;
import java.util.Vector;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ogiekako
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyScanner in = new MyScanner(inputStream);
        MyPrintWriter out = new MyPrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
            int h = in.nextInt(), w = in.nextInt();
            char[][] map = new char[h][w];
            for (int i = 0; i < h; i++) {
                map[i] = in.next().toCharArray();
            }
            boolean[][] grid = new boolean[h - 1][w - 1];
            for (int i = 0; i < h - 1; i++) {
                for (int j = 0; j < w - 1; j++) {
                    grid[i][j] = (map[i][j] != map[i][j + 1]) == (map[i + 1][j] != map[i + 1][j + 1]);
                }
            }
            int res = Math.max(h, w);
            int[] rect = MaxRectangle.maximalRectangles(grid);
            for (int i = 1; i < rect.length; i++) {
                res = Math.max(res, (i + 1) * (rect[i] + 1));
            }
            out.println(res);
        }

    }

    static class MyScanner {
        private final InputStream in;
        private static final int BUFSIZE = 65536;
        int bufLen;
        int bufPtr;
        byte[] buf = new byte[BUFSIZE];
        private char[] strBuf = new char[BUFSIZE];

        public MyScanner(InputStream in) {
            this.in = in;
        }

        public int read() {
            if (bufLen == -1)
                throw new InputMismatchException();
            if (bufPtr >= bufLen) {
                bufPtr = 0;
                try {
                    bufLen = in.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (bufLen <= 0)
                    return -1;
            }
            return buf[bufPtr++];
        }

        public String next() {
            int strLen = 0;
            int c;
            do {
                c = read();
                if (c == -1) throw new NoSuchElementException();
            } while (Character.isWhitespace(c));
            do {
                if (strLen + 1 >= strBuf.length) {
                    char[] tmp = new char[strBuf.length * 2];
                    System.arraycopy(strBuf, 0, tmp, 0, strBuf.length);
                    strBuf = tmp;
                }
                strBuf[strLen++] = (char) c;
                c = read();
            } while (c != -1 && !Character.isWhitespace(c));
            return new String(strBuf, 0, strLen);
        }

        public int nextInt() {
            int c = read();
            if (c == -1) throw new NoSuchElementException();
            while (c != '-' && (c < '0' || '9' < c)) {
                c = read();
                if (c == -1) throw new NoSuchElementException();
            }
            if (c == '-') return -nextInt();
            int res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while ('0' <= c && c <= '9');
            return res;
        }

    }

    static class MyPrintWriter {
        PrintWriter out;

        public MyPrintWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public MyPrintWriter(Writer writer) {
            out = new PrintWriter(writer);
        }

        public void println(int a) {
            out.println(a);
        }

        public void close() {
            out.close();
        }

    }

    static class MaxRectangle {
        public static int[] maximalRectangles(int[] histogram) {
            class E {
                int height;
                int pos;
            }

            histogram = Arrays.copyOf(histogram, histogram.length + 1);
            int[] res = new int[histogram.length];

            Stack<E> S = new Stack<>();
            for (int i = 0; i < histogram.length; i++) {
                E e = new E();
                e.height = histogram[i];
                e.pos = i;
                if (S.isEmpty()) {
                    S.push(e);
                } else {
                    if (S.peek().height < e.height) {
                        S.push(e);
                    } else if (S.peek().height > e.height) {
                        int target = i;
                        while (!S.empty() && S.peek().height >= e.height) {
                            E pre = S.pop();
                            int w = i - pre.pos;
                            res[w] = Math.max(res[w], pre.height);
                            target = pre.pos;
                        }
                        e.pos = target;
                        S.push(e);
                    }
                }
            }
            return res;
        }

        public static int[] maximalRectangles(boolean[][] grid) {
            if (grid.length == 0) return new int[0];
            int[] res = new int[grid[0].length + 1];
            int[] histogram = new int[grid[0].length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    histogram[j] = grid[i][j] ? histogram[j] + 1 : 0;
                }
                int[] cur = maximalRectangles(histogram);
                for (int j = 0; j < res.length; j++) {
                    res[j] = Math.max(res[j], cur[j]);
                }
            }
            return res;
        }

    }
}