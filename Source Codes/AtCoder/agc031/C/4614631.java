import java.io.*;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    static int N, A, B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();

        int[] ans = solve();
        PrintWriter pw = new PrintWriter(System.out);
        if( ans != null ) {
            // check(ans);
            pw.println("Yes");
            StringJoiner j = new StringJoiner(" ");
            for (int i : ans) {
                j.add(String.valueOf(i));
            }
            pw.println( j.toString() );

        } else {
            pw.println("No");
        }
        pw.flush();
    }

//    static void check(int[] ans) {
//        int[] check = Arrays.copyOf(ans, 1 << N);
//        for (int i = 1; i < 1 << N; i++) {
//            if( Integer.bitCount(check[i] ^ check[i-1]) != 1 ) {
//                throw new IllegalArgumentException("wtf");
//            }
//        }
//        Arrays.sort(check);
//        for (int i = 0; i < 1<<N; i++) {
//            if( check[i] != i ) {
//                throw new IllegalArgumentException("wtf");
//            }
//        }
//    }

    static int[] solve() {
        if( !isOk(A, B) ) return null;

        int[] ans = new int[1 << N];
        dfs(A, B, 0, 1 << N, 0, N, ans);
        return ans;
    }

    static void dfs(int a, int b, int from, int to, int fix, int n, int[] ans) {
        if( n == 1 ) {
            ans[from] = a;
            ans[to-1] = b;
            return;
        }

        int di = -1;
        for (int i = 0; i < N; i++) {
            int c = 1 << i;
            if( (fix & c) > 0 ) continue;
            if( (a & c) != (b & c) ) {
                di = i;
            }
        }

        // fix?d??????bit??????
        int s = -1;
        for (int i = 0; i < N; i++) {
            if( i != di && (fix & 1 << i) == 0 ) {
                s = a ^ (1 << i);
            }
        }
        // d??????
        int t = s ^ (1 << di);

        int m = from + (to - from) / 2;
        dfs(a, s, from, m, fix | 1 << di, n-1, ans);
        dfs(t, b, m, to, fix | 1 << di, n-1, ans);
    }

    static boolean isOk(int a, int b) {
        return Integer.bitCount(a ^ b) % 2 == 1;
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