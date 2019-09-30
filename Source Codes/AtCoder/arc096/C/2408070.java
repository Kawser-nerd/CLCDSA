import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    int mod;

    int add(int x, int y) {
        x += y;
        return x < mod ? x : (x - mod);
    }

    int sub(int x, int y) {
        x -= y;
        return x < 0 ? (x + mod) : x;
    }

    int mul(int x, int y) {
        return (int) (x * 1L * y % mod);
    }

    int[] pow2;
    int[] pow22;
    int[][] c;

    int pow(int x, int y) {
        int res = 1;
        for (int i = 31; i >= 0; i--) {
            res = mul(res, res);
            if (((1 << i) & y) != 0) {
                res = mul(res, x);
            }
        }
        return res;
    }

    int countWays(int totalLen, int failCnt, int groupsPrec) {
        int res = c[totalLen][failCnt];
        res = mul(res, pow22[totalLen - failCnt]);
        res = mul(res, groupsPrec);
        if (failCnt % 2 == 1) {
            res = sub(0, res);
        }
        return res;
    }

    void solve() {
        int n = in.nextInt();
        mod = in.nextInt();
        pow22 = new int[n + 1];
        pow22[0] = 2;
        int cc = 1;
        for (int l = 1; l <= n; l++) {
            cc = (cc + cc) % (mod - 1);
            pow22[l] = pow(2, cc);
        }
        pow2 = new int[n + 1];
        c = new int[n + 1][n + 1];
        c[0][0] = 1;
        for (int i = 1; i < c.length; i++) {
            c[i][0] = 1;
            for (int j = 1; j < c[i].length; j++) {
                c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
            }
        }
        pow2[0] = 1;
        for (int i = 1; i < pow2.length; i++) {
            pow2[i] = add(pow2[i - 1], pow2[i - 1]);
        }
        int[] groups = new int[n + 1];
        int[] nextGroups = new int[n + 1];
        groups[0] = 1;
        int res = 0;
        res = add(res, countWays(n, 0, 1));
        for (int totalLen = 1; totalLen <= n; totalLen++) {
            Arrays.fill(nextGroups, 0);
            for (int curGroups = 0; curGroups < totalLen; curGroups++) {
                int cur = groups[curGroups];
                if (cur == 0) {
                    continue;
                }
                nextGroups[curGroups + 1] = add(nextGroups[curGroups + 1], cur);
                nextGroups[curGroups] = add(nextGroups[curGroups], mul(cur, curGroups + 1));
            }
            int[] tmp = groups;
            groups = nextGroups;
            nextGroups = tmp;
            int groupPrec = 1;
            for (int gr = 0; gr <= totalLen; gr++) {
                res = add(res, mul(groups[gr], countWays(n, totalLen, groupPrec)));
                groupPrec = mul(groupPrec, pow2[n - totalLen]);
            }
        }
        out.println(res);
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