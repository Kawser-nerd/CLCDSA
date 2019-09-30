import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n;
    char[][] board;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        board = new char[n][n];
        for (int i = 0; i < n; i++) {
            board[i] = sc.next().toCharArray();
        }
        solve();
    }

    void solve() {
        long count = 0;
        for (int a = 0; a < n; a++) {
            int b = 0;
            boolean flag = true;
            b:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[(i + a) % n][(j + b) % n] !=
                            board[(j + a) % n][(i + b) % n]) {
                        flag = false;
                        break b;
                    }
                }
            }
            if (flag) {
                count++;
            }
        }
        System.out.println(count * n);
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