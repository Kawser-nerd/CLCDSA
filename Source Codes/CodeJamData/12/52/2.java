import java.io.*;
import java.util.StringTokenizer;

public class B {
    FastScanner in;
    PrintWriter out;
    
    class DSU {
        int[] p;
        int[] r;
        int[] v;

        DSU(int n) {
            p = new int[n];
            r = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
            v = new int[n];
        }
        
        int get(int x) {
            if (p[x] != x) {
                p[x] = get(p[x]);
            }
            return p[x];
        }
        
        void union(int x, int y, int newV) {
            x = get(x);
            y = get(y);
            if (r[x] == r[y]) {
                r[x]++;
            }
            if (r[x] < r[y]) {
                p[x] = y;
                v[y] = newV;
            } else {
                p[y] = x;
                v[x] = newV;
            }
        }
    }
    
    int S;
    
    int[] dx = new int[]{-1, -1, 0, 0, 1, 1};
    int[] dy = new int[]{-1, 0, -1, 1, 0, 1};
    
    boolean valid(int x, int y) {
        if (x <= 0) {
            return false;
        }
        if (x <= S) {
            return 1 <= y && y <= S + x - 1;
        }
        if (x < 2 * S) {
            return x - S + 1 <= y && y <= 2 * S - 1;
        }
        return false;
    }
    
    int corner(int x, int y) {
        if (x == 1 && y == 1) {
            return 0;
        }
        if (x == 1 && y == S) {
            return 1;
        }
        if (x == S && y == 2 * S - 1) {
            return 2;
        }
        if (x == 2 * S - 1 && y == 2 * S - 1) {
            return 3;
        }
        if (x == 2 * S - 1 && y == S) {
            return 4;
        }
        if (x == S && y == 1) {
            return 5;
        }
        return -1;
    }
    
    int border(int x, int y) {
        if (corner(x, y) != -1) {
            return -1;
        }
        if (x == 1) {
            return 0;
        }
        if (x <= S && y == x + S - 1) {
            return 1;
        }
        if (S <= x && x <= 2 * S - 1 && y == 2 * S - 1) {
            return 2;
        }
        if (x == 2 * S - 1) {
            return 3;
        }
        if (S <= x && x <= 2 * S - 1 && y == x + 1 - S) {
            return 4;
        }
        if (x <= S && y == 1) {
            return 5;
        }
        return -1;
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Test " + test);
            
            S = in.nextInt();
            int m = in.nextInt();
            int[] x = new int[m];
            int[] y = new int[m];
            boolean[][] f = new boolean[2 * S][2 * S];
            for (int i = 0; i < m; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }
            
            DSU d = new DSU(2 * S * 2 * S);
            int firstBridge = Integer.MAX_VALUE;
            for (int i = 0; i < m; i++) {
                int cc = corner(x[i], y[i]);
//                System.out.println(x[i] + " " + y[i] + " " + cc);
                int cv = 0;
                if (cc != -1) {
                    cv = 1 << cc;
                }
                
                int vx = x[i] * 2 * S + y[i];
                d.v[d.get(vx)] = cv;
                for (int k = 0; k < 6; k++) {
                    int nx = x[i] + dx[k];
                    int ny = y[i] + dy[k];
                    if (valid(nx, ny) && f[nx][ny]) {
                        int nvx = nx * 2 * S + ny;
                        int ov = d.v[d.get(vx)] | d.v[d.get(nvx)];
                        d.union(vx, nvx, ov | cv);
                    }
                }
//                System.out.println(d.v[d.get(vx)]);
                if (Integer.bitCount(d.v[d.get(vx)]) >= 2) {
                    firstBridge = i + 1;
                    break;
                }
                f[x[i]][y[i]] = true;
            }
            
            f = new boolean[2 * S][2 * S];
            int firstFork = Integer.MAX_VALUE;
            d = new DSU(2 * S * 2 * S);
            for (int i = 0; i < m; i++) {
                int cc = border(x[i], y[i]);
//                System.out.println(x[i] + " " + y[i] + " " + cc);
                int cv = 0;
                if (cc != -1) {
                    cv = 1 << cc;
                }

                int vx = x[i] * 2 * S + y[i];
                d.v[d.get(vx)] = cv;
                for (int k = 0; k < 6; k++) {
                    int nx = x[i] + dx[k];
                    int ny = y[i] + dy[k];
                    if (valid(nx, ny) && f[nx][ny]) {
                        int nvx = nx * 2 * S + ny;
                        int ov = d.v[d.get(vx)] | d.v[d.get(nvx)];
                        d.union(vx, nvx, ov | cv);
                    }
                }
//                System.out.println(d.v[d.get(vx)]);
                if (Integer.bitCount(d.v[d.get(vx)]) >= 3) {
                    firstFork = i + 1;
                    break;
                }
                f[x[i]][y[i]] = true;
            }
            
            int firstRing = Integer.MAX_VALUE;
            f = new boolean[2 * S][2 * S];
            for (int i = 0; i < m; i++) {
                f[x[i]][y[i]] = true;
            }
            
            d = new DSU(2 * S * 2 * S + 1);
            int nc = 1;
            for (int i = 0; i < 2 * S; i++) {
                for (int j = 0; j < 2 * S; j++) {
                    if (valid(i, j) && !f[i][j]) {
                        nc++;
                        int v = i * 2 * S + j;
                        for (int k = 0; k < 6; k++) {
                            int ni = i + dx[k];
                            int nj = j + dy[k];
                            if (valid(ni, nj) && !f[ni][nj]) {
                                int nv = ni * 2 * S + nj;
                                if (d.get(v) != d.get(nv)) {
                                    d.union(v, nv, 0);
                                    nc--;
                                }
                            }
                        }
                        if (border(i, j) != -1 || corner(i, j) != -1) {
                            int nv = 2 * S * 2 * S;
                            if (d.get(v) != d.get(nv)) {
                                d.union(v, nv, 0);
                                nc--;
                            }
                        }
                    }
                }
            }
            
            for (int i = m - 1; i >= 0; i--) {
                if (nc > 1) {
                    firstRing = i + 1;
                }
                f[x[i]][y[i]] = false;
                nc++;
                int v = x[i] * 2 * S + y[i];
                for (int k = 0; k < 6; k++) {
                    int ni = x[i] + dx[k];
                    int nj = y[i] + dy[k];
                    if (valid(ni, nj) && !f[ni][nj]) {
                        int nv = ni * 2 * S + nj;
                        if (d.get(v) != d.get(nv)) {
                            d.union(v, nv, 0);
                            nc--;
                        }
                    }
                }
                if (border(x[i], y[i]) != -1 || corner(x[i], y[i]) != -1) {
                    int nv = 2 * S * 2 * S;
                    if (d.get(v) != d.get(nv)) {
                        d.union(v, nv, 0);
                        nc--;
                    }
                }
            }
            
            int at = Math.min(Math.min(firstBridge, firstFork), firstRing);
            String ans = "";
            if (at == Integer.MAX_VALUE) {
                ans = "none";
            } else {
                if (firstBridge == at) {
                    ans = "bridge";
                }
                if (firstFork == at) {
                    if (!ans.equals("")) {
                        ans = ans + "-";
                    }
                    ans = ans + "fork";
                }
                if (firstRing == at) {
                    if (!ans.equals("")) {
                        ans = ans + "-";
                    }
                    ans = ans + "ring";
                }
                ans += " in move " + at;
            }
            
            out("Case #%d: %s\n", test, ans);
        }
    }
    
    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-large.in"));
            out = new PrintWriter(new File("B-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new B().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}