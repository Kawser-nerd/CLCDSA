
import java.io.*;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class B {

    private static final int BIGNUM = 100000;

    private String solveTest() throws IOException {
        int n = nextInt();

        fact = new double[n + 1];
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] + Math.log(i);
        }

        init(n);
        int[] roots = new int[n];
        int rn = 0;

        int[] p = new int[n];

        for (int i = 0; i < n; i++) {
            p[i] = nextInt() - 1;
            if (p[i] >= 0) {
                addEdge(p[i], i);
            } else {
                roots[rn++] = i;
            }
        }

        String ch = next();

        int m = nextInt();
        String[] cool = new String[m];
        for (int i = 0; i < m; i++) {
            cool[i] = next();
        }

        for (int i = 0; i < rn; i++) {
            dfs(roots[i], -1);
        }

        Random random = new Random(123425441232312L);

        int[] res = new int[m];

        for (int i = 0; i < BIGNUM; i++) {
            int[] rr = roots.clone();
            int rrn = rn;
            char[] s = new char[n];
            for (int j = 0; j < n; j++) {
                int ss = 0;
                for (int k = 0; k < rrn; k++) {
                    ss += sz[rr[k]];
                }
                int x = random.nextInt(ss);
                ss = 0;
                for (int k = 0; k < rrn; k++) {
                    int cr = rr[k];
                    ss += sz[cr];
                    if (ss > x) {
                        s[j] = ch.charAt(cr);
                        rrn--;
                        for (int t = k; t < rrn; t++) {
                            rr[t] = rr[t + 1];
                        }
                        int jj = head[cr];
                        while (jj >= 0) {
                            int y = dst[jj];
                            if (y != p[cr]) {
                                rr[rrn++] = y;
                            }
                            jj = nx[jj];
                        }
                        break;
                    }
                }
            }
            String ss = new String(s);
            for (int j = 0; j < m; j++) {
                if (ss.indexOf(cool[j]) >= 0) {
                    res[j]++;
                }
            }
        }
        String ans = "";
        for (int i = 0; i < m; i++) {
            ans += (1.0 * res[i] / BIGNUM) + " ";
        }
        return ans;
    }

    void init(int n) {
        this.n = n;
        this.m = (n - 1) * 2;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        sz = new int[n];
        dd = new double[n];
        Arrays.fill(head, -1);
    }


    void addEdge(int x, int y) {
        nx[last] = head[x];
        dst[last] = y;
        head[x] = last;
        last++;
        nx[last] = head[y];
        dst[last] = x;
        head[y] = last;
        last++;
    }

    private void dfs(int x, int p) {
        sz[x] = 1;
        {
            int j = head[x];
            while (j >= 0) {
                int y = dst[j];
                if (y != p) {
                    dfs(y, x);
                    sz[x] += sz[y];
                }
                j = nx[j];
            }
        }
        int ss = sz[x];
        dd[x] = 0;
        {
            int j = head[x];
            while (j >= 0) {
                int y = dst[j];
                if (y != p) {
                    dd[x] += dd[y];
                    dd[x] += calcC(ss, sz[y]);
                    ss -= sz[y];
                }
                j = nx[j];
            }
        }
    }

    double[] fact;

    private double calcC(int n, int k) {
        return fact[n] - fact[n - k] - fact[k];
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] dst;
    int last;

    int[] sz;
    double[] dd;




    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String res = solveTest();
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
        new B().run();
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