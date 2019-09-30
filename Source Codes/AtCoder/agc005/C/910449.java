import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt();

            TreeMap<Integer, Integer> widths = new TreeMap<>();

            for (int i = 0; i < N; i++) {
                widths.compute(in.nextInt(), (k, v) -> v == null ? 1 : v + 1);
            }

            int diameter = widths.lastKey();
            boolean possible = true;
            for (int i = 0; i < diameter + 1; i++) {
                int width = Math.max(diameter - i, i);
                int remains = widths.compute(width, (k, v) -> v == null ? -1 : v - 1);
                if (remains < 0) {
                    possible = false;
                }
            }

            for (int w : widths.keySet()) {
                if (widths.get(w) != 0 && w <= (diameter + 1) / 2) {
                    possible = false;
                }
            }

            out.println(possible ? "Possible" : "Impossible");
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