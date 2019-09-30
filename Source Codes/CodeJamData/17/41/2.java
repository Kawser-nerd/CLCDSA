import java.io.*;
import java.util.*;

public class Test {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            out.print("Case #" + (t + 1) + ": ");
            int n = in.nextInt();
            int p = in.nextInt();
            int[] cnt = new int[p];
            for (int i = 0; i < n; i++) {
                cnt[in.nextInt() % p]++;
            }
            int res = cnt[0];
            if (p == 2) {
                res += (cnt[1] + 1) / 2;
            } else if (p == 3) {
                int m = Math.min(cnt[1], cnt[2]);
                res += m;
                cnt[1] -= m;
                cnt[2] -= m;
                int v = Math.max(cnt[1], cnt[2]);
                res += (2 + v) / 3;
            } else if (p == 4) {
                int m = Math.min(cnt[1], cnt[3]);
                res += m;
                cnt[1] -= m;
                cnt[3] -= m;
                res += cnt[2] / 2;
                cnt[2] %= 2;
                m = Math.max(cnt[1], cnt[3]);
                if (cnt[2] == 0) {
                    res += (m + 3) / 4;
                } else {
                    if (m > 2) {
                        res += (m + 5) / 4;
                    } else {
                        res++;
                    }
                }
            }
            out.println(res);
            System.err.println((t + 1) + "/" + tc + " done");
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Test().run();
    }
}