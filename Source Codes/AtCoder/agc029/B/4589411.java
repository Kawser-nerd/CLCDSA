import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.LinkedList;
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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        B solver = new B();
        solver.solve(1, in, out);
        out.close();
    }

    static class B {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.ni();
            int[] a = in.na(n);
            HashMap<Integer, LinkedList<Integer>> map = new HashMap<>(n);
            for (int i = 0; i < n; i++) {
                LinkedList<Integer> update = map.computeIfAbsent(a[i], k -> new LinkedList<>());
                update.add(i);
            }
            int ans = 0;
            for (int j = 30; j > 0; j--) {
                int pow = 1 << j;
                //System.out.println("pow = " + pow);
                for (int i = 0; i < n; i++) {
                    LinkedList<Integer> cur = map.get(a[i]);
                    if (cur.size() == 0)
                        continue;
                    LinkedList<Integer> pairs = map.get(pow - a[i]);
                    if (pairs != null && pairs.size() > 0) {
                        if (pow - a[i] == a[i] && pairs.size() == 1)
                            continue;
                        pairs.poll();
                        cur.poll();
                        ans++;
                    }

                }
            }
            out.println(ans);
        }

    }

    static class FastScanner {
        private BufferedReader in;
        private StringTokenizer st;

        public FastScanner(InputStream stream) {
            in = new BufferedReader(new InputStreamReader(stream));
        }

        public String ns() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    String rl = in.readLine();
                    if (rl == null) {
                        return null;
                    }
                    st = new StringTokenizer(rl);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int ni() {
            return Integer.parseInt(ns());
        }

        public int[] na(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = ni();
            return a;
        }

    }
}