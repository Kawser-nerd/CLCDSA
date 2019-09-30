import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = sc.nextIntArray(N);

        System.out.println( solve() ? "YES" : "NO");
    }

    static boolean solve() {
        long sum = 0;
        for (int a : A) {
            sum += a;
        }

        long set;
        if( N % 2 == 0 ) {
            // 1 2 3 4 -> (1+4) * (4/2)
            set = ((long)N + 1) * (N / 2);

        } else {
            set = ((long)N/2 + 1) * N;
        }
        if( sum % set != 0 ) return false;

        long k = sum / set;

        long summ_diff = 0;
        int[] diff = new int[N];
        for (int i = 0; i < N-1; i++) {
            int d = A[i+1] - A[i];
            summ_diff += d;
            diff[i] = d;
        }
        summ_diff += A[0] - A[N-1];
        diff[N-1] = A[0] - A[N-1];
        if( summ_diff != 0 ) return false;

        int b_total = 0;
        for (int i = 0; i < N; i++) {
            // d = (k-b) + b*(1-N)
            // => b = (k-d)/N
            int d = diff[i];
            if( d > k ) return false; // b=0
            if( d < (long)(1-N) * k ) return false; // b=k

            long r = (k-d)%N;
            if( r != 0 ) return false;

            long b = (k-d)/N;
            b_total += b;
        }

        if( b_total != k ) return false;

        return true;
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

        double nextDouble() {
            return Double.parseDouble(next());
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