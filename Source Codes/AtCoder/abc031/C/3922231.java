import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

@SuppressWarnings("unchecked")
public class Main {
    static int[] a;

    static int tmpt;
    static int tmpa;

    static void f(int x, int y) {
        if (y < x) {
            int tmp = x;
            x = y;
            y = tmp;
        }

        tmpt = 0;
        tmpa = 0;

        for (int i = x; i <= y; i++) {
            if ((i - x) % 2 == 0) tmpt += a[i];
            else tmpa += a[i];
        }
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        final int N = nextInt();

        a = new int[N];

        for (int i = 0; i < N; i++) a[i] = nextInt();

        int takahashi = Integer.MIN_VALUE;

        for (int i = 0; i < N; i++) {
            int tmp = Integer.MIN_VALUE;
            int aoki = Integer.MIN_VALUE;

            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                f(i, j);
                if (aoki < tmpa) {
                    tmp = tmpt;
                    aoki = tmpa;
                }
            }

            takahashi = Math.max(takahashi, tmp);
        }

        out.println(takahashi);

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