import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.Arrays;

class Town {
    int start;
    int end;

    Town(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

@SuppressWarnings("unchecked")
public class Main {

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        final int N = nextInt();
        final int D = nextInt();
        final int K = nextInt();

        Town[] LR = new Town[D];
        Town[] ST = new Town[K];

        boolean[] done = new boolean[K];

        int[] day = new int[K];

        Arrays.fill(done, false);

        for (int i = 0; i < D; i++)
            LR[i] = new Town(nextInt() - 1, nextInt() - 1);

        for (int i = 0; i < K; i++)
            ST[i] = new Town(nextInt() - 1, nextInt() - 1);

        for (int i = 0; i < D; i++) {
            int L = LR[i].start;
            int R = LR[i].end;

            for (int j = 0; j < K; j++) {
                if (done[j]) continue;

                int S = ST[j].start;
                int T = ST[j].end;

                if (T < S) {
                    if (L <= S && S <= R) {
                        if (L <= T) {
                            done[j] = true;
                            day[j] = i + 1;
                        } else ST[j].start = L;
                    }
                } else {
                    if (L <= S && S <= R) {
                        if (T <= R) {
                            done[j] = true;
                            day[j] = i + 1;
                        } else ST[j].start = R;
                    }
                }
            }
        }

        for (int i = 0; i < K; i++) out.println(day[i]);

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