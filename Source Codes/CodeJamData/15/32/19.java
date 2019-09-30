import java.io.*;
import java.util.*;

public class B {

    MyScanner in;
    PrintWriter out;
    final static String FILENAME = "b";

    public static void main(String[] args) throws Exception {
        new B().run();
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

    public double solve() throws Exception {
        int k = in.nextInt();
        int l = in.nextInt();
        int s = in.nextInt();
        char[] keys = in.next().toCharArray();
        char[] word = in.next().toCharArray();

        double pword = 1.0;
        boolean fail = false;
        for (int i = 0; i < l; i++) {
            int occ = 0;
            for (int j = 0; j < k; j++) {
                if (word[i] == keys[j]) {
                    occ += 1;
                }
            }
            pword *= (1.0 * occ / k);
            if (occ == 0) {
                fail = true;
            }
        }

        int bmax = 0;
        if (!fail) {
            int offset = 1;
            while (offset < l) {
                boolean overlap = true;
                for (int i = 0; i < l - offset; i++) {
                    if (word[i] != word[i + offset]) {
                        overlap = false;
                        break;
                    }
                }
                if (overlap) {
                    break;
                }
                offset += 1;
            }
            bmax = 1 + (s - l) / offset;
        }
        return bmax - (s - l + 1) * pword;
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
