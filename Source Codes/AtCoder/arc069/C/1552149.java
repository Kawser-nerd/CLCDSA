import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
            int[] a = in.nextIntArray(n);

            Pair[] pairs = new Pair[n];
            List<Integer> list = new ArrayList<>();
            int max = 0;
            for (int i = 0; i < n; i++) {
                if (max < a[i]) {
                    list.add(i);
                    max = a[i];
                }
                pairs[i] = new Pair(i, a[i]);
            }
            Arrays.sort(pairs);

            long[] ans = new long[n];
            int idx = 0;
            long sum = 0;
            max = 0;
            for (int i = 0; i < n; i++) {
                if (idx < list.size() && pairs[i].x == list.get(idx)) {
                    idx++;
                    ans[pairs[i].x] = sum + (long) (n - i) * (pairs[i].y - max);
                    max = pairs[i].y;
                    sum = 0;
                } else {
                    sum += a[pairs[i].x] - max;
                }
            }

            for (int i = 0; i < n; i++) {
                out.println(ans[i]);
            }
        }

        public class Pair implements Comparable<Pair> {
            int x;
            int y;

            Pair(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public int compareTo(Pair p) {
                return y - p.y;
            }

        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public int[] nextIntArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
}