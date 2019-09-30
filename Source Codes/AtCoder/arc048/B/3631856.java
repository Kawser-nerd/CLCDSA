import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] R, H;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        R = new int[N];
        H = new int[N];
        for (int i = 0; i < N; i++) {
            R[i] = fc.nextInt();
            H[i] = fc.nextInt();
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (int[] wle : solve()) {
            pw.println(wle[0] + " " + wle[1] + " " + wle[2]);
        }
        pw.flush();
    }

    static int[][] solve() {
        int[][] ans = new int[N][3];

        int[] CR = new int[(int)1e6 + 1];
        int[][] CH = new int[(int)1e6 + 1][4];

        for (int i = 0; i < N; i++) {
            CR[R[i]]++;
            CH[R[i]][H[i]]++;
        }

        for (int i = 1; i < CR.length; i++) {
            CR[i] += CR[i-1];
        }

        for (int i = 0; i < N; i++) {
            int w = CR[R[i]-1];
            int l = N - CR[R[i]];

            if( H[i] == 1 ) {
                w += CH[R[i]][2];
                l += CH[R[i]][3];
            } else if( H[i] == 2 ) {
                w += CH[R[i]][3];
                l += CH[R[i]][1];
            } else {
                w += CH[R[i]][1];
                l += CH[R[i]][2];
            }

            ans[i][0] = w;
            ans[i][1] = l;
            ans[i][2] = N - w - l - 1;
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