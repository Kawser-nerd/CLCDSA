import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        static final long MODULO = 924844033;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();

            int max = (n - 1) / k + 1;
            int[][] waysOne = new int[max + 1][max + 1];
            int[][] waysLayer = new int[4][max + 1];
            int[][] nwaysLayer = new int[4][max + 1];
            waysLayer[1][0] = 1;
            waysOne[0][0] = 1;
            for (int cnt = 1; cnt <= max; ++cnt) {
                for (int[] x : nwaysLayer) Arrays.fill(x, 0);
                for (int mask = 0; mask < 4; ++mask) {
                    for (int old = 0; old < cnt; ++old) {
                        int ow = waysLayer[mask][old];
                        if (ow == 0) continue;
                        nwaysLayer[mask >> 1][old] += ow;
                        if (nwaysLayer[mask >> 1][old] >= MODULO) nwaysLayer[mask >> 1][old] -= MODULO;
                        nwaysLayer[2 + (mask >> 1)][old + 1] += ow;
                        if (nwaysLayer[2 + (mask >> 1)][old + 1] >= MODULO)
                            nwaysLayer[2 + (mask >> 1)][old + 1] -= MODULO;
                        if ((mask & 1) == 0) {
                            nwaysLayer[(mask >> 1)][old + 1] += ow;
                            if (nwaysLayer[(mask >> 1)][old + 1] >= MODULO) nwaysLayer[(mask >> 1)][old + 1] -= MODULO;
                        }
                    }
                }
                int[][] tmp = waysLayer;
                waysLayer = nwaysLayer;
                nwaysLayer = tmp;
                for (int old = 0; old <= cnt; ++old) {
                    waysOne[cnt][old] = waysLayer[0][old] + waysLayer[1][old];
                    if (waysOne[cnt][old] >= MODULO) waysOne[cnt][old] -= MODULO;
                }
            }

            int[] ways = new int[]{1};
            for (int rem = 0; rem < k; ++rem) {
                int am = (n - 1 - rem) / k + 1;
                int[] nways = new int[ways.length + am];
                for (int old = 0; old < ways.length; ++old) {
                    for (int cur = 0; cur <= am; ++cur) {
                        nways[old + cur] = (int) ((nways[old + cur] + ways[old] * (long) waysOne[am][cur]) % MODULO);
                    }
                }
                ways = nways;
            }
            if (ways.length != n + 1) throw new RuntimeException();

            long fact = 1;
            for (int i = 0; i <= n; ++i) {
                if (i > 0) fact = fact * i % MODULO;
                ways[n - i] = (int) (ways[n - i] * fact % MODULO);
            }

            long res = 0;
            for (int i = 0; i <= n; ++i) {
                if (i % 2 == 0) {
                    res = (res + ways[i]) % MODULO;
                } else {
                    res = (res - ways[i] + MODULO) % MODULO;
                }
            }
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