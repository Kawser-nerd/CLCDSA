import java.io.*;
import java.util.NoSuchElementException;

public class Main {
    public static void main(String[] args) {
        try (BufferedScanner in = new BufferedScanner();
             PrintWriter out = new PrintWriter(System.out)) {
            //
            String s = in.next();
            s += "B";
            long bCount = 0;
            long wCount = 0;
            long result = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s.charAt(i) == 'B') {
                    if (wCount >= 1) {
                        result += bCount * wCount;
                    }
                    ++bCount;
                    wCount = 0;
                } else {
                    ++wCount;
                }
            }

            out.println(result);
        } catch (IOException e) {
            e.printStackTrace();
        }
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