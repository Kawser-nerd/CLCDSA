import java.io.*;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class Main {

    static int H, W, h, w;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        h = sc.nextInt();
        w = sc.nextInt();

        int[][] ans = solve();
        if( ans != null ) {
            PrintWriter pw = new PrintWriter(System.out);
            pw.println("Yes");
            for (int i = 0; i < H; i++) {
                StringJoiner sj = new StringJoiner(" ");
                for (int j = 0; j < W; j++) {
                    sj.add( String.valueOf(ans[i][j]) );
                }
                pw.println(sj.toString());
            }
            pw.flush();

        } else {
            System.out.println("No");
        }
    }

    static int[][] solve() {
        // ?????????????????????
        if( H % h == 0 && W % w == 0 ) return null;

        // ??????????????????????
        // aaabaaaba ??????????? aaab = -1????????
        // a??????????????????
        int[][] ans = new int[H][W];

        if( H % h == 0 ) {
            int a = 1000;
            int b = -(1000*(w-1) + 1);
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if( j % w == w-1 ) {
                        ans[i][j] = b;
                    } else {
                        ans[i][j] = a;
                    }
                }
            }

        } else {
            int a = 1000;
            int b = -(1000*(h-1) + 1);
            for (int i = 0; i < W; i++) {
                for (int j = 0; j < H; j++) {
                    if( j % h == h -1 ) {
                        ans[j][i] = b;
                    } else {
                        ans[j][i] = a;
                    }
                }
            }
        }

//        int sum = 0;
//        for (int i = 0; i < H; i++) {
//            for (int j = 0; j < W; j++) {
//                sum += ans[i][j];
//            }
//        }
//        debug(sum);

        return ans;
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
}