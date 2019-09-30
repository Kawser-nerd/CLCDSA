import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] A;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        A = fc.nextIntArray(N);
        System.out.println(solve());
    }

    static int MOD = 1_000_000_007;

    static long solve() {
        if( A[0] != 0 ) return 0;

        int MAX = -1;
        for (int i = 0; i < N; i++) {
            MAX = Math.max(A[i], MAX);
        }

        int[] C = new int[MAX+1]; // ??
        int[] D = new int[MAX+1]; // ??(????)
        for (int i = 0; i < N; i++) {
            C[A[i]]++;
            D[A[i]]++;
        }

        // ?????????????
        if( C[0] != 1 ) return 0;
        for (int i = 1; i <= MAX; i++) {
            if( C[i] == 0 ) return 0;
        }

        int[] POW = new int[N];
        POW[0] = 1;
        for (int i = 1; i < N; i++) {
            POW[i] = POW[i-1] * 2 % MOD;
        }

        long ans = 1;
        for (int i = 1; i < N; i++) {
            // ???????????????????
            // 2 ^ sib
            // parent????????????
            // (2 ^ parent) - 1
            // ??????
            int sib = --D[A[i]];
            int parent = C[A[i]-1];
            ans = ans * POW[sib] % MOD;
            ans = ans * (POW[parent]-1 + MOD) % MOD;
        }
        return ans;
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