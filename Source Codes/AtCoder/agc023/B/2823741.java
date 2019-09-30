import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static char[][] S;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        S = new char[N][N];

        for (int i = 0; i < N; i++) {
            String s = sc.next();
            for (int j = 0; j < N; j++) {
                S[i][j] = s.charAt(j);
            }
        }

        System.out.println( solve() );
    }

    static int solve() {
        int ans = 0;
        loop: for (int a = 0; a < N; a++) {
            int b = 0;

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {

                    if( i == j ) continue;

                    // (i, j) -> (i+a, j+b)
                    // (j, i) -> (j+a, i+b)
                    if( S[(a + i) % N][(b + j) % N] != S[(a + j) % N][(b + i) % N] ) continue loop;
                }
            }
            ans += N;
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