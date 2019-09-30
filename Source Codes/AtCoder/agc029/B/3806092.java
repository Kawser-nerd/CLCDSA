import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.AbstractMap;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.util.Map;
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
        BPowersOfTwo solver = new BPowersOfTwo();
        solver.solve(1, in, out);
        out.close();
    }

    static class BPowersOfTwo {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt();
            TreeMap<Integer, Integer> counts = new TreeMap<>();

            for (int i = 0; i < N; i++) {
                counts.compute(in.nextInt(), (k, v) -> v == null ? 1 : v + 1);
            }

            int ans = 0;
            while (!counts.isEmpty()) {
                int cur = counts.lastKey();
                decrease(counts, cur);

                int p2 = 1;
                while (p2 <= cur) p2 *= 2;
                int need = p2 - cur;
                Integer got = counts.get(need);
                if (got != null) {
                    ans++;
                    decrease(counts, need);
                }
            }
            out.println(ans);
        }

        private void decrease(TreeMap<Integer, Integer> counts, int cur) {
            if (counts.get(cur) == 1) {
                counts.remove(cur);
            } else {
                counts.put(cur, counts.get(cur) - 1);
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