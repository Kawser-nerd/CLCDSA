import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();
            String t = in.next();
            TaskE.Sequence seq1 = parse(s);
            TaskE.Sequence seq2 = parse(t);
            int parity = (s.charAt(0) == t.charAt(0) ? 0 : 1);
            long res = Long.MAX_VALUE;
            for (int leftExplosions = -seq2.twos.length - 1; leftExplosions <= seq1.twos.length + 1; ++leftExplosions) {
                if ((leftExplosions + parity) % 2 != 0) continue;
                int rightExplosions = seq1.twos.length - seq2.twos.length - leftExplosions;
                long cur = 0;
                int remains = seq1.twos.length;
                int offset1 = 0;
                int offset2 = 0;
                int delta = 0;
                if (leftExplosions > 0) {
                    remains -= leftExplosions;
                    offset1 += leftExplosions;
                    delta += leftExplosions;
                    for (int i = 0; i < leftExplosions; ++i) {
                        if (i < seq1.twos.length) {
                            cur += seq1.twos[i] + (i + 1);
                        } else {
                            cur += 1 + (n - 2);
                        }
                    }
                } else if (leftExplosions < 0) {
                    offset2 += -leftExplosions;
                    delta -= -leftExplosions;
                    for (int i = 0; i < -leftExplosions; ++i) {
                        if (i < seq2.twos.length) {
                            cur += seq2.twos[i] + (i + 1);
                        } else {
                            cur += 1 + (n - 2);
                        }
                    }
                }
                if (rightExplosions > 0) {
                    remains -= rightExplosions;
                    for (int i = 0; i < rightExplosions; ++i) {
                        if (i < seq1.twos.length) {
                            cur += (seq1.len - 1 - seq1.twos[seq1.twos.length - 1 - i]) + (i + 1);
                        } else {
                            cur += 1;
                        }
                    }
                } else if (rightExplosions < 0) {
                    for (int i = 0; i < -rightExplosions; ++i) {
                        if (i < seq2.twos.length) {
                            cur += (seq2.len - 1 - seq2.twos[seq2.twos.length - 1 - i]) + (i + 1);
                        } else {
                            cur += 1;
                        }
                    }
                }
                if (remains > 0) {
                    for (int i = 0; i < remains; ++i) {
                        cur += Math.abs(seq2.twos[offset2 + i] - seq1.twos[offset1 + i] - delta);
                    }
                }
                res = Math.min(res, cur);
            }
            out.println(res);
        }

        private TaskE.Sequence parse(String s) {
            int[] res = new int[s.length()];
            int ptr = 0;
            int pos = 0;
            int start = 0;
            for (int i = 1; i <= s.length(); ++i) {
                if (i == s.length() || s.charAt(i) != s.charAt(i - 1)) {
                    if (i - start == 2) res[ptr++] = pos;
                    ++pos;
                    start = i;
                }
            }
            return new TaskE.Sequence(Arrays.copyOf(res, ptr), pos);
        }

        static class Sequence {
            int[] twos;
            int len;

            public Sequence(int[] twos, int len) {
                this.twos = twos;
                this.len = len;
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