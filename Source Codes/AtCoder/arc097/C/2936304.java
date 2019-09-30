import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static Ball[] B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        B = new Ball[N*2];
        for (int i = 0; i < N*2; i++) {
            B[i] = new Ball(sc.next().charAt(0), sc.nextInt());
        }

        System.out.println( solve() );
    }

    static class Ball {
        char bw;
        int n;

        public Ball(char bw, int n) {
            this.bw = bw;
            this.n = n;
        }

        boolean isBlack() {
            return bw == 'B';
        }

        boolean isWhite() {
            return bw == 'W';
        }

        public String toString() {
            return bw + " " + n;
        }
    }

    static int solve() {
        int[] windex = new int[N+1];
        int[] bindex = new int[N+1];
        for (int i = 0; i < N * 2; i++) {
            if( B[i].isWhite() ) {
                windex[B[i].n] = i;
            } else {
                bindex[B[i].n] = i;
            }
        }

        // ???????
        BinaryIndexedTree bit = new BinaryIndexedTree(N*2);

        // dp[b][w]
        int[][] dp = new int[N+1][N+1];
        int INF = Integer.MAX_VALUE / 2;
        for (int[] array : dp) {
            Arrays.fill(array, INF);
        }
        dp[0][0] = 0;

        // ??DP
        for (int b = 0; b <= N; b++) {
            if( b != 0 ) {
                bit.add(1, 1);
                bit.add(bindex[b]+1, -1);
            }

            for (int w = 0; w <= N; w++) {
                if( w != 0 ) {
                    bit.add(1, 1);
                    bit.add(windex[w]+1, -1);
                }

                if( b < N ) {
                    int bi = bindex[b+1];
                    int inv = bit.sum(bi+1);
                    int swap = (bi - (b+w)) + inv;
                    dp[b+1][w] = Math.min(dp[b+1][w], dp[b][w] + swap);
                }
                if( w < N ) {
                    int wi = windex[w+1];
                    int inv = bit.sum(wi+1);
                    int swap = (wi - (b+w)) + inv;
                    dp[b][w+1] = Math.min(dp[b][w+1], dp[b][w] + swap);
                }
            }

            // w???????
            for (int w = N; w >=1; w--) {
                bit.add(1, -1);
                bit.add(windex[w]+1, +1);
            }
        }

        return dp[N][N];
    }

    static class BinaryIndexedTree {
        int n;
        int[] bit;

        BinaryIndexedTree(int n) {
            this.n = n;
            this.bit = new int[n+1];
        }

        int sum(int i) {
            int s = 0;

            while(i > 0) {
                s += bit[i];
                i -=i & -i;
            }
            return s;
        }

        void add(int i, int x) {
            while( i <= n ) {
                bit[i] += x;
                i += i & -i;
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