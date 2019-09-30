import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Set;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        static List<TaskC.Vertex> curCycle = new ArrayList<>();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            TaskC.Vertex done = new TaskC.Vertex();
            int n = in.nextInt();
            int m = in.nextInt();
            TaskC.Vertex[] vs = new TaskC.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskC.Vertex();
            }
            for (int i = 0; i < m; ++i) {
                TaskC.Vertex a = vs[in.nextInt() - 1];
                TaskC.Vertex b = vs[in.nextInt() - 1];
                a.adjSeq.add(b);
                b.adjSeq.add(a);
            }
            for (TaskC.Vertex v : vs)
                if (v.adjSeq.size() % 2 != 0) {
                    out.println("No");
                    return;
                }
            long finish = System.currentTimeMillis() + 1500;
            Random random = new Random(55413543513L);
            List<TaskC.Vertex> vList = new ArrayList<>();
            for (TaskC.Vertex v : vs) {
                vList.add(v);
            }
            outer2:
            while (System.currentTimeMillis() < finish) {
                List<List<TaskC.Vertex>> cycles = new ArrayList<>();
                for (TaskC.Vertex v : vs) {
                    v.adj.clear();
                    v.adj.addAll(v.adjSeq);
                    Collections.shuffle(v.adjSeq, random);
                }
                Collections.shuffle(vList, random);
                outer:
                for (int i = 0; i < 3; ++i) {
                    curCycle = new ArrayList<>();
                    for (TaskC.Vertex v : vList) v.state = 0;
                    for (TaskC.Vertex v : vList)
                        if (!v.adj.isEmpty()) {
                            if (v.removeCycle(null, done) != done) throw new RuntimeException();
                            cycles.add(curCycle);
                            continue outer;
                        }
                    break;
                }
                if (cycles.size() <= 1) {
                    out.println("No");
                } else if (cycles.size() >= 3) {
                    out.println("Yes");
                } else {
                    int bigDeg = 0;
                    for (TaskC.Vertex v : vList) {
                        if (v.adjSeq.size() > 2)
                            ++bigDeg;
                    }
                    if (bigDeg >= 3) {
                        out.println("Yes");
                    } else {
                        out.println("No");
                    }
                }


                return;
            }
            out.println("No");
        }

        static class Vertex {
            int state = 0;
            Set<TaskC.Vertex> adj = new HashSet<>();
            List<TaskC.Vertex> adjSeq = new ArrayList<>();

            public TaskC.Vertex removeCycle(TaskC.Vertex parent, TaskC.Vertex done) {
                state = 1;
                for (TaskC.Vertex v : adjSeq)
                    if (v != parent && adj.contains(v)) {
                        if (v.state == 1) {
                            adj.remove(v);
                            v.adj.remove(this);
                            return v;
                        } else if (v.state == 0) {
                            TaskC.Vertex got = v.removeCycle(this, done);
                            if (got == done) {
                                return done;
                            }
                            if (got != null) {
                                adj.remove(v);
                                v.adj.remove(this);
                                curCycle.add(this);
                                if (got == this) return done;
                                else return got;
                            }
                        }
                    }
                state = 2;
                return null;
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