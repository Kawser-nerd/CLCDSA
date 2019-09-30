import java.io.*;
import java.lang.Math;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        Task task = new Task();
        task.solve(in, out);
        out.close();
    }

    static class Task {

        SegmentTree plus;

        SegmentTree minus;

        long offset;

        void init(int n, int a) {
            plus = new SegmentTree(n);
            minus = new SegmentTree(n);
            setDP(a, 0);
            offset = 0;
        }

        long rmq(int u) {
            return Math.min(minus.rangeMinQuery(1, u - 1) + u, plus.rangeMinQuery(u, plus.n) - u);
        }

        void setDP(int u, long v) {
            plus.pointUpdate(u, v + u);
            minus.pointUpdate(u, v - u);
        }

        long getDP(int u) {
            return plus.rangeMinQuery(u, u) - u + offset;
        }

        void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            int a = in.nextInt();
            int prev = in.nextInt();
            init(n, a);
            for (int i = 1; i <= q; ++i) {
                int curr = in.nextInt();
                long cost = Math.abs(curr - prev);
                long o1 = rmq(curr);
                long o2 = getDP(prev) + cost;
                setDP(prev, Math.min(o1, o2) - cost);
                offset += cost;
                prev = curr;
            }
            long ans = (long)1e18;
            for (int i = 1; i <= n; ++i) {
                ans = Math.min(ans, getDP(i));
            }
            out.println(ans);
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
class SegmentTree {

    private static final long INF = 1000000000000000000L;

    class Node {

        private long val;

        private Node l;

        private Node r;

        Node() {
            val = INF;
        }

    }

    private long rangeMinQuery(Node u ,int x, int y, int l ,int r) {
        if (x > r || y < l) {
            return INF;
        }
        else if (x <= l && r <= y) {
            return u.val;
        }
        else {
            int m = (l + r) / 2;
            return Math.min(rangeMinQuery(u.l, x, y, l, m), rangeMinQuery(u.r, x, y, m + 1, r));
        }
    }

    private void pointUpdate(Node u, int x, long v, int l, int r) {
        if (l == r) {
            u.val = v;
        }
        else {
            int m = (l + r) / 2;
            if (x <= m) {
                pointUpdate(u.l, x, v, l, m);
            }
            else {
                pointUpdate(u.r, x, v, m + 1, r);
            }
            u.val = Math.min(u.l.val, u.r.val);
        }
    }

    private void makeTree(Node u, int l, int r) {
        if (l != r) {
            int m = (l + r) / 2;
            u.l = new Node();
            u.r = new Node();
            makeTree(u.l, l, m);
            makeTree(u.r, m + 1, r);
            u.val = Math.min(u.l.val, u.r.val);
        }
    }

    Node root;

    int n;

    SegmentTree(int n) {
        root = new Node();
        this.n = n;
        makeTree(root, 1, n);
    }

    long rangeMinQuery(int x, int y) {
        return rangeMinQuery(root, x, y, 1, n);
    }

    void pointUpdate(int x, long v) {
        pointUpdate(root, x, v, 1, n);
    }


}