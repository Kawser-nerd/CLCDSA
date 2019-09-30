import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    int n, c;
    int[] len;
    double[][][] dp;

    double solve(int[] perm) {
        double[] add = new double[n + 1];
        for (int i = 0; i < perm.length; i++) {
            add[i] = (1 + perm[i]) / (n + 5.);
        }
        double firstProb = 1;
        for (int i = 1; i <= n; i++) {
            firstProb /= i;
        }
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[i].length; j++) {
                for (int k = 0; k < dp[i][j].length; k++) {
                    Arrays.fill(dp[i][j], 0);
                }
            }
        }
        dp[0][0][0] = firstProb;
        double result = 0;
        for (int pos = 0; pos <= c; pos++) {
            for (int mask = 0; mask < 1 << n; mask++) {
                for (int lastIndex = 0; lastIndex < dp[pos][mask].length; lastIndex++) {
                    double cur = dp[pos][mask][lastIndex];
                    if (cur < 1e-20) {
                        continue;
                    }
//                    System.err.println(pos + " " + mask + " " + lastIndex + "->" + cur);
                    int upToPos = (lastIndex - 1) / n;
                    int id = (lastIndex - 1) % n;
                    if (lastIndex == 0) {
                        id = n;
                        upToPos = 0;
                    }
                    double realUpTo = upToPos + len[id] + add[id];
//                    System.err.println("real = " + realUpTo);
                    if (realUpTo >= c) {
                        result += cur;
                        continue;
                    }
                    int notMask = ((1 << n) - 1) ^ mask;
                    for (int useMask = notMask; useMask > 0; useMask = (useMask - 1) & notMask) {
                        double goProb = 1;
                        double goLen = realUpTo;
                        double min = pos + 1;
                        int nextIndex = lastIndex;
                        for (int i = 0; i < n; i++) {
                            if (((1 << i) & useMask) != 0) {
                                goProb /= (c - pos + 0.);
                                min = Math.min(add[i] + pos, min);
                                double go = pos + add[i] + len[i];
                                if (go > goLen) {
                                    goLen = go;
                                    nextIndex = 1 + n * pos + i;
                                }
                            } else if (((1 << i) & notMask) != 0) {
                                goProb *= (c - pos - 1) / (c - pos + 0.);
                            }
                        }
                        if (min > realUpTo) {
                            continue;
                        }
                        int nextMask = mask | useMask;
                        dp[pos + 1][nextMask][nextIndex] += cur * goProb;

                    }

                    if (realUpTo >= pos + 1) {
                        for (int i = 0; i < n; i++) {
                            if (((1 << i) & mask) == 0) {
                                cur *= (c - pos - 1.) / (c - pos);
                            }
                        }
                        dp[pos + 1][mask][lastIndex] += cur;
                    }
                }
            }
        }
//        System.err.println("result = " + result);
//        throw new AssertionError();
        return result;
    }

    double go(int[] perm, boolean[] used, int it) {
        if (it == perm.length) {
            return solve(perm);
        } else {
            double res = 0;
            for (int i = 0; i < perm.length; i++) {
                if (!used[i]) {
                    used[i] = true;
                    perm[it] = i;
                    res += go(perm, used, it + 1);
                    used[i] = false;
                }
            }
            return res;
        }
    }

    void solve() {
        n = in.nextInt();
        c = in.nextInt();
        len = new int[n];
        for (int i = 0; i < n; i++) {
            len[i] = in.nextInt();
        }
        Arrays.sort(len);
        n--;
        dp = new double[c + 1][1 << n][n * c + 1]; // [cur position] [mask used] [current end = (pos * n + index + 1)]
        out.println(go(new int[n], new boolean[n], 0));
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