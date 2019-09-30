import java.io.*;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    static int N, L, T;
    static int[] X, W;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();
        T = sc.nextInt();
        X = new int[N];
        W = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = sc.nextInt();
            W[i] = sc.nextInt();
        }

        writeLines( solve() );
    }

    static int[] solve() {
        Ant[] A = new Ant[N];
        int w1 = 0;
        for (int i = 0; i < N; i++) {
            A[i] = new Ant(i, X[i], W[i]);
            if( W[i] == 1 ) w1++;
        }
        int w2 = N-w1;

        // ???????????????2???????
        // ???????????
        int q = T / L;
        for (int i = 0; i < N; i++) {
            Ant ant = A[i];
            // ??????????????
            if( ant.w == 1 ) {
                long time = (long)w2 * 2 * q;
                ant.z = (int)((ant.z + time) % N);
                if( time % 2 == 1 ) ant.flip();

            } else {
                long time = (long)w1 * 2 * q;
                ant.z = (int)((ant.z - time) % N);
                if( ant.z < 0 ) ant.z += N;
                if( time % 2 == 1 ) ant.flip();
            }
        }

        // w???????????? r*2??????????????????????
        // ????????????
        w1 = 0;
        for (int i = 0; i < N; i++) {
            if( A[i].w == 1 ) w1++;
        }
        w2 = N-w1;

        int[] XW1 = new int[w1];
        int[] XW2 = new int[w2];
        for (int i = 0; i < N; i++) {
            if( A[i].w == 1 ) {
                XW1[XW1.length - (--w1) - 1] = A[i].x;
            } else {
                XW2[XW2.length - (--w2) - 1] = A[i].x;
            }
        }

        int r = T % L;
        for (int i = 0; i < N; i++) {
            Ant ant = A[i];
            if( ant.w == 1 ) {
                int c = countModLike(XW2, ant.x, ant.x + r*2);
                ant.z = (ant.z + c) % N;
                ant.x = (ant.x + r) % L;
            } else {
                int c = countModLike(XW1, ant.x-r*2, ant.x);
                ant.z = (ant.z - c);
                if( ant.z < 0 ) ant.z += N;
                ant.x = (ant.x - r);
                if( ant.x < 0 ) ant.x += L;
            }
        }

        int[] ans = new int[N];
        for (int i = 0; i < N; i++) {
            Ant ant = A[i];
            ans[ant.z] = ant.x;
        }
        return ans;
    }

    // from, to????????????????????
    // [-2, -1] ?? [N+1, N+2] ?????
    static int countModLike(int[] XW, int from, int to) {
        int n = XW.length;
        int ret = 0;
        if( from < 0 ) {
            int dist = Math.abs(from);
            if( dist >= L ) {
                dist -= L;
                ret += n;
            }
            ret += count(L-dist, L, XW);
            from = 0;

        }
        if( to >= L ) {
            int dist = to - L;
            if( dist >= L ) {
                dist -= L;
                ret += n;
            }
            ret += count(0, dist, XW);
            to = L-1;
        }
        ret += count(from, to, XW);
        return ret;
    }

    // [from, to]
    static int count(int from, int to, int[] array) {
        int f = lowerBound(array, from);
        int t = upperBound(array, to);
        return t - f;
    }

    static int lowerBound(int[] array, int value) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( array[mid] < value ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    static int upperBound(int[] array, int value) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( array[mid] <= value ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    static class Ant {
        int z, x, w;

        public Ant(int z, int x, int w) {
            this.z = z;
            this.x = x;
            this.w = w;
        }

        public void flip() {
            w = w == 1 ? 2 : 1;
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