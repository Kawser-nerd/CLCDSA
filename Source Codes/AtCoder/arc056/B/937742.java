import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    ArrayList<ArrayList<Integer>> G;

    void solve() throws IOException {
        int N = ni();
        int M = ni();
        int S = ni();

        G = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            G.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            int u = ni() - 1;
            int v = ni() - 1;

            G.get(u).add(v);
            G.get(v).add(u);
        }

        PriorityQueue<Pair> Q = new PriorityQueue<>();
        Q.add(new Pair(S - 1, S - 1));
        int[] max = new int[N];
        boolean[] used = new boolean[N];

        while (!Q.isEmpty()) {
            Pair p = Q.poll();
            if (used[p.x]) continue;
            used[p.x] = true;
            max[p.x] = Math.max(max[p.x], p.y);

            for (int next : G.get(p.x)) {
                Q.add(new Pair(next, Math.min(next, max[p.x])));
            }
        }

        for (int i = 0; i < N; i++) {
            if (i <= max[i]) out.println(i + 1);
        }
    }

    public class Pair implements Comparable<Pair> {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Pair p) {
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