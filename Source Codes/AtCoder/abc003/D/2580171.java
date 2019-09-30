import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int r, c, x, y, d, l;
    int MOD = 1000000007;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        r = sc.nextInt();
        c = sc.nextInt();
        x = sc.nextInt();
        y = sc.nextInt();
        d = sc.nextInt();
        l = sc.nextInt();
        solve();
    }

    void solve() {
        int dl = d + l;
        Combination comb = new Combination(900, MOD);
        long ans = 0;
        for (int i = 0; i < 1 << 4; i++) {
            int tx = x;
            int ty = y;
            if ((i & 1) > 0) {
                tx--;
            }
            if ((i & 2) > 0) {
                tx--;
            }
            if ((i & 4) > 0) {
                ty--;
            }
            if ((i & 8) > 0) {
                ty--;
            }
            if (tx < 0 || ty < 0) {
                continue;
            }
            if (Integer.bitCount(i) % 2 == 0) {
                ans += comb.comb(tx * ty, d + l) * comb.comb(d + l, d);
            } else {
                ans -= comb.comb(tx * ty, d + l) * comb.comb(d + l, d);
            }
            ans = (ans + MOD) % MOD;
        }
        ans = ans * (r - x + 1) * (c - y + 1) % MOD;
        System.out.println(ans);
    }

    class Combination {
        long mod;
        int[] facts;
        int[] invs;
        int[] invFacts;

        public Combination(int max, int mod) {
            this.mod = mod;
            facts = new int[max + 2];
            invs = new int[max + 2];
            invFacts = new int[max + 2];
            invs[1] = 1;
            for (int i = 2; i <= max + 1; i++) {
                invs[i] = (int)((long)invs[mod % i] * (mod - mod / i) % mod);
            }
            facts[0] = 1;
            invFacts[0] = 1;
            for (int i = 1; i <= max + 1; i++) {
                facts[i] = (int)(facts[i - 1] * (long)i % mod);
                invFacts[i] = (int)(invFacts[i - 1] * (long)invs[i] % mod);
            }
        }

        long comb (int n, int k) {
            if (k < 0 || k > n) return 0;
            return facts[n] * (long)invFacts[k] % mod * (long)invFacts[n - k] % mod;
        }

        long combRep(int n, int k) {
            return comb(n + k - 1, k);

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