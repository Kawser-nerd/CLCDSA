import java.io.*;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class Main {

    static int N, X;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        X = sc.nextInt();
        A = sc.nextIntArray(N);

        System.out.println(solve());
    }

    static long solve() {
        long[] RC = new long[N+1];
        for (int i = 0; i < N; i++) {
            RC[N-i-1] = A[i] + RC[N-i];
        }

        long ans = Long.MAX_VALUE;
        for (int k = 1; k <= N; k++) {
            ans = Math.min(calc(k, RC), ans);
        }
        return ans;
    }

    // k????????????
    static long calc(int k, long[] RC) {
        int q = N / k;
        int r = N % k;

        // ???long????????????????
       long ret = 0;
        for (int i = 0; i < q; i++) {
            // [i*k, (i+1)*k]
            long c = RC[i*k] - RC[(i+1)*k];
            // 5, 5, 7, 9.... ?????????
            //   ??????????????
            long a = i == 0 ? 5 : 5 + (i-1) * 2;
            ret = summ(ret, c*a);
        }

        if( r > 0 ) {
            long c = RC[q*k] - RC[N];
            long a = q == 0 ? 5 : 5 + (q-1) * 2;
            ret = summ(ret, c*a);
        }

        // ????
        ret = summ(ret, (long)N*X);
        // ????
        ret = summ(ret, (long)X*k);

        return ret;
    }

    // ??long??????????????????max???????????????????
    static long summ(long a, long b) {
        return a > Long.MAX_VALUE - b ? Long.MAX_VALUE : a + b;
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
            pw.print(as[i]);
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
            if (arg == null) j.add("null");
            else if (arg instanceof int[]) j.add(Arrays.toString((int[]) arg));
            else if (arg instanceof long[]) j.add(Arrays.toString((long[]) arg));
            else if (arg instanceof double[]) j.add(Arrays.toString((double[]) arg));
            else if (arg instanceof Object[]) j.add(Arrays.toString((Object[]) arg));
            else j.add(arg.toString());
        }
        System.err.println(j.toString());
    }

    static void printSingleLine(int[] array) {
        PrintWriter pw = new PrintWriter(System.out);
        for (int i = 0; i < array.length; i++) {
            if (i != 0) pw.print(" ");
            pw.print(array[i]);
        }
        pw.println();
        pw.flush();
    }

    static int lowerBound(int[] array, int value) {
        int lo = 0, hi = array.length, mid;
        while (lo < hi) {
            mid = (hi + lo) / 2;
            if (array[mid] < value) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    static int upperBound(int[] array, int value) {
        int lo = 0, hi = array.length, mid;
        while (lo < hi) {
            mid = (hi + lo) / 2;
            if (array[mid] <= value) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}