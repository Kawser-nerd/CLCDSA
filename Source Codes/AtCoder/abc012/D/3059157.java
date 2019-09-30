import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;
    static int[] A;
    static int[] B;
    static int[] T;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        A = new int[M];
        B = new int[M];
        T = new int[M];
        for (int i = 0; i < M; i++) {
            A[i] = sc.nextInt()-1;
            B[i] = sc.nextInt()-1;
            T[i] = sc.nextInt();
        }
        System.out.println( solve() );
    }

    static int solve() {
        int INF = Integer.MAX_VALUE / 2;

        int[][] dist = new int[N][N];
        for (int[] arr : dist) Arrays.fill(arr, INF);
        for (int i = 0; i < N; i++) dist[i][i] = 0;

        for (int i = 0; i < M; i++) {
            dist[A[i]][B[i]] = T[i];
            dist[B[i]][A[i]] = T[i];
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if( dist[i][k] == INF || dist[k][j] == INF ) continue;

                    if( dist[i][k] + dist[k][j] < dist[i][j] ) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < N; i++) {
            int max = 0;
            for (int j = 0; j < N; j++) {
                max = Math.max(dist[i][j], max);
            }
            ans = Math.min(ans, max);
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