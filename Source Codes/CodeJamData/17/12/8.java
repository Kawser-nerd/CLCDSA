import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            out.print("Case #" + (t + 1) + ": ");
            int n = in.nextInt();
            int p = in.nextInt();

            int[] ri = new int[n];
            for (int i = 0; i < n; i++) {
                ri[i] = in.nextInt();
            }
            int[][] sizes = new int[n][p];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < p; j++) {
                    sizes[i][j] = in.nextInt();
                }
                Arrays.sort(sizes[i]);
            }
            int[] it = new int[n];
            int result = 0;
            int count = 1;
            while (true) {
                boolean ok = true;
                for (int i = 0; i < n; i++) {
                    while (it[i] < p && sizes[i][it[i]] * 10L < 9L * count * ri[i]) {
                        it[i]++;
                    }
                    if (it[i] == p) {
                        ok = false;
                    }
                }
                if (!ok) {
                    break;
                }
                for (int i = 0; i < n; i++) {
                    if (sizes[i][it[i]] * 10L > 11L * count * ri[i]) {
                        ok = false;
                    }
                }
                if (!ok) {
                    count++;
                    continue;
                }
                result++;
                for (int i = 0; i < n; i++) {
                    it[i]++;
                }
            }
            out.println(result);
            System.err.println((t + 1) + "/" + tc + " done");
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("input.txt"));
            out = new PrintWriter(new File("output.txt"));

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
        new Main().run();
    }
}