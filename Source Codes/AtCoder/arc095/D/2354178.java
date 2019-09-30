import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.OptionalInt;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        List<Integer>[] tree;
        boolean[] leaf;
        List<Integer> result = new ArrayList<>();

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            tree = new List[n];
            for (int i = 0; i < n; i++) {
                tree[i] = new ArrayList<>();
            }
            for (int i = 0; i < n - 1; i++) {
                int from = in.nextInt() - 1, to = in.nextInt() - 1;
                tree[from].add(to);
                tree[to].add(from);
            }

            leaf = new boolean[n];
            for (int i = 0; i < n; i++) {
                leaf[i] = tree[i].size() == 1;
            }
            int[] deg = new int[n];
            for (int i = 0; i < n; i++) {
                if (!leaf[i]) {
                    for (int j : tree[i]) {
                        if (!leaf[j]) {
                            deg[i]++;
                        }
                    }
                }
            }
            int max = Arrays.stream(deg).max().getAsInt();
            if (max > 2) {
                out.println(-1);
                return;
            }

            int[] result = new int[n];
            for (int i = n - 1; i >= 0; i--) {
                result[i] = n - 1 - i;
            }
            if (max == 0) {
                for (int i = 0; i < n; i++) {
                    if (leaf[i]) {
                        result = get(i);
                        break;
                    }
                }

            } else {
                for (int i = 0; i < n; i++) {
                    if (!leaf[i] && deg[i] == 1) {
                        for (int j : tree[i]) {
                            if (leaf[j]) {
                                int[] newResult = get(j);
                                for (int t = 0; t < n; t++) {
                                    if (result[t] < newResult[t]) {
                                        break;
                                    } else if (result[t] > newResult[t]) {
                                        result = newResult;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
            }

            for (int i : result) {
                out.print((i + 1) + " ");
            }
            out.println();
        }

        int[] get(int start) {
            int n = tree.length;
            result = new ArrayList<>();
            go(start, -1, 0);
            int[] ret = new int[n];
            System.err.println(result.toString());
            for (int i = 0; i < n; i++) {
                ret[result.get(i)] = i;
            }
            return ret;
        }

        private void go(int i, int p, int startId) {
            int deg = 0;
            for (int t : tree[i]) {
                if (t != p) {
                    deg++;
                }
            }
            int ourId = -1;
            if (deg == 0) {
                ourId = startId;
                result.add(startId);
            } else {
                ourId = startId + deg - 1;
                result.add(startId + deg - 1);
            }
            for (int t : tree[i]) {
                if (t != p) {
                    if (leaf[t]) {
                        if (startId == ourId) {
                            startId++;
                        }
                        go(t, i, startId);
                        startId++;
                    }
                }
            }
            for (int t : tree[i]) {
                if (t != p) {
                    if (!leaf[t]) {
                        if (startId == ourId) {
                            startId++;
                        }
                        go(t, i, startId);
                        startId++;
                    }
                }
            }
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.