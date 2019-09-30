import java.io.*;
import java.util.*;
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

        System.out.println(solve() ? "YES" : "NO");
    }

    static boolean solve() {
        char[][] D = new char[H][];
        boolean[] used = new boolean[H];

        return dfs(D, used, 0, 0, H-1, 0);
    }

    static boolean dfs(char[][] D, boolean[] used, int start, int top, int bot, int cnt) {
        if( cnt == H ) {
            return check(D);
        }

        for (int i = start; i < H; i++) {
            if( used[i] ) continue;

            // find pair
            for (int j = i+1; j < H; j++) {
                if( used[j] ) continue;

                if( canPair(i, j) ) {
                    D[top++] = C[i];
                    D[bot--] = C[j];
                    used[i] = true;
                    used[j] = true;
                    boolean ok = dfs(D, used, i+1, top, bot, cnt+2);
                    if( ok ) {
                        return true;
                    } else {
                        D[top--] = null;
                        D[bot++] = null;
                        used[i] = false;
                        used[j] = false;
                    }
                }
            }

            // ??????????????????????
            if( H % 2 == 1 && D[H/2] == null && canMid(i) ) {
                D[H/2] = C[i];
                used[i] = true;
                boolean ok = dfs(D, used, i+1, top, bot, cnt+1);
                if( ok ) {
                    return true;
                } else {
                    D[H/2] = null;
                    used[i] = false;
                }
            }
        }
        return false;
    }

    static boolean check(char[][] D) {
        boolean[] used = new boolean[W];
        boolean mid = false;
        lo: for (int i = 0; i < W; i++) {
            if( used[i] ) continue;
            for (int j = i+1; j < W; j++) {
                if( used[j] ) continue;

                if( canPairCol(D, i, j) ) {
                    used[i] = true;
                    used[j] = true;
                    continue lo;
                }
            }

            if( W % 2 == 1 && !mid ) {
                mid = true;
                used[i] = true;
                continue;
            }
            return false; // no pair
        }
        return true;
    }

    static boolean canPairCol(char[][] D, int i, int j) {
        for (int k = 0; k < H/2; k++) {
            if( D[k][i] != D[H-k-1][j] ) return false;
        }
        return true;
    }

    static boolean canPair(int i, int j) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int k = 0; k < W; k++) {
            char c = C[i][k];
            char d = C[j][k];

            if( c > d ) {
                char t = c;
                c = d;
                d = t;
            }

            int cd = c * 100 + d;
            if( cnt.containsKey(cd) ) {
                cnt.put(cd, cnt.get(cd)+1);
            } else {
                cnt.put(cd, 1);
            }
        }

        int odd = 0;
        for (Map.Entry<Integer, Integer> each : cnt.entrySet()) {
            if( each.getValue() % 2 == 1 ) odd++;
        }

        if( W % 2 == 0 ) {
            return odd == 0;
        } else {
            return odd <= 1;
        }
    }

    static boolean canMid(int i) {
        char[] cnt = new char[26];
        for (int j = 0; j < W; j++) {
            cnt[C[i][j]-'a']++;
        }
        int odd = 0;
        for (char c : cnt) {
            if( c % 2 == 1 ) odd++;
        }
        if( W % 2 == 0 ) {
            return odd == 0;
        } else {
            return odd <= 1;
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