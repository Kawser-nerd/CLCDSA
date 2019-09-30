import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.io.PrintWriter;
import java.util.SplittableRandom;
import java.util.Stack;

public class Main {
    private long startTime = System.currentTimeMillis();
    private long endTime = startTime + 3500L;

    static FastScanner sc = new FastScanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static final void main(String[] args) {
        new Main().solve();
        out.flush();
    }

    // ========================================================================= //

    public void solve() {
        int N = sc.nextInt();
        long[] X = new long[N];
        long[] sortedX = new long[N];
        for (int i = 0; i < N; i++) {
            sortedX[i] = X[i] = sc.nextInt();
        }
        Arrays.sort(sortedX);

        int cIndex = N / 2 - 1;
        long a = sortedX[cIndex];
        long b = sortedX[cIndex + 1];
        for (int i = 0; i < N; i++) {
            long c = X[i];
            if (c <= a) {
                System.out.println(b);
            }
            else {
                System.out.println(a);
            }
        }
    }
}

class FastScanner {
    public static void main(String[] args) {
        FastScanner f = new FastScanner(System.in);
        while (true) {
            System.out.println(f.nextInt());
        }
    }
    private final InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }
        else {
            ptr = 0;
            try { buflen = in.read(buffer); }
            catch (IOException e) { e.printStackTrace(); }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1; }
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126; }
    private void skipUnprintable() { while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; }
    private boolean hasNext() { skipUnprintable(); return hasNextByte(); }
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
    public String nextLine() {
        if (!hasNext()) return null;
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (b != -1 && b != '\n') {
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
            }
            else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            }
            else {
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
            }
            else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            }
            else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public FastScanner(String str) {
        this(new ByteArrayInputStream(str.getBytes()));
    }
    public FastScanner(InputStream in) {
        this.in = in;
    }
}