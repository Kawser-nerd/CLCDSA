import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

public class Main {

    static int N;
    static int[] H, W;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        H = new int[N];
        W = new int[N];

        for (int i = 0; i < N; i++) {
            H[i] = sc.nextInt();
            W[i] = sc.nextInt();
        }

        System.out.println(solve());
    }

    static int solve(int n, int[] h, int[] w) {
        N = n;
        H = h;
        W = w;
        return solve();
    }

    static int solve() {
        Box[] B = new Box[N];
        for (int i = 0; i < N; i++) {
            B[i] = new Box(H[i], W[i]);
        }
        Arrays.sort(B, Comparator.<Box>comparingInt(b -> b.h).thenComparingInt(b -> -b.w));

        int ans = 0;
        BinaryIndexedTree bit = new BinaryIndexedTree((int)1e5);
        for (int i = 0; i < N; i++) {
            int w = B[i].w;
            int cur = bit.get(w-1) + 1;
            bit.set(w, cur);
            ans = Math.max(ans, cur);
        }
        return ans;
    }

    static class Box {
        int h, w;

        public Box(int h, int w) {
            this.h = h;
            this.w = w;
        }
    }

    // max?
    static class BinaryIndexedTree {

        int n;
        int[] bit;

        BinaryIndexedTree(int n) {
            this.n = n;
            this.bit = new int[n+1];
        }

        void set(int i, int v) {
            i++; // 0 index -> 1 index

            while( i <= n ) {
                bit[i] = Math.max(bit[i], v);
                i += i & -i;
            }
        }

        int get(int i) {
            i++; // 0 index -> 1 index

            int ret = 0;
            while(i > 0) {
                ret = Math.max(bit[i], ret);
                i -= i & -i;
            }
            return ret;
        }
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