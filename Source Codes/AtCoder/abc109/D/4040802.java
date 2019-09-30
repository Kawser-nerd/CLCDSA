import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.ArrayList;

@SuppressWarnings("unchecked")
public class Main {
    static String sp = " ";
    static StringBuilder sb = new StringBuilder();
    static ArrayList<String> al;

    static void ans(int y, int x, int ny, int nx) {
        sb.setLength(0);
        sb.append(y + 1);
        sb.append(sp);
        sb.append(x + 1);
        sb.append(sp);
        sb.append(ny + 1);
        sb.append(sp);
        sb.append(nx + 1);
        al.add(sb.toString());
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        final int H = nextInt();
        final int W = nextInt();

        int[][] a = new int[H][W];

        for (int x = 0; x < H; x++)
            for (int y = 0; y < W; y++) a[x][y] = nextInt();

        int x = 0;

        al = new ArrayList<>();

        int flg = 1;

        for (int y = 0; y < H; y++) {
            while (-1 < x && x < W) {
                if (-1 < x + flg && x + flg < W) {
                    if (a[y][x] % 2 == 1) {
                        a[y][x]--;
                        a[y][x + flg]++;

                        ans(y, x, y, x + flg);
                    }

                    x += flg;
                }

                if (H - 2 < y) {
                    if (x < 1 || W - 2 < x) break;
                    continue;
                }

                if (x < 1 || W - 2 < x) {
                    if (-1 < x && x < W && a[y][x] % 2 == 1) {
                        a[y][x]--;
                        a[y + 1][x]++;

                        ans(y, x, y + 1, x);
                    }

                    flg *= -1;
                    break;
                }
            }
        }

        out.println(al.size());

        for (String s : al) out.println(s);

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