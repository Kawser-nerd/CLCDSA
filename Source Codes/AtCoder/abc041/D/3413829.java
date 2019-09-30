import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;
    static int[] X;
    static int[] Y;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        X = new int[M];
        Y = new int[M];
        for (int i = 0; i < M; i++) {
            X[i] = sc.nextInt() - 1;
            Y[i] = sc.nextInt() - 1;
        }
        System.out.println(solve());
    }

    static long[] MEMO;

    static long solve() {
        int[] G = adjDS(N, X, Y);

        MEMO = new long[1 << N];
        Arrays.fill(MEMO, -1);

        // bitDP?ok???
        // 000 -> 001 -> 010 -> 011 -> 100 -> 101 -> 110 -> 111
        // ???????????
        // ????????
        //   011??? 010, 001
        //   101??? 100, 001
        //   110??? 100, 010
        //   111??? 011, 101, 110
        // ????????????
        // ????????????bitDP??????????????????????????2^N?????

        // dfs?????N!???????????????????????bitDP??????????
        return dfs((1 << N) - 1, G);
    }

    static long dfs(int s, int[] G) {
        if( MEMO[s] != -1 ) {
            return MEMO[s];
        }

        if( Integer.bitCount(s) == 1 ) {
            MEMO[s] = 1;
            return 1;
        }

        long ret = 0;
        for (int i = 0; i < N; i++) {
            int b = 1 << i;

            if( (s & b) == 0 ) continue;

            int ns = s ^ b;
            // ???bit(x) in ns ???? i -> x ?edge?????ok
            if( (G[i] & ns) == 0 ) {
                ret += dfs(ns, G);
            }
        }
        MEMO[s] = ret;
        return ret;
    }

    static int[] adjDS(int n, int[] from, int[] to) {
        int[][] G = adjD(n, from, to);

        int[] GS = new int[n];

        for (int i = 0; i < N; i++) {
            int[] tos = G[i];

            int s = 0;
            for (int t : tos) {
                s |= 1 << t;
            }
            GS[i] = s;
        }
        return GS;
    }

    static int[][] adjD(int n, int[] from, int[] to) {
        int[][] adj = new int[n][];
        int[] cnt = new int[n];
        for (int f : from) {
            cnt[f]++;
        }
        for (int i = 0; i < n; i++) {
            adj[i] = new int[cnt[i]];
        }
        for (int i = 0; i < from.length; i++) {
            adj[from[i]][--cnt[from[i]]] = to[i];
        }
        return adj;
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