
import java.io.*;
import java.util.*;

public class C {

    private boolean[][] a;
    private boolean[] z;
    private int[] rp;

    private int solveTest() throws IOException {
        int n = nextInt();
        int nl = 0;
        int nr = 0;
        Map<String, Integer> lmap = new HashMap<>();
        Map<String, Integer> rmap = new HashMap<>();
        int[] lc = new int[n];
        int[] rc = new int[n];
        for (int i = 0; i < n; i++) {
            String lw = next();
            String rw = next();
            if (!lmap.containsKey(lw)) {
                lmap.put(lw, nl++);
            }
            if (!rmap.containsKey(rw)) {
                rmap.put(rw, nr++);
            }
            lc[i] = lmap.get(lw);
            rc[i] = rmap.get(rw);
        }
        a = new boolean[nl][nr];
        for (int i = 0; i < n; i++) {
            a[lc[i]][rc[i]] = true;
        }
        z = new boolean[nl];
        rp = new int[nr];
        Arrays.fill(rp, -1);
        int pn = 0;
        for (int i = 0; i < nl; i++) {
            Arrays.fill(z, false);
            if (dfs(i)) {
                pn++;
            }
        }
        return n - (nl + nr - pn);
    }

    private boolean dfs(int i) {
        if (z[i]) return false;
        z[i] = true;
        for (int j = 0; j < rp.length; j++) {
            if (a[i][j]) {
                if (rp[j] == -1 || dfs(rp[j])) {
                    rp[j] = i;
                    return true;
                }
            }
        }
        return false;
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            int res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new C().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}