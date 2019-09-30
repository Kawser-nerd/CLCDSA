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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final int MODULO = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            int[] mustMask = new int[m];
            int[] mustValue = new int[m];
            for (int i = 0; i < k; ++i) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                int c = in.nextInt();
                mustMask[a] |= 1 << b;
                mustValue[a] |= c << b;
            }
            int[] ways = new int[1 << (n - 1)];
            int[] nways = new int[1 << (n - 1)];
            ways[0] = 1;
            for (int i = 0; i < m; ++i) {
                for (int pos = 0; pos < n - 1; ++pos) {
                    System.arraycopy(ways, 0, nways, 0, ways.length);
                    int bit = 1 << pos;
                    for (int old = 0; old < ways.length; ++old)
                        if (ways[old] != 0) {
                            if ((old & bit) == 0) {
                                int nxt = (old & (old - bit)) + bit;
                                nways[nxt] += ways[old];
                                if (nways[nxt] >= MODULO) nways[nxt] -= MODULO;
                            }
                        }
                    int[] tmp = ways;
                    ways = nways;
                    nways = tmp;
                }
                int mask = mustMask[i];
                int val = mustValue[i];
                for (int old = 0; old < ways.length; ++old) if ((old & mask) != val) ways[old] = 0;
            }
            long res = 0;
            for (int x : ways) res += x;
            res %= MODULO;
            out.println(res);
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