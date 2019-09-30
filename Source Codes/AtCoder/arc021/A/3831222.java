import java.io.*;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class Main {

    static int[][] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        A = new int[4][];
        for (int i = 0; i < 4; i++) {
            A[i] = sc.nextIntArray(4);
        }

        System.out.println(solve() ? "CONTINUE" : "GAMEOVER");
    }

    static int[] DH = {0, 1, 0, -1};
    static int[] DW = {1, 0, -1, 0};

    static boolean solve() {
        for (int h = 0; h < 4; h++) {
            for (int w = 0; w < 4; w++) {
                for (int i = 0; i < 4; i++) {
                    int nh = DH[i] + h;
                    int nw = DW[i] + w;
                    if( inRange(nh, nw) && A[h][w] == A[nh][nw] ) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    static boolean inRange(int h, int w) {
        return 0 <= h && h < 4 && 0 <= w && w < 4;
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