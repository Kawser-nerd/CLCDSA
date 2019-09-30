import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int R, C, D;
    static int[][] A;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        R = fc.nextInt();
        C = fc.nextInt();
        D = fc.nextInt();
        A = new int[R][];
        for (int i = 0; i < R; i++) {
            A[i] = fc.nextIntArray(C);
        }
        System.out.println(solve());
    }

    static int solve() {
        int ans = -1;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if( r + c <= D && (r + c) % 2 == D % 2 ) {
                    ans = Math.max(ans, A[r][c]);
                }
            }
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