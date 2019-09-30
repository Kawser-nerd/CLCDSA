import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int testNo = in.nextInt();

        for (int test = 1; test <= testNo; test++) {
            int ac = in.nextInt();
            int aj = in.nextInt();

            boolean[][] can = new boolean[2][24 * 60];
            for (boolean[] z : can) {
                Arrays.fill(z, true);
            }

            for (int i = 0; i < ac; i++) {
                int f = in.nextInt();
                int t = in.nextInt();
                for (int j = f; j < t; j++) {
                    can[0][j] = false;
                }
            }
            for (int i = 0; i < aj; i++) {
                int f = in.nextInt();
                int t = in.nextInt();
                for (int j = f; j < t; j++) {
                    can[1][j] = false;
                }
            }

            int ans = Integer.MAX_VALUE;
            for (int who = 0; who < 2; who++) {
                int[][][] a = new int[24 * 60 + 1][721][2];
                for (int[][] z : a) {
                    for (int[] y : z) {
                        Arrays.fill(y, Integer.MAX_VALUE);
                    }
                }

                a[0][0][who] = 0;
                for (int h = 0; h < 24 * 60; h++) {
                    for (int t = 0; t <= 720; t++) {
                        for (int w = 0; w < 2; w++) {
                            if (a[h][t][w] != Integer.MAX_VALUE) {
                                // keep baby
                                if (can[w][h] && t + 1 <= 720) {
                                    a[h + 1][t + 1][w] = Math.min(a[h + 1][t + 1][w], a[h][t][w]);
                                }
                                // move baby
                                int ot = h - t;
                                if (can[1 - w][h] && ot + 1 <= 720) {
                                    a[h + 1][ot + 1][1 - w] = Math.min(a[h + 1][ot + 1][1 - w], a[h][t][w] + 1);
                                }
                            }
                        }
                    }
                }
                ans = Math.min(ans, a[24 * 60][720][who]);
            }
            out.println("Case #" + test + ": " + ans);
            System.out.println("Case #" + test + ": " + ans);
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
        Locale.setDefault(Locale.US);
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