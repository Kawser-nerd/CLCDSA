import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int H;
    static int W;
    static int K;
    static char[][] S;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        K = sc.nextInt();
        S = new char[H][];
        for (int i = 0; i < H; i++) {
            S[i] = sc.next().toCharArray();
        }
        System.out.println( solve() );
    }

    static int solve() {
        int[][] DOWN = new int[H][W];
        for (int w = 0; w < W; w++) {
            int cnt = 0;
            for (int h = H-1; h >= 0; h--) {
                if( S[h][w] == 'o' ) {
                    cnt++;
                } else {
                    cnt = 0;
                }
                DOWN[h][w] = cnt;
            }
        }

        int[][] UP = new int[H][W];
        for (int w = 0; w < W; w++) {
            int cnt = 0;
            for (int h = 0; h < H; h++) {
                if( S[h][w] == 'o' ) {
                    cnt++;
                } else {
                    cnt = 0;
                }
                UP[h][w] = cnt;
            }
        }

        int ans = 0;
        for (int h = 1; h <= H-2; h++) {
            w_loop: for (int w = 1; w <= W-2; w++) {
                int l = w;
                int r = W-w-1;

                if( l < K-1 ) continue;
                if( r < K-1 ) continue;

                for (int dk = -(K-1); dk <= K-1; dk++) {
                    int req = K - Math.abs(dk);
                    int wk = w + dk;
                    if( UP[h][wk] < req || DOWN[h][wk] < req ) {
                        continue w_loop;
                    }
                }
                ans++;
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