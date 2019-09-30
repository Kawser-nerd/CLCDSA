import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, Z;
    static int[] X;
    static char[] D;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        Z = fc.nextInt();
        X = new int[N];
        D = new char[N];
        for (int i = 0; i < N; i++) {
            X[i] = fc.nextInt()-1;
            D[i] = fc.next().charAt(0);
        }
        System.out.println(solve());
    }

    static long solve() {
        int[] L = new int[N]; // ?????????????
        int[] R = new int[N];
        for (int i = N-1; i >= 0; i--) {
            if( D[i] == 'L' ) {
                if( i != N-1 ) {
                    L[i] = L[i+1] + 1;
                } else {
                    L[i] = 1;
                }
            } else {
                L[i] = 0;
            }
        }
        for (int i = 0; i < N; i++) {
            if( D[i] == 'R' ) {
                if( i != 0 ) {
                    R[i] = R[i-1] + 1;
                } else {
                    R[i] = 1;
                }
            } else {
                R[i] = 0;
            }
        }

        long ans = 0;
        // ????L??
        for (int i = N-2; i >= 0; i--) {
            if( L[i] == 0 ) {
                // L???L?????
                if( L[i+1] >= R[i] ) {
                    long dist = X[i+1] - X[i] - 1;
                    ans += dist * L[i+1];
                }
            } else if( L[i] > 1 ) {
                // L3 L2
                long dist = X[i+1] - X[i] - 1;
                ans += dist * L[i+1];
            }
        }
        if( L[0] > 0 ) {
            long dist = X[0];
            ans += dist * L[0];
        }

        for (int i = 1; i < N; i++) {
            if( R[i] == 0 ) {
                // L???L?????(??=???????)
                if( R[i-1] > L[i] ) {
                    long dist = X[i] - X[i-1] - 1;
                    ans += dist * R[i-1];
                }
            } else if( R[i] > 1 ) {
                // R2 R3
                long dist = X[i] - X[i-1] - 1;
                ans += dist * R[i-1];
            }
        }
        if( R[N-1] > 0 ) {
            long dist = Z - X[N-1] - 1;
            ans += dist * R[N-1];
        }

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