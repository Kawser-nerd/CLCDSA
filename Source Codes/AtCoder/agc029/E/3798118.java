import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskE.Vertex[] vs = new TaskE.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskE.Vertex();
                vs[i].what = i + 1;
            }
            for (int i = 0; i < n - 1; ++i) {
                TaskE.Vertex a = vs[in.nextInt() - 1];
                TaskE.Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            vs[0].dfs1(0, 0, null);
            vs[0].dfs2(0, 0, null);
            for (int i = 1; i < n; ++i) {
                out.print(vs[i].answer - 1);
                out.print(" ");
            }
            out.println();
        }

        static class Vertex {
            List<TaskE.Vertex> adj = new ArrayList<>();
            int what;
            int smallerThanAbove;
            int smallerThanSecondMaxAbove;
            int answer;
            int totalBelowFirst;
            int totalBelowSecond;

            public void dfs1(int maxAbove, int secondMaxAbove, TaskE.Vertex parent) {
                totalBelowFirst = 0;
                totalBelowSecond = 0;
                int newMaxAbove = maxAbove;
                int newSecondMaxAbove = secondMaxAbove;
                if (what > maxAbove) {
                    newSecondMaxAbove = newMaxAbove;
                    newMaxAbove = what;
                } else if (what > secondMaxAbove) {
                    newSecondMaxAbove = what;
                }
                for (TaskE.Vertex v : adj) {
                    if (v != parent) {
                        v.dfs1(newMaxAbove, newSecondMaxAbove, this);
                        totalBelowFirst += v.smallerThanAbove;
                        totalBelowSecond += v.smallerThanSecondMaxAbove;
                    }
                }
                if (what > maxAbove) {
                    smallerThanAbove = 0;
                    smallerThanSecondMaxAbove = 0;
                } else if (what > secondMaxAbove) {
                    smallerThanAbove = 1 + totalBelowFirst;
                    smallerThanSecondMaxAbove = 0;
                } else {
                    smallerThanAbove = 1 + totalBelowFirst;
                    smallerThanSecondMaxAbove = 1 + totalBelowSecond;
                }
            }

            public void dfs2(int maxAbove, int extra, TaskE.Vertex parent) {
                int newExtra = 1;
                if (what > maxAbove) {
                    answer = extra + 1 + totalBelowSecond;
                    for (TaskE.Vertex v : adj)
                        if (v != parent) {
                            newExtra += v.smallerThanSecondMaxAbove;
                        }
                } else {
                    answer = extra + 1 + totalBelowFirst;
                    for (TaskE.Vertex v : adj)
                        if (v != parent) {
                            newExtra += v.smallerThanAbove;
                        }
                }
                int newMaxAbove = Math.max(maxAbove, what);
                for (TaskE.Vertex v : adj)
                    if (v != parent) {
                        v.dfs2(newMaxAbove, extra + newExtra - (what > maxAbove ? v.smallerThanSecondMaxAbove : v.smallerThanAbove), this);
                    }
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