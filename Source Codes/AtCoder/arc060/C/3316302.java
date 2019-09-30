import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.function.IntPredicate;

public class Main {

    static int N;
    static int[] X;
    static int L;
    static int Q;
    static int[] A, B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        X = fc.nextIntArray(N);
        L = fc.nextInt();
        Q = fc.nextInt();
        A = new int[Q];
        B = new int[Q];
        for (int i = 0; i < Q; i++) {
            A[i] = fc.nextInt()-1;
            B[i] = fc.nextInt()-1;
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (int i : solve()) {
            pw.println(i);
        }
        pw.flush();
    }

    static int[] solve() {
        int[] pow2 = new int[30];
        pow2[0] = 1;
        for (int i = 1; i < 30; i++) {
            pow2[i] = pow2[i-1] * 2;
        }

        int[][] lr = new int[30][N];
        int[][] rl = new int[30][N];
        for (int i = 0; i < N-1; i++) {
            int x = X[i];
            lr[0][i] = upperBound(X, x + L)-1;
        }
        lr[0][N-1] = N;

        for (int i = N-1; i >= 1; i--) {
            int x = X[i];
            rl[0][i] = lowerBound(X, x - L);
        }
        rl[0][0] = -1;

        for (int i = 1; i < 30; i++) {
            for (int j = 0; j < N; j++) {
                int half = lr[i-1][j];
                if( half == N ) {
                    lr[i][j] = N;
                } else {
                    lr[i][j] = lr[i-1][half];
                }
            }

            for (int j = 0; j < N; j++) {
                int half = rl[i-1][j];
                if( half == -1 ) {
                    rl[i][j] = -1;
                } else {
                    rl[i][j] = rl[i-1][half];
                }
            }
        }

        int[] ans = new int[Q];
        for (int i = 0; i < Q; i++) {
            if( A[i] < B[i] ) {
                ans[i] = calc_lr(A[i], B[i], lr, pow2);
            } else {
                ans[i] = calc_rl(A[i], B[i], rl, pow2);
            }
        }
        return ans;
    }

    static int calc_rl(int a, int b, int[][] next, int[] pow2) {
        int d = 0;
        while( a != b ) {
            final int aa = a; // fuck java
            int k = maximize(0, 30, kk -> b <= next[kk][aa]);

            if( k == -1 ) {
                a = b;
                d++;
            } else {
                a = next[k][a];
                d += pow2[k];
            }
        }
        return d;
    }

    static int calc_lr(int a, int b, int[][] next, int[] pow2) {
        int d = 0;
        while( a != b ) {
            final int aa = a; // fuck java
            int k = maximize(0, 30, kk -> b >= next[kk][aa]);
            if( k == -1 ) {
                a = b;
                d++;
            } else {
                a = next[k][a];
                d += pow2[k];
            }
        }
        return d;
    }

    static int maximize(int lo, int hi, IntPredicate p) {
        while(lo < hi) {
            int x = ((hi - lo) >>> 1) + lo;
            if( p.test(x) ) {
                lo = x + 1;
            } else {
                hi = x;
            }
        }
        return lo - 1;
    }

    static int lowerBound(int[] array, int value) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( array[mid] < value ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    static int upperBound(int[] array, int value) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( array[mid] <= value ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
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