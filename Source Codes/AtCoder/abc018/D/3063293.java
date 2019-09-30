import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;
    static int P;
    static int Q;
    static int R;
    static int[] X;
    static int[] Y;
    static int[] Z;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        P = sc.nextInt();
        Q = sc.nextInt();
        R = sc.nextInt();
        X = new int[R];
        Y = new int[R];
        Z = new int[R];
        for (int i = 0; i < R; i++) {
            X[i] = sc.nextInt()-1;
            Y[i] = sc.nextInt()-1;
            Z[i] = sc.nextInt();
        }

        System.out.println(solve());
    }

    static int solve() {
        int[][] G = new int[N][M];
        for (int i = 0; i < R; i++) {
            G[X[i]][Y[i]] = Z[i];
        }

        int ans = 0;
        int[] F = new int[M];

        int comb = (1 << P) - 1;
        while( comb < 1 << N ) {
            Arrays.fill(F, 0);
            for (int i = 0; i < N; i++) {
                if( (comb & 1 << i) > 0 ) {
                    for (int j = 0; j < M; j++) {
                        F[j] += G[i][j];
                    }
                }
            }
            int sum = 0;
            Arrays.sort(F);
            for (int j = M-1; j >= M-Q; j--) {
                sum += F[j];
            }
            ans = Math.max(sum, ans);

            int x = comb & -comb;
            int y = comb + x;
            comb = ((comb & ~y) / x >> 1) | y;
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