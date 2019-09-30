import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int M;
    static String S;
    static int[] X;
    static int[] Y;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        S = sc.next();

        X = new int[M];
        Y = new int[M];
        for (int i = 0; i < M; i++) {
            X[i] = sc.nextInt()-1;
            Y[i] = sc.nextInt()-1;
        }

        System.out.println( solve() ? "Yes" : "No" );
    }

    static boolean solve() {
        int[][] G = adjB(N, X, Y);

        int[] A = new int[N];
        int[] B = new int[N];

        for (int i = 0; i < M; i++) {
            int x = X[i];
            int y = Y[i];

            if( x == y ) {
                if( S.charAt(x) == 'A' ) {
                    A[x]++;
                } else {
                    B[x]++;
                }

            } else {
                (S.charAt(y) == 'A' ? A : B)[x]++;
                (S.charAt(x) == 'A' ? A : B)[y]++;
            }
        }

        int last = N;
        ArrayDeque<Integer> bads = new ArrayDeque<>();
        boolean[] done = new boolean[N];
        for (int i = 0; i < N; i++) {
            if( A[i] == 0 || B[i] == 0 ) {
                bads.add(i);
                done[i] = true;
            }
        }

        while(!bads.isEmpty()) {
            int bad = bads.poll();
            boolean is_a = S.charAt(bad) == 'A';
            for (int i : G[bad]) {
                if( done[i] ) continue;

                (is_a ? A : B)[i]--;

                if( A[i] == 0 || B[i] == 0 ) {
                    bads.add(i);
                    done[i] = true;
                }
            }
            last--;
        }

        return last > 0;
    }

    static int[][] adjB(int n, int[] from, int[] to) {
        int[][] adj = new int[n][];
        int[] cnt = new int[n];
        for (int f : from) {
            cnt[f]++;
        }
        for (int t : to) {
            cnt[t]++;
        }
        for (int i = 0; i < n; i++) {
            adj[i] = new int[cnt[i]];
        }
        for (int i = 0; i < from.length; i++) {
            adj[from[i]][--cnt[from[i]]] = to[i];
            adj[to[i]][--cnt[to[i]]] = from[i];
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