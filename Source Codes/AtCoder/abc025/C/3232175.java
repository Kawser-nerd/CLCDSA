import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;
import java.util.function.IntBinaryOperator;

public class Main {

    static int[][] B;
    static int[][] C;
    static int TOTAL = 0;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        B = new int[2][3];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                B[i][j] = fc.nextInt();
                TOTAL += B[i][j];
            }
        }
        C = new int[3][2];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                C[i][j] = fc.nextInt();
                TOTAL += C[i][j];
            }
        }
        int ans = solve();
        System.out.println(ans);
        System.out.println(TOTAL - ans);
    }

    static int solve() {
        init();

        return dfs(0, 0, 0);
    }

    static int MASK = (1 << 9) - 1;
    static List<Point> P;
    static int[][] MEMO;

    static int dfs(int n, int x, int y) {
        if( MEMO[x][y] != -1 ) {
            return MEMO[x][y];
        }

        int r = _dfs(n, x, y);
        MEMO[x][y] = r;
        return r;
    }

    static int _dfs(int n, int x, int y) {
        if( n == 9 ) {
            return calc(x, y);
        }

        int bits = (x | y) ^ MASK;
        int ret = n % 2 == 0 ? -1 : Integer.MAX_VALUE;
        IntBinaryOperator f = n % 2 == 0 ? Math::max : Math::min;
        while( bits != 0 ) {
            int high = Integer.highestOneBit(bits);
            int xx = n % 2 == 0 ? x|high : x;
            int yy = n % 2 == 1 ? y|high : y;
            int r = dfs(n+1, xx, yy);
            ret = f.applyAsInt(r, ret);
            bits -= high;
        }
        return ret;
    }

    static void init() {
        MEMO = new int[1<<9][1<<9];
        for (int[] arr : MEMO) {
            Arrays.fill(arr, -1);
        }

        // 0, 1, 2
        // 3, 4, 5
        // 6, 7, 8
        P = new ArrayList<>();

        P.add( new Point(bit(0, 3), B[0][0]) );
        P.add( new Point(bit(1, 4), B[0][1]) );
        P.add( new Point(bit(2, 5), B[0][2]) );
        P.add( new Point(bit(3, 6), B[1][0]) );
        P.add( new Point(bit(4, 7), B[1][1]) );
        P.add( new Point(bit(5, 8), B[1][2]) );

        P.add( new Point(bit(0, 1), C[0][0]) );
        P.add( new Point(bit(1, 2), C[0][1]) );
        P.add( new Point(bit(3, 4), C[1][0]) );
        P.add( new Point(bit(4, 5), C[1][1]) );
        P.add( new Point(bit(6, 7), C[2][0]) );
        P.add( new Point(bit(7, 8), C[2][1]) );
    }

    static int bit(int a, int b) {
        return (1 << a) | (1 << b);
    }

    static int calc(int x, int y) {
        int ret = 0;
        for (Point p : P) {
            if( (p.bit & x) == p.bit || (p.bit & y) == p.bit ) {
                ret += p.p;
            }
        }
        return ret;
    }

    static class Point {
        int bit;
        int p;

        public Point(int bit, int p) {
            this.bit = bit;
            this.p = p;
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