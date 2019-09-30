import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {
    static final int UNCALC = -1;
    static final int INF = (int) 1e9;
    static ArrayList<Integer> adjList[];
    static int[] color;
    static int n, m, wb[];
    static ArrayList<Integer> one, two;
    static boolean poss;
    static int memo[][];
    static int[] cum;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        n = sc.nextInt();
        int e = sc.nextInt();
        boolean[][] edges = new boolean[n][n];
        while (e-- > 0) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            edges[u][v] = true;
            edges[v][u] = true;
        }
        adjList = new ArrayList[n];
        for (int i = 0; i < n; i++)
            adjList[i] = new ArrayList<>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && !edges[i][j])
                    adjList[i].add(j);
        solve();
        m = one.size();
        cum = new int[m + 1];
        for (int i = 1; i <= m; i++)
            cum[i] = one.get(i - 1) + two.get(i - 1) + cum[i - 1];
        memo = new int[m][n + 1];
        for (int[] b : memo)
            Arrays.fill(b, UNCALC);
        out.println(poss ? dp(0, 0) : -1);
        out.flush();
        out.close();
    }

    static void solve() {
        color = new int[n];
        poss = true;
        Arrays.fill(color, UNCALC);
        one = new ArrayList<>();
        two = new ArrayList<>();
        for (int i = 0; i < n && poss; i++) {
            if (color[i] != UNCALC) continue;
            wb = new int[2];
            wb[0]++;
            color[i] = 0;
            poss = bipartiteCheck(i);
            one.add(wb[0]);
            two.add(wb[1]);
        }
    }

    static int dp(int idx, int taka) {
        int hashi = cum[idx] - taka;
        if (idx == one.size()) return calc(taka) + calc(hashi);
        if (memo[idx][taka] != UNCALC)
            return memo[idx][taka];
        int a = one.get(idx);
        int b = two.get(idx);
        return memo[idx][taka] = Math.min(dp(idx + 1, taka + a), dp(idx + 1, taka + b));
    }

    static int calc(int x) {
        return x * (x - 1) / 2;
    }


    static boolean bipartiteCheck(int u) {
        for (int v : adjList[u]) {
            if (color[v] == UNCALC) {
                color[v] = 1 - color[u];
                wb[color[v]]++;
                if (!bipartiteCheck(v)) return false;
            } else if (color[u] == color[v]) return false;
        }
        return true;
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream system) {
            br = new BufferedReader(new InputStreamReader(system));
        }

        public Scanner(String file) throws Exception {
            br = new BufferedReader(new FileReader(file));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public char nextChar() throws IOException {
            return next().charAt(0);
        }

        public Long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public boolean ready() throws IOException {
            return br.ready();
        }

        public void waitForInput() throws InterruptedException {
            Thread.sleep(3000);
        }

        public int[] nextIntArray(int n) throws IOException {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.