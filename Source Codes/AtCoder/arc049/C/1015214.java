import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    void solve() throws IOException {
        int n = ni();
        int a = ni();
        int[] x = new int[a];
        int[] y = new int[a];
        for (int i = 0; i < a; i++) {
            x[i] = ni() - 1;
            y[i] = ni() - 1;
        }
        int b = ni();
        int[] u = new int[b];
        int[] v = new int[b];
        for (int i = 0; i < b; i++) {
            u[i] = ni() - 1;
            v[i] = ni() - 1;
        }

        ArrayList<ArrayList<Integer>> G = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            G.add(new ArrayList<>());
        }

        int[] cnt = new int[n];
        for (int i = 0; i < a; i++) {
            G.get(y[i]).add(x[i]);
            cnt[x[i]]++;
        }
        ArrayList<Integer> ulist = new ArrayList<>();
        for (int i = 0; i < b; i++) {
            G.get(u[i]).add(v[i]);
            if (!ulist.contains(u[i])) {
                ulist.add(u[i]);
            }
            cnt[v[i]]++;
        }

        int ans = 0;
        int m = ulist.size();
        boolean[] used = new boolean[n];
        for (int i = 0; i < 1 << m; i++) {
            Arrays.fill(used, false);
            int[] ccnt = cnt.clone();
            for (int j = 0; j < m; j++) {
                if ((i >> j & 1) == 0) {
                    used[ulist.get(j)] = true;
                    for (int k = 0; k < b; k++) {
                        if (u[k] == ulist.get(j)) {
                            ccnt[v[k]]--;
                        }
                    }
                }
            }
            ArrayDeque<Integer> Q = new ArrayDeque<>();
            for (int j = 0; j < n; j++) {
                if (!used[j] && ccnt[j] == 0) {
                    Q.add(j);
                }
            }

            int tmp = 0;
            while (!Q.isEmpty()) {
                int p = Q.poll();
                if (used[p]) continue;
                tmp++;
                for (int j : G.get(p)) {
                    ccnt[j]--;
                    if (!used[j] && ccnt[j] == 0) {
                        Q.add(j);
                    }
                }
            }
            ans = Math.max(ans, tmp);
        }

        out.println(ans);
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