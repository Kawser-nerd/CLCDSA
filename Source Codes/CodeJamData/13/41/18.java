import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class GCJA {

    static final long mod = 1000002013L;

    static long f(long n, long d) {
        return (2 * n - d + 1) * d / 2;
    }

    static class Pos implements Comparable<Pos> {
        long x, c;

        Pos(long x, long c) {
            this.x = x;
            this.c = c;
        }

        @Override
        public int compareTo(Pos o) {
            return Long.compare(x, o.x);
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        long n = in.nextLong();
        int m = in.nextInt();
        HashMap<Long, Long> counts = new HashMap<Long, Long>();
        long ans1 = 0;
        for (int i = 0; i < m; ++i) {
            long u = in.nextLong();
            long v = in.nextLong();
            long c = in.nextLong();
            ans1 = (ans1 + (f(n, v - u) % mod) * c) % mod;
            inc(counts, u, c);
            inc(counts, v, -c);
        }
        Pos[] poses = new Pos[counts.size()];
        int ps = 0;
        for (long x : counts.keySet()) {
            poses[ps++] = new Pos(x, counts.get(x));
        }
        Pos[] stack = new Pos[poses.length];
        int stackp = 0;
        Arrays.sort(poses);
        long ans = 0;
        for (Pos pos : poses) {
            if (pos.c > 0) {
                stack[stackp++] = pos;
            } else {
                long need = -pos.c;
                while (need > 0) {
                    if (stackp == 0) {
                        throw new AssertionError();
                    }
                    long d = Math.min(need, stack[stackp - 1].c);
                    ans = (ans + (f(n, pos.x - stack[stackp - 1].x) % mod) * d) % mod;
                    need -= d;
                    stack[stackp - 1].c -= d;
                    if (stack[stackp - 1].c == 0) {
                        --stackp;
                    }
                }
            }
        }
        out.println((ans1 + mod - ans) % mod);
    }

    private static void inc(HashMap<Long, Long> counts, long x, long c) {
        if (!counts.containsKey(x)) {
            counts.put(x, c);
        } else {
            counts.put(x, counts.get(x) + c);
        }
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        Input in = new Input(new BufferedReader(new InputStreamReader(System.in)));
        int tests = in.nextInt();
        for (int i = 0; i < tests; ++i) {
            out.print("Case #" + (i + 1) + ": ");
            solve(in, out);
            out.flush();
        }
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringTokenizer st;

        public Input(BufferedReader in) {
            this.in = in;
            eat("");
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public void eat(String str) {
            st = new StringTokenizer(str);
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null) {
                    return null;
                }
                eat(line);
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}
