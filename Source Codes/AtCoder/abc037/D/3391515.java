import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int H;
    static int W;
    static int[][] A;
    static int MOD = 1_000_000_007;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        A = new int[H][W];
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                A[h][w] = sc.nextInt();
            }
        }

        System.out.println(solve());
    }

    static int[] DH = {1, 0, -1, 0};
    static int[] DW = {0, 1, 0, -1};

    static int solve() {
        int[][] ref = new int[H][W];
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                int a = A[h][w];
                for (int i = 0; i < 4; i++) {
                    int nh = h + DH[i];
                    int nw = w + DW[i];
                    if( inRange(nh, H) && inRange(nw, W) && A[nh][nw] < a ) {
                        ref[h][w]++;
                    }
                }
            }
        }

        ArrayDeque<Cord> q = new ArrayDeque<>();
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if( ref[h][w] == 0 ) {
                    q.add( new Cord(h, w) );
                }
            }
        }

        int[][] cnt = new int[H][W];
        for (int[] arr : cnt) {
            Arrays.fill(arr, 1);
        }
        while(!q.isEmpty()) {
            Cord c = q.poll();
            int a = A[c.h][c.w];
            for (int i = 0; i < 4; i++) {
                int nh = c.h + DH[i];
                int nw = c.w + DW[i];
                if( inRange(nh, H) && inRange(nw, W) && A[nh][nw] > a ) {
                    cnt[nh][nw] += cnt[c.h][c.w];
                    cnt[nh][nw] %= MOD;
                    ref[nh][nw]--;

                    if( ref[nh][nw] == 0 ) {
                        q.add( new Cord(nh, nw) );
                    }
                }
            }
        }

        int ans = 0;
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                ans += cnt[h][w];
                ans %= MOD;
            }
        }
        return ans;
    }

    static boolean hasNext(int h, int w) {
        int a = A[h][w];
        for (int i = 0; i < 4; i++) {
            int nh = h + DH[i];
            int nw = w + DW[i];

            if( inRange(nh, H) && inRange(nw, W) && A[nh][nw] > a ) {
                return true;
            }
        }
        return false;
    }

    static class Cord {
        int h, w;

        public Cord(int h, int w) {
            this.h = h;
            this.w = w;
        }
    }

    static boolean inRange(int n, int hw) {
        return 0 <= n && n < hw;
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