import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    void solve() throws IOException {
        int n = ni();
        int[] x = nia(n);
        int m = ni();
        long k = nl();
        int[] a = nia(m);

        int[] y = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            y[i] = i;
        }
        for (int i = 0; i < m; i++) {
            int tmp = y[a[i] - 2];
            y[a[i] - 2] = y[a[i] - 1];
            y[a[i] - 1] = tmp;
        }

        y = mul(y, k);

        int[] d = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            d[i] = x[i + 1] - x[i];
        }
        int[] d2 = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            d2[i] = d[y[i]];
        }

        long ans = x[0];
        out.println(ans);
        for (int i = 0; i < n - 1; i++) {
            ans += d2[i];
            out.println(ans);
        }
    }

    int[] mul(int[] a, long x) {
        int n = a.length;
        int[] b = a.clone();
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = i;
        }
        while (x > 0) {
            if ((x & 1) == 1) {
                int[] next = new int[n];
                for (int i = 0; i < n; i++) {
                    next[i] = ret[b[i]];
                }
                ret = next;
            }

            int[] tmp = new int[n];
            for (int i = 0; i < n; i++) {
                tmp[i] = b[b[i]];
            }
            b = tmp;

            x >>= 1;
        }
        return ret;
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

    class INA {
        int[][] a;

        INA(int n, int m) throws IOException {
            this(n, m, -1);
        }

        INA(int n, int m, int t) throws IOException {
            a = new int[m][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[j][i] = ni() + t;
                }
            }
        }

        int[] get(int i) {
            return a[i - 1];
        }
    }

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        Main main = new Main();
        main.solve();
        out.close();
    }
}