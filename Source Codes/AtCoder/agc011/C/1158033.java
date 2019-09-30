import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by Aksenov239 on 12.03.2017.
 */
public class Main {
    public static void main(String[] args) {
        new Main().run();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public void solveA() throws IOException {
        int n = nextInt();
        int c = nextInt();
        int k = nextInt();

        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = nextInt();
        }

        Arrays.sort(t);

        int ans = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < i + c && j < n && t[j] <= t[i] + k) {
                j++;
            }
            i = j;
            ans++;
        }
        out.println(ans);
    }

    public void solveB() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }

        Arrays.sort(a);

        int l = -1;
        int r = n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            long size = a[m];
            for (int i = 0; i < m; i++) {
                size += a[i];
            }
            int i = m + 1;
            while (i < n && 2 * size >= a[i]) {
                size += a[i];
                i++;
            }
            if (i == n) {
                r = m;
            } else {
                l = m;
            }
        }
        out.println(n - r);
    }

    int[] color;
    ArrayList<Integer>[] e;
    int size;

    public boolean dfs(int v, int c) {
        color[v] = c;
        size++;
        boolean ans = true;
        for (int u : e[v]) {
            if (color[u] == 0) {
                ans &= dfs(u, 3 - c);
            } else {
                ans &= color[v] + color[u] == 3;
            }
        }
        return ans;
    }

    public void solveCStupid(ArrayList<Integer>[] g) throws IOException {
//        int n = nextInt();
//        int m = nextInt();
//        ArrayList<Integer>[] g = new ArrayList[n];
//        for (int i = 0; i < n; i++) {
//            g[i] = new ArrayList<Integer>();
//        }
//        for (int i = 0; i < m; i++) {
//            int a = nextInt() - 1;
//            int b = nextInt() - 1;
//            g[a].add(b);
//            g[b].add(a);
//        }

        int n = g.length;

        e = new ArrayList[n * n];
        for (int i = 0; i < e.length; i++) {
            e[i] = new ArrayList<Integer>();
        }
        for (int u1 = 0; u1 < n; u1++) {
            for (int v1 = 0; v1 < n; v1++) {
                for (int u2 : g[u1]) {
                    for (int v2 : g[v1]) {
                        e[u1 * n + v1].add(u2 * n + v2);
                    }
                }
            }
        }

        int ans = 0;
        color = new int[e.length];
        for (int i = 0; i < e.length; i++) {
            if (color[i] == 0) {
                System.err.println(i / n + " " + i % n);
                ans++;
                dfs(i, 1);
            }
        }
        out.println(ans);
    }

    public void solveC() throws IOException {
        int n = nextInt();
        int m = nextInt();
        ArrayList<Integer>[] e = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            e[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            e[a].add(b);
            e[b].add(a);
        }

        this.e = e;

        color = new int[n];
        long k1 = 0;
        long k2 = 0;
        long k3 = 0;
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                size = 0;
                if (dfs(i, 1)) {
                    if (size == 1) {
                        k3++;
                    } else {
                        k1++;
                    }
                } else {
                    k2++;
                }
            }
        }

        // 3 + 3

//        System.err.println(k1 + " " + k2);

        out.println(
                2 * k1 * k1 + k1 * k2 +
                        k2 * k1 + k2 * k2 +
                        2 * k3 * n - k3 * k3
        );
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solveC();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.