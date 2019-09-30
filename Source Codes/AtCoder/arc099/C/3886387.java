import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[] A, B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        A = new int[M];
        B = new int[M];
        for (int i = 0; i < M; i++) {
            A[i] = sc.nextInt() - 1;
            B[i] = sc.nextInt() - 1;
        }

        System.out.println(solve());
    }

    static int solve() {
        int[][] G = adjB(N, A, B);
        int[][] H = complement(N, G);

        if( !isBipartite(N, H)) return -1;

        List<int[]> components = calcComponents(H);

        boolean[][] dp = new boolean[components.size()+1][N+1];
        dp[0][0] = true;

        for (int i = 0; i < components.size(); i++) {
            int[] comp = components.get(i);
            for (int j = N-1; j >= 0; j--) {
                if( dp[i][j] ) {
                    dp[i+1][j+comp[0]] = true;
                    dp[i+1][j+comp[1]] = true;
                }
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int s = 0; s <= N; s++) {
            if( dp[components.size()][s] ) {
                int t = N-s;
                ans = Math.min(perfect(s) + perfect(t), ans);
            }
        }
        return ans;
    }

    static int perfect(int n) {
        return n * (n-1) / 2;
    }

    // ???????????????????
    static List<int[]> calcComponents(int[][] H) {
        int[] flag = new int[N];
        List<int[]> components = new ArrayList<>();

        ArrayDeque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < N; i++) {
            if( flag[i] != 0 ) continue;

            int s = 1, t = 0;
            flag[i] = 1;
            q.add(i);

            while( !q.isEmpty() ) {
                int a = q.poll();

                for (int next : H[a]) {
                    if( flag[next] == 0 ) {
                        flag[next] = -flag[a];
                        if( flag[next] == 1 ) {
                            s++;
                        } else {
                            t++;
                        }
                        q.add(next);
                    }
                }
            }
            components.add(new int[]{s, t});
        }

        return components;
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

    // ????????
    static int[][] complement(int n, int[][] G) {
        int[][] H = new int[N][];
        for (int i = 0; i < N; i++) {
            int[] row = new int[N];
            for (int j : G[i]) {
                row[j] = 1;
            }
            int len = N - G[i].length - 1;
            int[] arr = new int[len];
            for (int j = 0; j < N; j++) {
                if( i == j ) continue;
                if( row[j] == 0 ) {
                    arr[--len] = j;
                }
            }
            H[i] = arr;
        }
        return H;
    }

    static boolean isBipartite(int V, int[][] G) {
        int[] C = new int[V];
        for (int v = 0; v < V; v++) {
            if( C[v] == 0 ) {
                if( !_isBipartite(v, 1, C, G) ) {
                    return false;
                }
            }
        }
        return true;
    }

    @SuppressWarnings("BooleanMethodIsAlwaysInverted")
    static boolean _isBipartite(int v, int c, int[] C, int[][] G) {
        C[v] = c;

        for (int next : G[v]) {
            if( C[next] == c ) return false;
            if( C[next] == 0 && !_isBipartite(next, -c, C, G) ) return false;
        }
        return true;
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
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        int[] nextIntArray(int n, int delta) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt() + delta;
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }
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

    static void writeSingleLine(int[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (int i = 0; i < as.length; i++) {
            if (i != 0) pw.print(" ");
            pw.print(i);
        }
        pw.println();
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
            else j.add(arg == null ? "null" : arg.toString());
        }
        System.err.println(j.toString());
    }

    static void printSingleLine(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0) System.out.print(" ");
            System.out.print(array[i]);
        }
        System.out.println();
    }

    static int lowerBound(int[] array, int value) {
        int low = 0, high = array.length, mid;
        while (low < high) {
            mid = ((high - low) >>> 1) + low;
            if (array[mid] < value) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    static int upperBound(int[] array, int value) {
        int low = 0, high = array.length, mid;
        while (low < high) {
            mid = ((high - low) >>> 1) + low;
            if (array[mid] <= value) low = mid + 1;
            else high = mid;
        }
        return low;
    }
}