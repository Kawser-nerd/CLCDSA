import java.io.*;
import java.util.NoSuchElementException;

public class Main {
    public static void main(String[] args) {
        try (BufferedScanner in = new BufferedScanner();
             PrintWriter out = new PrintWriter(System.out)) {
            //
            int n = in.nextInt();
            int m = in.nextInt();
            UnionFindTree uft = new UnionFindTree(n);
            long[] results = new long[m + 1];

            int[] a = new int[m];
            int[] b = new int[m];
            for (int i = 0; i < m; ++i) {
                a[i] = in.nextInt() - 1;
                b[i] = in.nextInt() - 1;
            }

            results[m] = (long) n * (n - 1) / 2;
            for (int i = m - 1; i >= 0; --i) {
                if (uft.find(a[i], b[i])) {
                    results[i] = results[i + 1];
                    continue;
                }
                long prev = uft.getSize(a[i]) * uft.getSize(b[i]);
                uft.union(a[i], b[i]);
                results[i] = results[i + 1] - prev;
            }

            for (int i = 0; i < m; ++i) {
                out.println(results[i + 1]);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class UnionFindTree {
    private final int[] elements;
    private final int[] ranks;

    public UnionFindTree(int size) {
        this.elements = new int[size];
        this.ranks = new int[size];

        for (int i = 0; i < size; ++i) {
            this.elements[i] = i;
            this.ranks[i] = 1;
        }
    }

    public boolean union(int elementA, int elementB) {
        int aRoot = getRoot(elementA);
        int bRoot = getRoot(elementB);
        if (aRoot == bRoot) {
            return false;
        }

        int aRank = ranks[aRoot];
        int bRank = ranks[bRoot];

        if (aRank < bRank) {
            ranks[bRoot] += aRank;
            elements[aRoot] = bRoot;
        } else {
            ranks[aRoot] += bRank;
            elements[bRoot] = aRoot;
        }
        return true;
    }

    public boolean find(int elementA, int elementB) {
        return getRoot(elementA) == getRoot(elementB);
    }

    private int getRoot(int element) {
        int parent = this.elements[element];
        if (parent == element) {
            return element;
        }
        return this.elements[element] = getRoot(parent);
    }

    public int getSize(int elementA) {
        return this.ranks[getRoot(elementA)];
    }
}

class BufferedScanner implements Closeable {
    private InputStream in = System.in;
    private int BUFFER_SIZE = 65536;
    private int toBuffers = 0;
    private byte buffer[] = new byte[BUFFER_SIZE];
    private int nextByte = 0;

    boolean isEOF() {
        if (nextByte >= toBuffers) {
            fill();
            if (nextByte >= toBuffers) {
                return true;
            }
        }
        return false;
    }

    private void fill() {
        nextByte = 0;

        try {
            toBuffers = in.read(buffer);
        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
    }

    private int read() {
        if (isEOF()) {
            return -1;
        }
        return buffer[nextByte++];
    }

    String nextLine() {
        if (!hasNext()) {
            return null;
            //throw new NoSuchElementException("EOF");
        }

        StringBuilder result = new StringBuilder();
        int now;
        for (now = read(); isPrintableByte(now) || now == ' '; now = read()) {
            result.append((char) now);
        }

        if (now == '\r') {
            now = read();
        }

        if (now == '\n') {
            read();
            return result.toString();
        }
        throw new IllegalArgumentException("???");
    }

    String next() {
        if (!hasNext()) {
            return null;
            //throw new NoSuchElementException("EOF");
        }

        StringBuilder result = new StringBuilder();
        for (int now = read(); isPrintableByte(now); now = read()) {
            result.append((char) now);
        }

        return result.toString();
    }

    long nextLong() {
        if (!hasNext()) {
            throw new NoSuchElementException("EOF");
        }

        boolean isMinus;
        int result = 0;
        int now = read();
        if (now == '-') {
            isMinus = true;
            now = read();
        } else if (isNumber(now)) {
            isMinus = false;
        } else {
            throw new NumberFormatException("notNumber");
        }


        for (; isNumber(now); now = read()) {
            result = result * 10 + (now & 15);
        }

        if (!isNumber(now) || now == -1) {
            return isMinus ? -result : result;
        }

        throw new NumberFormatException("notNumber?");
    }

    int nextInt() {
        long result = nextLong();
        if (result > Integer.MAX_VALUE || result < Integer.MIN_VALUE) {
            throw new NoSuchElementException("isLong");
        }
        return (int) result;
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    boolean hasNext() {
        while (!isEOF() && !isPrintableByte(buffer[nextByte])) {
            ++nextByte;
        }
        return !isEOF();
    }


    private static boolean isPrintableByte(int c) {
        return ' ' < c && c <= 126;
    }

    private static boolean isNumber(int n) {
        return n >= '0' && n <= '9';
    }

    @Override
    public void close() throws IOException {
        in.close();
    }
}