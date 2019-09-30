import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n, d, x, y;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        d = sc.nextInt();
        x = sc.nextInt();
        y = sc.nextInt();
        solve();
    }

    void solve() {
        if (x % d != 0 || y % d != 0) {
            System.out.println(0.0);
            return;
        }
        int xNum = Math.abs(x) / d;
        int yNum = Math.abs(y) / d;
        if (xNum + yNum > n || (n - xNum - yNum) % 2 == 1) {
            System.out.println(0.0);
            return;
        }
        // comb[i][j] represents iCj / 2 ^ n;
        double[][] comb = new double[1001][1001];
        comb[0][0] = 1;
        for (int i = 1; i < comb.length; i++) {
            for (int j = 0; j <= i; j++) {
                comb[i][j] = (comb[i - 1][j] +
                        (j > 0 ? comb[i - 1][j - 1] : 0)) * 0.5;
            }
        }
        double ans = 0;
        int diff = n - xNum - yNum;
        for (int i = 0; i <= diff; i += 2) {
            ans += comb[xNum + i][xNum + i / 2] *
                    comb[yNum + diff - i][yNum + (diff - i) / 2] *
                    comb[n][xNum + i];
        }
        System.out.println(ans);
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