import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    final int mod = (int) 1e9 + 7;

    int[] fact;
    int[] factInv;

    int mul(int x, int y) {
        return (int) (x * 1L * y % mod);
    }

    int c(int n, int k) {
        if (k < 0 || k > n) {
            return 0;
        }
        return mul(fact[n], mul(factInv[k], factInv[n - k]));
    }

    void solve() {
        final int n = in.nextInt();
        fact = new int[n + 1];
        fact[0] = 1;
        for (int i = 1; i < fact.length; i++) {
            fact[i] = mul(i, fact[i - 1]);
        }
        factInv = new int[fact.length];
        factInv[factInv.length - 1] = BigInteger.valueOf(fact[fact.length - 1]).modInverse(BigInteger.valueOf(mod)).intValue();
        for (int i = factInv.length - 2; i >= 0; i--) {
            factInv[i] = mul(factInv[i + 1], i + 1);
        }
        if (n == 2) {
            out.println(1);
            return;
        }
        int res = 0;
        int prev = 0;
        for (int used = 2; used < n; used++) {
            int have = used - 2;
            int min = (n - 3) / 2;
            int more = have - min;
            if (more < 0) {
                continue;
            }
            int cells = 2 * used - n;
            int vars = c(used - 1, cells);
            vars = mul(vars, fact[n - 1 - used]);
            vars = mul(vars, fact[used]);
            res = add(res, mul(sub(vars, prev), used));
            prev = vars;
        }
        out.println(res);
    }

    int sub(int x, int y) {
        x -= y;
        return x < 0 ? (x + mod) : x;
    }

    int add(int x, int y) {
        x += y;
        return x < mod ? x : (x - mod);
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