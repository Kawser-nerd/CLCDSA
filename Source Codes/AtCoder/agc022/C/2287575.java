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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n), b = in.nextIntArray(n);

            boolean[][][] dp = new boolean[51][51][51];
            for (int i = 0; i <= 50; i++) {
                dp[i][i][0] = true;
            }
            for (int mod = 1; mod <= 50; mod++) {
                for (int i = 0; i <= 50; i++) {
                    for (int j = 0; j <= i; j++) {
                        dp[i][j][mod] = dp[i][j][mod - 1] | dp[i % mod][j][mod - 1];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (dp[a[i]][b[i]][50] == false) {
                    out.println(-1);
                    return;
                }
            }
            long result = 0;
            boolean[][] can = new boolean[n][51];
            for (int i = 0; i < n; i++) {
                can[i][a[i]] = true;
            }
            for (int bit = 50; bit >= 1; bit--) {
                boolean ok = true;
                for (int i = 0; i < n; i++) {
                    boolean any = false;
                    for (int j = 0; j <= 50; j++) {
                        if (can[i][j] && dp[j][b[i]][bit - 1]) {
                            any = true;
                        }
                    }
                    if (!any) {
                        ok = false;
                    }
                }
                if (ok) {
                    continue;
                }
                result += 1L << bit;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j <= 50; j++) {
                        if (can[i][j]) {
                            can[i][j % bit] = true;
                        }
                    }
                }
            }
            out.println(result);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }
}