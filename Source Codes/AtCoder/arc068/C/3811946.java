import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    static int N, M;
    static Item[] I;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        I = new Item[N];
        for (int i = 0; i < N; i++) {
            I[i] = new Item(sc.nextInt(), sc.nextInt());
        }

        writeLines(solve());
    }

    static int[] solve() {
        Arrays.sort(I);

        BinaryIndexedTree bit = new BinaryIndexedTree(M+2);
        int i = 0;
        int[] ans = new int[M];
        ans[0] = N;
        for (int d = 2; d <= M; d++) {
            while(i < N) {
                if( I[i].length() < d ) {
                    bit.add(I[i].l, 1);
                    bit.add(I[i].r+1, -1);
                    i++;
                } else {
                    break;
                }
            }

            int matagu = N - i;
            for (int j = d; j <= M; j += d) {
                matagu += bit.sum(j);
            }

            ans[d-1] = matagu;
        }
        return ans;
    }

    static class Item implements Comparable<Item> {
        final int l, r;

        public Item(int l, int r) {
            this.l = l;
            this.r = r;
        }

        @Override
        public int compareTo(Item o) {
            return Integer.compare(length(), o.length());
        }

        public int length() {
            return r - l;
        }
    }

    static class BinaryIndexedTree {

        int n;
        int[] bit;

        BinaryIndexedTree(int n) {
            this.n = n;
            this.bit = new int[n+1];
        }

        void add(int i, int v) {
            i++; // 0 index -> 1 index

            while( i <= n ) {
                bit[i] += v;
                i += i & -i;
            }
        }

        int sum(int i) {
            i++; // 0 index -> 1 index

            int ret = 0;
            while(i > 0) {
                ret += bit[i];
                i -= i & -i;
            }
            return ret;
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