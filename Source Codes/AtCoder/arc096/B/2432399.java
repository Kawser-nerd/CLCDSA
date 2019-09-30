import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;


public class Main {

    int N;
    long C;
    long[] x;
    int[] v;

    private void solve() {
        N = nextInt();
        C = nextLong();
        x = new long[N];
        v = new int[N];

        for(int i = 0;i < N;i++) {
            x[i] = nextLong();
            v[i] = nextInt();
        }

        long[] asum = new long[N + 1];
        for(int i = 0;i < N;i++) {
            asum[i] += v[i];
            asum[i+1] += asum[i];
        }

        long[] bsum = new long[N + 1];
        for(int i = N;i > 0;i--) {
            bsum[i-1] += v[i-1];
            bsum[i-1] += bsum[i];
        }

        int[] aIndex = new int[N];
        for(int i = 1;i < N;i++) {
            if (asum[aIndex[i-1]] - x[aIndex[i-1]] < asum[i] - x[i]) {
                aIndex[i] = i;
            } else {
                aIndex[i] = aIndex[i-1];
            }
        }

        int[] bIndex = new int[N];
        Arrays.fill(bIndex,N-1);
        for(int i = N - 2;i >= 0;i--) {
            if (bsum[bIndex[i+1]] - (C - x[bIndex[i+1]]) < bsum[i] - (C - x[i])) {
                bIndex[i] = i;
            } else {
                bIndex[i] = bIndex[i+1];
            }
        }

        long ans = 0;
        for(int i = 0;i < N-1;i++) {
            long sum = asum[i] + bsum[bIndex[i+1]];
            long cost = Math.min(x[i] * 2 + (C - x[bIndex[i+1]]),x[i] + (C - x[bIndex[i+1]]) * 2);
            ans = Math.max(ans,sum - cost);
        }

        for(int i = N-1;i > 0;i--) {
            long sum = asum[aIndex[i-1]] + bsum[i];
            long cost = Math.min(x[aIndex[i-1]] * 2 + (C - x[i]),x[aIndex[i-1]] + (C - x[i]) * 2);
            ans = Math.max(ans,sum - cost);
        }

        for(int i = 0;i < N;i++) {
            ans = Math.max(ans,asum[i] - x[i]);
        }

        for(int i = N-1;i >= 0;i--) {
            ans = Math.max(ans, bsum[i] - (C - x[i]));
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