import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int L;
    static int[] B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        L = fc.nextInt();
        B = fc.nextIntArray(L);

        int[] ans = solve();
        if( ans == null ) {
            System.out.println(-1);

        } else {
            PrintWriter pw = new PrintWriter(System.out);
            for (int i : ans) {
                pw.println(i);
            }
            pw.flush();
        }
    }

    static int[] solve() {
        // A0 ^ A1 = B0
        // => A0 ^ B0 = A1
        // B0?? A0, A1????
        // A1 ^ A2 = B1 => A1 ^ B1 = A2
        // ?????????????????????ok
        int[] A = new int[L];
        for (int i = 0; i <= 30; i++) {
            int bit = 1 << i;
            // bit???????
            // A[0] = 0, A[1] = 1 ?????
            // A[0] ?0??????????
            if( (B[0] & bit) > 0 ) {
                A[1] |= bit;
            }
        }

        for (int i = 1; i < L-1; i++) {
            A[i+1] = A[i] ^ B[i];
        }

        if( (A[L-1] ^ B[L-1]) == A[0] ) {
            return A;
        } else {
            return null;
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