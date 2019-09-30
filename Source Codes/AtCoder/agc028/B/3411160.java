import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    final int mod = (int) 1e9 + 7;

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    int sub(int x, int y) {
        x -= y;
        return x <0 ? (x + mod) : x;
    }

    int mul(int x, int y) {
        return (int) (x * 1L * y % mod);
    }

    void solve() {
        int n = in.nextInt() + 1;

        int[] fact = new int[n];
        fact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = mul(fact[i - 1], i);
        }
        int[] inv = new int[n];
        for (int i = n - 1; i > 0; i--) {
            inv[i] = BigInteger.valueOf(i).modInverse(BigInteger.valueOf(mod)).intValue();
        }
        inv[0] = 1;

        n--;
        int[] f = new int[n];
        for (int k = 0; k < n; k++) {
            f[k] = mul(fact[n], inv[k + 1]);
        }
        int[] pref = new int[n];
        pref[0] = f[0];
        for (int i = 1; i < n; i++) {
            pref[i] = add(pref[i - 1], f[i]);
        }

        int[] a = new int[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            res = add(res, mul(a[i], pref[i]));
            res= add(res, mul(a[i], pref[n - 1 -i ]));
            res = sub(res, mul(a[i], f[0]));
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