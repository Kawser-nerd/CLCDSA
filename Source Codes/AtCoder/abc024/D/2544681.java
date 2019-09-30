import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    long a, b, c;
    int MOD = 1000000007;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        solve();
    }

    void solve() {
        long ab = a * b % MOD;
        long ac = a * c % MOD;
        long bc = b * c % MOD;
        long r = (bc - ac + MOD) % MOD * inverse((ab - bc + ac + MOD) % MOD, MOD) % MOD;
        long c = (bc - ab + MOD) % MOD * inverse((ab - bc + ac + MOD) % MOD, MOD) % MOD;
        System.out.println(r + " " + c);
    }

    long inverse(long num, int mod) {
        return pow(num, mod - 2, mod);
    }

    long pow(long x, int n, int MOD) {
        long ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = ans * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return ans;
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