import java.io.*;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    static int H, W, Q;
    static char[][] S;
    static int[] H1, W1, H2, W2;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        Q = sc.nextInt();
        S = new char[H][];
        for (int i = 0; i < H; i++) {
            S[i] = sc.next().toCharArray();
        }
        H1 = new int[Q];
        W1 = new int[Q];
        H2 = new int[Q];
        W2 = new int[Q];
        for (int i = 0; i < Q; i++) {
            H1[i] = sc.nextInt()-1;
            W1[i] = sc.nextInt()-1;
            H2[i] = sc.nextInt()-1;
            W2[i] = sc.nextInt()-1;
        }

        writeLines(solve());
    }

    static int[] solve() {

        long[][] node = new long[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                node[i][j] = S[i][j] == '0' ? 0 : 1;
            }
        }

        long[][] edge1 = new long[H][W-1];
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W-1; w++) {
                if( S[h][w] == '1' && S[h][w+1] == '1') {
                    edge1[h][w] = 1;
                }
            }
        }
        long[][] edge2 = new long[H-1][W];
        for (int w = 0; w < W; w++) {
            for (int h = 0; h < H-1; h++) {
                if( S[h][w] == '1' && S[h+1][w] == '1') {
                    edge2[h][w] = 1;
                }
            }
        }

        CumulativeSum2D node_2d = new CumulativeSum2D();
        node_2d.init(H, W, node);
        CumulativeSum2D edge1_2d = new CumulativeSum2D();
        edge1_2d.init(H, W-1, edge1);
        CumulativeSum2D edge2_2d = new CumulativeSum2D();
        edge2_2d.init(H-1, W, edge2);

        int[] ans = new int[Q];
        for (int i = 0; i < Q; i++) {
            int n = (int)node_2d.get(H1[i], W1[i], H2[i], W2[i]);
            int e1;
            if( W1[i] != W2[i] ) {
                e1 = (int)edge1_2d.get(H1[i], W1[i], H2[i], W2[i]-1);
            } else {
                e1 = 0;
            }
            int e2;
            if( H1[i] != H2[i] ) {
                e2 = (int)edge2_2d.get(H1[i], W1[i], H2[i]-1, W2[i]);
            } else {
                e2 = 0;
            }
            ans[i] = n - e1 - e2;
        }

        return ans;
    }

    static class CumulativeSum2D {

        long[][] cs2d;

        void init(int h, int w, long[][] c) {
            this.cs2d = c;
            for (int i = 0; i < h; i++) {
                for (int j = 1; j < w; j++) {
                    c[i][j] += c[i][j-1];
                }
            }
            for (int j = 0; j < w; j++) {
                for (int i = 1; i < h; i++) {
                    c[i][j] += c[i-1][j];
                }
            }
        }

        // ??? (h1, w1), ???(h2, w2), ???
        long get(int h1, int w1, int h2, int w2) {
            // d c
            // b a
            long abcd = cs2d[h2][w2];

            long cd;
            if( h1 > 0 ) {
                cd = cs2d[h1-1][w2];
            } else {
                cd = 0;
            }

            long bd;
            if( w1 > 0 ) {
                bd = cs2d[h2][w1-1];
            } else {
                bd = 0;
            }

            long d;
            if( w1 > 0 && h1 > 0 ) {
                d = cs2d[h1-1][w1-1];
            } else {
                d = 0;
            }

            return abcd - cd - bd + d;
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