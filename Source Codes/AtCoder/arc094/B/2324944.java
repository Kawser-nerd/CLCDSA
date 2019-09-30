import java.io.*;
import java.util.*;
 
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
 
            int N = in.nextInt();
            for (int i = 0; i < N; i++) {
                long A = in.nextLong();
                long B = in.nextLong();
 
                long a = Math.min(A, B);
                long b = Math.max(A, B);
 
                long ans = 2L * (a - 1) + przedzial(a, b);
 
                out.println(ans);
            }
        }
 
        private long przedzial(long a, long b) {
            if (a == b || a + 1 == b) {
                return 0;
            }
 
            return 1L + szukaj(a + 1, b - 2, a * b);
        }
 
        private long szukaj(long a, long b, long LIMIT) {
            if (a > b) return 0;
            if (a == b) {
                return a * b < LIMIT ? 1 : 0;
            }
            long lo = a, hi = b;
            while (lo + 1 < hi) {
                long m = lo + (hi - lo) / 2;
                if (m * m >= LIMIT) {
                    hi = m;
                } else {
                    lo = m;
                }
            }
            long ans1 = 1 + 2L * (lo - 1 - a + 1);
            long ans2 = 0;
            if (lo * (lo + 1) < LIMIT) {
                ans2 = 2L * (lo - a + 1);
            }
            return Math.max(ans1, ans2);
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
        public int nextInt() {
            return Integer.parseInt(next());
        }
    }
}