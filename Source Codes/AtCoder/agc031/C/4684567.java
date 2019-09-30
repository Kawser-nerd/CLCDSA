import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Don Li
 */
public class Main {
    void solve() {
        int n = in.nextInt();
        int a = in.nextInt(), b = in.nextInt();

        if (Integer.bitCount(a) % 2 == Integer.bitCount(b) % 2) {
            out.println("NO");
            return;
        }

        out.println("YES");
        int[] res = build(n, a, b);
        for (int i = 0; i < 1 << n; i++) {
            if (i > 0) out.print(' ');
            out.print(res[i]);
        }
    }

    int[] build(int n, int a, int b) {
        if (n == 1) {
            return new int[]{a, b};
        }

        int x = Integer.numberOfTrailingZeros(a ^ b);

        int aa = (a >> x + 1) << x | (a & (1 << x) - 1);
        int bb = (b >> x + 1) << x | (b & (1 << x) - 1);
        int cc = aa ^ 1;
        int[] p = build(n - 1, aa, cc), q = build(n - 1, cc, bb);
        
        int[] res = new int[1 << n];
        for (int i = 0; i < 1 << n - 1; i++) {
            int u = p[i] & ~((1 << x) - 1);
            int v = p[i] & (1 << x) - 1;
            res[i] = u << 1 | (a & 1 << x) | v;
        }
        for (int i = 0; i < 1 << n - 1; i++) {
            int u = q[i] & ~((1 << x) - 1);
            int v = q[i] & (1 << x) - 1;
            res[(1 << n - 1) + i] = u << 1 | (b & 1 << x) | v;
        }
        return res;
    }

    public static void main(String[] args) {
        in = new FastScanner(new BufferedReader(new InputStreamReader(System.in)));
        out = new PrintWriter(System.out);
        new Main().solve();
        out.close();
    }

    static FastScanner in;
    static PrintWriter out;

    static class FastScanner {
        BufferedReader in;
        StringTokenizer st;

        public FastScanner(BufferedReader in) {
            this.in = in;
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }
}