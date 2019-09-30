import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int K;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        A = sc.nextIntArray(N);
        System.out.println(solve());
    }

    static long solve() {
        long[] S = new long[N+1];
        S[0] = 0;
        for (int i = 1; i < N+1; i++) {
            S[i] = (A[i-1] - K) + S[i-1];
        }

        long[] T = Arrays.copyOf(S, N+1);
        Arrays.sort(T);
        int id = 1;
        Map<Long, Integer> map = new HashMap<>();

        long prev = T[0];
        map.put(prev, id);
        id++;
        for (int i = 1; i < N+1; i++) {
            long t = T[i];
            if( t == prev ) continue;

            map.put(t, id);
            prev = t;
            id++;
        }

        int[] C = new int[N+1];
        for (int i = 0; i < N+1; i++) {
            C[i] = map.get(S[i]);
        }

        long ans = 0;
        BinaryIndexedTree bit = new BinaryIndexedTree(N+1);
        for (int i = 0; i < N+1; i++) {
            ans += bit.sum(C[i]);
            bit.add(C[i], 1);
        }

        return ans;
    }

    static class BinaryIndexedTree {
        int n;
        int[] bit;

        BinaryIndexedTree(int n) {
            this.n = n;
            bit = new int[n+1];
        }

        void add(int i, int x) {
            while( i <= n ) {
                bit[i] += x;
                i += (i & -i);
            }
        }

        int sum(int i) {
            int ret = 0;
            while( i > 0 ) {
                ret += bit[i];
                i -= (i & -i);
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