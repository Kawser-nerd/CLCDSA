import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

    private static int divAndCeil(int divident, int divisor) {
        return (divident + divisor - 1) / divisor;
    }

    static void exec(MyScanner in, PrintWriter out) {
        int D = in.nextInt();
        int G = in.nextInt();
        int[] p = new int[D];
        int[] c = new int[D];
        for (int i = 0; i < D; i += 1) {
            p[i] = in.nextInt();
            c[i] = in.nextInt();
        }
        int minCount = Integer.MAX_VALUE;
        for (int bit = 0; bit < (1 << D); bit += 1) {
            int point = 0;
            int count = 0;
            int maxRest = -1;
            for (int i = 0; i < D; i += 1) {
                if ((bit & (1 << i)) > 0) {
                    point += 100 * (i + 1) * p[i] + c[i];
                    count += p[i];
                } else {
                    maxRest = i;
                }
            }
            if (point < G) {
                int a = divAndCeil(G - point, 100 * (maxRest + 1));
                if (a >= p[maxRest])
                    continue;
                count += a;
            }
            minCount = Math.min(minCount, count);
        }
        out.println(minCount);
    }

    public static void main(String[] args) {
        PrintWriter w = new PrintWriter(System.out);
        exec(new MyScanner(System.in), w);
        w.flush();
    }

    static final class MyScanner {
        static final int BUFFER_SIZE = 8192;
        private final InputStream in;
        private final byte[] buffer = new byte[BUFFER_SIZE];
        private int point;
        private int readLength;
        MyScanner(InputStream in) {
            this.in = in;
        }
        private int readByte() {
            if (point < readLength) {
                int result = buffer[point];
                point += 1;
                return result;
            }
            try {
                readLength = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (readLength == -1) {
                return -1;
            }
            point = 1;
            return buffer[0];
        }
        private static boolean isPrintableCharExceptSpace(int c) {
            return 33 <= c && c <= 126;
        }
        String next() {
            StringBuilder b = new StringBuilder();
            int c = readByte();
            while (!(c == -1 || isPrintableCharExceptSpace(c))) {
                c = readByte();
            }
            if (c == -1) {
                throw new NoSuchElementException();
            }
            do {
                b.appendCodePoint(c);
                c = readByte();
            } while (c != -1 && isPrintableCharExceptSpace(c));
            return b.toString();
        }
        long nextLong() {
            int c = readByte();
            while (!(c == -1 || isPrintableCharExceptSpace(c))) {
                c = readByte();
            }
            if (c == -1) {
                throw new NoSuchElementException();
            }
            boolean minus = false;
            if (c == '-') {
                minus = true;
                c = readByte();
            }
            long result = 0L;
            do {
                if (!('0' <= c && c <= '9')) {
                    throw new InputMismatchException();
                }
                result = result * 10L + (c - '0');
                c = readByte();
            } while (c != -1 && isPrintableCharExceptSpace(c));
            return minus ? -result : result;
        }
        int nextInt() {
            long n = nextLong();
            if (Integer.MIN_VALUE <= n && n <= Integer.MAX_VALUE) {
                return (int) n;
            }
            throw new InputMismatchException();
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}