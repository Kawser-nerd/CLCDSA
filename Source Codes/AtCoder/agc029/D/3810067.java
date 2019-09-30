import java.io.*;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    static int H, W, N;
    static int[] HX, WY;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        N = sc.nextInt();
        HX = new int[N];
        WY = new int[N];
        for (int i = 0; i < N; i++) {
            HX[i] = sc.nextInt()-1;
            WY[i] = sc.nextInt()-1;
        }

        System.out.println(solve());
    }

    static int solve() {
        int[][] HS_ON_W = new int[W][];
        int[] cnt = new int[W];
        for (int i = 0; i < N; i++) {
            cnt[WY[i]]++;
        }
        for (int i = 0; i < W; i++) {
            HS_ON_W[i] = new int[cnt[i]];
        }
        for (int i = 0; i < N; i++) {
            HS_ON_W[WY[i]][--cnt[WY[i]]] = HX[i];
        }
        for (int i = 0; i < W; i++) {
            Arrays.sort(HS_ON_W[i]);
        }

        int h=0;
        int ans = Integer.MAX_VALUE;

        for (int w = 0; w < W; w++) {
            // debug(h, w);
            int ceil = findCeil(h, w, HS_ON_W);

            ans = Math.min(ceil, ans);

            if( h+1 == ceil ) {
                break;
            }

            int space = findSpace(h, w+1, HS_ON_W);
            if( space == -1 ) {
                break;
            }
            h = space;
        }

        return ans;
    }

    static int findCeil(int h, int w, int[][] HS_ON_W) {
        int[] hs = HS_ON_W[w];
        for (int h1 : hs) {
            if (h1 > h) return h1;
        }
        return H;
    }

    // h????(??????)??space???
    static int findSpace(int curh, int nextw, int[][] HS_ON_W) {
        if( nextw == W ) return -1;

        int[] blocks = HS_ON_W[nextw];
        for (int block : blocks) {
            if( block <= curh ) continue;

            if( block == curh+1 ) {
                curh = block;
            } else {
                return curh+1;
            }
        }
        if( curh == H-1 ) return -1;
        else return curh+1;
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