import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static Coder[] C;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        C = new Coder[N];
        for (int i = 0; i < N; i++) {
            C[i] = new Coder(i, fc.nextInt(), fc.nextInt());
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (int[] wle : solve()) {
            pw.println(wle[0] + " " + wle[1] + " " + wle[2]);
        }
        pw.flush();
    }

    static int[][] solve() {
        Arrays.sort(C, Comparator.<Coder>comparingInt(c -> c.r).thenComparing(c -> c.h));

        int[][] ans = new int[N][3];
        for (int i = 0; i < N; i++) {
            Coder c = C[i];
            int win_r = lowerBound(C, c1 -> Integer.compare(c.r, c1.r));
            int lose_r = N - upperBound(C, c1 -> Integer.compare(c.r, c1.r));

            int win_g;
            int lose_g;
            if ( c.h == 1 ) { // ??
                win_g = count(C, c.r, 2);
                lose_g = count(C, c.r, 3);

            } else if( c.h == 2 ) { // ???
                win_g = count(C, c.r, 3);
                lose_g = count(C, c.r, 1);

            } else {
                win_g = count(C, c.r, 1);
                lose_g = count(C, c.r, 2);
            }
            ans[c.i][0] = win_r + win_g;
            ans[c.i][1] = lose_r + lose_g;
            ans[c.i][2] = N - ans[c.i][0] - ans[c.i][1] - 1;
        }
        return ans;
    }

    static <A> int count(Coder[] array, int r, int h) {
        Comparable<Coder> comp = c1 -> {
            if( c1.r == r ) {
                return Integer.compare(h, c1.h);

            } else {
                return Integer.compare(r, c1.r);
            }
        };
        return upperBound(array, comp) - lowerBound(array, comp);
    }

    static <A> int lowerBound(A[] array, Comparable<A> c) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            int comp = c.compareTo(array[mid]);
            if( comp > 0 ) { // array[mid] < value ??
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    static <A> int upperBound(A[] array, Comparable<A> c) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            int comp = c.compareTo(array[mid]);
            if( comp >= 0 ) { // array[mid] <= value ??
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    static class Coder {
        int i, r, h;

        public Coder(int i, int r, int h) {
            this.i = i;
            this.r = r;
            this.h = h;
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

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}