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
            int n = in.nextInt();
            long s = in.nextLong();
            long[] x = new long[n];
            long[] p = new long[n];
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextLong();
                p[i] = in.nextLong();
            }
            int pos = -(Arrays.binarySearch(x, s) + 1);
            if (pos == 0) {
                out.println(x[n - 1] - s);
            } else if (pos == n) {
                out.println(s - x[0]);
            } else {
                int left = 0;
                int right = n - 1;
                boolean leftWins = false;
                long res = x[n - 1] - x[0];
                long people = p[0] + p[n - 1];
                long lastTurn;
                if (p[left] >= p[right]) {
                    leftWins = true;
                    lastTurn = x[left];
                } else {
                    lastTurn = x[right];
                }
                while (true) {
                    if (leftWins) {
                        if (right - 1 >= pos) {
                            if (p[right - 1] > people) {
                                leftWins = false;
                                res += x[right - 1] - lastTurn;
                                lastTurn = x[right - 1];
                            }
                            people += p[right - 1];
                            --right;
                        } else {
                            res += s - lastTurn;
                            break;
                        }
                    } else {
                        if (left + 1 < pos) {
                            if (p[left + 1] >= people) {
                                leftWins = true;
                                res += lastTurn - x[left + 1];
                                lastTurn = x[left + 1];
                            }
                            people += p[left + 1];
                            ++left;
                        } else {
                            res += lastTurn - s;
                            break;
                        }
                    }
                }
                out.println(res);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}