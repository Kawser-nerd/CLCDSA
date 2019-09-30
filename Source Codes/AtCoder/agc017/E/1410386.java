import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class Main {

    private int h;
    private boolean ok;
    private int[] dd;

    private void solve() throws IOException {
        int n = nextInt();
        h = nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
            b[i] = nextInt();
            c[i] = nextInt();
            d[i] = nextInt();
        }

        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = c[i] == 0 ? h + a[i] : h - c[i];
            r[i] = d[i] == 0 ? h - b[i] : h + d[i];
        }
        dd = new int[2 * h + 1];
        for (int i = 0; i < n; i++) {
            dd[l[i]]++;
            dd[r[i]]--;
        }
//        System.out.println(Arrays.toString(l));
//        System.out.println(Arrays.toString(r));
//        System.out.println(Arrays.toString(dd));

        for (int i = 0; i < h; i++) {
            if (dd[i] > 0) {
                out.println("NO");
                return;
            }
        }
        for (int i = h + 1; i < 2 * h + 1; i++) {
            if (dd[i] < 0) {
                out.println("NO");
                return;
            }
        }
        init(2 * h + 1, n);
        for (int i = 0; i < n; i++) {
            addEdge(l[i], r[i]);
        }
        for (int i = 0; i < 2 * h + 1; i++) {
            if (!z[i] && head[i] != -1) {
                ok = false;
                dfs(i);
                if (!ok) {
                    out.println("NO");
                    return;
                }
            }
        }
        out.println("YES");
    }

    void init(int n, int m) {
        m *= 2;
        this.n = n;
        this.m = m;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        src = new int[m];
        Arrays.fill(head, -1);
        z = new boolean[n];
    }

    void addEdge(int x, int y) {
        nx[last] = head[x];
        src[last] = x;
        dst[last] = y;
        head[x] = last;
        last++;
        nx[last] = head[y];
        src[last] = y;
        dst[last] = x;
        head[y] = last;
        last++;
    }

    private void dfs(int x) {
        if (z[x]) return;
        z[x] = true;
        if (dd[x] != 0) {
            ok = true;
        }
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            dfs(y);
            j = nx[j];
        }
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] src;
    int[] dst;
    boolean[] z;
    int last;

    // ------------------

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}