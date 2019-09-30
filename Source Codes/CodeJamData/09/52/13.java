import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class BEasy implements Runnable {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
    String filename = BEasy.class.getName().substring(0, 1);

    void preSolve() {

    }

    boolean inc(int[] v, int max) {
        for (int i = 0; i < v.length; ++i) {
            ++v[i];
            if (v[i] < max) {
                return true;
            }
            v[i] = 0;
        }
        return false;
    }

    void solve(int testNumber) throws IOException {
        StringTokenizer poly = new StringTokenizer(next(), "+");
        String[] polynom = new String[poly.countTokens()];
        for (int i = 0; i < polynom.length; ++i) {
            polynom[i] = poly.nextToken();
        }
        int k = nextInt();
        int[] ans = new int[k + 1];
        int n = nextInt();
        int[][] words = new int[n][26];
        for (int i = 0; i < n; ++i) {
            String s = next();
            for (int j = 0; j < s.length(); ++j) {
                words[i][s.charAt(j) - 'a']++;
            }
        }

        int[] sum = new int[26];

        final int MOD = 10009;

        for (int kk = 1; kk <= k; ++kk) {
            int[] sel = new int[kk];

            do {
                Arrays.fill(sum, 0);
                for (int j : sel) {
                    int[] wj = words[j];
                    for (int t = 0; t < 26; ++t) {
                        sum[t] += wj[t];
                    }
                }
                long a = 0;
                for (String p : polynom) {
                    long m = 1;
                    for (int j = 0; j < p.length(); ++j) {
                        char c = p.charAt(j);
                        m *= sum[c - 'a'];
                    }
                    a = (a + m) % MOD;
                }
                ans[kk] = (int) ((ans[kk] + a) % MOD);
            } while (inc(sel, n));
        }

        out.print("Case #" + testNumber + ":");
        for (int i = 1; i <= k; ++i) {
            out.print(" " + ans[i]);
        }
        out.println();
    }

    public void run() {
        try {
            in = new BufferedReader(new FileReader(filename + ".in"));
            out = new PrintWriter(filename + ".out");
            eat(null);

            preSolve();
            int nt = nextInt();
            for (int i = 1; i <= nt; ++i) {
                long t0 = System.currentTimeMillis();
                solve(i);
                t0 = System.currentTimeMillis() - t0;
                System.out.println(i + "/" + nt + " done in " + t0 + " ms.");
            }

            out.close();
            in.close();
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }

    void eat(String s) {
        st = s == null ? null : new StringTokenizer(s);
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    int[] nextIntArray() throws IOException {
        int n = nextInt();
        int[] rv = new int[n];
        for (int i = 0; i < n; ++i) {
            rv[i] = nextInt();
        }
        return rv;
    }

    int[] nextIntArrayFromLine() throws IOException {
        StringTokenizer st = new StringTokenizer(nextLine());
        int[] rv = new int[st.countTokens()];
        for (int i = 0; i < rv.length; ++i) {
            rv[i] = Integer.parseInt(st.nextToken());
        }
        return rv;
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    String nextLine() throws IOException {
        eat(null);
        return in.readLine();
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new Thread(new BEasy()).start();
    }
}