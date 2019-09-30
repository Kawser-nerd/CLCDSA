import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    void solve() throws IOException {
        int n = ni();
        int[] a = nia(n - 1);

        G = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            G.add(new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            G.get(a[i] - 1).add(i + 1);
        }

        out.println(rec(0));
    }

    ArrayList<ArrayList<Integer>> G;

    int rec(int x) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int y : G.get(x)) {
            list.add(rec(y));
        }
        Collections.sort(list);
        int ret = 0;
        for (int i = 0; i < list.size(); i++) {
            ret = Math.max(ret, list.get(i) + list.size() - i);
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