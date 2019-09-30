import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();

            int ans = Math.min(solve(n, m, k), solve(m, n, k));

            out("Case #%d: %d\n", test, ans);
        }
    }

    int solve(int n, int m, int k) {
        int[] best = new int[n * m + 1];
        int ans = -1;
        for (int s = 1; s <= n * m; s++) {
            best[s] = s;
            for (int w = 1; 2 * w < s && w <= n - 2; w++) {
                int h = (s - 2 * w) / 2;
                int r = 0;
                if (h > m - 2) {
                    h = m - 2;
                    r = h * w + 2 * h + 2 * w + (s - 2 * h - 2 * w);
                    if (r >  m * n) {
                        r = m * n;
                    }
                } else if (h < m - 2 && h + (h + 1) + 2 * w <= s) {
                    r = h * w + 2 * h + 2 * w + w;
                } else {
                    r = h * w + 2 * h + 2 * w + (s - 2 * h - 2 * w);
                    if (r >  m * n) {
                        r = m * n;
                    }
                }
                if (r > best[s]) {
                    best[s] = r;
                }
            }
            if (best[s] >= k && ans == -1) {
                ans = s;
            }
//            System.out.println(n + " " + m + ": " + s + " -> " + best[s]);
        }
        return ans;
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-small-attempt1.in"));
            out = new PrintWriter(new File("C-small-attempt1.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new C().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}