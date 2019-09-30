import java.io.*;
import java.util.StringTokenizer;

public class Main {
    /**********************************************************************************************
     *                                            DEBUG                                           *
     **********************************************************************************************/
    private final static boolean DEBUG = false;
    private final static String[] DEBUG_INPUT = {
//            "5 2",
            "5 0",
//            "10000 1242"
    };



    /**********************************************************************************************
     *                                             MAIN                                           *
     **********************************************************************************************/
    private static class Solver {
        private static final int MIN = -999_999_999;
        private static final int MAX = 999_999_999;

        public void solve(Reader in, PrintWriter out) throws IOException {
            int n = in.nextInt();
            int k = in.nextInt();
            out.println(solve2(n, k));
        }

        private long solve2(int n, int k) {
            if (k == 0) return (long) n * n;
            long res = 0;
            for (int b = k + 1; b <= n; b++) {
                int p = n / b;
                int r = n % b;
                res += (long) p * (b - k);
                res += Math.max(0, r - k + 1);
            }
            return res;
        }
    }



    /**********************************************************************************************
     *                                           TEMPLATE                                         *
     **********************************************************************************************/
    public static void main(String[] args) throws IOException {
        PrintWriter out = null;
        Reader in;
        if (DEBUG) {
            for (String s : DEBUG_INPUT) {
                in = new Reader(new ByteArrayInputStream(s.getBytes()));
                out = new PrintWriter(System.out);
                out.println("===>>> INPUT");
                out.println(s + "\n\n");
                out.println("===>>> OUTPUT");
                long start = System.currentTimeMillis();
                new Solver().solve(in, out);
                long end = System.currentTimeMillis();
                out.println("\n");
                out.println("===========");
                out.println("Took: " + (end - start) + "ms");
                out.println("====================================================================");
                out.println();
                out.println();
                out.flush();
            }
        } else {
            in = new Reader(System.in);
            out = new PrintWriter(System.out);
            new Solver().solve(in, out);
        }
        if (out != null) out.flush();
    }

    /** Reader **/
    private static class Reader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public Reader(InputStream input) {
            reader = new BufferedReader(
                    new InputStreamReader(input));
            tokenizer = new StringTokenizer("");
        }

        private String nextWord() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        private int nextInt() throws IOException {
            return Integer.parseInt(nextWord());
        }

        private long nextLong() throws IOException {
            return Long.parseLong(nextWord());
        }

        private double nextDouble() throws IOException {
            return Double.parseDouble(nextWord());
        }
    }
}