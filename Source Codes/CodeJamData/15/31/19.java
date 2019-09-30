import java.io.*;
import java.util.*;

public class A {

    MyScanner in;
    PrintWriter out;
    final static String FILENAME = "a";

    public static void main(String[] args) throws Exception {
        new A().run();
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
        int r = in.nextInt();
        int c = in.nextInt();
        int w = in.nextInt();

        return r * (c / w + w + (c % w == 0 ? -1 : 0));
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
