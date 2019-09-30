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
            int p = in.nextInt();
            int q = in.nextInt();
            int n = in.nextInt();
            int[] h = new int[n];
            int[] g = new int[n];
            for (int i = 0; i < n; i++) {
                h[i] = in.nextInt();
                g[i] = in.nextInt();
            }

            int[][][] d = new int[2][n + 1][10 * n + 1];
            for (int k = 0; k < 2; k++) {
                for (int[] z : d[k]) {
                    Arrays.fill(z, -1);
                }
            }
            d[0][0][0] = 0;
            for (int i = 0; i < n; i++) {
                for (int t = 0; t < 2; t++) {
                    for (int j = 0; j < d[t][i].length; j++) {
                        if (d[t][i][j] >= 0) {
                            // let it go
                            int ns = (h[i] + q - 1) / q - t;
                            if (d[t][i][j] > d[0][i + 1][j + ns]) {
                                d[0][i + 1][j + ns] = d[t][i][j];
                            }
                            // kill it
                            prehits:
                            for (int k = 0; k <= j; k++) {
                                int hp = h[i] - k * p;
                                if (hp <= 0) {
                                    if (d[t][i][j] + g[i] > d[t][i + 1][j - k]) {
                                        d[t][i + 1][j - k] = d[t][i][j] + g[i];
                                    }
                                    break;
                                }
                                skipit:
                                for (int skip = t; skip <= 10; skip++) {
                                    int left = j - k;
                                    hp = h[i] - k * p;
                                    if (hp <= q * skip) {
                                        continue prehits;
                                    }
                                    hp -= q * skip;
                                    left += skip - t;
                                    while (hp > 0) {
                                        if (hp <= p) {
                                            if (d[t][i][j] + g[i] > d[1][i + 1][left]) {
                                                d[1][i + 1][left] = d[t][i][j] + g[i];
                                            }
                                        }
                                        hp -= p;
                                        if (hp <= q) {
                                            continue skipit;
                                        }
                                        hp -= q;
                                    }
                                }
                            }
                        }
                    }
                }
//                System.out.println(Arrays.toString(d[0][i + 1]));
//                System.out.println(Arrays.toString(d[1][i + 1]));
//                System.out.println();
            }


            int ans = 0;
            for (int j = 0; j < d[0][n].length; j++) {
                if (d[0][n][j] > ans) {
                    ans = d[0][n][j];
                }
                if (d[1][n][j] > ans) {
                    ans = d[1][n][j];
                }
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