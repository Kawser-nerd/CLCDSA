import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.BitSet;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author kessido
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        private int n;
        private BitSet[] edges;
        private int[] color;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.NextInt();
            int m = in.NextInt();
            edges = new BitSet[n];
            for (int i = 0; i < n; i++) {
                edges[i] = new BitSet(n);
                edges[i].set(i, true);
            }
            for (int i = 0; i < m; i++) {
                int u = in.NextInt() - 1;
                int v = in.NextInt() - 1;
                edges[u].set(v, true);
                edges[v].set(u, true);
            }
            for (int i = 0; i < n; i++) {
                edges[i].flip(0, n);
            }
            ArrayList<Pair<Integer, Integer>> cc = new ArrayList<>();
            color = new int[n];
            Arrays.fill(color, -1);
            for (int i = 0; i < n; i++) {
                if (color[i] == -1) {
                    Pair<Integer, Integer> res = dfs(i, 0);
                    if (res == null) {
                        out.println(-1);
                        return;
                    }
                    cc.add(res);
                }
            }
            boolean[] options = new boolean[n + 1];
            options[0] = true;
            for (Pair<Integer, Integer> p : cc) {
                boolean[] options1 = new boolean[n + 1];
                for (int i = n; i >= 0; i--) {
                    if (i + p.first <= n) options1[i + p.first] |= options[i];
                    if (i + p.second <= n) options1[i + p.second] |= options[i];
                }
                options = options1;
            }
            long min = n * n;
            for (int i = 0; i <= n; i++) {
                if (options[i]) {
                    min = Math.min(min, (i * (i - 1)) / 2 + ((n - i) * (n - i - 1)) / 2);
                }
            }
            out.println(min);
        }

        private Pair<Integer, Integer> dfs(int i, int colorI) {
            if (color[i] == colorI) return new Pair<>(0, 0);
            if (color[i] == (1 ^ colorI)) return null;
            color[i] = colorI;
            Pair<Integer, Integer> res = new Pair<>(0, 0);
            if (colorI == 1) res.first++;
            else res.second++;
            for (int j = 0; j < n; j++) {
                if (edges[i].get(j)) {
                    Pair<Integer, Integer> r = dfs(j, colorI ^ 1);
                    if (r == null) return null;
                    res.first += r.first;
                    res.second += r.second;
                }
            }
            return res;
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine(), " \t\n\r\f,");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int NextInt() {
            return Integer.parseInt(next());
        }

    }

    static class Pair<T1, T2> {
        public T1 first;
        public T2 second;

        public Pair(T1 f, T2 s) {
            first = f;
            second = s;
        }

    }
}