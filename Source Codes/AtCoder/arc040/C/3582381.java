import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static char[][] S;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        S = new char[N][];
        for (int i = 0; i < N; i++) {
            S[i] = sc.next().toCharArray();
        }

        System.out.println(solve());
    }

    static int solve() {
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int r = -1;
            for (int j = 0; j < N; j++) {
                if( S[i][j] == '.' ) {
                    r = j;
                }
            }
            if( r != -1 ) {
                ans++;
                nuru(i, r);
            }
        }
        return ans;
    }

    static void nuru(int r, int c) {
        for (int i = 0; i <= c; i++) {
            S[r][i] = 'o';
        }
        if( r+1 != N ) {
            for (int i = c; i < N; i++) {
                S[r+1][i] = 'o';
            }
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