import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n + 1];
            int[] b = new int[n + 1];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                a[n] ^= a[i];
            }
            for (int i = 0; i < n; ++i) {
                b[i] = in.nextInt();
                b[n] ^= b[i];
            }
            int[] as = a.clone();
            Arrays.sort(as);
            int[] bs = b.clone();
            Arrays.sort(bs);
            if (!Arrays.equals(as, bs)) {
                out.println(-1);
                return;
            }
            Map<Integer, TaskD.Vertex> vs = new HashMap<>();
            for (int i = 0; i <= n; ++i) {
                TaskD.Vertex va = vs.computeIfAbsent(a[i], k -> new TaskD.Vertex());
                TaskD.Vertex vb = vs.computeIfAbsent(b[i], k -> new TaskD.Vertex());
                ++va.count;
                ++vb.count;
                if (i < n && a[i] == b[i]) ++va.countIdentity;
                va.adj.add(vb);
                vb.adj.add(va);
            }
            int res = 0;
            for (int i = n; i >= 0; --i) {
                TaskD.Vertex v = vs.get(a[i]);
                if (!v.mark) {
                    TaskD.Pair p = new TaskD.Pair();
                    v.dfs(p);
                    if (p.total % 2 != 0) throw new RuntimeException();
                    p.total /= 2;
                    p.total -= p.totalIdentity;
                    if (i == n)
                        res += p.total - 1;
                    else if (p.total > 0)
                        res += p.total + 1;
                }
            }
            out.println(res);
        }

        static class Pair {
            int total;
            int totalIdentity;

        }

        static class Vertex {
            boolean mark = false;
            int count = 0;
            int countIdentity = 0;
            List<TaskD.Vertex> adj = new ArrayList<>();

            public void dfs(TaskD.Pair res) {
                mark = true;
                res.total += count;
                res.totalIdentity += countIdentity;
                for (TaskD.Vertex v : adj) if (!v.mark) v.dfs(res);
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}