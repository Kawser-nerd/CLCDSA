import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.LinkedList;
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
            List<Node> l = new ArrayList<>();
            for (int i = 1; i <= n; i++) l.add(new Node());
            for (int i = 0; i < n - 1; i++) {
                Node a = l.get(in.nextInt() - 1);
                Node b = l.get(in.nextInt() - 1);
                a.neighbors.add(b);
                b.neighbors.add(a);
            }
            Queue<Node> q = new LinkedList<>();
            Set<Node> seen = new HashSet<>();
            q.offer(l.get(0));
            seen.add(l.get(0));
            while (!q.isEmpty()) {
                Node cur = q.poll();
                for (Node node : cur.neighbors) {
                    if (!seen.contains(node)) {
                        node.first = cur.first + 1;
                        q.offer(node);
                        seen.add(node);
                    }
                }
            }
            seen = new HashSet<>();
            q.offer(l.get(n - 1));
            seen.add(l.get(n - 1));
            int size = 0;
            while (!q.isEmpty()) {
                Node cur = q.poll();
                if (cur.second < cur.first) size++;
                for (Node node : cur.neighbors) {
                    if (!seen.contains(node)) {
                        node.second = cur.second + 1;
                        q.offer(node);
                        seen.add(node);
                    }
                }
            }
            out.println(size >= n - size ? "Snuke" : "Fennec");
        }

        public class Node {
            List<Node> neighbors = new ArrayList<>();
            int first = 0;
            int second = 0;

            public Node() {
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
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