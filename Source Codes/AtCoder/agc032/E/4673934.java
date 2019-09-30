import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    boolean ok(int[] a, int mod, int maxSum) {
        int n = a.length;
        int maxCntLeft;
        {
            int l = 0, r = n / 2 + 1;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                boolean ok = true;
                for (int i = 0; i < m; i++) {
                    if (a[i] + a[m * 2 - 1 - i] > maxSum) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    l = m;
                } else {
                    r = m;
                }
            }
            maxCntLeft = l;
        }
        int maxCntOver;
        {
            int l = 0, r = n / 2 + 1;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                boolean ok = true;
                for (int i = 0; i < m; i++) {
                    if (a[n - i - 1] + a[n - m * 2 + i] < mod) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    r = m;
                } else {
                    l = m;
                }
            }
            maxCntOver = l;
        }
        int minCnt;
        {
            int l = 0, r = n / 2 + 1;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                boolean ok = true;
                for (int i = 0; i < m; i++) {
                    if (a[n - i - 1] + a[n - m * 2 + i] - mod > maxSum) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    r = m;
                } else {
                    l = m;
                }
            }
            minCnt = r;
        }
        if (minCnt > maxCntOver) {
            return false;
        }
        if (maxCntOver + maxCntLeft >= n / 2) {
            return true;
        }
        return false;
    }

    int justPair(int[] a, int module) {
        int r = 0;
        for (int i = 0; i < a.length; i++) {
            r = Math.max(r, (a[i] + a[a.length - 1 - i]) % module);
        }
        return r;
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n * 2];
        for (int i = 0; i < a.length; ++i) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
//        System.err.println("?? " + ok(a, m, 5));
        int lAns = -1, rAns = m;
        while (rAns - lAns > 1) {
            int ans = (lAns + rAns) >> 1;
            if (ok(a, m, ans)) {
                rAns = ans;
            } else {
                lAns = ans;
            }
        }
        out.println(Math.min(rAns, justPair(a, m)));
    }

    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

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
        new Main().runIO();
    }
}