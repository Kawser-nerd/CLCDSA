import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int h, w;
    int[][] board;
    Triplet[] series;
    int MOD = 1000000007;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        h = sc.nextInt();
        w = sc.nextInt();
        board = new int[h][w];
        series = new Triplet[h * w];
        int index = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                board[i][j] = sc.nextInt();
                series[index] = new Triplet(i, j, board[i][j]);
                index++;
            }
        }
        solve();
    }

    void solve() {
        long[][] dp = new long[h][w];
        Arrays.sort(series);
        for (int i = 0; i < series.length; i++) {
            int y = series[i].y;
            int x = series[i].x;
            int value = series[i].value;
            dp[y][x] = 1;
            if (x > 0 && board[y][x - 1] < board[y][x]) {
                dp[y][x] += dp[y][x - 1];
                dp[y][x] %= MOD;
            }
            if (x < w - 1 && board[y][x + 1] < board[y][x]) {
                dp[y][x] += dp[y][x + 1];
                dp[y][x] %= MOD;
            }
            if (y > 0 && board[y - 1][x] < board[y][x]) {
                dp[y][x] += dp[y - 1][x];
                dp[y][x] %= MOD;
            }
            if (y < h - 1 && board[y + 1][x] < board[y][x]) {
                dp[y][x] += dp[y + 1][x];
                dp[y][x] %= MOD;
            }
        }
        long sum = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                sum += dp[i][j];
                sum %= MOD;
            }
        }
        System.out.println(sum);
    }

    class Triplet implements Comparable<Triplet> {
        int y;
        int x;
        int value;

        Triplet(int y, int x, int value) {
            this.y = y;
            this.x = x;
            this.value = value;
        }

        public int compareTo(Triplet t) {
            return this.value - t.value;
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}