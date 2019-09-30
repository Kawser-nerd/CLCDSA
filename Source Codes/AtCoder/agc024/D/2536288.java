import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    ArrayList<Integer>[] g;

    void go(int v, int p, int curH) {
        int cntCh = 0;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            cntCh++;
            go(to, v, curH + 1);
        }
        cntCh = Math.max(cntCh, 1);
        maxCh[curH] = Math.max(maxCh[curH], cntCh);
    }

    int[] maxCh;

    void updateAns(long start) {
        double curCost = start;
        int curMaxH = 0;
        long curCostLong = start;
        for (int h = 0; h <= maxCh.length - 1; h++) {
            if (maxCh[h] != 0) {
                curCost *= maxCh[h];
                curMaxH = h;
                curCostLong *= maxCh[h];
            }
        }
        if (curCost > Long.MAX_VALUE) {
            return;
        }
        if (curMaxH < ansH || (curCostLong < ans && ansH == curMaxH)) {
            ansH = curMaxH;
            ans = curCostLong;
        }
    }

    long ans;
    int ansH;

    void solve() {
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i + 1< n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() -1 ;
            g[fr].add(to);
            g[to].add(fr);
        }
        ans = Long.MAX_VALUE;
        ansH = Integer.MAX_VALUE;
        maxCh = new int[n + 1];
        for (int v = 0;v < n; v++) {
            Arrays.fill(maxCh, 0);
            go(v, v, 0);
            updateAns(1);
        }
        for (int v =0 ;v < n; v++) {
            for (int to : g[v]) {
                if (to > v) {
                    Arrays.fill(maxCh, 0);
                    go(v, to, 0);
                    go(to, v, 0);
                    updateAns(2);
                }
            }
        }
        out.println((ansH + 1)  + " " + ans);
    }

    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.