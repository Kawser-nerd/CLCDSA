import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
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
        DHistogramColoring solver = new DHistogramColoring();
        solver.solve(1, in, out);
        out.close();
    }

    static class DHistogramColoring {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = in.nextLongArray(n);

            Node root = makeTree(0, n, 0, a);

            long MOD = 1000000007;
            Modulo modulo = new Modulo(MOD);

            out.println(calc(root, modulo)[1]);
        }

        Node makeTree(int l, int r, long h, long[] a) {
            int minIndex = l;
            for (int i = l; i < r; i++) {
                if (a[i] < a[minIndex]) minIndex = i;
            }

            Node node = new Node();
            long w = 0;
            for (int i = l; i < r; i++) {
                if (a[i] == a[minIndex]) {
                    w++;
                } else {
                    int j = i;
                    while (j < r && a[j] != a[minIndex]) j++;
                    node.children.add(makeTree(i, j, a[minIndex], a));
                    i = j - 1;
                }
            }
            node.x = a[minIndex] - h;
            node.w = w;

            return node;
        }

        long[] calc(Node node, Modulo modulo) {
            long tmp1 = 1;
            long tmp2 = 1;

            for (Node child : node.children) {
                long[] childDp = calc(child, modulo);
                tmp1 = modulo.mlt(tmp1, childDp[0]);
                tmp2 = modulo.mlt(tmp2, childDp[0] + childDp[1]);
            }

            long dp1 = modulo.mlt(modulo.pow(2, node.x), tmp1);
            long dp2 = modulo.add(modulo.mlt(modulo.pow(2, node.w), tmp2),
                    modulo.mlt(modulo.sub(modulo.pow(2, node.x), 2), tmp1));

            return new long[]{dp1, dp2};
        }

        class Node {
            long x;
            long w;
            List<Node> children;

            Node() {
                children = new ArrayList<>();
            }

        }

    }

    static class InputReader {
        private BufferedReader br;
        private StringTokenizer st;

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
            st = new StringTokenizer("");
        }

        public String nextString() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public long nextLong() {
            return Long.parseLong(nextString());
        }

        public long[] nextLongArray(int n) {
            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextLong();
            }
            return res;
        }

    }

    static class Modulo {
        long m;

        public Modulo(long m) {
            this.m = m;
        }

        public long add(long a, long b) {
            return (a + b) % m;
        }

        public long sub(long a, long b) {
            return (a - b + m) % m;
        }

        public long mlt(long a, long b) {
            return (a * b) % m;
        }

        public long pow(long a, long x) {
            long ans = 1;
            while (x > 0) {
                if ((x & 1) != 0) {
                    ans = (ans * a) % m;
                }
                x >>= 1;
                a = (a * a) % m;
            }
            return ans;
        }

    }
}