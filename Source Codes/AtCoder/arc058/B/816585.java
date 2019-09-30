import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
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
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        long MOD = (long) 1e9 + 7;
        long[] fact = new long[(int) 2e5 + 1];

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int N = in.nextInt(), M = in.nextInt(), A = in.nextInt(), B = in.nextInt();
            int i;
            fact[0] = fact[1] = 1;
            for (i = 2; i <= 200000; i++) {
                fact[i] = fact[i - 1] * i;
                fact[i] %= MOD;
            }
            long ans = numWays(N, M);
            int X = A;
            for (i = N - A + 1; i <= N; i++) {
                long way = numWays(i, B);
                way *= numWays(X, M - B);
                way %= MOD;
                ans -= way;
                while (ans < 0) ans += MOD;
                X--;
            }
            while (ans < 0) ans += MOD;
            out.printLine(ans);
        }

        public long numWays(int x, int y) {
            long ans = fact[(x + y - 2)];
            ans *= IntegerUtils.extededGCD(MOD, fact[x - 1])[0];
            ans %= MOD;
            ans *= IntegerUtils.extededGCD(MOD, fact[y - 1])[0];
            ans %= MOD;
            return ans;
        }

    }

    static class IntegerUtils {
        public static int[] extededGCD(long MOD, long a) {
            long x = 0, y = 1, lastx = 1, lasty = 0, m1 = MOD;
            while (MOD != 0) {
                long q = a / MOD, r = a % MOD;
                long m = lastx - q * x, n = lasty - q * y;
                lastx = x;
                lasty = y;
                x = m;
                y = n;
                a = MOD;
                MOD = r;
            }
            while (lastx < 0) {
                lastx += m1;
            }
            return new int[]{(int) lastx, (int) lasty};
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tokenizer = null;

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() {
            try {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                    tokenizer = new StringTokenizer(in.readLine());
                }
                return tokenizer.nextToken();
            } catch (IOException e) {
                return null;
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}