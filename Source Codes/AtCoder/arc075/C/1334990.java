import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author vikas.k
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int[] BIT;
        private static final int MAXN = 200005;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int N = in.nextInt();
            int K = in.nextInt();

            Long[] sum = new Long[N + 1];
            sum[0] = 0L;

            for (int i = 1; i <= N; i++) {
                sum[i] = in.nextLong();
                sum[i] -= K;
                sum[i] += sum[i - 1];
            }

            HashSet<Long> hash = new HashSet<>(Arrays.asList(sum));
            List<Long> mean = new ArrayList<>();
            mean.addAll(hash);

            Collections.sort(mean);

            BIT = new int[MAXN];
            long ans = 0;
            for (int i = 0; i <= N; i++) {
                int pos = Collections.binarySearch(mean, sum[i]);
                ans += get(pos + 1);
                //out.print(ans + " " + pos);
                add(pos + 1, 1);
            }
            out.println(ans);
        }

        private void add(int k, int v) {
            while (k < MAXN) {
                BIT[k] += v;
                k += k & -k;
            }
        }

        private int get(int k) {
            int ans = 0;
            while (k > 0) {
                ans += BIT[k];
                k -= k & -k;
            }
            return ans;
        }

    }

    static class FastScanner {
        private BufferedReader bufferedReader;
        private StringTokenizer stringTokenizer;

        public FastScanner(InputStream inputStream) {
            bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() {
            if (stringTokenizer == null || !stringTokenizer.hasMoreElements()) {
                try {
                    stringTokenizer = new StringTokenizer(bufferedReader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return stringTokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}