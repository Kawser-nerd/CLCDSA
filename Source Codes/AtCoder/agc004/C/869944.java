import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int h = sc.nextInt();
        int w = sc.nextInt();
        char[][] a = new char[h][w];
        for (int i = 0; i < h; i++) {
            String buf = sc.next();
            for (int j = 0; j < w; j++) {
                a[i][j] = buf.charAt(j);
            }
        }
        char[][] r = new char[h][w];
        char[][] b = new char[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (j == 0 || (j != w-1 && i % 2 == 0)) {
                    r[i][j] = '#';
                    b[i][j] = '.';
                } else {
                    r[i][j] = '.';
                    b[i][j] = '#';
                }
                if (a[i][j] == '#') {
                    r[i][j] = '#';
                    b[i][j] = '#';
                }
            }
        }
        printCharMatrix(r);
        System.out.println();
        printCharMatrix(b);
    }

    public static void printCharMatrix(char[][] matrix) {
        StringBuilder sb = new StringBuilder();
        for (char[] line : matrix) {
            for (char c : line) {
                sb.append(c);
            }
            sb.append('\n');
        }
        System.out.println(sb.toString());
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

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
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
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}