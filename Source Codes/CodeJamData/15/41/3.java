import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int r = in.nextInt();
            int c = in.nextInt();
            int[][] d = new int[r + 2][c + 2];
            for (int[] z : d) {
                Arrays.fill(z, -1);
            }
            for (int i = 0; i < r; i++) {
                String s = in.next();
                for (int j = 0; j < c; j++) {
                    d[i + 1][j + 1] = "^>v<".indexOf(s.charAt(j));
                }
            }

            int[] dx = {-1, 0, 1, 0};
            int[] dy = {0, 1, 0, -1};

            r += 2;
            c += 2;
            int ans = 0;
            boolean can = true;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (d[i][j] != -1) {
                        int min = 2;
                        for (int q = 0; q < 4; q++) {
                            int x = i + dx[q];
                            int y = j + dy[q];
                            while (0 <= x && x < r && 0 <= y && y < c && d[x][y] == -1) {
                                x += dx[q];
                                y += dy[q];
                            }
                            if (0 <= x && x < r && 0 <= y && y < c) {
                                min = Math.min(min, q == d[i][j] ? 0 : 1);
                            }
                        }
                        if (min == 2) {
                            can = false;
                        }
                        ans += min;
                    }
                }
            }
            if (can) {
                out("Case #%d: %d\n", test, ans);
            } else {
                out("Case #%d: IMPOSSIBLE\n", test);
            }
        }
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    public void run() {
        try {
            in = new FastScanner(new File("A-large.in"));
            out = new PrintWriter(new File("A-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new A().run();
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