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

    private void solve() throws IOException {
        int n = nextInt();
        init(n);
        for (int i = 0; i < n - 1; i++) {
            addEdge(nextInt() - 1, nextInt() - 1);
        }
        if (dfs(0, -1) > 0) {
            out.println("Alice");
        } else {
            out.println("Bob");
        }
    }

    void init(int n) {
        this.n = n;
        this.m = (n - 1) * 2;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
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

    private int dfs(int x, int p) {
        int j = head[x];
        int res = 0;
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                res ^= dfs(y, x) + 1;
            }
            j = nx[j];
        }
        return res;
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] dst;
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