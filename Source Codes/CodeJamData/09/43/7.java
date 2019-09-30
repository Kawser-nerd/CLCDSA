import java.util.*;
import java.math.*;
import java.io.*;

class C implements Runnable {
    BufferedReader in;
    StringTokenizer st;

    int nextInt() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

    int n;
    boolean[][] a;
    boolean[] u;
    int[] p;

    boolean dfs(int i) {
        u[i] = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] && (p[j] == -1 || (!u[p[j]] && dfs(p[j]) ) ) ) {
                p[j] = i;
                return true;
            }
        }
        return false;
    }

    public void solve() throws IOException {
        in = new BufferedReader(new FileReader("C-large.in"));
        PrintWriter out = new PrintWriter(new File("C-large.out"));

        int testn = nextInt();
        for (int test = 0; test < testn; test++) {
            n = nextInt();
            int k = nextInt();
            int[][] l = new int[n][k];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < k; j++) {
                    l[i][j] = nextInt();
                }
            }

            a = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    boolean less = true;
                    for (int t = 0; t < k; t++) {
                        if (l[i][t] >= l[j][t]) {
                            less = false;
                            break;
                        }
                    }
                    a[i][j] = less;
                }
            }

            int r = 0;
            u = new boolean[n];
            p = new int[n];
            Arrays.fill(p, -1);
            for (int i = 0; i < n; i++) {
                Arrays.fill(u, false);
                if (dfs(i)) {
                    r++;
                }
            }
            
            System.out.println("Case #" + (test + 1) + ": " + (n - r));
            out.println("Case #" + (test + 1) + ": " + (n - r));
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            throw new AssertionError();
        }
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new Thread(new C()).start();
    }
}