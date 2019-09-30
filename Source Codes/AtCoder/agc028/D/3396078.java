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
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] a = new int[k];
            int[] b = new int[k];
            for (int i = 0; i < k; ++i) {
                a[i] = in.nextInt() - 1;
                b[i] = in.nextInt() - 1;
            }
            long[][] freeInside = new long[2 * n][2 * n];
            long[][] freeOutside = new long[2 * n][2 * n];
            long[][] waysToSeparate = new long[2 * n][2 * n];
            long[][] waysToFirstSeparate = new long[2 * n][2 * n];
            long[] twofacts = new long[2 * n + 1];
            int m = 2 * n;
            long[] invs = new long[m + 1];
            if (m > 0)
                invs[1] = 1;
            for (int i = 2; i <= m; ++i) {
                invs[i] = (MODULO - invs[((int) (MODULO % i))] * (MODULO / i) % MODULO) % MODULO;
                if (invs[i] * i % MODULO != 1) throw new RuntimeException();
            }
            twofacts[0] = 1;
            for (int i = 2; i < twofacts.length; i += 2) {
                twofacts[i] = twofacts[i - 2] * (i - 1) % MODULO;
            }
            long res = 0;
            for (int min = 2 * n - 1; min >= 0; --min) {
                for (int max = min + 1; max < 2 * n; max += 2) {
                    boolean ok = true;
                    int fi = max - min + 1;
                    int fo = 2 * n - fi;
                    for (int i = 0; i < k; ++i) {
                        if (a[i] >= min && a[i] <= max) {
                            if (b[i] >= min && b[i] <= max) {
                                fi -= 2;
                            } else {
                                ok = false;
                                break;
                            }
                        } else {
                            if (b[i] >= min && b[i] <= max) {
                                ok = false;
                                break;
                            } else {
                                fo -= 2;
                            }
                        }
                    }
                    if (!ok) continue;
                    freeInside[min][max] = fi;
                    freeOutside[min][max] = fo;
                    waysToSeparate[min][max] = twofacts[fi];
                    long wfs = twofacts[fi];
                    for (int omax = min + 1; omax < max; omax += 2)
                        if (waysToFirstSeparate[min][omax] != 0 && waysToSeparate[omax + 1][max] != 0) {
                            wfs -= waysToFirstSeparate[min][omax] * waysToSeparate[omax + 1][max] % MODULO;
                            wfs += MODULO;
                            wfs %= MODULO;
                        }
                    waysToFirstSeparate[min][max] = wfs;
                    res = (res + wfs * twofacts[fo]) % MODULO;
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