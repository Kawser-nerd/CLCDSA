import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int h, w, n;
    int[] as;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        h = sc.nextInt();
        w = sc.nextInt();
        n = sc.nextInt();
        as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        solve();
    }

    void solve() {
        int[] sums = new int[n];
        sums[0] = as[0];
        for (int i = 1; i < n; i++) {
            sums[i] = as[i] + sums[i - 1];
        }
        int[][] board = new int[h][w];
        int index = 0;
        int count = 0;
        for (int i = 0; i < h; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < w; j++) {
                    if (count >= sums[index]) {
                        index++;
                    }
                    board[i][j] = index + 1;
                    count++;
                }
            } else {
                for (int j = w - 1; j >= 0; j--) {
                    if (count >= sums[index]) {
                        index++;
                    }
                    board[i][j] = index + 1;
                    count++;
                }
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                System.out.print(board[i][j]);
                if (j < w - 1) {
                    System.out.print(" ");
                } else {
                    System.out.println();
                }
            }
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