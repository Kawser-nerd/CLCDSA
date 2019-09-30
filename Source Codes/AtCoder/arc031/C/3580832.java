import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        B = sc.nextIntArray(N);

        System.out.println(solve());
    }

    static long solve() {
        long[] F = new long[N+1];
        BinaryIndexedTree bit = new BinaryIndexedTree(N+1);
        for (int i = 0; i < N; i++) {
            int f = i - bit.sum(B[i]);
            F[B[i]] = f;
            bit.add(B[i], 1);
        }

        Arrays.fill(bit.bit, 0);
        long[] G = new long[N+1];
        for (int i = N-1; i >= 0; i--) {
            int g = (N-1-i) - bit.sum(B[i]);
            G[B[i]] = g;
            bit.add(B[i], 1);
        }

        long ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += Math.min(F[i], G[i]);
        }
        return ans;
    }

    static class BinaryIndexedTree {

        int n;
        int[] bit;

        BinaryIndexedTree(int n) {
            this.n = n;
            this.bit = new int[n+1];
        }

        void add(int i, int v) {
            i++; // 0 index -> 1 index

            while( i <= n ) {
                bit[i] += v;
                i += i & -i;
            }
        }

        int sum(int i) {
            i++; // 0 index -> 1 index

            int ret = 0;
            while(i > 0) {
                ret += bit[i];
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