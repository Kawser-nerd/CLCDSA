import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.HashSet;

@SuppressWarnings("unchecked")
public class Main {
    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        int N = nextInt();

        final int[] sub = {3, 2, 1};

        HashSet<Integer> hs = new HashSet<>();

        for (int i = 0; i < sub.length; i++) {
            int x = nextInt();
            hs.add(x);
        }

        boolean flg = true;

        if (hs.contains(N)) flg = false;
        else {
            int cnt = 0;

            while (0 < N) {
                boolean none = true;

                for (int i = 0; i < sub.length; i++) {
                    if (hs.contains(N - sub[i])) continue;

                    none = false;
                    N -= sub[i];
                    cnt++;
                    break;
                }

                if (none || 100 < cnt) {
                    flg = false;
                    break;
                }
            }
        }

        out.println(flg ? "YES" : "NO");

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