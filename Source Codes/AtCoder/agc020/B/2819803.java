import java.io.*;
import java.util.*;

public class Main {

    static int K;
    static long[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        K = sc.nextInt();
        A = sc.nextLongArray(K);

        System.out.println( solve() );
    }

    static String solve() {
        long min = 2;
        long max = 2;

        for (int i = K-1; i >= 0; i--) {
            long a = A[i];

            if (min % a != 0 && max % a != 0) {
                long min_q = min / a;
                long max_q = max / a;

                if( !(min_q < max_q) ) return "-1";
            }

            min = min % a == 0 ? min : ((min / a) + 1) * a;
            max = (max / a) * a + (a-1);
        }

        return min + " " + max;
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