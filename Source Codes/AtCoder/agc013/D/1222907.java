import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final int MODULO = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] totalBig = onePart(n, m);
            int[] totalSmall = onePart(n - 1, m);
            long res = totalBig[m - 1];
            for (int smallPart = 0; smallPart <= m - 2; ++smallPart) {
                res = (res + totalSmall[smallPart] * (long) totalBig[m - 2 - smallPart]) % MODULO;
            }
            out.println(res * 4 % MODULO);
        }

        private int[] onePart(int n, int m) {
            int[] ways = new int[n];
            if (n > 0) {
                ways[0] = 1;
            }
            int[] nways = new int[n];
            int[] total = new int[m];
            if (n > 0) {
                total[0] = 1;
            }
            for (int len = 1; len < m; ++len) {
                for (int i = 0; i < n; ++i) {
                    nways[i] = ways[i] * 2;
                    if (nways[i] >= MODULO) nways[i] -= MODULO;
                }
                for (int i = 0; i < n; ++i) {
                    if (i > 0) {
                        nways[i - 1] = (nways[i - 1] + ways[i]);
                        if (nways[i - 1] >= MODULO) nways[i - 1] -= MODULO;
                    }
                    if (i + 1 < n) {
                        nways[i + 1] = (nways[i + 1] + ways[i]);
                        if (nways[i + 1] >= MODULO) nways[i + 1] -= MODULO;
                    }
                }
                int[] tmp = ways;
                ways = nways;
                nways = tmp;
                long s = 0;
                for (int i = 0; i < n; ++i) {
                    s += ways[i];
                }
                total[len] = (int) (s % MODULO);
            }
            return total;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}