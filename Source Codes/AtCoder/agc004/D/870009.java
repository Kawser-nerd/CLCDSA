import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main implements Runnable {

    int ans, k;
    List<Integer>[] r;

    int dfs(int q, int p) {
        int h = 0;
        for (int w : r[q]) {
            h = Math.max(h, dfs(w, q) + 1);
        }
        if (h == k - 1 && p != 0) {
            ans++;
            h = -1;
        }
        return h;
    }

    void solve() throws IOException {
        int n = nextInt();
        k = nextInt();
        r = new List[n];
        for (int i = 0; i < n; i++) r[i] = new ArrayList<>();
        ans = 0;
        for (int i = 0; i < n; i++) {
            int q = nextInt();
            if (i != 0) r[q - 1].add(i); else if (q != 1) ans++;
        }
        dfs(0, 0);
        out.println(ans);
    }


    public static void main(String[] args) {
	    new Thread(null, new Main(), "name", 1 << 27).start();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        } finally {
            out.close();
        }
    }

    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(System.out);
    StringTokenizer st;

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(in.readLine());
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.