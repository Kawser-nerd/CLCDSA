import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] A, B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        A = new int[N];
        B = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = fc.nextInt();
            B[i] = fc.nextInt();
        }
        System.out.println(solve());
    }

    static long solve() {
        if( isSame() ) return 0;

        long fst = 0;
        for (int i = 0; i < N; i++) {
            int a = A[i];
            int b = B[i];

            if( a < b ) {
                fst += a;
                A[i] = 0;
                B[i] = b - a;
            } else if( a == b ) {
                fst += a;
                A[i] = 0;
                B[i] = 0;
            }
        }

        // A > B ????????????????? +A
        // ?????????????????? +(A-B)
        long total = 0;
        long cnt = 0;
        for (int i = 0; i < N; i++) {
            int a = A[i];
            int b = B[i];

            if( a > b ) {
                total += a;
                cnt++;
            }
        }

        if( cnt == 0 ) {
            return fst;

        } else if( cnt == 1 ) {
            for (int i = 0; i < N; i++) {
                int a = A[i];
                int b = B[i];

                if( a > b ) {
                    return fst + a - b;
                }
            }
            throw new RuntimeException("wtf");

        } else {
            long snd = -1;
            for (int i = 0; i < N; i++) {
                int a = A[i];
                int b = B[i];

                if( a > b ) {
                    snd = Math.max(total - b, snd);
                }
            }

            return fst + snd;
        }
    }

    static boolean isSame() {
        for (int i = 0; i < N; i++) {
            if( A[i] != B[i] ) return false;
        }
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