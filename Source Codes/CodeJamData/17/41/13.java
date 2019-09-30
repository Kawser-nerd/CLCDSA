import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int p;

    class S {
        int[] a;

        public S() {
            a = new int[p];
        }

        public S(S s, int v) {
            a = s.a.clone();
            a[v]--;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            S s = (S) o;

            return Arrays.equals(a, s.a);
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(a);
        }

        int sum() {
            int r = 0;
            for (int i = 0; i < p; i++) {
                r = (r + a[i] * i) % p;
            }
            return r;
        }
    }

    Map<S, Integer> memo;

    int dfs(S s) {
        if (memo.containsKey(s)) {
            return memo.get(s);
        }

        int best = 0;
        for (int i = 0; i < p; i++) {
            if (s.a[i] > 0) {
                S ns = new S(s, i);
                int g = dfs(ns);
                if (ns.sum() == 0) {
                    g++;
                }
                if (g > best) {
                    best = g;
                }
            }
        }
        memo.put(s, best);
        return best;
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();

        for (int test = 1; test <= testNo; test++) {
            memo = new HashMap<>();

            int n = in.nextInt();
            p = in.nextInt();
            S s = new S();
            for (int i = 0; i < n; i++) {
                int g = in.nextInt();
                s.a[g % p]++;
            }

            int ans = dfs(s);

            System.out.println("Case #" + test + ": " + ans);
            out.println("Case #" + test + ": " + ans);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("A-large.in"));
            out = new PrintWriter(new File("A-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        Locale.setDefault(Locale.US);
        new A().run();
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
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