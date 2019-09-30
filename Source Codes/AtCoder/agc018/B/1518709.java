import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextIntArray0indexed(m);
            }

            int ans = n;
            boolean[] used = new boolean[m];
            for (int i = 0; i < m; i++) {
                int[] cnt = new int[m];
                for (int j = 0; j < n; j++) {
                    int idx = 0;
                    while (used[a[j][idx]]) idx++;

                    cnt[a[j][idx]]++;
                }

                int max = ArrayUtils.max(cnt);
                ans = Math.min(ans, max);

                int rmIdx = ArrayUtils.maxIndex(cnt);
                used[rmIdx] = true;
            }

            out.println(ans);
        }

    }

    static class ArrayUtils {
        public static int max(int[] array) {
            int ret = array[0];
            for (int i = 1; i < array.length; i++) {
                ret = Math.max(ret, array[i]);
            }

            return ret;
        }

        public static int maxIndex(int[] array) {
            int ret = 0;
            int max = array[0];
            for (int i = 1; i < array.length; i++) {
                if (max < array[i]) {
                    ret = i;
                    max = array[i];
                }
            }

            return ret;
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

        public int[] nextIntArray0indexed(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt() - 1;
            }
            return res;
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
}