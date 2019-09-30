import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    boolean ok(int[] res, int[] a, int[] b) {
        int n = res.length;
        int[] dp1 = new int[n];
        Arrays.fill(dp1, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (res[j] < res[i])
                    dp1[i] = Math.max(dp1[i], dp1[j] + 1);
            }
        }
        int[] dp2 = new int[n];
        Arrays.fill(dp2, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (res[j] < res[i])
                    dp2[i] = Math.max(dp2[i], dp2[j] + 1);
            }
        }
        for (int i = 0; i < n; i++)
            if (dp1[i] != a[i] || dp2[i] != b[i])
                return false;
        return true;
    }

    int[] go(int v, int[] res, int[] a, int[] b) {
        int n = res.length;
        if (v > n)
            return res;
        int[] dp1 = new int[n];
        Arrays.fill(dp1, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (res[j] < res[i])
                    dp1[i] = Math.max(dp1[i], dp1[j] + 1);
            }
        }
        int[] dp2 = new int[n];
        Arrays.fill(dp2, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (res[j] < res[i])
                    dp2[i] = Math.max(dp2[i], dp2[j] + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (res[i] == Integer.MAX_VALUE && dp1[i] == a[i] && dp2[i] == b[i]) {
                int[] tmp = new int[n];
                for (int j = 0; j < n; j++)
                    tmp[j] = res[j];
                res[i] = v;
                res = go(v + 1, res, a, b);
                if (res != null && ok(res, a, b)) {
                    return res;
                }
                res = tmp;
            }
        }
        return null;
    }

    void solve() throws IOException {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        int[] res = new int[n];
        Arrays.fill(res, Integer.MAX_VALUE);
        res = go(1, res, a, b);
        if (res == null)
            throw new AssertionError();

        int[] dp1 = new int[n];
        Arrays.fill(dp1, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (res[j] < res[i])
                    dp1[i] = Math.max(dp1[i], dp1[j] + 1);
            }
        }
        int[] dp2 = new int[n];
        Arrays.fill(dp2, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (res[j] < res[i])
                    dp2[i] = Math.max(dp2[i], dp2[j] + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (dp1[i] != a[i])
                throw new AssertionError();
            if (dp2[i] != b[i]) {
                for (int j = 0; j < n; j++) {
                    if (j == i) {
                        System.err.println("(" + a[j] + ", " + b[j] + ") - "
                                + res[j] + " !");
                    } else {
                        System.err.println("(" + a[j] + ", " + b[j] + ") - "
                                + res[j]);
                    }
                }
                throw new AssertionError();
            }
        }
        for (int i = 0; i < n; i++) {
            out.print(res[i]);
            if (i == n - 1) {
                out.println();
            } else {
                out.print(" ");
            }
        }
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.print("Case #" + (test) + ": ");
                solve();
                System.out.println(test);
            }

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        try {
            solve();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

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
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }
}