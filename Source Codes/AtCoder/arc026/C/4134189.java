import java.io.*;
import java.util.*;
import java.util.function.IntConsumer;

public class Main {

    static int N, L;
    static Kei[] K;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();

        K = new Kei[N];
        for (int i = 0; i < N; i++) {
            K[i] = new Kei(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }

        System.out.println(solve());
    }

    static long solve() {
        Arrays.sort(K, Comparator.comparingInt(k -> k.l));

        RangeMinimumQuery rmq = new RangeMinimumQuery(L+10);
        rmq.update(0, 0);
        for (int i = 0; i < N; i++) {
            long min = rmq.query(K[i].l, K[i].r);
            rmq.update(K[i].r, Math.min(min + K[i].c, rmq.get(K[i].r)));
        }
        return rmq.get(L);
    }

    static class Kei {
        int l, r, c;

        public Kei(int l, int r, int c) {
            this.l = l;
            this.r = r;
            this.c = c;
        }
    }

    static class RangeMinimumQuery {

        static final long INF = Long.MAX_VALUE / 2;

        private int n;
        private long[] dat;

        RangeMinimumQuery(int n_) {
            n = 1;
            while( n < n_ ) n *= 2;
            dat = new long[n*2];
            Arrays.fill(dat, INF);
        }

        void update(int k, long a) {
            k += n;
            dat[k] = a;

            while(k > 0) {
                k /= 2;
                dat[k] = Math.min(dat[k*2], dat[k*2+1]);
            }
        }

        long query(int a, int b, int k, int l, int r) {
            if (r <= a || b <= l) return INF;

            if (a <= l && r <= b) {
                return dat[k];

            } else {
                long vl = query(a, b, k * 2, l, (l + r) / 2);
                long vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
                return Math.min(vl, vr);
            }
        }

        long query(int a, int b) {
            return query(a, b, 1, 0, n);
        }

        long get(int a) {
            return query(a, a+1);
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