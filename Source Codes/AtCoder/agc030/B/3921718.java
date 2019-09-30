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
            long l = in.nextLong();
            int n = in.nextInt();
            long[] a = new long[n + 1];
            long[] scw = new long[n + 1];
            long[] sacw = new long[n + 1];

            for (int i = 1; i <= n; i++)
                a[i] = in.nextLong();

            for (int i = 1; i <= n; i++) {
                scw[i] = scw[i - 1] + a[i];
                sacw[i] = sacw[i - 1] + l - a[n - i + 1];
            }

            long max = Math.max(a[n], l - a[1]);
            for (int i = 1; i < n; i++) {
                long cd = a[i] + sacw[(n - i) / 2] + (scw[i + (n - i) / 2] - scw[i]) + (scw[i + (n - i - 1) / 2] - scw[i - 1]) + sacw[1 + (n - i - 1) / 2];
                if (cd > max) max = cd;
                cd = l - a[n - i + 1] + scw[(n - i) / 2] + (sacw[i + (n - i) / 2] - sacw[i]) + (sacw[i + (n - i - 1) / 2] - sacw[i - 1]) + scw[1 + (n - i - 1) / 2];
                if (cd > max) max = cd;
            }

            out.println(max);
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public long nextLong() {
            long n = 0;

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

        public int nextInt() {
            long n = nextLong();

            if (n < Integer.MIN_VALUE || n > Integer.MAX_VALUE)
                throw new NumberFormatException();

            return (int) n;
        }

    }
}