import java.util.*;
import java.io.*;

public class Main {
    static final int MOD = 998244353;

    public static void main(String args[]) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int n = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        long k = in.nextLong();

        int[] fact = new int[n + 1];
        int[] inv = new int[n + 1];

        fact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = (int) ((1l * i * fact[i - 1]) % MOD);
        }

        for (int i = 0; i <= n; i++) {
            inv[i] = mod_pow(fact[i], MOD - 2);
        }

        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        int[] c = new int[b];
        int cycleLength;

        for (int i = 0; i < b; i++) c[i] = -1;

        for (int i = 0; ; i++) {
            if (c[(int) (1l * i * a % b)] != -1) {
                cycleLength = i;
                break;
            }

            c[(int) (1l * i * a % b)] = i;
        }

        if (c[(int) (k % b)] == -1) {
            out.println(0);
        } else {
            int needA = c[(int) (k % b)];
            int needB = (int) ((k - 1l * needA * a) / b);

            int res = 0;

            while (needA <= n && needB >= 0) {
                if (needA <= n && needB <= n) res = (int) ((1l * res + 1l * comb(n, needA, fact, inv) * comb(n, needB, fact, inv)) % MOD);
                needA += cycleLength;
                needB = (int) ((k - 1l * needA * a) / b);
            }

            out.println(res);
        }

        out.close();
    }

    private static long comb(int n, int k, int[] fact, int[] inv) {
        return (long) fact[n] * inv[k] % MOD * inv[n - k] % MOD;
    }

    private static int mod_pow(int n, int k) {
        if (k == 0) return 1;

        int res = mod_pow(n, k >> 1);
        res = (int) ((1l * res * res) % MOD);

        if ((k & 1) > 0) res = (int) ((1l * res * n) % MOD);
        return res;
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f), 32768);
            st = null;
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
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