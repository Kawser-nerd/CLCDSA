import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static TaskE.Vertex[] dest;
        static int[] next;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskE.Vertex[] vs = new TaskE.Vertex[n];
            for (int i = 0; i < n; ++i) vs[i] = new TaskE.Vertex();
            TaskE.Vertex us = vs[in.nextInt() - 1];
            TaskE.Vertex root = vs[in.nextInt() - 1];
            dest = new TaskE.Vertex[4 * (n - 1)];
            next = new int[4 * (n - 1)];
            int ptr = 0;
            for (int i = 0; i < n - 1; ++i) {
                TaskE.Vertex a = vs[in.nextInt() - 1];
                TaskE.Vertex b = vs[in.nextInt() - 1];
                next[ptr] = a.firstUs;
                dest[ptr] = b;
                a.firstUs = ptr++;
                next[ptr] = b.firstUs;
                dest[ptr] = a;
                b.firstUs = ptr++;
            }
            for (int i = 0; i < n - 1; ++i) {
                TaskE.Vertex a = vs[in.nextInt() - 1];
                TaskE.Vertex b = vs[in.nextInt() - 1];
                next[ptr] = a.firstThey;
                dest[ptr] = b;
                a.firstThey = ptr++;
                next[ptr] = b.firstThey;
                dest[ptr] = a;
                b.firstThey = ptr++;
            }
            root.fillWhenThey(0);
            us.fillWhenUs(0);

            int res = 0;
            for (TaskE.Vertex v : vs)
                if (v.whenUs >= 0) {
                    boolean golden = false;
                    int tmp = v.firstUs;
                    while (tmp >= 0) {
                        TaskE.Vertex u = dest[tmp];
                        golden = true;
                        if (v == u.parentThey) golden = false;
                        if (u == v.parentThey) golden = false;
                        if (u.parentThey != null && v == u.parentThey.parentThey) golden = false;
                        if (v.parentThey != null && u == v.parentThey.parentThey) golden = false;
                        if (u.parentThey != null && u.parentThey == v.parentThey) golden = false;
                        if (golden) break;
                        tmp = next[tmp];
                    }
                    if (golden) {
                        out.println(-1);
                        return;
                    } else {
                        res = Math.max(res, 2 * v.whenThey);
                    }
                }
            out.println(res);
        }

        static class Vertex {
            int whenThey = -1;
            int whenUs = -1;
            int firstUs = -1;
            int firstThey = -1;
            TaskE.Vertex parentThey;

            public void fillWhenThey(int val) {
                whenThey = val;
                int tmp = firstThey;
                while (tmp >= 0) {
                    TaskE.Vertex v = dest[tmp];
                    if (v.whenThey < 0) v.fillWhenThey(val + 1);
                    else parentThey = v;
                    tmp = next[tmp];
                }
            }

            public void fillWhenUs(int val) {
                if (val >= whenThey) return;
                whenUs = val;
                int tmp = firstUs;
                while (tmp >= 0) {
                    TaskE.Vertex v = dest[tmp];
                    if (v.whenUs < 0) v.fillWhenUs(val + 1);
                    tmp = next[tmp];
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