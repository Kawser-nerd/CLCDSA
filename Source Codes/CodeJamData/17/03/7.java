import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Chiaki.Hoshinomori
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long k = in.nextLong();
            TreeMap<Long, Long> map = new TreeMap<>();
            map.put(n, 1l);
            while (k > 0) {
                long l = map.lastKey();
                long c = map.get(l);
                map.remove(l);
                if (c >= k) {
                    out.printf("Case #%d: %d %d\n", testNumber, l / 2, l - 1 - l / 2);
                    return;
                }
                k -= c;
                long a = l / 2;
                long b = l - 1 - l / 2;
                long ca = map.containsKey(a) ? map.get(a) : 0;
                ca += c;
                if (a > 0) map.put(a, ca);
                long cb = map.containsKey(b) ? map.get(b) : 0;
                cb += c;
                if (b > 0) map.put(b, cb);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}

