import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    void solve() throws IOException {
        int n = ni();
        long[][] s = new long[n][n];

        for (int i = 0; i < n; i++) {
            String t = ns();
            for (int j = 0; j < n; j++) {
                if (t.charAt(j) == '1') {
                    s[i][j] = 1;
                }
            }
        }

        out.println(detMod(s, 2) == 0 ? "Even" : "Odd");
    }

    int detMod(long[][] a, int m) {
        int n = a.length;
        long det = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                while (a[j][i] != 0) {
                    long r = a[i][i] / a[j][i];
                    for (int k = i; k < n; k++) {
                        long t = (a[i][k] - r * a[j][k]) % m;
                        a[i][k] = a[j][k];
                        a[j][k] = t;
                    }
                    det = -det;
                }
            }
            det = (det * a[i][i]) % m;
        }
        return (int) det;
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