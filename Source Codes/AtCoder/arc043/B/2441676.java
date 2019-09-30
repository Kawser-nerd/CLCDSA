import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;


public class Main {
    private static final int MOD = (int)1e9 + 7;
    int N;
    int[] D;

    private int[] greaterThan() {
        int[] X = new int[N];
        for(int i = 0;i < N;i++) {
            int low = 0;
            int high = N;
            while(high - low > 1) {
                int mid = (high + low) / 2;
                if (D[i] * 2 <= D[mid]) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            X[i] = N - high;
        }
        return X;
    }

    private int[] lessThan() {
        int[] X = new int[N];
        for(int i = 0;i < N;i++) {
            int low = -1;
            int high = N-1;
            while(high - low > 1) {
                int mid = (high + low) / 2;
                if (D[mid] * 2 <= D[i]) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            X[i] = high;
        }
        return X;
    }

    private void solve() {
        N = nextInt();
        D = new int[N];
        for(int i = 0;i < N;i++) {
            D[i] = nextInt();
        }

        Arrays.sort(D);

        int[] A = greaterThan();
        int[] B = lessThan();

        long ans = 0;

        long[] sum = new long[N+1];
        for(int i = N - 1;i >= 0;i--) {
            sum[i] += A[i] + sum[i+1];
        }

        for(int i = 0;i < N;i++) {

            int low = -1;
            int high = N;
            while(high - low > 1) {
                int mid = (high + low) / 2;
                if (D[i] * 2 <= D[mid]) {
                    high = mid;
                } else {
                    low = mid;
                }
            }

            ans += B[i] * sum[high] % MOD;
            ans %= MOD;
        }

        out.println(ans);
    }
    public static void main(String[] args) {
        out.flush();
        new Main().solve();
        out.close();
    }

    /* Input */
    private static final InputStream in = System.in;
    private static final PrintWriter out = new PrintWriter(System.out);
    private final byte[] buffer = new byte[4096];
    private int p = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (p < buflen)
            return true;
        p = 0;
        try {
            buflen = in.read(buffer);
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (buflen <= 0)
            return false;
        return true;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrint(buffer[p])) {
            p++;
        }
        return hasNextByte();
    }

    private boolean isPrint(int ch) {
        if (ch >= '!' && ch <= '~')
            return true;
        return false;
    }

    private int nextByte() {
        if (!hasNextByte())
            return -1;
        return buffer[p++];
    }

    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = -1;
        while (isPrint((b = nextByte()))) {
            sb.appendCodePoint(b);
        }
        return sb.toString();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}