import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    static int H, W, K;
    static char[][] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        K = sc.nextInt();
        A = new char[H][];
        for (int i = 0; i < H; i++) {
            A[i] = sc.next().toCharArray();
        }

        System.out.println(solve());
    }

    static int[] DH = {0, 1, 0, -1};
    static int[] DW = {1, 0, -1, 0};

    static int solve() {
        int sh = -1;
        int sw = -1;
        lo: for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if( A[i][j] == 'S' ) {
                    sh = i;
                    sw = j;
                    break lo;
                }
            }
        }

        boolean[][] B = new boolean[H][W];
        B[sh][sw] = true;
        ArrayDeque<State> q = new ArrayDeque<>();
        q.add( new State(sh, sw, K) );

        while(!q.isEmpty()) {
            State s = q.poll();
            if( s.d == 0 ) continue;

            for (int i = 0; i < 4; i++) {
                int nh = s.h + DH[i];
                int nw = s.w + DW[i];
                int nd = s.d - 1;

                if( 0 <= nh && nh < H && 0 <= nw && nw < W && A[nh][nw] == '.' && !B[nh][nw]) {
                    q.add( new State(nh, nw, nd) );
                    B[nh][nw] = true;
                }
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if( B[i][j] ) {
                    ans = Math.min(calc(i, j), ans);
                }
            }
        }

        return ans;
    }

    static int calc(int h, int w) {
        int d = min(h, H-h-1, w, W-w-1);
        return (d + K-1) / K + 1;
    }

    static class State {
        int h, w, d;

        public State(int h, int w, int d) {
            this.h = h;
            this.w = w;
            this.d = d;
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