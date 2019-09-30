import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.math.BigDecimal;
import java.math.RoundingMode;

import java.util.Arrays;
import java.util.ArrayList;

@SuppressWarnings("unchecked")
public class Main {
    static final int scale = 12;

    // ??????
    static int dcount(ArrayList<Integer> ary, int x) {
        int res = 0;

        for (Integer i : ary) if (x % i == 0) res++;

        return res;
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        final int N = nextInt();

        ArrayList<Integer> al = new ArrayList<>();

        for (int i = 0; i < N; i++) al.add(nextInt());

        BigDecimal bd = BigDecimal.ZERO;

        for (Integer a : al) {
            final int cnt = dcount(al, a);

            if (cnt % 2 == 0) {
                // ?? ????? ??(x)
                // 1 / 2
                bd = bd.add(BigDecimal.valueOf(0.5));
            } else {
                // ?? ????? ??(x)
                // (x + 1) / 2 * x
                bd = bd.add(BigDecimal.valueOf(cnt + 1)
                        .divide(
                                BigDecimal.valueOf(2)
                                .multiply(BigDecimal.valueOf(cnt))
                                , scale
                                , RoundingMode.DOWN));
            }
        }

        out.println(bd.setScale(scale, RoundingMode.DOWN));

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