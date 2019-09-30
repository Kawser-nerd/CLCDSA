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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            long n = in.nextLong();
            long m = in.nextLong();
            String s = in.next();
            String t = in.next();

            long gcd = Numbers.gcd(n, m);
            long ans = n * m / gcd;

            long cni = 0;
            long cmi = 0;
            for (long i = 1; cni < n && cmi < m; i++) { // <-----
                if (s.charAt((int) cni) != t.charAt((int) cmi)) {
                    ans = -1;
                    break;
                }
                cni = i * n / gcd;
                cmi = i * m / gcd;
            }

            out.println(ans);
        }

    }

    static class Numbers {
        public static long gcd(long a, long b) {
            return a % b == 0 ? b : gcd(b, a % b);
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
            return hasNext() ? buffer[bufPointer++] : -1;
        }

        private static boolean isPrintableChar(int c) {
            return (c >= 33 && c <= 126);
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public boolean hasNext() {
            if (bufPointer < bufLength)
                return true;
            bufPointer = 0;
            try {
                bufLength = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return (bufLength > 0);
        }

        public String next() {
            if (!hasNext())
                throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isSpaceChar(b))
                b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
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
                } else if (!isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

    }
}