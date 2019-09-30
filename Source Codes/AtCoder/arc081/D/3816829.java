import java.io.*;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    static int H, W;
    static char[][] C;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        C = new char[H][];
        for (int i = 0; i < H; i++) {
            C[i] = sc.next().toCharArray();
        }

        System.out.println(solve());
    }

    static long solve() {
        int[][] D = new int[H-1][W-1];

        for (int h = 0; h < H-1; h++) {
            for (int w = 0; w < W-1; w++) {
                D[h][w] = isOk(h, w) ? 1 : 0;
            }
        }

        // 1 1 0 1 1 -> 1 2 0 1 2
        // ??
        for (int w = 0; w < W-1; w++) {
            for (int h = 0; h < H-1; h++) {
                if( D[h][w] == 1 ) {
                    D[h][w] += h == 0 ? 0 : D[h-1][w];
                }
            }
        }

        long ans = Math.max(H, W); // ??????(?)??????
        for (int h = 0; h < H-1; h++) {
            ans = Math.max(maxRectPlus(D[h]), ans);
        }
        return ans;
    }

    static int[] DH = {0, 1, 0, 1};
    static int[] DW = {0, 0, 1, 1};

    static boolean isOk(int h, int w) {
        // h, w???
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            if( C[h + DH[i]][w + DW[i]] == '#' ) cnt++;
        }
        return cnt % 2 == 0;
    }

    static long maxRectPlus(int[] a) {
        int n = a.length;
        int[] stack = new int[n];
        int[] left = new int[n];
        int p = 0;
        long max = 0;
        for(int i = 0; i < n; i++){
            int o = p;
            while(p > 0 && stack[p-1] >= a[i]) {
                p--;
                int w = i-1-left[p]+1;
                int h = stack[p];
                max = Math.max(max, (long)(w+1)*(h+1));
            }
            if(o == p) left[p] = i;
            stack[p++] = a[i];
        }
        while(p > 0) {
            p--;
            int w = n-1-left[p]+1;
            int h = stack[p];
            max = Math.max(max, (long)(w+1)*(h+1));
        }
        return max;
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