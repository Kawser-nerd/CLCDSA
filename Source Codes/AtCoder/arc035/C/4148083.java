import java.io.*;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    static int N, M;
    static int[] A, B, C;
    static int K;
    static int[] X, Y, Z;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();

        A = new int[M];
        B = new int[M];
        C = new int[M];
        for (int i = 0; i < M; i++) {
            A[i] = sc.nextInt()-1;
            B[i] = sc.nextInt()-1;
            C[i] = sc.nextInt();
        }
        K = sc.nextInt();
        X = new int[K];
        Y = new int[K];
        Z = new int[K];
        for (int i = 0; i < K; i++) {
            X[i] = sc.nextInt()-1;
            Y[i] = sc.nextInt()-1;
            Z[i] = sc.nextInt();
        }

        writeLines(solve());
    }

    static long[] solve() {
        long INF = Long.MAX_VALUE / 2;
        long[][] dist = new long[N][N];
        for (long[] rows : dist) {
            Arrays.fill(rows, INF);
        }
        for (int i = 0; i < M; i++) {
            dist[A[i]][B[i]] = C[i];
            dist[B[i]][A[i]] = C[i];
        }
        for (int i = 0; i < N; i++) {
            dist[i][i] = 0;
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if( i == j ) continue;

                    if( dist[i][k] + dist[k][j] < dist[i][j] ) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        long[] ans = new long[K];
        for (int k = 0; k < K; k++) {
            int x = X[k];
            int y = Y[k];
            int z = Z[k];
            long sum = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if( i == j ) continue;

                    if( dist[i][x] + dist[y][j] + z < dist[i][j] ) {
                        dist[i][j] = dist[i][x] + dist[y][j] + z;
                    }

                    if( dist[i][y] + dist[x][j] + z < dist[i][j] ) {
                        dist[i][j] = dist[i][y] + dist[x][j] + z;
                    }

                    if( i < j ) {
                        sum += dist[i][j];
                    }
                }
            }
            ans[k] = sum;
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

        int[] nextIntArray(int n, int delta) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt() + delta;
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }

    static <A> void writeLines(A[] as, Function<A, String> f) {
        PrintWriter pw = new PrintWriter(System.out);
        for (A a : as) {
            pw.println(f.apply(a));
        }
        pw.flush();
    }

    static void writeLines(int[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (int a : as) pw.println(a);
        pw.flush();
    }

    static void writeLines(long[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (long a : as) pw.println(a);
        pw.flush();
    }

    static int max(int... as) {
        int max = Integer.MIN_VALUE;
        for (int a : as) max = Math.max(a, max);
        return max;
    }

    static int min(int... as) {
        int min = Integer.MAX_VALUE;
        for (int a : as) min = Math.min(a, min);
        return min;
    }

    static void debug(Object... args) {
        StringJoiner j = new StringJoiner(" ");
        for (Object arg : args) {
            if (arg instanceof int[]) j.add(Arrays.toString((int[]) arg));
            else if (arg instanceof long[]) j.add(Arrays.toString((long[]) arg));
            else if (arg instanceof double[]) j.add(Arrays.toString((double[]) arg));
            else if (arg instanceof Object[]) j.add(Arrays.toString((Object[]) arg));
            else j.add(arg.toString());
        }
        System.err.println(j.toString());
    }
}