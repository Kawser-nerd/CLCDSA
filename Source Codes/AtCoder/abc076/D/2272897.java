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
            final int n = in.nextInt();
            double[] t = new double[n + 2];
            double[] v = new double[n + 2];
            t[0] = 0;
            v[0] = 0;
            for (int i = 0; i < n; i++) t[i + 1] = t[i] + in.nextDouble();
            for (int i = 0; i < n; i++) v[i + 1] = in.nextDouble();
            t[n + 1] = t[n];
            v[n + 1] = 0;

            double ct = 0;
            double cv = 0;
            double ans = 0;
            int index = 1;
            while (index < n + 2) {
                ct += 0.5;
                double maxV = v[index];
                for (int i = index + 1; i < n + 2; i++) {
                    if ((v[i] + t[i - 1] - ct) < maxV) maxV = v[i] + t[i - 1] - ct;
                }
                double dv = 0;
                if (cv > maxV) dv = -0.5;
                else if (cv < maxV) dv = 0.5;
                ans += 0.5 * (cv + (cv + dv)) / 2;
                cv += dv;
                while (index < n + 2 && ct >= t[index]) index++;
            }
            out.println(ans);
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

        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }
}