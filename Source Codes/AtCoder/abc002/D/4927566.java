import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

    static void exec(MyScanner in, PrintWriter out) {
        int N = in.nextInt();
        int M = in.nextInt();
        if (N == 1 || M == 0) {
            out.println(1);
            return;
        }
        int[] x = new int[M];
        int[] y = new int[M];
        for (int i = 0; i < M; i += 1) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }
        boolean[][] xy = new boolean[N][N];
        for (int i = 0; i < M; i += 1)
            xy[x[i] - 1][y[i] - 1] = true;
        int maxNum = 1;
        label : for (int b = 1; b < (1 << N); b += 1) {
            for (int i = 0; i < N - 1; i += 1) {
                if ((b & (1 << i)) == 0)
                    continue;
                for (int j = i + 1; j < N; j += 1) {
                    if ((b & (1 << j)) == 0)
                        continue;
                    if (!xy[i][j])
                        continue label;
                }
            }
            maxNum = Math.max(maxNum, Integer.bitCount(b));
        }
        out.println(maxNum);
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
                throw new AssertionError(null, e);
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