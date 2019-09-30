import java.io.*;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    final int mod = (int) 1e9 + 7;

    class Pair {
        int one;
        int zero;

        public Pair(int one, int zero) {
            this.one = one;
            this.zero = zero;
        }
    }

    ArrayList<Integer>[] g;

    long[] pow2(int n) {
        long[] res = new long[n];
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] + res[i - 1];
            if (res[i] >= mod) {
                res[i] -= mod;
            }
        }
        return res;
    }

    ArrayList<Pair> go(int v, int h) {
        cntH[h]++;
        if (g[v].size() == 0) {
            ArrayList<Pair> res = new ArrayList<>();
            res.add(new Pair(1, 1));
            return res;
        }
        ArrayList<Pair>[] child = new ArrayList[g[v].size()];
        int it = 0;
        for (int to : g[v]) {
            child[it++] = go(to, h + 1);
        }
        Arrays.sort(child, new Comparator<ArrayList<Pair>>() {
            @Override
            public int compare(ArrayList<Pair> o1, ArrayList<Pair> o2) {
                return Integer.compare(o2.size(), o1.size());
            }
        });
        if (child.length > 1) {
            for (int i = 0; i < child[1].size(); i++) {
                long total = 1;
                int sz = 0;
                for (int j = 0; j < child.length; j++) {
                    if (child[j].size() <= i) {
                        break;
                    }
                    int curlen = child[j].size() - 1;
                    total *= (child[j].get(curlen - i).one + child[j].get(curlen - i).zero);
                    total %= mod;
                    sz++;
                }
                long[] suf = new long[sz + 1];
                suf[sz] = 1;
                for (int j = sz - 1; j >= 0; j--) {
                    int curlen = child[j].size() - 1;
                    suf[j] = suf[j + 1] * child[j].get(curlen - i).zero % mod;
                }
                long ones = 0;
                long pref = 1;
                for (int j = 0; j < sz; j++) {
                    int curlen = child[j].size() - 1;
                    long cur = child[j].get(curlen - i).one * pref % mod * suf[j + 1] % mod;
                    ones += cur;
                    pref = pref * child[j].get(curlen - i).zero % mod;
                }
                ones %= mod;
                child[0].get(child[0].size() - i - 1).one = (int) ones;
                int zeros = (int) ((total - ones + mod) % mod);
                child[0].get(child[0].size() - i - 1).zero = zeros;
            }
        }
        child[0].add(new Pair(1, 1));
        return child[0];
    }

    int[] cntH;

    private void solve() {
        int n = in.nextInt() + 1;
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            g[in.nextInt()].add(i);
        }
        cntH = new int[n];
        ArrayList<Pair> res = go(0, 0);
        long sum = 0;
        int it = res.size();
        long[] pow2 = pow2(n + 1);
        for (Pair x : res) {
            sum += x.one * pow2[n - cntH[--it]];
            sum %= mod;
        }
        out.println(sum % mod);
    }

    private void run() {
        try {
            in = new FastScanner(new File("ARC_086_C.in"));
            out = new PrintWriter(new File("ARC_086_C.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.