import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M;
    static int[] U, V, L;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        U = new int[M];
        V = new int[M];
        L = new int[M];
        for (int i = 0; i < M; i++) {
            U[i] = sc.nextInt()-1;
            V[i] = sc.nextInt()-1;
            L[i] = sc.nextInt();
        }

        System.out.println(solve());
    }

    static long INF = Long.MAX_VALUE / 3;

    static long solve() {
        long[][] dist = calcDist(N, U, V, L);

        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < M; i++) {
            if( U[i] == 0 ) {
                dist[0][V[i]] = L[i];
                set.add(V[i]);
            } else if( V[i] == 0 ) {
                dist[0][U[i]] = L[i];
                set.add(U[i]);
            }
        }

        long ans = INF;
        List<Integer> list = new ArrayList<>(set);
        for (int i = 0; i < list.size()-1; i++) {
            for (int j = i+1; j < list.size(); j++) {
                if( dist[list.get(i)][list.get(j)] == INF ) continue;
                long d = dist[list.get(i)][list.get(j)] + dist[0][list.get(i)] + dist[0][list.get(j)];
                ans = Math.min(d, ans);
            }
        }
        return ans == INF ? -1 : ans;
    }

    static long[][] calcDist(int N, int[] A, int[] B, int[] C) {
        long[][] dist = new long[N][N];
        for (long[] arr : dist) Arrays.fill(arr, INF);
        for (int i = 0; i < N; i++) dist[i][i] = 0;

        for (int i = 0; i < A.length; i++) {
            if( A[i] == 0 || B[i] == 0 ) continue;

            dist[A[i]][B[i]] = C[i];
            dist[B[i]][A[i]] = C[i];
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

        return dist;
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