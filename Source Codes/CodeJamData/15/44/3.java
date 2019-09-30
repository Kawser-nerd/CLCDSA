import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class D {
    FastScanner in;
    PrintWriter out;

    long MOD = 1000000007;

    public void solve() throws IOException {

        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int r = in.nextInt();
            int c = in.nextInt();

            long sum = 0;
            for (int i = 0; i < c; i++) {
                long[][] cnt = new long[2][r + 1];
                cnt[0][0] = cnt[1][0] = 1;
                for (int j = 0; j < r; j++) {
                    if (j + 2 <= r) {
                        cnt[1][j + 2] = (cnt[1][j + 2] + cnt[0][j]) % MOD;
                    }

                    // 1
                    cnt[0][j + 1] = (cnt[0][j + 1] + cnt[1][j]) % MOD;

                    // 4
                    if (j + 3 <= r && c % 4 == 0 && i % 4 == 0) {
                        cnt[0][j + 3] = (cnt[0][j + 3] + 4 * cnt[1][j]) % MOD;
                    }

                    // 6
                    if (j + 2 <= r && c % 6 == 0 && i % 6 == 0) {
                        cnt[0][j + 2] = (cnt[0][j + 2] + 6 * cnt[1][j]) % MOD;
                    }

                    // 3
                    if (j + 2 <= r && c % 3 == 0 && i % 3 == 0) {
                        cnt[0][j + 2] = (cnt[0][j + 2] + 3 * cnt[1][j]) % MOD;
                    }
                }

                sum = (sum + cnt[0][r] + cnt[1][r]) % MOD;
            }

            long ans = (sum * BigInteger.valueOf(c).modInverse(BigInteger.valueOf(MOD)).longValue()) % MOD;
//            long ans = sum / c;
            out("Case #%d: %d\n", test, ans);
        }
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    public void run() {
        try {
            in = new FastScanner(new File("D-large.in"));
            out = new PrintWriter(new File("D-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new D().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}