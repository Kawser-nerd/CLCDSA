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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = new long[2 * n];
            long[] sumHalf = new long[2];
            for (int i = 0; i < a.length; ++i) {
                int half = i % 2;
                int pos = i / 2;
                long cur = in.nextLong();
                a[i] = (cur * n + pos) * 2 + half;
                sumHalf[half] += cur;
            }
            long[] aOriginal = a.clone();
            Arrays.sort(a);
            int[] numHalf = new int[2];
            int[] numPos = new int[n];
            for (int i = 0; i < n; ++i) {
                int pos = (int) (a[i] / 2 % n);
                int half = (int) (a[i] % 2);
                ++numHalf[half];
                ++numPos[pos];
            }
            boolean ok = false;
            for (int i = 0; i < n; ++i) {
                if (numPos[i] == 0) {
                    ok = true;
                }
            }
            for (int i = 0; i < 2; ++i) {
                if (numHalf[i] == 0) {
                    ok = true;
                }
            }
            long s = 0;
            long max = 0;
            long max2 = 0;
            for (int i = 0; i < n; ++i) {
                long cur = a[i] / (2 * n);
                s += cur;
                if (cur > max) {
                    max2 = max;
                    max = cur;
                } else if (cur > max2) {
                    max2 = cur;
                }
            }
            if (!ok) {
                long best = Math.min(sumHalf[0], sumHalf[1]);
                for (int i = 0; i < n; ++i) {
                    long v1 = aOriginal[i * 2] / (2 * n);
                    long v2 = aOriginal[i * 2 + 1] / (2 * n);
                    long used = Math.min(v1, v2);
                    long got = s + Math.max(v1, v2);
                    if (used == max) got -= max2;
                    else got -= max;
                    best = Math.min(best, got);
                }
                s = best;
            }
            out.println(s);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}