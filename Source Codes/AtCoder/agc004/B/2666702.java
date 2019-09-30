import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int X;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        X = sc.nextInt();
        A = sc.nextIntArray(N);

        System.out.println( solve() );
    }

    private static long solve() {
        int[][] cost = new int[N][N];

        for (int i = 0; i < N; i++) {
            cost[0][i] = A[i];
        }

        for (int magic = 1; magic <= N-1; magic++) {
            for (int i = 0; i < N; i++) {
                int prevIndex = i - magic;
                if( prevIndex < 0 ) prevIndex+=N;
                cost[magic][i] = Math.min(cost[magic-1][i], A[prevIndex]);
            }
        }

        long ans = Long.MAX_VALUE;
        for (int magic = 0; magic <= N-1; magic++) {
            long sum = 0;
            for (int i = 0; i < N; i++) {
                sum += cost[magic][i];
            }
            ans = Math.min(((long)X) * magic + sum, ans);
        }
        return ans;
    }

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