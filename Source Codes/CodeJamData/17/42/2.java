import java.io.*;
import java.util.*;

public class B {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            out.print("Case #" + (t + 1) + ": ");
            int n = in.nextInt();
            int c = in.nextInt();
            int m = in.nextInt();
            int[] p = new int[m];
            int[] id = new int[m];
            for (int i = 0; i < m; i++) {
                p[i] = in.nextInt() - 1;
                id[i] = in.nextInt() - 1;
            }
            int[] sumPos = new int[n];
            int[] cnt = new int[c];
            for (int i = 0; i < m; i++) {
                sumPos[p[i]]++;
                cnt[id[i]]++;
            }
            int res = 0;
            for (int z : cnt) {
                res = Math.max(res, z);
            }
            int totalTickets = 0;
            for (int i = 0; i < n; i++) {
                totalTickets += sumPos[i];
                // res * (i + 1) >= totalTickets
                res = Math.max(res, (i + totalTickets) / (i + 1));
            }
            int add = 0;
            for (int i = 0; i < n; i++) {
                add += Math.max(0, sumPos[i] - res);
            }
            out.println(res + " " + add);
            System.err.println((t + 1) + "/" + tc + " done");
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("B.in"));
            out = new PrintWriter(new File("B.out"));

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
        new B().run();
    }
}