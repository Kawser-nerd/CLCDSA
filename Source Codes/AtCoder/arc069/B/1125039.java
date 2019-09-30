import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    void solve() throws IOException {
        int n = ni();
        String s = ns();

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int[] a = new int[n];
                a[0] = i;
                a[1] = j;

                for (int k = 2; k < n; k++) {
                    boolean isSame = s.charAt(k - 1) == 'o';
                    if (a[k - 1] == 1) isSame = !isSame;

                    a[k] = isSame ? a[k - 2] : 1 - a[k - 2];
                }

                if (a[n - 1] == 0) {
                    if (s.charAt(n - 1) == 'o') {
                        if (a[n - 2] != a[0]) {
                            continue;
                        }
                    } else {
                        if (a[n - 2] == a[0]) {
                            continue;
                        }
                    }
                } else {
                    if (s.charAt(n - 1) == 'o') {
                        if (a[n - 2] == a[0]) {
                            continue;
                        }
                    } else {
                        if (a[n - 2] != a[0]) {
                            continue;
                        }
                    }
                }

                if (a[0] == 0) {
                    if (s.charAt(0) == 'o') {
                        if (a[n - 1] != a[1]) {
                            continue;
                        }
                    } else {
                        if (a[n - 1] == a[1]) {
                            continue;
                        }
                    }
                } else {
                    if (s.charAt(0) == 'o') {
                        if (a[n - 1] == a[1]) {
                            continue;
                        }
                    } else {
                        if (a[n - 1] != a[1]) {
                            continue;
                        }
                    }
                }

                StringBuilder sb = new StringBuilder();
                for (int k = 0; k < n; k++) {
                    sb.append(a[k] == 0 ? "S" : "W");
                }
                out.println(sb);
                return;
            }
        }

        out.println(-1);
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