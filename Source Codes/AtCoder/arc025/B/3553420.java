import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int H, W;
    static int C[][];

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        H = fc.nextInt();
        W = fc.nextInt();
        C = new int[H][];
        for (int h = 0; h < H; h++) {
            C[h] = fc.nextIntArray(W);
        }
        System.out.println(solve());
    }

    static int solve() {
        // comb(100, 2) ? 5000 ??? 5000 * 5000 = 25M????
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if( (h + w) % 2 == 1 ) C[h][w] = -C[h][w];
            }
        }

        CumulativeSum2D c2d = new CumulativeSum2D();
        c2d.init(H, W, C);

        int ans = 0;
        for (int h1 = 0; h1 < H; h1++) {
            for (int h2 = h1; h2 < H; h2++) {
                for (int w1 = 0; w1 < W; w1++) {
                    for (int w2 = w1; w2 < W; w2++) {
                        if( c2d.get(h1, w1, h2, w2) == 0 ) {
                            ans = Math.max((h2-h1+1) * (w2-w1+1), ans);
                        }
                    }
                }
            }
        }
        return ans;
    }

    static class CumulativeSum2D {

        int[][] cs2d;

        void init(int h, int w, int[][] c) {
            this.cs2d = c;
            for (int i = 0; i < h; i++) {
                for (int j = 1; j < w; j++) {
                    c[i][j] += c[i][j-1];
                }
            }
            for (int j = 0; j < w; j++) {
                for (int i = 1; i < h; i++) {
                    c[i][j] += c[i-1][j];
                }
            }
        }

        // ??? (h1, w1), ???(h2, w2), ???
        int get(int h1, int w1, int h2, int w2) {
            // d c
            // b a
            int abcd = cs2d[h2][w2];

            int cd;
            if( h1 > 0 ) {
                cd = cs2d[h1-1][w2];
            } else {
                cd = 0;
            }

            int bd;
            if( w1 > 0 ) {
                bd = cs2d[h2][w1-1];
            } else {
                bd = 0;
            }

            int d;
            if( w1 > 0 && h1 > 0 ) {
                d = cs2d[h1-1][w1-1];
            } else {
                d = 0;
            }

            return abcd - cd - bd + d;
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