import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("chocolate.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("chocolate.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Chocolate solver = new Chocolate();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class Chocolate {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int p = in.nextInt();
            int[] g = new int[n];
            for (int i = 0; i < n; i++) {
                g[i] = in.nextInt();
            }
            int[] cnt = new int[p];
            for (int i = 0; i < n; i++) {
                ++cnt[g[i] % p];
            }
            Map<Chocolate.State, Integer> cache = new HashMap<>();
            for (int i = 0; i < p; i++) {
                cache.put(new Chocolate.State(new int[p], i), 0);
            }
            int answer = solve(new Chocolate.State(cnt, 0), cache);
            out.println("Case #" + testNumber + ": " + (n - answer));
        }

        int solve(Chocolate.State state, Map<Chocolate.State, Integer> cache) {
            Integer answer = cache.get(state);
            if (answer != null) {
                return answer;
            }
            int cost = (state.leftover == 0 ? 0 : 1);
            int best = Integer.MAX_VALUE;
            for (int i = 0; i < state.cnt.length; i++) {
                if (state.cnt[i] == 0) {
                    continue;
                }
                int newLeftover = (i + state.leftover);
                if (newLeftover >= state.cnt.length) {
                    newLeftover -= state.cnt.length;
                }
                int oldLeftover = state.leftover;
                --state.cnt[i];
                state.leftover = newLeftover;
                int cur = solve(state, cache) + cost;
                ++state.cnt[i];
                state.leftover = oldLeftover;
                best = Math.min(best, cur);
            }
            if (best == Integer.MAX_VALUE) {
                throw new AssertionError();
            }
            Chocolate.State copy = new Chocolate.State(state.cnt.clone(), state.leftover);
            cache.put(copy, best);
            return best;
        }

        static class State {
            int[] cnt;
            int leftover;

            public State(int[] cnt, int leftover) {
                this.cnt = cnt;
                this.leftover = leftover;
            }


            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                Chocolate.State state = (Chocolate.State) o;
                if (leftover != state.leftover) return false;
                return Arrays.equals(cnt, state.cnt);
            }


            public int hashCode() {
                int result = Arrays.hashCode(cnt);
                result = 31 * result + leftover;
                return result;
            }

        }

    }

    static class InputReader {
        public BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            return nextToken();
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

    }
}

