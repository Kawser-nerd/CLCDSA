import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static long TW;
    static long[] V;
    static long[] W;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        TW = sc.nextInt();
        V = new long[N];
        W = new long[N];
        for (int i = 0; i < N; i++) {
            V[i] = sc.nextInt();
            W[i] = sc.nextInt();
        }

        System.out.println(solve());
    }

    static long solve() {
        if( N <= 30 ) {
            return case1();
        } else if( isCase2() ) {
            return case2();
        } else {
            return case3();
        }
    }

    static boolean isCase2() {
        for (long w : W) {
            if( w > 1000 ) return false;
        }
        return true;
    }

    static long case1() {
        int N1 = N / 2;
        int N2 = N - N1;

        ValueWeight[] VW2 = new ValueWeight[1 << N2];
        for (int s2 = 0; s2 < 1 << N2; s2++) {
            long v = 0;
            long w = 0;
            for (int n2 = 0; n2 < N2; n2++) {
                if( (s2 & 1 << n2) > 0 ) {
                    v += V[N1 + n2];
                    w += W[N1 + n2];
                }
            }
            VW2[s2] = new ValueWeight(v, w);
        }
        Arrays.sort(VW2, Comparator.comparingLong(vw -> vw.w) );
        long maxv = 0;
        for (int s2 = 0; s2 < 1 << N2; s2++) {
            if( VW2[s2].v < maxv ) {
                VW2[s2].v = maxv;
            } else {
                maxv = VW2[s2].v;
            }
        }

        long ans = 0;
        for (int s1 = 0; s1 < 1 << N1; s1++) {
            long w1 = 0;
            long v1 = 0;
            for (int i = 0; i < N1; i++) {
                if( (s1 & 1 << i) > 0 ) {
                    w1 += W[i];
                    v1 += V[i];
                }
            }

            if( w1 > TW ) continue;

            long v2 = availableValue(VW2, TW - w1);
            ans = Math.max(v1 + v2, ans);
        }
        return ans;
    }

    private static long availableValue(ValueWeight[] array, long weight) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( array[mid].w <= weight ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if( low == 0 ) {
            return 0;
        } else {
            return array[low-1].v;
        }
    }

    static class ValueWeight {
        long v;
        long w;

        public ValueWeight(long v, long w) {
            this.v = v;
            this.w = w;
        }

        public String toString() {
            return "(" + v + "," + w + ")";
        }
    }

    static long case2() {
        final long INF = -1;
        int MAX_W = (int)Math.min(TW, N*1000);
        long[] dp = new long[MAX_W + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            for (int w = MAX_W; w >= W[i]; w--) {
                if( dp[w - (int)W[i]] != INF ) {
                    dp[w] = Math.max(dp[w - (int)W[i]] + V[i], dp[w]);
                }
            }
        }

        long maxv = 0;
        for (int w = 0; w <= MAX_W; w++) {
            maxv = Math.max(dp[w], maxv);
        }
        return maxv;
    }

    static int case3() {
        final long INF = Long.MAX_VALUE / 2;

        int MAX_V = 0;
        for (int i = 0; i < N; i++) {
            MAX_V += V[i];
        }
        long[] dp = new long[MAX_V + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            for (int v = MAX_V; v >= V[i]; v--) {
                if( dp[v - (int)V[i]] != INF ) {
                    dp[v] = Math.min(dp[v - (int)V[i]] + W[i], dp[v]);
                }
            }
        }

        for (int v = MAX_V; v >= 0; v--) {
            if( dp[v] != INF && dp[v] <= TW ) return v;
        }
        return 0;
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}