import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    void solve() throws IOException {
        int h = ni(), w = ni();
        String[] a = nsa(h);

        char[][] ansR = new char[h][w];
        char[][] ansB = new char[h][w];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 || i < h - 1 && j % 2 == 0) {
                    ansR[i][j] = '#';
                    ansB[i][j] = '.';
                } else {
                    ansR[i][j] = '.';
                    ansB[i][j] = '#';
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (a[i].charAt(j) == '#') {
                    ansR[i][j] = '#';
                    ansB[i][j] = '#';
                }
            }
        }

        for (int i = 0; i < h; i++) {
            out.println(String.valueOf(ansR[i]));
        }
        out.println();
        for (int i = 0; i < h; i++) {
            out.println(String.valueOf(ansB[i]));
        }
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