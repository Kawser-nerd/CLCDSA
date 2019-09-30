import java.io.*;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    static int H, W;
    static char[][] A;

    static char[][] R;
    static char[][] B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        A = new char[H][];
        for (int i = 0; i < H; i++) {
            A[i] = sc.next().toCharArray();
        }

        solve();
        PrintWriter pw = new PrintWriter(System.out);
        for (int i = 0; i < H; i++) {
            pw.println( new String(R[i]) );
        }
        pw.println();
        for (int i = 0; i < H; i++) {
            pw.println( new String(B[i]) );
        }
        pw.flush();
    }

    static void solve() {
        R = new char[H][W];
        B = new char[H][W];
        for (int h = 0; h < H; h++) {
            R[h][0] = '#';
            R[h][W-1] = '.';
            B[h][0] = '.';
            B[h][W-1] = '#';
        }
        for (int h = 0; h < H; h++) {
            for (int w = 1; w < W-1; w++) {
                R[h][w] = h%2 == 0 ? '#' : '.';
                B[h][w] = h%2 == 1 ? '#' : '.';
            }
        }

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if( A[h][w] == '#' ) {
                    R[h][w] = '#';
                    B[h][w] = '#';
                }
            }
        }
//        char[][] P = new char[H][W];
//        for (int h = 0; h < H; h++) {
//            for (int w = 0; w < W; w++) {
//                P[h][w] = R[h][w] == '#' && B[h][w] == '#' ? '#' : '.';
//            }
//        }
//        for (char[] row : P) {
//            System.out.println( new String(row) );
//        }
//
//        for (int h = 0; h < H; h++) {
//            for (int w = 0; w < W; w++) {
//                if( A[h][w] != P[h][w] ) {
//                    throw new RuntimeException(h + " " + w);
//                }
//            }
//        }
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