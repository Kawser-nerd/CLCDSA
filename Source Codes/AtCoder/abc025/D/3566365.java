import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    // ij -> num
    static int[] X;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        X = new int[25];
        for (int i = 0; i < 5; i++) {
            int[] arr = sc.nextIntArray(5);
            for (int j = 0; j < 5; j++) {
                X[i*5 + j] = arr[j];
            }
        }

        System.out.println(solve());
    }

    static int solve() {
        // num -> ij
        int[] Y = new int[26];
        Arrays.fill(Y, -1);
        for (int ij = 0; ij < 25; ij++) {
            int num = X[ij];
            if( num > 0 ) {
                Y[num] = ij;
            }
        }

        int[] dp = new int[1 << 25];
        dp[0] = 1;

        for (int s = 0; s < (1 << 25) - 1; s++) {
            if( dp[s] == 0 ) continue;

            int nextNum = Integer.bitCount(s) + 1;
            if( Y[nextNum] != -1 ) {
                int ij = Y[nextNum];
                if( isOk(s, ij) ) {
                    dp[s | (1 << ij)] = sum(dp[s], dp[s | (1 << ij)]);
                }

            } else {
                for (int ij = 0; ij < 25; ij++) {
                    if( isOk(s, ij) ) {
                        dp[s | (1 << ij)] = sum(dp[s], dp[s | (1 << ij)]);
                    }
                }
            }
        }
        return dp[(1 << 25) - 1];
    }

    static int MOD = 1_000_000_007;

    static boolean isOk(int s, int ij) {
        if( (s & 1 << ij) > 0 ) return false;

        int u = ij - 5;
        int d = ij + 5;
        if( u >= 0 && d < 25 ) {
            boolean uon = (s & 1 << u) > 0;
            boolean don = (s & 1 << d) > 0;
            if( uon ^ don ) return false;
        }

        int l = ij - 1;
        int r = ij + 1;
        if( l >= 0 && l / 5 == ij / 5
                && r < 25 && r / 5 == ij / 5)
        {
            boolean lon = (s & 1 << l) > 0;
            boolean ron = (s & 1 << r) > 0;
            if( lon ^ ron ) return false;
        }
        return true;
    }

    static int sum(int a, int b) {
        int c = a + b;
        if( c >= MOD ) {
            c %= MOD;
        }
        return c;
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