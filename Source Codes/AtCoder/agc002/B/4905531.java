import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] x = new int[m];
        int[] y = new int[m];
        for (int i = 0; i < m; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }

        boolean[] red = new boolean[n + 1];
        red[1] = true;
        int[] num = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            num[i] = 1;
        }
        // System.out.println(Arrays.toString(num));
        // System.out.println(Arrays.toString(red));

        for (int i = 0; i < m; i++) {
            if (red[x[i]]) {
                red[y[i]] = true;
                if (num[x[i]] == 1) {
                    red[x[i]] = false;
                }
            }
            num[x[i]]--;
            num[y[i]]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (red[i]) {
                ans++;
            }
        }
        System.out.println(ans);
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
        if (hasNextByte())
            return buffer[ptr++];
        else
            return -1;
    }
    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    public String next() {
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
    public long nextLong() {
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
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
            throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() {
        return Double.parseDouble(next());
    }
}