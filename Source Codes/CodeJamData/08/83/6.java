import java.io.*;
import java.util.StringTokenizer;

public class C {
    public static final long MOD = 1000000009L;
    private boolean[][] e;
    private boolean[] w;
    private int n;
    private int k;

    public C(boolean[][] e, int n, int k) {
        this.e = e;
        this.n = n;
        this.k = k;
        w = new boolean[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("C-large.in"));
        PrintWriter out = new PrintWriter("c.out");

        int count = Integer.parseInt(in.readLine());
        for (int i = 1; i <= count; i++) {
            StringTokenizer tz = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(tz.nextToken());
            int k = Integer.parseInt(tz.nextToken());
            boolean[][] e = new boolean[n][n];
            for (int j = 0; j < n - 1; j++) {
                tz = new StringTokenizer(in.readLine());
                int x = Integer.parseInt(tz.nextToken())-1;
                int y = Integer.parseInt(tz.nextToken())-1;
                e[x][y] = e[y][x] = true;
            }

            C s = new C(e, n, k);
            long r = s.solve(0, 0, 0);
            out.println("Case #" + i + ": " + r);
        }

        in.close();
        out.close();
    }

    private long solve(int v, int dep, int bc) {
        w[v] = true;
        int m = 0;
        for (int i = 0; i < n; i++) {
            if (e[v][i] && !w[i]) m++;
        }
        int ac = k - bc;
        if (dep > 1) ac--;
        if (ac < m) return 0;

        long r = 1;
        for (int i = 0; i < n; i++) {
            if (e[v][i] && !w[i]) {
                r = (r*ac) % MOD;
                long rr = solve(i, dep + 1, m);
                r = (r*rr) % MOD;
                ac--;
            }
        }

        return r;
    }
}