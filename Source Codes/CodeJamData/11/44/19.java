import java.io.*;
import java.util.*;
import java.math.*;

/**
 * User: Igor Kirov
 * Date: 04.06.11
 */
public class D implements Runnable {
    int p, w;
    boolean[][] a;
    boolean[] used;
    int shortest;
    int max;

    class Pair {
        int f, s;

        Pair(int f, int s) {
            this.f = f;
            this.s = s;
        }
    }

    private int bfs() {
        boolean[] used = new boolean[p + 10];
        Queue<Pair> q = new LinkedList<Pair>();
        q.add(new Pair(0, 0));
        used[0] = true;
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            for (int i = 0; i < p; i++) {
                if (a[cur.f][i] && !used[i]) {
                    if (i == 1)
                    {
                        return cur.s;
                    }
                    used[i] = true;
                    q.add(new Pair(i, cur.s + 1));
                }
            }
        }
        throw new RuntimeException();
    }

    private void update()
    {
        boolean[] t = new boolean[p+10];
        for (int i = 0; i<p; i++)
        {
            if (used[i])
            {
                for (int j = 0; j<p; j++)
                {
                    if (!used[j] && a[i][j])
                    {
                        t[j] = true;
                    }
                }
            }
        }
        int cnt = 0;
        for (int i =0; i<p; i++)
        {
            if (t[i])
            {
                cnt++;
            }
        }
        if (t[1])
        {
            max = Math.max(max, cnt);
        }
    }

    private void dfs(int cur, int len)
    {
        if (len == shortest)
        {
            update();
            return;
        }
        for (int i = 0; i<p; i++)
        {
            if (a[cur][i] && !used[i])
            {
                used[i] = true;
                dfs(i, len + 1);
                used[i] = false;
            }
        }
    }

    private void solve() throws IOException {
        p = nextInt();
        w = nextInt();

        a = new boolean[p + 10][p + 10];

        for (int i = 0; i < w; i++) {
            String[] s = nextToken().split(",");
            int u = Integer.valueOf(s[0]);
            int v = Integer.valueOf(s[1]);
            a[u][v] = true;
            a[v][u] = true;
        }

        shortest = bfs();
        used = new boolean[p+10];
        max = 0;
        used[0] = true;
        dfs(0, 0);
        writer.println(shortest + " " + max);
    }

    public static void main(String[] args) {
        new Thread(null, new D(), "", 64 * 1024 * 1024).start();
    }

    StringTokenizer tokenizer;
    BufferedReader reader;
    PrintWriter writer;

    public void run() {
        try {
            try {
                Locale.setDefault(Locale.US);
            } catch (Exception ignored) {
            }

            reader = new BufferedReader(new FileReader("D.in"));
            writer = new PrintWriter(new FileWriter("D.out"));
            tokenizer = null;

            int tests = nextInt();
            for (int i = 0; i < tests; i++) {
                writer.printf("Case #%d: ", i + 1);
                solve();
                writer.flush();
            }

            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}