import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FasterScanner in = new FasterScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FasterScanner in, PrintWriter out) {
            final int h = in.nextInt();
            final int w = in.nextInt();
            final int n = in.nextInt();

            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = in.nextInt();

            int[] f = new int[h * w];
            int index = 0;
            int max = a[index++];
            int cn = 0;
            for (int i = 0; i < h * w; i++) {
                f[i] = index;
                if (++cn >= max && index < n) {
                    cn = 0;
                    max = a[index++];
                }
            }

            boolean[][] checked = new boolean[w][h];
            int[][] field = new int[w][h];

            int cx = 0;
            int cy = 0;
            int dir = (w > 1) ? 0 : 1;

            for (int i = 0; i < h * w; i++) {
                checked[cx][cy] = true;
                field[cx][cy] = f[i];

                if (dir == 0) cx++;
                else if (dir == 1) cy++;
                else if (dir == 2) cx--;
                else cy--;

                if (dir == 0 && (cx + 1 >= w || checked[cx + 1][cy])) dir = 1;
                else if (dir == 1 && (cy + 1 >= h || checked[cx][cy + 1])) dir = 2;
                else if (dir == 2 && (cx - 1 < 0 || checked[cx - 1][cy])) dir = 3;
                else if (dir == 3 && (cy - 1 < 0 || checked[cx][cy - 1])) dir = 0;
            }

            StringBuilder sb = new StringBuilder();
            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    sb.append(field[x][y]);
                    if (x < w - 1) sb.append(" ");
                    else sb.append("\n");
                }
            }
            out.println(sb);
        }

    }

    static class FasterScanner {
        private InputStream in;
        private byte[] buffer;
        private int bufPointer;
        private int bufLength;

        public FasterScanner(InputStream in) {
            this.in = in;
            buffer = new byte[1024];
        }

        private boolean hasNextByte() {
            if (bufPointer < bufLength) return true;
            bufPointer = 0;
            try {
                bufLength = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return (bufLength > 0);
        }

        private int readByte() {
            if (hasNextByte()) return buffer[bufPointer++];
            return -1;
        }

        private static boolean isPrintableChar(int c) {
            return (c >= 33 && c <= 126);
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[bufPointer])) bufPointer++;
            return hasNextByte();
        }

        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }

        public long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || b > '9') throw new NumberFormatException();

            while (true) {
                if (b >= '0' && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

    }
}