import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author HossamDoma
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
        int n;
        int[] id;
        int[] sz;

        public void solve(int testNumber, InputReader in, PrintWriter out) {

            n = in.nextInt();
            id = new int[n + 2];
            sz = new int[n + 2];

            Arrays.fill(sz, 1);

            TaskD.XX Xs[] = new TaskD.XX[n];
            TaskD.XX Ys[] = new TaskD.XX[n];

            for (int i = 0; i < n; ++i) {
                int a = in.nextInt();
                int b = in.nextInt();
                id[i + 1] = i + 1;
                Xs[i] = new TaskD.XX(a, i);
                Ys[i] = new TaskD.XX(b, i);

            }


            Arrays.sort(Xs, (o1, o2) -> {
                if (o1.v < o2.v) return -1;
                else if (o1.v > o2.v) return 1;
                else return 0;
            });
            Arrays.sort(Ys, (o1, o2) -> {
                if (o1.v < o2.v) return -1;
                else if (o1.v > o2.v) return 1;
                else return 0;
            });

            ArrayList<TaskD.Point> pts = new ArrayList<>();

            for (int i = 0; i + 1 < n; ++i) {
                pts.add(new TaskD.Point(Math.abs(Xs[i].v - Xs[i + 1].v), Xs[i].idd + 1, Xs[i + 1].idd + 1));
                pts.add(new TaskD.Point(Math.abs(Ys[i].v - Ys[i + 1].v), Ys[i].idd + 1, Ys[i + 1].idd + 1));
            }


            pts.sort((o1, o2) -> {
                if (o1.d < o2.d) return -1;
                else if (o1.d > o2.d) return 1;
                else return 0;
            });

//
//        for(Point x : pts)
//            out.println(x.d + " " + x.a + " " + x.b);


            int ans = 0;

            for (TaskD.Point x : pts) {

                if (!find(x.a, x.b)) {
//                out.println(x.a + " " + x.b + " " + x.d);
                    union(x.a, x.b);
                    ans += x.d;
                }

                if (sz[root(x.a)] == n || sz[root(x.b)] == n)
                    break;
            }

            out.println(ans);

        }

        private boolean find(int p, int q) {
            return root(p) == root(q);
        }

        private int root(int i) {

            while (i != id[i]) {

                // Simple path-compression (link child to grandparent).
                id[i] = id[id[i]]; // one line to keep it ALMOST flat.

                i = id[i];
            }

            return i;

        }

        private void union(int p, int q) {

            int i = root(p);
            int j = root(q);


            if (i == j) return; // connected to the same root!

            // Keeping it logarithmic O(log N) at most.
            // Linking the smaller tree to the bigger.

            if (sz[i] >= sz[j]) {
                id[j] = i;
                sz[i] += sz[j];
            } else {
                id[i] = j;
                sz[j] += sz[i];
            }
        }

        static class Point {
            int d;
            int a;
            int b;

            Point(int d, int a, int b) {
                this.d = d;
                this.a = a;
                this.b = b;
            }

        }

        static class XX {
            int v;
            int idd;

            XX(int v, int dd) {
                this.v = v;
                this.idd = dd;
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