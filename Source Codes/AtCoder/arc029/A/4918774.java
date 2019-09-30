import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.stream.IntStream;

public class Main {

    static void exec(MyScanner in, PrintWriter out) {
        int N = in.nextInt();
        int[] t = IntStream.range(0, N).map(i -> in.nextInt()).toArray();
        int minTime = Integer.MAX_VALUE;
        for (int bit = 0; bit < (1 << N); bit += 1) {
            int time1 = 0;
            int time2 = 0;
            for (int i = 0; i < N; i += 1) {
                if ((bit & (1 << i)) > 0) {
                    time1 += t[i];
                } else {
                    time2 += t[i];
                }
            }
            minTime = Math.min(minTime, Math.max(time1, time2));
        }
        out.println(minTime);
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