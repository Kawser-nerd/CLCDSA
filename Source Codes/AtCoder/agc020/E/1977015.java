import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    final int mod = 998244353;

    int add(int x, int y) {
        x += y;
        if (x >= mod) {
            x -= mod;
        }
        return x;
    }

    int mul(int x, int y) {
        return (int) (x * 1L * y % mod);
    }

    HashMap<String, Integer> cache = new HashMap<>();

    int solve(String s) {
        Integer res = cache.get(s);
        if (res == null) {
            int n = s.length();
            int[] dp = new int[n + 1];
            dp[0] = 1;
            for (int pref = 0; pref < n; pref++) {
                int cur = dp[pref];
                if (cur == 0) {
                    continue;
                }
                dp[pref + 1] = add(dp[pref + 1], cur);
                if (s.charAt(pref) == '1') {
                    dp[pref + 1] = add(dp[pref + 1], cur);
                }
                int more = n - pref;
                for (int len = 1; len <= more / 2; len++) {
                    char[] tmp = new char[len];
                    for (int cnt = 2; cnt * len <= more; cnt++) {
                        for (int i = 0; i < len; i++) {
                            boolean haveZero = false;
                            for (int j = 0; j < cnt; j++) {
                                if (s.charAt(pref + j * len + i) == '0') {
                                    haveZero = true;
                                    break;
                                }
                            }
                            if (haveZero) {
                                tmp[i] = '0';
                            } else {
                                tmp[i] = '1';
                            }
                        }
                        int ways = solve(new String(tmp));
                        dp[pref + cnt * len] = add(dp[pref + cnt * len], mul(ways, cur));
                    }
                }
            }
            cache.put(s, dp[n]);
        }
        return cache.get(s);
    }

    void solve22() {
        Random rnd =new Random(123);
        char[] t =new char[100];
        for (int i =0 ; i < t.length; i++) {
            t[i] = rnd.nextBoolean() ? '1' :'0';
        }
        out.println(solve(new String(t)));
    }

    void solve() {
        out.println(solve(in.next()));
    }

    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
}