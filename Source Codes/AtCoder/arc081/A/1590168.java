import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
import java.io.BufferedReader;
import java.util.Collections;
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
            long n = in.nextInt();
            long ans = 0;
            HashMap<Long, Long> hm = new HashMap<>();
            for (int i = 0; i < n; i++) {
                long x = in.nextInt();
                if (hm.containsKey(x)) {
                    hm.put(x, hm.get(x) + 1);
                } else {
                    hm.put(x, (long) 1);
                }
            }
            List<Pair> pairs = new ArrayList<>();
            for (Map.Entry<Long, Long> entry : hm.entrySet()) pairs.add(new Pair(entry.getKey(), entry.getValue()));
            Collections.sort(pairs);
            long first = 0;
            boolean found = false;
            for (Pair pair : pairs) {
                if (pair.howMany >= 4) ans = Math.max(ans, pair.number * pair.number);
                if (pair.howMany >= 2 && found) {
                    ans = Math.max(ans, pair.number * first);
                } else if (pair.howMany >= 2) {
                    found = true;
                    first = pair.number;
                }
            }
            out.println(ans);
        }

        public class Pair implements Comparable<Pair> {
            private long number;
            private long howMany;

            public Pair(long number, long howMany) {
                this.number = number;
                this.howMany = howMany;
            }

            public int compareTo(Pair o) {
                if (o.number > number) return 1;
                if (o.number == number) return 0;
                return -1;
            }


            public String toString() {
                return "Pair{" +
                        "number=" + number +
                        ", howMany=" + howMany +
                        '}';
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