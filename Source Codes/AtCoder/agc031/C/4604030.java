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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
            if (Integer.bitCount(a ^ b) % 2 == 0) {
                out.println("NO");
                return;
            }
            out.println("YES");
            int[] res = new int[1 << n];
            printOut(n, a, b, 0, res);
            for (int x : res) {
                out.print(x + " ");
            }
            out.println();
        }

        private void printOut(int n, int a, int b, int start, int[] res) {
            if (n == 1) {
                res[start] = a;
                res[start + 1] = b;
                return;
            }
            int diffAt = Integer.numberOfTrailingZeros(a ^ b);
            int na = (a >> (diffAt + 1)) << diffAt;
            na += a & ((1 << diffAt) - 1);
            int nb = (b >> (diffAt + 1)) << diffAt;
            nb += b & ((1 << diffAt) - 1);
            int abit = ((a >> diffAt) & 1) << diffAt;
            int bbit = ((b >> diffAt) & 1) << diffAt;
            printOut(n - 1, na, na ^ 1, start, res);
            for (int i = 0; i < (1 << (n - 1)); ++i) {
                int v = res[start + i];
                res[start + i] = (v >> diffAt) << (diffAt + 1);
                res[start + i] += abit;
                res[start + i] += v & ((1 << diffAt) - 1);
            }
            start += 1 << (n - 1);
            printOut(n - 1, na ^ 1, nb, start, res);
            for (int i = 0; i < (1 << (n - 1)); ++i) {
                int v = res[start + i];
                res[start + i] = (v >> diffAt) << (diffAt + 1);
                res[start + i] += bbit;
                res[start + i] += v & ((1 << diffAt) - 1);
            }
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