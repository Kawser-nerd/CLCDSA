import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;

public class Main {
    static FastScanner in;
    static PrintWriter out;
    static final int MAX_DIGIT = 40;
    static int n;
    static long k;
    static long[] a;
    static long[][] dp;

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        in = new FastScanner(inputStream);
        out = new PrintWriter(outputStream);
        solve();
        out.flush();
    }

    static void solve() {
        n = in.nextInt();
        k = in.nextLong();
        a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextLong();
        }
        dp = new long[MAX_DIGIT+1][2];
        // [??][tight]
        for (int i = 0; i < dp.length; i++) {
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        dp[0][1] = 0;
        for (int i = 0; i < MAX_DIGIT; i++) {
            long mask = 1L << (MAX_DIGIT - i - 1);
            int num = 0;
            for (int j = 0; j < n; j++) {
                if ((a[j] & mask) > 0) num++;
            }
            long cost0 = mask * num;
            long cost1 = mask * (n - num);
            // s -> s
            if (dp[i][0] != -1) {
                dp[i + 1][0] = dp[i][0] + Math.max(cost0, cost1);
            }
            // t -> s
            if ((k & mask) > 0) {
                dp[i + 1][0] = Math.max(dp[i + 1][0], dp[i][1] + cost0);
            }
            // t -> t
            if((k & mask) > 0) {
                dp[i+1][1] = dp[i][1] + cost1;
            }
            else {
                dp[i+1][1] = dp[i][1] + cost0;
            }
        }

        out.println(Math.max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]));
    }


    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
        }

        private int readByte() {
            if (bufPointer >= bufLength) {
                if (bufLength == -1)
                    throw new InputMismatchException();

                bufPointer = 0;
                try {
                    bufLength = in.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (bufLength <= 0)
                    return -1;
            }
            return buffer[bufPointer++];
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public long nextLong() {
            long n = 0;

            int b = readByte();
            while (isSpaceChar(b))
                b = readByte();

            boolean minus = (b == '-');
            if (minus)
                b = readByte();

            while (b >= '0' && b <= '9') {
                n *= 10;
                n += b - '0';
                b = readByte();
            }

            if (!isSpaceChar(b))
                throw new NumberFormatException();

            return minus ? -n : n;
        }

        public int nextInt() {
            long n = nextLong();

            if (n < Integer.MIN_VALUE || n > Integer.MAX_VALUE)
                throw new NumberFormatException();

            return (int) n;
        }

    }
}