import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
            int[][] grid = new int[h - 1][w];
            for (int i = 0; i < h - 1; i++) {
                for (int j = 0; j < w - 1; j++) {
                    grid[i][j] = (map[i][j] != map[i][j + 1]) == (map[i + 1][j] != map[i + 1][j + 1]) ? 1 : 0;
                }
            }
            for (int i = 0; i < h - 1; i++) {
                for (int j = 0; j < w - 1; j++) {
                    if (i > 0 && grid[i][j] == 1) grid[i][j] += grid[i - 1][j];
                }
            }
            int res = Math.max(h, w);
            for (int i = 0; i < grid.length; i++) {
                res = Math.max(res, getLargestRectangle(w - 1, grid[i]));
            }
            out.println(res);
        }

        int getLargestRectangle(int size, int buffer[]) {
            Stack<Rectangle> S = new Stack<>();
            int maxv = 0;
            buffer[size] = 0;

            for (int i = 0; i <= size; i++) {
                Rectangle rect = new Rectangle();
                rect.height = buffer[i];
                rect.pos = i;
                if (S.isEmpty()) {
                    S.push(rect);
                } else {
                    if (S.peek().height < rect.height) {
                        S.push(rect);
                    } else if (S.peek().height > rect.height) {
                        int target = i;
                        while (!S.empty() && S.peek().height >= rect.height) {
                            Rectangle pre = S.peek();
                            S.pop();
                            int area = (pre.height + 1) * (i - pre.pos + 1);
                            maxv = Math.max(maxv, area);
                            target = pre.pos;
                        }
                        rect.pos = target;
                        S.push(rect);
                    }
                }
            }
            return maxv;
        }

        class Rectangle {
            int height;
            int pos;

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
}