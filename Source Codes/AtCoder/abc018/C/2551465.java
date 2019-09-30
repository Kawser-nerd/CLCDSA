import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int r, c, k;
    boolean[][] board;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        r = sc.nextInt();
        c = sc.nextInt();
        k = sc.nextInt();
        board = new boolean[r][c];
        for (int i = 0; i < r; i++) {
            char[] cs = sc.next().toCharArray();
            for (int j = 0; j < c; j++) {
                board[i][j] = cs[j] == 'o';
            }
        }
        solve();
    }

    void solve() {
        int[][] upper = new int[r][c];
        int[][] lower = new int[r][c];
        int count = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int upperCount = 0;
                int lowerCount = 0;
                for (int l = 0; l < k; l++) {
                    if (j < l) {
                        continue;
                    }
                    if (!board[i][j - l]) {
                        break;
                    }
                    upperCount++;
                }
                for (int l = 0; l < k; l++) {
                    if (j + l >= c) {
                        continue;
                    }
                    if(!board[i][j + l]) {
                        break;
                    }
                    lowerCount++;
                }
                upper[i][j] = upperCount;
                lower[i][j] = lowerCount;
            }
        }
        for (int i = k - 1; i <= r - k; i++) {
            for (int j = k - 1; j <= c - k; j++) {
                boolean flag = true;
                for (int l = -k + 1; l < k; l++) {
                    int bound = k - Math.abs(l);
                    if (upper[i + l][j] < bound || lower[i + l][j] < bound) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    count++;
                }
            }
        }
        System.out.println(count);
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