import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;


    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        boolean[] res = new boolean[55];
        Arrays.fill(res, true);
        if (!can(a, b, res)) {
            out.println(-1);
            return;
        }
        for (int i = res.length - 1; i >= 0; i--) {
            res[i] = false;
            if (!can(a, b, res)) {
                res[i] = true;
            }
        }
        long cost = 0;
        for (int i = 0; i < res.length; i++) {
            if (res[i]) {
                cost += 1L << i;
            }
        }
        out.println(cost);
    }

    boolean can(int[] a, int[] b, boolean[] res) {
        for (int i = 0; i < a.length; i++) {
            if (!can(a[i], b[i], res)) {
                return false;
            }
        }
        return true;
    }

    boolean can(int x, int y, boolean[] res) {
        boolean[] possible = new boolean[x + 1];
        possible[x] = true;
        for (int i = res.length - 1; i > 0; i--) {
            if (!res[i]) {
                continue;
            }
            for (int j = 0; j < possible.length; j++) {
                if (possible[j]) {
                    possible[j % (i)] = true;
                }
            }
        }
        if (y < possible.length && possible[y]) {
            return true;
        }
        return false;
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