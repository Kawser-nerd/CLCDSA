import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class Main {

    private static final double EPS = 1e-10;

    public static void main(String args[]) throws Exception {
        FastScanner sc = new FastScanner();

        int N = sc.nextInt();
        int Q = sc.nextInt();

        long[] x = new long[N];
        long[] h = new long[N];
        long[] r = new long[N];

        for (int i = 0; i < N; i++) {
            x[i] = sc.nextInt();
            r[i] = sc.nextInt();
            h[i] = sc.nextInt();
        }

        for (int i = 0; i < Q; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            double sum = 0;
            for (int j = 0; j < N; j++) {
                long end = x[j] + h[j];
                if (end < a || b < x[j]) {

                } else if (a <= x[j] && end <= b) {//???ab???????
                    sum+=r[j]*r[j]*h[j];
                } else if (x[j] < a && b < end) {//?????ab
                    long tmphL=end-a;
                    double tmprL=r[j]*(double)tmphL/(double)h[j];
                    long tmphS=end-b;
                    double tmprS=r[j]*(double)tmphS/(double)h[j];
                    sum+=(tmphL*tmprL*tmprL)-(tmphS*tmprS*tmprS);
                } else if (a <= x[j] && b <= end) {
                    long tmph=end-b;
                    double tmpr=r[j]*(double)tmph/(double)h[j];
                    sum+=r[j]*r[j]*h[j]-tmpr*tmpr*tmph;
                } else if (x[j] <= a && end <= b) {
                    long tmph=end-a;
                    double tmpr=r[j]*(double)tmph/(double)h[j];
                    sum+=tmpr*tmpr*tmph;
                } else {
                    throw new Exception();
                }
            }
            System.out.println(sum*Math.PI/3);
        }

    }
}


class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
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

    private int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }

    private boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    public boolean hasNext() {
        skipUnprintable();
        return hasNextByte();
    }

    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
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
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public int nextInt() {
        if (!hasNext()) throw new NoSuchElementException();
        int n = 0;
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
}