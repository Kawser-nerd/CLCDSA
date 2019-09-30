import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    static int N;
    static int[] L, R;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        L = new int[N];
        R = new int[N];
        for (int i = 0; i < N; i++) {
            L[i] = sc.nextInt();
            R[i] = sc.nextInt();
        }

        System.out.println(solve());
    }

    static long solve(int n, int[] l, int[] r) {
        N = n;
        L = l;
        R = r;
        return solve();
    }

    static long solve() {
        Area[] X = new Area[N];
        Area[] Y = new Area[N];
        for (int i = 0; i < N; i++) {
            Area a = new Area(L[i], R[i]);
            X[i] = a;
            Y[i] = a;
        }
        Arrays.sort(X, Comparator.<Area>comparingInt(a -> a.l).reversed());
        Arrays.sort(Y, Comparator.comparingInt(a -> a.r));

        long x = calc(true, X, Y);
        for (Area area : X) {
            area.used = false;
        }
        long y = calc(false, X, Y);
        return Math.max(x, y);
    }

    static long calc(boolean xfirst, Area[] X, Area[] Y) {
        long ans = 0;
        int cur = 0;
        int xi = 0;
        int yi = 0;
        while(true) {
            while(xi < N && X[xi].used) xi++;
            while(yi < N && Y[yi].used) yi++;

            if( xi == N && yi == N ) {
                ans += Math.abs(cur);
                break;

            } else if( xi == N ) {
                if( Y[yi].r < cur ) {
                    ans += cur - Y[yi].r;
                    Y[yi].used = true;
                    cur = Y[yi].r;
                    yi++;

                } else {
                    ans += Math.abs(cur);
                    break;
                }

            } else if( yi == N ) {
                if( cur < X[xi].l ) {
                    ans += X[xi].l - cur;
                    X[xi].used = true;
                    cur = X[xi].l;
                    xi++;

                } else {
                    ans += Math.abs(cur);
                    break;
                }

            } else {
                int xd = cur < X[xi].l ? X[xi].l - cur : -1;
                int yd = Y[yi].r < cur ? cur - Y[yi].r : -1;

                int run;
                if( xd == -1 && yd == -1 ) {
                    run = 0;
                } else if( yd == -1 ) {
                    run = 1;
                } else if( xd == -1 ) {
                    run = -1;

                } else {
                    if( xi == 0 && yi == 0 ) {
                        run = xfirst ? 1 : -1;
                    } else {
                        run = xd >= yd ? 1 : -1;
                    }
                }

                if( run > 0 ) {
                    ans += xd;
                    X[xi].used = true;
                    cur = X[xi].l;
                    xi++;

                } else if(run < 0) {
                    ans += yd;
                    Y[yi].used = true;
                    cur = Y[yi].r;
                    yi++;

                } else {
                    ans += Math.abs(cur);
                    break;
                }
            }
        }
        return ans;
    }

    static class Area {
        int l, r;
        boolean used;

        public Area(int l, int r) {
            this.l = l;
            this.r = r;
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