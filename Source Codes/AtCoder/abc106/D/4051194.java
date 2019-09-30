import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.Arrays;

@SuppressWarnings("unchecked")
public class Main {
    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        final int N = nextInt();
        final int M = nextInt();
        final int Q = nextInt();

        int[][] t = new int[N][N];

        for (int[] x : t) Arrays.fill(x, 0);

        for (int i = 0; i < M; i++) t[nextInt() - 1][nextInt() - 1]++;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N - 1; j++) t[i][j + 1] += t[i][j];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N - 1; j++) t[j + 1][i] += t[j][i];

        for (int i = 0; i < Q; i++) {
            int p = nextInt() - 1;
            int q = nextInt() - 1;

            int x = 0;
            int y = 0;
            int xy = 0;

            if (0 <= p - 1) {
                x = t[p - 1][q];
                y = t[q][p - 1];
                xy = t[p - 1][p - 1];
            }

            int ans = t[q][q] - x - y + xy;

            out.println(ans);
        }

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
        if (hasNextByte())
            return buffer[ptr++];
        else
            return -1;
    }

    static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    static boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr]))
            ptr++;
        return hasNextByte();
    }

    static String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    static long nextLong() {
        if (!hasNext())
            throw new NoSuchElementException();
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
            } else if (b == -1 || !isPrintableChar(b)) {
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