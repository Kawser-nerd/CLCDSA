import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    void solve() throws IOException {
        long a = nl();
        long b = nl();
        long m = nl();

        long d = gcd(a, b);

        long[] X = {0, 1};

        long[][] A = {{10, 1}, {0, 1}};
        long[] ret1 = pow(A, X, a, m);

        long[][] B = {{(int) pow(10, d, m), 1}, {0, 1}};
        long[] ret2 = pow(B, X, b / d, m);

        out.println((ret1[0] * ret2[0]) % m);
    }

    long pow(long a, long x, long m) {
        long ans = 1;
        while (x > 0) {
            if ((x & 1) == 1) {
                ans = (ans * a) % m;
            }
            x >>= 1;
            a = (a * a) % m;
        }
        return ans;
    }

    long[] pow(long[][] a, long[] x, long p, long m) {
        int n = a.length;
        long[][] tmp = new long[n][n];
        for (int i = 0; i < n; i++) {
            tmp[i] = Arrays.copyOf(a[i], n);
        }
        long[] ret = Arrays.copyOf(x, n);
        for (int i = 0; i < n; i++) {
            ret[i] %= m;
        }
        while (p > 0) {
            if ((p & 1) == 1) {
                ret = mul(tmp, ret, m);
            }
            tmp = p2(tmp, m);
            p >>= 1;
        }
        return ret;
    }

    long[] mul(long[][] a, long[] x, long m) {
        int n = a.length;
        long[] ret = new long[n];
        for (int i = 0; i < n; i++) {
            long sum = 0;
            for (int j = 0; j < n; j++) {
                sum += a[i][j] * x[j];
                sum %= m;
            }
            ret[i] = sum;
        }
        return ret;
    }

    long[][] p2(long[][] a, long m) {
        int n = a.length;
        long[][] ret = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += a[i][k] * a[k][j];
                    sum %= m;
                }
                ret[i][j] = sum;
            }
        }
        return ret;
    }

    long gcd(long a, long b) {
        return a == 0 ? b : gcd(b % a, a);
    }

    String ns() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine(), " ");
        }
        return tok.nextToken();
    }

    int ni() throws IOException {
        return Integer.parseInt(ns());
    }

    long nl() throws IOException {
        return Long.parseLong(ns());
    }

    double nd() throws IOException {
        return Double.parseDouble(ns());
    }

    String[] nsa(int n) throws IOException {
        String[] res = new String[n];
        for (int i = 0; i < n; i++) {
            res[i] = ns();
        }
        return res;
    }

    int[] nia(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ni();
        }
        return res;
    }

    long[] nla(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nl();
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        Main main = new Main();
        main.solve();
        out.close();
    }
}