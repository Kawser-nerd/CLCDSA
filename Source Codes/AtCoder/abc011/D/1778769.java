import java.util.*;
import java.io.*;

public class Main {
    private static IO io = new IO();
    private static int n = io.nextInt();

    public static void main(String[] args) {
        int d = io.nextInt();
        int x = io.nextInt();
        int y = io.nextInt();

        if (x%d!=0 || x%d!=0) {
            System.out.println(0.0);
            return;
        }

        // ??????????????
        int xr=0, xl=0, yu=0, yd=0;
        if (x/d<0) xl = -x/d;
        else xr = x/d;
        if (y/d<0) yd = -y/d;
        else yu = y/d;
        // def????????????????????
        int def = Math.abs(xl+xr) + Math.abs(yu+yd);
        // ??indef???????????0??????
        int indef = n-def;
        if (indef<0 || indef%2!=0) {
            System.out.println(0.0);
            return;
        }
        indef /= 2;

        double ans = 0;
        for (int i = 0; i <= indef; i++) {
            ans += comb(new int[] {xr+i, xl+i, yu+(indef-i), yd+(indef-i)});
        }
        System.out.println(ans);
    }

    // (n!/(a!b!c!d!)) / 4^n (a+b+c+d=n)
    private static double comb(int[] a) {
        List<Double> up = new ArrayList<>();
        for (double i=1; i<=n; i++) up.add(i/4);
        int i = 0;
        for (int j = 0; j < 4; j++) {
            for (int k = a[j]; k >= 2; k--) {
                up.set(i, up.get(i++)/k);
            }
        }
        double ans = 1;
        for (int j=0; j<n; j++) ans *= up.get(j);
        return ans;
    }

    private static class IO extends PrintWriter {
        private final InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        IO() {
            this(System.in);
        }

        IO(InputStream source) {
            super(System.out);
            this.in = source;
        }

        boolean hasNextByte() {
            if (ptr < buflen) return true;
            else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) return false;
            }
            return true;
        }
        int readByte() {
            if (hasNextByte()) return buffer[ptr++];
            else return -1;
        }
        boolean isPrintableChar(int c) {return 33<=c &&c <=126;}
        void skipUnprintable() {while(hasNextByte() && !isPrintableChar(buffer[ptr]))ptr++;}
        boolean hasNext() {
            skipUnprintable();
            return hasNextByte();
        }

        long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) throw new NumberFormatException();
            while (true) {
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) return minus ? -n : n;
                else throw new NumberFormatException();
                b = readByte();
            }
        }

        int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }

        public void close() {
            super.close();
            try {
                in.close();
            } catch (IOException ignored) {
            }
        }
    }
}