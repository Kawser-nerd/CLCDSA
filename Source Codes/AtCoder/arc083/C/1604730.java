import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
    private static final int INF = (int)1e9 + 7;
    int N;
    int[] X;
    int[] sum;
    ArrayList<Integer>[] children;

    public void dfs(int v) {

        //???????
        if (children[v].size() == 0) {
            sum[v] = 0;
            return;
        }

        //????????????
        for(int u : children[v]) {
            dfs(u);
        }

        int K = children[v].size();
        //dp[k][w] = k?????????????v????????w????????????
        int[][] dp = new int[K + 1][X[v] + 1];
        for(int i = 0;i < K + 1;i++) {
            Arrays.fill(dp[i],INF);
        }
        dp[0][0] = 0;

        for(int i = 0;i < K;i++) {
            //????
            int u = children[v].get(i);

            for (int w = X[v]; w >= 0; w--) {
                if (w + X[u] <= X[v]) {
                    dp[i + 1][w + X[u]] = Math.min(dp[i + 1][w + X[u]], dp[i][w] + sum[u]);
                }
                if (w + sum[u] <= X[v]) {
                    dp[i + 1][w + sum[u]] = Math.min(dp[i + 1][w + sum[u]], dp[i][w] + X[u]);
                }
            }
        }

        int min = INF;
        for(int i = 0;i <= X[v];i++) {
            min = Math.min(min,dp[K][i]);
        }
        sum[v] = min;
    }

    public void solve() {
        N = nextInt();
        X = new int[N];
        children = new ArrayList[N];
        for(int i = 0;i < N;i++) {
            children[i] = new ArrayList<>();
        }
        for(int i = 1;i < N;i++) {
            int P = nextInt()-1;
            children[P].add(i);
        }
        for(int i = 0;i < N;i++) {
            X[i] = nextInt();
        }

        sum = new int[N];
        Arrays.fill(sum,INF);

        dfs(0);

        if (sum[0] != INF) {
            out.println("POSSIBLE");
        } else {
            out.println("IMPOSSIBLE");
        }

    }

    public static void main(String[] args) {
        out.flush();
        new Main().solve();
        out.close();
    }

    /* Input */
    private static final InputStream in = System.in;
    private static final PrintWriter out = new PrintWriter(System.out);
    private final byte[] buffer = new byte[2048];
    private int p = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (p < buflen)
            return true;
        p = 0;
        try {
            buflen = in.read(buffer);
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (buflen <= 0)
            return false;
        return true;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrint(buffer[p])) {
            p++;
        }
        return hasNextByte();
    }

    private boolean isPrint(int ch) {
        if (ch >= '!' && ch <= '~')
            return true;
        return false;
    }

    private int nextByte() {
        if (!hasNextByte())
            return -1;
        return buffer[p++];
    }

    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = -1;
        while (isPrint((b = nextByte()))) {
            sb.appendCodePoint(b);
        }
        return sb.toString();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.