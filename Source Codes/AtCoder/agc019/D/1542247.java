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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String a = in.next();
            String b = in.next();
            String bbb = b + b + b;
            int[] prev1 = new int[bbb.length()];
            for (int i = 0; i < bbb.length(); ++i) {
                if (bbb.charAt(i) == '1') prev1[i] = i;
                else if (i > 0) prev1[i] = prev1[i - 1];
                else prev1[i] = -1;
            }
            int[] next1 = new int[bbb.length()];
            for (int i = bbb.length() - 1; i >= 0; --i) {
                if (bbb.charAt(i) == '1') next1[i] = i;
                else if (i + 1 < bbb.length()) next1[i] = next1[i + 1];
                else next1[i] = bbb.length();
            }
            long res = Long.MAX_VALUE;
            int[] toRight = new int[a.length()];
            int[] nextByLeft = new int[a.length()];
            int[] firstByLeft = new int[a.length()];
            outer:
            for (int rot = 0; rot < a.length(); ++rot) {
                Arrays.fill(firstByLeft, -1);
                int n01 = 0;
                int n10 = 0;
                for (int i = 0; i < a.length(); ++i) {
                    char c1 = a.charAt(i);
                    char c2 = b.charAt((i + rot) % a.length());
                    if (c1 == c2) continue;
                    if (c1 == '0') {
                        ++n01;
                        continue;
                    }
                    ++n10;
                    if (prev1[i + a.length()] < 0) {
                        continue outer;
                    }
                    int left = i + a.length() - prev1[i + a.length()];
                    int right = next1[i + a.length()] - (i + a.length());
                    toRight[i] = right;
                    nextByLeft[i] = firstByLeft[left];
                    firstByLeft[left] = i;
                }
                res = Math.min(res, a.length() - 1 + cdist(a.length(), 1, rot) + n01 + n10);
                res = Math.min(res, a.length() - 1 + cdist(a.length(), -1, rot) + n01 + n10);
                int rightmost = 0;
                for (int leftmost = a.length() - 1; leftmost >= 0; --leftmost) {
                    res = Math.min(res, cdist(a.length(), 0, -leftmost) + (rightmost + leftmost) + cdist(a.length(), rightmost, rot) + n01 + n10);
                    res = Math.min(res, cdist(a.length(), 0, rightmost) + (rightmost + leftmost) + cdist(a.length(), -leftmost, rot) + n01 + n10);
                    {
                        int c = firstByLeft[leftmost];
                        while (c >= 0) {
                            rightmost = Math.max(rightmost, toRight[c]);
                            c = nextByLeft[c];
                        }
                    }
                }
            }
            if (res == Long.MAX_VALUE) res = -1;
            out.println(res);
        }

        private int cdist(int length, int p, int q) {
            if (p < 0) p += length;
            if (q < 0) q += length;
            return Math.min(Math.abs(p - q), length - Math.abs(p - q));
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

    }
}