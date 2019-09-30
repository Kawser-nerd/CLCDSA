import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    void solve() throws IOException {
        int n = ni();

        ArrayList<Pair> list1 = new ArrayList<>();
        ArrayList<Pair2> list2 = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int a = ni();
            int b = ni();

            if (a < b) {
                list1.add(new Pair(a, b));
            } else {
                list2.add(new Pair2(a, b));
            }
        }

        Collections.sort(list1);
        Collections.sort(list2);

        long sum = 0;
        long ans = 0;
        for (Pair p : list1) {
            sum += p.x;
            ans = Math.max(ans, sum);
            sum -= p.y;
        }
        for (Pair2 p : list2) {
            sum += p.x;
            ans = Math.max(ans, sum);
            sum -= p.y;
        }

        out.println(ans);
    }

    public class Pair implements Comparable<Pair> {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Pair p) {
            return x - p.x;
        }
    }

    public class Pair2 implements Comparable<Pair2> {
        int x, y;

        public Pair2(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Pair2 p) {
            return p.y - y;
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

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        Main main = new Main();
        main.solve();
        out.close();
    }
}