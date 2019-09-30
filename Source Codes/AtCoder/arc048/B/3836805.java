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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();

            int[][] hr = new int[3][100001];
            int[] winR = new int[100001];
            int[][] winH = new int[3][100001];
            int[] r = new int[n];
            int[] h = new int[n];
            for (int i = 0; i < n; i++) {
                r[i] = in.nextInt();
                h[i] = in.nextInt() - 1;
                hr[h[i]][r[i]] += 1;
            }

            winR[0] = 0;
            for (int i = 1; i <= 100000; i++) {
                winR[i] = winR[i - 1] + hr[0][i - 1] + hr[1][i - 1] + hr[2][i - 1];
                winH[0][i] = winR[i] + hr[1][i];
                winH[1][i] = winR[i] + hr[2][i];
                winH[2][i] = winR[i] + hr[0][i];
            }

            for (int i = 0; i < n; i++) {
                int cw = winH[h[i]][r[i]];
                int cd = hr[h[i]][r[i]] - 1;
                int cl = n - 1 - cw - cd;
                out.printf("%d %d %d\n", cw, cl, cd);
            }
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer;
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
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
            return hasNextByte() ? buffer[bufPointer++] : -1;
        }

        private static boolean isPrintableChar(int c) {
            return (c >= 33 && c <= 126);
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[bufPointer]))
                bufPointer++;
            return hasNextByte();
        }

        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
                throw new NumberFormatException();
            return (int) nl;
        }

        public long nextLong() {
            if (!hasNext())
                throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || b > '9')
                throw new NumberFormatException();

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