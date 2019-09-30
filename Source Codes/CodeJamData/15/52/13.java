import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Math.*;

public class B {
    FastScanner in;
    PrintWriter out;


    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int n = in.nextInt();
            int k = in.nextInt();
            long[] sum = new long[n - k + 1];
            for (int i = 0; i < n - k + 1; i++) {
                sum[i] = in.nextInt();
            }
            long[] st = new long[k];
            long[] min = new long[k];
            long[] max = new long[k];
            for (int i = 0; i < k; i++) {
                int j = i;
                long cur = 0;
                while (j + k < n) {
                    cur += sum[j + 1] - sum[j];
                    j += k;
                    min[i] = Math.min(cur, min[i]);
                    max[i] = Math.max(cur, max[i]);
                }
                st[i] -= min[i];
                max[i] -= min[i];
                min[i] -= min[i];
            }

            long cursum = 0;
            for (int i = 0; i < k; i++) {
                cursum += st[i];
            }
            if (cursum < sum[0]) {
                long d = (sum[0] - cursum) / k;
                for (int i = 0; i < k; i++) {
                    st[i] += d;
                }
                cursum += k * d;
            } else if (cursum > sum[0]) {
                long d = (cursum - sum[0] + k - 1) / k;
                for (int i = 0; i < k; i++) {
                    st[i] -= d;
                }
                cursum -= k * d;
            }
            while (cursum < sum[0]) {
                long best = Long.MAX_VALUE;
                int bi = -1;
                for (int i = 0; i < k; i++) {
                    if (max[i] < best) {
                        best = max[i];
                        bi = i;
                    }
                }
                cursum++;
                max[bi]++;
            }

            long ans = 0;
            for (int i = 0; i < k; i++) {
                ans = Math.max(ans, max[i]);
            }

            out("Case #%d: %d\n", test, ans);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-large.in"));
            out = new PrintWriter(new File("B-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new B().run();
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}