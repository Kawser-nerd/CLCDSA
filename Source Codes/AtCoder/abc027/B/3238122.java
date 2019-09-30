import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            FastScanner fs = new FastScanner();

            final int N = fs.nextInt();

            int[] a = new int[N];

            int sum = 0;

            for (int i = 0; i < N; i++) {
                a[i] = fs.nextInt();
                sum += a[i];
            }

            int avg = sum / N;

            if (sum % N == 0) {
                int start = 0;
                int now = 0;
                int cnt = 0;

                int population = 0;

                boolean buildnext = false;

                do {
                    // ?????????
                    if (buildnext) cnt++;

                    // ????
                    population += a[now];

                    buildnext = true;

                    // ??????????????????
                    // ???????
                    if (population % (now - start + 1) == 0) {
                        if (population / (now - start + 1) == avg) {
                            // ?????????
                            // ??
                            buildnext = false;

                            population = 0;

                            start = now + 1;
                        }
                    }

                    now++;
                } while (now < N);

                System.out.println(cnt);
             } else System.out.println(-1);
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
    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
    public boolean hasNext() {
        while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
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
        while(true) {
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