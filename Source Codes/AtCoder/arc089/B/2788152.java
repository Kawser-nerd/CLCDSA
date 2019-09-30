import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int K;
    static Req[] R;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        R = new Req[N];
        for (int i = 0; i < N; i++) {
            R[i] = new Req(sc.nextInt(), sc.nextInt(), sc.next().charAt(0));
        }

        System.out.println( solve() );
    }

    static int solve() {
        for (Req r : R) {
            if( r.c == 'B' ) {
                r.c = 'W';
                r.x = r.x + K;
            }

            r.x = r.x % (2*K);
            r.y = r.y % (2*K);
        }

        int[][] rui = calcRui();

        int ans = 0;

        for (int x = 0; x < K; x++) {
            for (int y = 0; y < K; y++) {
                ans = Math.max(calc(x, y, rui), ans);
            }
        }

        return ans;
    }

    static int calc(int x, int y, int[][] rui) {
        int max = 2*K-1;

        if( x == 0 && y == 0 ) {
            int a = count(0, 0, K-1, K-1, rui);
            int b = count(K, K, max, max, rui);
            return Math.max(a+b, N-(a+b));

        } else if( x == 0 ) {
            int c = count(0, y, K-1, y+K-1, rui);
            int rd = count(K, 0, max, y-1, rui);
            int ru = count(K, y+K, max, max, rui);

            int sum = c + rd + ru;
            return Math.max(sum, N-sum);

        } else if( y == 0 ) {
            int c = count(x, 0, x+K-1, K-1, rui);
            int lu = count(0, K, x-1, max, rui);
            int ru = count(x+K, K, max, max, rui);
            int sum = c + lu + ru;
            return Math.max(sum, N-sum);

        } else {
            int c = count(x, y, x+K-1, y+K-1, rui);
            int ld = count(0, 0, x-1, y-1, rui);
            int lu = count(0, y+K, x-1, max, rui);
            int rd = count(x+K, 0, max, y-1, rui);
            int ru = count(x+K, y+K, max, max, rui);

            int sum = c + ld + lu + rd + ru;
            return Math.max(sum, N-sum);
        }
    }

    // (x1, y1)??? (x2, y2)???
    static int count(int x1, int y1, int x2, int y2, int[][] rui) {
        assert(x2 >= x1);
        assert(y2 >= y1);

        if( x1 == 0 && y1 == 0 ) {
            return rui[x2][y2];

        } else if( x1 == 0 ) {
            // a
            // b
            int ab = rui[x2][y2];
            int b = rui[x2][y1-1];
            return ab - b;

        } else if( y1 == 0 ) {
            // b a
            int ab = rui[x2][y2];
            int b = rui[x1-1][y2];
            return ab - b;

        } else {
            // b a
            // d c
            int abcd = rui[x2][y2];
            int bd = rui[x1-1][y2];
            int cd = rui[x2][y1-1];
            int d = rui[x1-1][y1-1];

            return abcd - bd - cd + d;
        }

    }

    static int[][] calcRui() {
        int[][] rui = new int[K*2][K*2];

        for (Req r : R) {
            rui[r.x][r.y] ++;
        }

        for (int y = 0; y < K * 2; y++) {
            for (int x = 1; x < K * 2; x++) {
                rui[x][y] += rui[x-1][y];
            }
        }


        for (int x = 0; x < K * 2; x++) {
            for (int y = 1; y < K * 2; y++) {
                rui[x][y] += rui[x][y-1];
            }
        }
        return rui;
    }

    static class Req {
        int x;
        int y;
        char c;

        public Req(int x, int y, char c) {
            this.x = x;
            this.y = y;
            this.c = c;
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