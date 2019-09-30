import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            String w = in.next();

            TaskB.Card c = new TaskB.Card(x, y, w);
            for (int cy = 0; cy < 9; cy++) {
                String s = in.next();
                for (int cx = 0; cx < 9; cx++) {
                    c.set(cx, cy, s.charAt(cx));
                }
            }

            out.println(c.getNum());
        }

        static class Card {
            int x;
            int y;
            String w;
            char[][] c;

            Card(int x, int y, String w) {
                this.x = x;
                this.y = y;
                this.w = w;
                c = new char[9][9];
            }

            void set(int x, int y, char c) {
                this.c[x][y] = c;
            }

            String getNum() {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < 4; i++) {
                    sb.append(c[x][y]);
                    move();
                }
                return sb.toString();
            }

            private void move() {
                if (x == 0)
                    w = w.replace("L", "R");
                if (x == 8)
                    w = w.replace("R", "L");
                if (y == 0)
                    w = w.replace("U", "D");
                if (y == 8)
                    w = w.replace("D", "U");
                if (w.contains("R"))
                    x++;
                if (w.contains("L"))
                    x--;
                if (w.contains("D"))
                    y++;
                if (w.contains("U"))
                    y--;
            }

        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
            this.bufPointer = 0;
            this.bufLength = 0;
        }

        private int readByte() {
            if (bufPointer >= bufLength) {
                if (bufLength == -1)
                    throw new InputMismatchException();

                bufPointer = 0;
                try {
                    bufLength = in.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (bufLength <= 0)
                    return -1;
            }
            return buffer[bufPointer++];
        }

        private static boolean isPrintableChar(int c) {
            return c >= 33 && c <= 126;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            StringBuilder sb = new StringBuilder();

            int b = readByte();
            while (!isPrintableChar(b))
                b = readByte();

            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }

            return sb.toString();
        }

        public int nextInt() {
            int n = 0;

            int b = readByte();
            while (isSpaceChar(b))
                b = readByte();

            boolean minus = (b == '-');
            if (minus)
                b = readByte();

            while (b >= '0' && b <= '9') {
                n *= 10;
                n += b - '0';
                b = readByte();
            }

            if (!isSpaceChar(b))
                throw new NumberFormatException();

            return minus ? -n : n;
        }

    }
}