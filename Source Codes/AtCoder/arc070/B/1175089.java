import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            new Main().solve(in);
        }
    }

    private void solve(Scanner in) {
        int N = in.nextInt(), K = in.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = in.nextInt();
        }
        java.util.Arrays.sort(a);

        int from = -1;
        int to = N;
        while (from + 1 < to) {
            int n = (to + from) / 2;
            if (a[n] >= K) {
                to = n;
                continue;// necessary
            }
            boolean[][] dp = new boolean[N + 1][K];
            dp[0][0] = true;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < K; j++) {
                    if (n != i && a[i] + j < K) {
                        dp[i + 1][a[i] + j] |= dp[i][j];
                    }
                    dp[i + 1][j] |= dp[i][j];
                }
            }
            boolean nece = false;
            for (int j = K - a[n]; j < K; j++) {
                if (dp[N][j]) {
                    nece = true;
                    break;
                }
            }
            if (nece) {
                to = n;
            } else {
                from = n;
            }
        }
        int ans = to;
        System.out.println(ans);
    }

    static final class Scanner implements Closeable {
        private final InputStream stream;
        private final byte[] buf = new byte[1024];
        private int cur, num;

        Scanner(InputStream stream) {
            this.stream = stream;
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        int nextInt() {
            return (int) nextLong();
        }

        long nextLong() {
            int c = read();
            while (isdel(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long l = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                l *= 10;
                l += c - '0';
                c = read();
            } while (!isdel(c));
            return l * sgn;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String next() {
            int c = read();
            while (isdel(c))
                c = read();
            StringBuilder s = new StringBuilder();
            do {
                s.appendCodePoint(c);
                c = read();
            } while (!isdel(c));
            return s.toString();
        }

        private int read() {
            if (num == -1)
                throw new InputMismatchException();
            if (cur >= num) {
                cur = 0;
                try {
                    num = stream.read(buf);
                } catch (Exception e) {
                    throw new InputMismatchException();
                }
                if (num <= 0)
                    return -1;
            }
            return buf[cur++];
        }

        private boolean isdel(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        @Override
        public void close() {
            try {
                stream.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}