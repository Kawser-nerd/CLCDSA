import java.io.*;
import java.util.*;

public class C {

    MyScanner in;
    PrintWriter out;
    final static String FILENAME = "c";

    public static void main(String[] args) throws Exception {
        new C().run();
    }

    public void run() throws Exception {
        in = new MyScanner(FILENAME + ".in");
        out = new PrintWriter(FILENAME + ".out");

        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            out.println("Case #" + (test + 1) + ": " + solve());
        }

        out.close();
    }

    public long solve() throws Exception {
        long c = in.nextInt();
        int d = in.nextInt();
        long v = in.nextInt();
        TreeSet<Long> coins = new TreeSet<Long>();
        for (int i = 0; i < d; i++) {
            coins.add(in.nextLong());
        }

        int ans = 0;
        if (!coins.contains(1L)) {
            ans++;
        } else {
            coins.remove(1L);
        }
        long sumMax = c;
        while (sumMax < v) {
            Long newCoin = coins.floor(sumMax + 1);
            if (newCoin == null) {
                ans++;
                sumMax += c * (sumMax + 1);
            } else {
                sumMax += c * coins.pollFirst();
            }
        }
        return ans;
    }

    class MyScanner {

        BufferedReader br;
        StringTokenizer st;

        public MyScanner(String file) throws Exception {
            br = new BufferedReader(new FileReader(file));
        }

        String next() throws Exception {
            while ((st == null) || (!st.hasMoreTokens())) {
                String t = br.readLine();
                if (t == null) {
                    return null;
                }
                st = new StringTokenizer(t);
            }
            return st.nextToken();
        }

        int nextInt() throws Exception {
            return Integer.parseInt(next());
        }

        double nextDouble() throws Exception {
            return Double.parseDouble(next());
        }

        boolean nextBoolean() throws Exception {
            return Boolean.parseBoolean(next());
        }

        long nextLong() throws Exception {
            return Long.parseLong(next());
        }
    }
}
