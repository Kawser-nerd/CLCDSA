import java.io.*;
import java.util.StringTokenizer;

public class GCJB {

    static long solveG(int n, long p) {
        if (n == 0) {
            return 0;
        }
        if (p <= 1L << (n - 1)) {
            return 0;
        } else {
            return Math.min((1L << n) - 1, 2 * solveG(n - 1, p - (1L << (n - 1))) + 2);
        }
    }

    static long solveC(int n, long p) {
        if (n == 0) {
            return 0;
        }
        if (p <= 1L << (n - 1)) {
            return 2 * solveC(n - 1, p);
        } else {
            return Math.max((1L << (n - 1)) + solveC(n - 1, p - (1L << (n - 1))), (1L << n) - 2);
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        long p = in.nextLong();
        long ansG = solveG(n, p);
        long ansC = solveC(n, p);
        if (ansG < 0 || ansG >= 1L << n || ansC < 0 || ansC >= 1L << n || ansG > ansC) {
            throw new AssertionError(n + " " + ansG + " " + ansC);
        }
        out.println(ansG + " " + ansC);
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        Input in = new Input(new BufferedReader(new InputStreamReader(System.in)));
        int tests = in.nextInt();
        for (int i = 0; i < tests; ++i) {
            out.print("Case #" + (i + 1) + ": ");
            solve(in, out);
            out.flush();
        }
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringTokenizer st;

        public Input(BufferedReader in) {
            this.in = in;
            eat("");
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public void eat(String str) {
            st = new StringTokenizer(str);
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null) {
                    return null;
                }
                eat(line);
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}
