import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final long INF = (long) 1e18;
        private TreeSet<TaskC.Person>[][] queues;
        int[] togo;
        long[][] best;
        int[][] bestVia;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            togo = new int[3];
            int n = 0;
            for (int i = 0; i < 3; ++i) {
                togo[i] = in.nextInt();
                n += togo[i];
            }
            TaskC.Person[] p = new TaskC.Person[n];
            for (int i = 0; i < n; ++i) {
                p[i] = new TaskC.Person();
                p[i].id = i;
                for (int j = 0; j < 3; ++j) p[i].cost[j] = in.nextInt();
            }
            queues = new TreeSet[4][4];
            for (int old = 0; old < 4; ++old) {
                for (int nxt = 0; nxt < 3; ++nxt) {
                    if (nxt != old) {
                        final int nxtCopy = nxt;
                        final int oldCopy = old;
                        queues[old][nxt] = new TreeSet<>(new Comparator<TaskC.Person>() {

                            public int compare(TaskC.Person o1, TaskC.Person o2) {
                                int z = (o2.cost[nxtCopy] - o2.cost[oldCopy]) - (o1.cost[nxtCopy] - o1.cost[oldCopy]);
                                if (z == 0) z = o1.id - o2.id;
                                return z;
                            }
                        });
                    }
                }
            }
            for (TaskC.Person pp : p) {
                for (int nxt = 0; nxt < 3; ++nxt) {
                    queues[3][nxt].add(pp);
                }
            }
            best = new long[4][1 << 3];
            bestVia = new int[4][1 << 3];
            long res = 0;
            for (int i = 0; i < n; ++i) {
                int c = 3;
                int av = (1 << 3) - 1;
                for (long[] x : best) Arrays.fill(x, -INF);
                for (int[] x : bestVia) Arrays.fill(x, -2);
                rec(c, av);
                if (bestVia[c][av] < 0) throw new RuntimeException();
                res += best[c][av];
                while (true) {
                    int d = bestVia[c][av];
                    if (d == -1) {
                        --togo[c];
                        break;
                    }
                    TreeSet<TaskC.Person> q = queues[c][d];
                    TaskC.Person pp = q.first();
                    if (pp.now != c) throw new RuntimeException();
                    for (int nxt = 0; nxt < 3; ++nxt) if (queues[c][nxt] != null) queues[c][nxt].remove(pp);
                    pp.now = d;
                    for (int nxt = 0; nxt < 3; ++nxt) if (queues[d][nxt] != null) queues[d][nxt].add(pp);
                    av ^= (1 << d);
                    c = d;
                }
            }
            for (int x : togo) if (x != 0) throw new RuntimeException();
            out.println(res);
        }

        private void rec(int c, int av) {
            if (c < 3) {
                if (togo[c] > 0) {
                    best[c][av] = 0;
                    bestVia[c][av] = -1;
                }
            }
            for (int cc = 0; cc < 3; ++cc)
                if ((av & (1 << cc)) != 0) {
                    TreeSet<TaskC.Person> q = queues[c][cc];
                    if (q.isEmpty()) continue;
                    TaskC.Person p = q.first();
                    if (bestVia[cc][av ^ (1 << cc)] == -2) rec(cc, av ^ (1 << cc));
                    long cur = p.cost[cc] - p.cost[c] + best[cc][av ^ (1 << cc)];
                    if (cur > best[c][av]) {
                        best[c][av] = cur;
                        bestVia[c][av] = cc;
                    }
                }
            if (bestVia[c][av] == -2) bestVia[c][av] = -3;
        }

        static class Person {
            int id;
            int[] cost = new int[4];
            int now = 3;

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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.