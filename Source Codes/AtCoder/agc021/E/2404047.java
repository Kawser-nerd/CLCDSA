import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    final int mod = 998244353;

    int[] fact, factInv;

    void prec(int maxN) {
        maxN *= 2;
        fact = new int[maxN];
        fact[0] = 1;
        for (int i = 1; i < maxN; i++) {
            fact[i] = mul(fact[i - 1], i);
        }
        factInv = new int[maxN];
        factInv[maxN - 1] = BigInteger.valueOf(fact[maxN - 1]).modInverse(BigInteger.valueOf(mod)).intValue();
        for (int i = maxN - 2; i >= 0; i--) {
            factInv[i] = mul(factInv[i + 1], i + 1);
        }
    }

    int c(int n, int k) {
        if (k < 0 || k > n) {
            return 0;
        }
        return mul(fact[n], mul(factInv[k], factInv[n - k]));
    }

    private int mul(int x, int y) {
        return (int) (x * 1L * y % mod);
    }

    int add(int x, int y) {
        x += y;
        if (x >= mod) {
            x -= mod;
        }
        return x;
    }

    int getWays(int x, int y) {
        y = Math.abs(y);
        if (x % 2 != y % 2) {
            return 0;
        }
        int cntPlus = (x + y) / 2;
        int cntMinus = (x - y) / 2;
        if (cntMinus < 0) {
            return 0;
        }
        return c(cntPlus + cntMinus, cntPlus);
    }

    int countSame(int red, int n) {
        int moreRed = red - n;
        if (moreRed < 0) {
            return 0;
        }
        int x = red * 2 - 1;
        return sub(getWays(x, 1), getWays(x, 2 * moreRed + 3));
    }

    int sub(int x, int y) {
        x -= y;
        return x < 0 ? (x + mod) : x;
    }

    // reds = ones + pairs + (z + 1)
    // blues = pairs + (z)
    int count(int red, int blue, int n) {
        if (red == blue) {
            return countSame(red, n);
        }
        if (red <= blue) {
            throw new AssertionError();
        }
        int z = red - n;
        if (z < 0) {
            return 0;
        }
        int pairs = blue - z;
        int moreRed = red - pairs;
        int x = red + blue;
        int y = blue - red;
        return sub(getWays(x, y), getWays(x, -y - 2 * moreRed - 2));
    }

    void solve() {
        int n = in.nextInt();
        int balls = in.nextInt();
        prec(n + balls + 4);
        int res = 0;
        for (int red = (balls + 1) / 2; red <= balls; red++) {
            int blue = balls - red;
            int nowRes = count(red, blue, n);
            res = add(res, nowRes);
        }
        out.println(res);
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