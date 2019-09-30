import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    void solve() throws IOException {
        int n = ni();
        int[] a = nia(n);

        Arrays.sort(a);

        if ((a[n - 1] + 1) / 2 != a[0]) {
            out.println("Impossible");
            return;
        }

        if (a[0] * 2 == a[n - 1]) {
            int[] cnt = new int[a[0] + 1];
            for (int i = 0; i < n; i++) {
                cnt[a[i] - a[0]]++;
            }
            if (cnt[0] != 1) {
                out.println("Impossible");
                return;
            }
            for (int i = 1; i <= a[0]; i++) {
                if (cnt[i] < 2) {
                    out.println("Impossible");
                    return;
                }
            }
        } else {
            int[] cnt = new int[a[0]];
            for (int i = 0; i < n; i++) {
                cnt[a[i] - a[0]]++;
            }
            if (cnt[0] != 2) {
                out.println("Impossible");
                return;
            }
            for (int i = 2; i < a[0]; i++) {
                if (cnt[i] < 2) {
                    out.println("Impossible");
                    return;
                }
            }
        }

        out.println("Possible");
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