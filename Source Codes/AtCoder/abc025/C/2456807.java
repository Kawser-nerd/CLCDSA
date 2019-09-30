import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int[][] bs, cs;
    int sum;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        bs = new int[2][3];
        cs = new int[3][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                bs[i][j] = sc.nextInt();
                sum += bs[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                cs[i][j] = sc.nextInt();
                sum += cs[i][j];
            }
        }
        solve();
    }

    void solve() {
        int ans = rec(new int[3][3], 1);
        System.out.println(ans);
        System.out.println(sum - ans);
    }

    int rec(int[][] board, int turn) {
        if (turn == 9) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 0) {
                        board[i][j] = 1;
                        int ret = calc(board);
                        board[i][j] = 0;
                        return ret;
                    }
                }
            }
        }
        int max = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = turn % 2 == 1 ? 1 : 2;
                    int score = rec(board, turn + 1);
                    max = Math.max(max, score);
                    min = Math.min(min, score);
                    board[i][j] = 0;
                }
            }
        }
        return turn % 2 == 1 ? max : min;
    }

    int calc(int[][] board) {
        int score = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == board[i + 1][j]) {
                    score += bs[i][j];
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                if (board[i][j] == board[i][j + 1]) {
                    score += cs[i][j];
                }
            }
        }
        return score;
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