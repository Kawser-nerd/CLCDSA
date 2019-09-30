import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CMinCostCycle solver = new CMinCostCycle();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMinCostCycle {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            List<CMinCostCycle.Node> a = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                a.add(new CMinCostCycle.Node(in.ints(), true, i));
                a.add(new CMinCostCycle.Node(in.ints(), false, i));
            }
            a.sort(Comparator.comparing(node -> node.cost));
            int[] use = new int[n];
            long ans = 0;
            boolean du = false;
            int type = 0;
            for (int i = 0; i < n; i++) {
                int index = a.get(i).i;
                ans += a.get(i).cost;
                if (use[index] > 0) {
                    du = true;
                }
                if (a.get(i).in) {
                    type |= 1;
                } else {
                    type |= 2;
                }
                use[index]++;
            }
            if (!du && type == 3) {
                int d;
                if (a.get(n - 1).i == a.get(n).i) {
                    d = a.get(n + 1).cost - a.get(n - 1).cost;
                } else {
                    d = a.get(n).cost - a.get(n - 1).cost;
                }
                if (a.get(n - 2).i == a.get(n).i) {
                    d = Math.min(d, a.get(n + 1).cost - a.get(n - 2).cost);
                } else {
                    d = Math.min(d, a.get(n).cost - a.get(n - 2).cost);
                }
                ans += d;
            }
            out.println(ans);
        }

        static class Node {
            int cost;
            boolean in;
            int i;

            public Node(int cost, boolean in, int i) {
                this.cost = cost;
                this.in = in;
                this.i = i;
            }

        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int ints() {
            return Integer.parseInt(string());
        }

    }
}