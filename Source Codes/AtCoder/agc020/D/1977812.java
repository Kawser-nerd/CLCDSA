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
        TaskD solver = new TaskD();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt() - 1;
            int d = in.nextInt();
            String res;
            if (a >= b) {
                res = solveOne(a, b, c, d);
            } else {
                res = solveOne(b, a, a + b - d, a + b - c);
                StringBuilder bb = new StringBuilder();
                for (int i = res.length() - 1; i >= 0; --i) {
                    char ch = res.charAt(i);
                    bb.append(ch == 'A' ? 'B' : 'A');
                }
                res = bb.toString();
            }
            out.println(res);
        }

        private String solveOne(int a, int b, int c, int d) {
            String res;
            TaskD.Outputter outp = new TaskD.Outputter(c, d);
            int k = (a + b) / (b + 1);
            int whole = a / k;
            int zero = b + 1 - whole;
            if (a % k != 0) --zero;
            if (zero < 0) throw new RuntimeException();
            if (zero <= k) {
                outp.dump(whole, k, 1);
                if (a % k != 0) outp.dump(1, a % k, 1);
                outp.dump(zero, 0, 1);
            } else {
                int left = 0;
                int right = b / k + 1;
                while (right - left > 1) {
                    int mid = (left + right) / 2;
                    int remSlots = b - k * mid;
                    int remWhat = a - mid;
                    whole = remWhat / k;
                    zero = remSlots - whole;
                    if (remWhat % k != 0) --zero;
                    if (zero < k) {
                        right = mid;
                    } else {
                        left = mid;
                    }
                }
                int mid = right;
                int remSlots = b - k * mid;
                int remWhat = a - mid;
                whole = remWhat / k;
                outp.dump(whole, k, 1);
                zero = remSlots - whole;
                if (remWhat % k != 0) {
                    --zero;
                    outp.dump(1, remWhat % k, 1);
                }
                if (zero < 0 || zero >= k) throw new RuntimeException();
                outp.dump(zero, 0, 1);
                outp.dump(mid, 1, k);
            }
            res = outp.getRes();
            return res;
        }

        static class Outputter {
            int len;
            int pos;
            StringBuilder res = new StringBuilder();

            public Outputter(int c, int d) {
                this.pos = -c;
                this.len = d - c;
            }

            String getRes() {
                if (pos < len) throw new RuntimeException();
                return res.toString();
            }

            void dump(int reps, int a, int b) {
                if (pos >= len) return;
                if (a == 0 && b == 0) return;
                if (pos < 0) {
                    int skipWhole = Math.min(reps, (-pos) / (a + b));
                    reps -= skipWhole;
                    pos += skipWhole * (a + b);
                    if (reps == 0) return;
                    if (-pos < a) {
                        int extraas = Math.min(a + pos, len);
                        pos = 0;
                        for (int i = 0; i < extraas; ++i) {
                            res.append('A');
                            ++pos;
                        }
                    } else {
                        pos += a;
                    }
                    if (pos < 0) {
                        int extrabs = Math.min(b + pos, len);
                        if (extrabs < 0) throw new RuntimeException();
                        pos = 0;
                        for (int i = 0; i < extrabs; ++i) {
                            res.append('B');
                            ++pos;
                        }
                    } else {
                        int bs = Math.min(b, len - pos);
                        for (int i = 0; i < bs; ++i) {
                            res.append('B');
                            ++pos;
                        }
                    }
                    --reps;
                }
                for (int j = 0; j < reps && pos < len; ++j) {
                    int as = Math.min(a, len - pos);
                    for (int i = 0; i < as; ++i) {
                        res.append('A');
                        ++pos;
                    }
                    int bs = Math.min(b, len - pos);
                    for (int i = 0; i < bs; ++i) {
                        res.append('B');
                        ++pos;
                    }
                }
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