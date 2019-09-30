import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class Main {

    static int N;
    static int[] A, B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = sc.nextIntArray(N);
        B = sc.nextIntArray(N);

        System.out.println(solve());
    }

    static long solve() {
        List<Edge> edges = new ArrayList<>();
        for (int from = 0; from <= 50; from++) {
            for (int d = 1; d <= from ; d++) {
                int to = from % d;
                edges.add( new Edge(from, to, d) );
            }
        }
        List<Edge>[] G = adjListD(51, edges);

        Set<Integer> set = new HashSet<>();
        for (int i = 1; i <= 50; i++) {
            set.add(i);
        }

        // ????????????????
        if( !check(set, G) ) return -1;

        // ??????????????????
        // 2??????????????
        for (int i = 50; i >= 1; i--) {
            // ??????????????????
            set.remove(i);
            if( !check(set, G) ) {
                set.add(i);
            }
        }

        long ans = 0;
        for (int i = 1; i <= 50; i++) {
            if( set.contains(i) ) {
                ans += (long)Math.pow(2, i);
            }
        }
        return ans;
    }

    static boolean check(Set<Integer> set, List<Edge>[] G) {
        for (int i = 0; i < N; i++) {
            if( !isOk(A[i], B[i], set, G) ) {
                return false;
            }
        }
        return true;
    }

    static boolean isOk(int a, int b, Set<Integer> set, List<Edge>[] G) {
        if( a == b ) return true;

        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.add(a);
        while(!q.isEmpty()) {
            int curr = q.poll();

            for (Edge edge : G[curr]) {
                if( !set.contains(edge.d) ) continue;

                int next = edge.b;
                if( b == next ) return true;

                q.add(next);
            }

        }
        return false;
    }

    static List<Edge>[] adjListD(int n, List<Edge> es) {
        List<Edge>[] adj = new List[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (Edge e : es) {
            adj[e.a].add( e );
        }
        return adj;
    }

    static class Edge {
        int a, b, d;

        public Edge(int a, int b, int d) {
            this.a = a;
            this.b = b;
            this.d = d;
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
            pw.print(i);
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
            if (arg instanceof int[]) j.add(Arrays.toString((int[]) arg));
            else if (arg instanceof long[]) j.add(Arrays.toString((long[]) arg));
            else if (arg instanceof double[]) j.add(Arrays.toString((double[]) arg));
            else if (arg instanceof Object[]) j.add(Arrays.toString((Object[]) arg));
            else j.add(arg == null ? "null" : arg.toString());
        }
        System.err.println(j.toString());
    }

    static void printSingleLine(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0) System.out.print(" ");
            System.out.print(array[i]);
        }
        System.out.println();
    }

    static int lowerBound(int[] array, int value) {
        int low = 0, high = array.length, mid;
        while (low < high) {
            mid = ((high - low) >>> 1) + low;
            if (array[mid] < value) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    static int upperBound(int[] array, int value) {
        int low = 0, high = array.length, mid;
        while (low < high) {
            mid = ((high - low) >>> 1) + low;
            if (array[mid] <= value) low = mid + 1;
            else high = mid;
        }
        return low;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.