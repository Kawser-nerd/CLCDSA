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
 *
 * @author Xi Lin
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
        static public int mod = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            boolean mark[] = new boolean[n + 1];
            for (int i = 0; i <= n; ++i) mark[i] = true;
            for (int i = 2; i <= n; ++i)
                if (mark[i]) {
                    for (int j = i + i; j <= n; j += i) mark[j] = false;
                }
            long r = 1;
            for (int i = 2; i <= n; ++i)
                if (mark[i]) {
                    int c = 0;
                    for (long p = i; p <= n; p *= i) c += n / p;
                    r = r * (c + 1) % mod;
                }
            out.println(r);
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