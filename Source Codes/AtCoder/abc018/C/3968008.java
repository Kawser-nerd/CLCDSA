import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

@SuppressWarnings("unchecked")
public class Main {
    static final char o = 'o';
    static final char x = 'x';

    static int R;
    static int C;
    static int K;

    static int[][] ary;
    static int[][] sum;

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        R = nextInt();
        C = nextInt();
        K = nextInt();

        ary = new int[R][C];
        sum = new int[R][C];

        for (int y = 0; y < R; y++) {
            String s = next();

            for (int x = 0; x < C; x++) {
                if (s.charAt(x) == o) ary[y][x] = 1;
                else ary[y][x] = 0;
            }
        }

        for (int x = 0; x < C; x++) {
            sum[0][x] = ary[0][x];

            for (int y = 1; y < R; y++) {
                // White ???
                if (ary[y][x] == 1)
                    sum[y][x] += sum[y - 1][x] + ary[y][x];
                else sum[y][x] = 0;
            }
        }

        int ans = 0;

        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (y - K + 1 < 0 || R - 1 < y + K - 1) continue;
                if (x - K + 1 < 0 || C - 1 < x + K - 1) continue;

                boolean flg = true;

                for (int tx = x - K + 1; tx < x + K; tx++) {
                    int h = K - Math.abs(tx - x);

                    int tmp = 0;

                    if (0 <= y - h) tmp = sum[y - h][tx];

                    if (sum[y + h - 1][tx] - tmp < 2 * (h - 1) + 1) {
                        flg = false;
                        break;
                    }
                }

                if (flg) ans++;
            }
        }

        out.println(ans);

        out.flush();
    }

    // FastScanner start
    static final InputStream in = System.in;
    static final byte[] buffer = new byte[1024];
    static int ptr = 0;
    static int buflen = 0;
    static boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    static int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }
    static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
    static boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    static String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    static long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if(b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    static int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
            throw new NumberFormatException();
        return (int) nl;
    }
    static double nextDouble() {
        return Double.parseDouble(next());
    }
    // FastScanner end
}