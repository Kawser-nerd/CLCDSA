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
            int n = in.nextInt();
            Map<Long, Long> map = new HashMap<>();
            for (int i = 0; i < n; ++i) {
                long x = in.nextInt();
                if (!map.containsKey(x)) {
                    map.put(x, 1L);
                } else {
                    map.put(x, map.get(x) + 1L);
                }
            }
            List<Pair> list = new ArrayList<>();
            for (Long key : map.keySet()) {
                list.add(new Pair(key, map.get(key)));
            }
            Collections.sort(list);
            boolean got = false;
            boolean have = false;
            long[] res = new long[2];
            res[1] = 1L;
            for (Pair pair : list) {
                if (pair.y < 2) continue;
                have = true;
                if (pair.y >= 4) {
                    res[0] = Math.max(res[0], pair.x * pair.x);
                }
                res[1] *= pair.x;
                if (got) break;
                got = true;

            }
            out.println(have ? Math.max(res[0], res[1]) : Math.max(res[0], 0));
        }

        class Pair implements Comparable<Pair> {
            long x;
            long y;

            public Pair(long x, long y) {
                this.x = x;
                this.y = y;
            }


            public int compareTo(Pair o) {
                if (this.x > o.x) return -1;
                if (this.x < o.x) return 1;
                return 0;
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