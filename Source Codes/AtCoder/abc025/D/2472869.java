import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int[][] board;
    int MOD = 1000000007;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        board = new int[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                board[i][j] = sc.nextInt();
            }
        }
        solve();
    }

    void solve() {
        int[] dp = new int[1 << 25];
        dp[0] = 1;
        for (int state = 0; state < dp.length; state++) {
            if (dp[state] == 0) {
                continue;
            }
            int n = Integer.bitCount(state) + 1;
            for (int i = 0; i < 25; i++) {
                if ((state & 1 << i) > 0) continue;
                int y = i / 5;
                int x = i % 5;
                if (board[y][x] != 0 && board[y][x] != n) {
                    continue;
                }
                if (check(y, x, i, state)) {
                    int newState = state | 1 << i;
                    dp[newState] = (dp[newState] + dp[state]) % MOD;
                }
            }
        }
        System.out.println(dp[dp.length - 1]);
    }

    boolean check(int y, int x, int i, int state) {
        int leftX = x - 1;
        int rightX = x + 1;
        int upperY = y - 1;
        int lowerY = y + 1;
        if (leftX >= 0 && rightX < 5) {
            if ((state & (1 << (i - 1))) > 0 && (state & (1 << (i + 1))) == 0 ||
                    (state & (1 << (i - 1))) == 0 && (state & (1 << (i + 1))) > 0) {
                return false;
            }
        }
        if (upperY >= 0 && lowerY < 5) {
            if ((state & (1 << (i - 5))) > 0 && (state & (1 << (i + 5))) == 0 ||
                    (state & (1 << (i - 5))) == 0 && (state & (1 << (i + 5))) > 0) {
                return false;
            }
        }
        return true;
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