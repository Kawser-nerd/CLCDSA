import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n;
    char[][] ss;
    int MOD = 1000000007;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        ss = new char[2][n];
        for (int i = 0; i < 2; i++) {
            ss[i] = sc.next().toCharArray();
        }
        solve();
    }

    void solve() {
        long num = 1;
        int prevBlock = 0;
        for (int i = 0; i < n; i++) {
            if (ss[0][i] == ss[1][i]) {
                switch (prevBlock) {
                    case 0:
                        num *= 3;
                        break;
                    case 1:
                        num *= 2;
                        break;
                }
                num %= MOD;
                prevBlock = 1;
            } else {
                switch (prevBlock) {
                    case 0:
                        num *= 6;
                        break;
                    case 1:
                        num *= 2;
                        break;
                    case 2:
                        num *= 3;
                        break;
                }
                num %= MOD;
                prevBlock = 2;
                i++;
            }
        }
        System.out.println(num);
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