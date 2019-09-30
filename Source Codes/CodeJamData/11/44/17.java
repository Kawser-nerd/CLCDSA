import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class D {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    List<List<Integer>> graph;

    List<List<Integer>> pathNet;

    long[] mask;

    int best;

    void dfs(int curr, int stop, long side, long path) {
        if (curr == stop) {
            throw new AssertionError();
        } else {
            for (int next : pathNet.get(curr)) {
                if (next == stop) {
                    best = Math.max(best, Long.bitCount(side & ~path));
                } else {
                    dfs(next, stop, side | mask[next], path | (1L << next));
                }
            }
        }
    }

    public void solveOne(String prefix) throws IOException {
        int p = nextInt();
        int w = nextInt();
        graph = new ArrayList<List<Integer>>();
        for (int i = 0; i < p; ++i) {
            graph.add(new ArrayList<Integer>());
        }
        mask = new long[p];
        for (int i = 0; i < w; ++i) {
            int src = nextInt();
            int trg = nextInt();
            graph.get(src).add(trg);
            graph.get(trg).add(src);
            mask[src] |= 1L << trg;
            mask[trg] |= 1L << src;
        }

        pathNet = new ArrayList<List<Integer>>();
        List<List<Integer>> revPaths = new ArrayList<List<Integer>>();
        for (int i = 0; i < p; ++i) {
            pathNet.add(new ArrayList<Integer>());
            revPaths.add(new ArrayList<Integer>());
        }
        int[] q = new int[p];
        int[] d = new int[p];
        boolean[] u = new boolean[p];
        int head = 0, tail = 0;
        q[head++] = 0;
        Arrays.fill(d, Integer.MAX_VALUE);
        d[0] = 0;
        u[0] = true;
        while (head > tail) {
            int curr = q[tail++];
            for (int next : graph.get(curr)) {
                if (!u[next]) {
                    u[next] = true;
                    d[next] = d[curr] + 1;
                    q[head++] = next;
                }
                if (d[next] == d[curr] + 1) {
                    revPaths.get(next).add(curr);
                }
            }
        }

        head = tail = 0;
        Arrays.fill(u, false);
        q[head++] = 1;
        u[1] = true;
        while (head > tail) {
            int curr = q[tail++];
            for (int prev : revPaths.get(curr)) {
                if (!u[prev]) {
                    u[prev] = true;
                    q[head++] = prev;
                }
                pathNet.get(prev).add(curr);
            }
        }

        best = 0;
        dfs(0, 1, mask[0], 1L);

        out.println(prefix + (d[1] - 1) + " " + best);
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader(D.class.getSimpleName() + ".in"));
        out = new PrintWriter(D.class.getSimpleName() + ".out");

        int nTests = nextInt();

        for (int i = 1; i <= nTests; ++i) {
            solveOne(String.format("Case #%d: ", i));
        }

        out.close();
        in.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line, " \n\r\t,");
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new D().run();
    }
}
