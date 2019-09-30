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
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] outgo = new int[n];
            int[] incom = new int[n];
            for (int i = 0; i < m; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                outgo[x] |= 1 << y;
                incom[y] |= 1 << x;
            }
            int[] ways = new int[1 << n];
            for (int s = 1; s < ways.length; ++s) {
                if ((s & 3) != 3) continue;
                long cw = 0;
                outer:
                for (int t = s; t > 0; t = (t - 1) & s) {
                    if ((t & 3) == 3) continue;
                    int rem = s ^ t;
                    if ((t & 3) == 0 && ways[rem] == 0) continue;
                    long w = 1;
                    for (int u = 0; u < n; ++u)
                        if ((rem & (1 << u)) != 0) {
                            int oup = outgo[u] & t;
                            int cnt = Integer.bitCount(oup);
                            if (cnt == 0) {
                                continue outer;
                            }
                            w *= (1 << cnt) - 1;
                            w %= MODULO;
                            int inp = incom[u] & t;
                            w *= 1 << Integer.bitCount(inp);
                            w %= MODULO;
                        }
                    long ow;
                    if ((t & 3) == 0) {
                        ow = ways[rem];
                    } else {
                        ow = 1;
                        for (int u = 0; u < n; ++u)
                            if ((rem & (1 << u)) != 0) {
                                ow *= 1 << Integer.bitCount(outgo[u] & rem);
                                ow %= MODULO;
                            }
                    }
                    cw += ow * w;
                    cw %= MODULO;
                }
                ways[s] = (int) cw;
            }
            out.println(ways[ways.length - 1]);
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