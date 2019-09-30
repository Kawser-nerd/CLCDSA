import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BTreeBurning solver = new BTreeBurning();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTreeBurning {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            long l = in.longs();
            int n = in.ints();
            long[] x = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                x[i] = in.longs();
            }
            long ans = 0;
            // ????
            long t = 0;
            for (int i = 1; i <= n; i++) {
                if (i % 2 == 1) {
                    t += x[i / 2 + 1] - x[i / 2];
                    t += 2 * (x[i] - x[i / 2 + 1]);
                } else {
                    t += 2 * (x[i] - x[i / 2]);
                }
                long a = i * l - t;
                if (a > ans) {
                    //System.out.println("LEFT i="+i+" a="+a);
                    ans = a;
                }
            }

            for (int i = 1; i <= n; i++) {
                x[i] = l - x[i];
            }
            Arrays.sort(x);

            t = 0;
            for (int i = 1; i <= n; i++) {
                if (i % 2 == 1) {
                    t += x[i / 2 + 1] - x[i / 2];
                    t += 2 * (x[i] - x[i / 2 + 1]);
                } else {
                    t += 2 * (x[i] - x[i / 2]);
                }
                long a = i * l - t;
                if (a > ans) {
                    //System.out.println("RIGHT i="+i+" a="+a);
                    ans = a;
                }
            }


            out.println(ans);
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int ints() {
            return Integer.parseInt(string());
        }

        public long longs() {
            return Long.parseLong(string());
        }

    }
}