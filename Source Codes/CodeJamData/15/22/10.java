import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Math.*;

public class B {
    FastScanner in;
    PrintWriter out;

    int solveStupid(int r, int c, int n) {
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, -1, 0, 1};

        boolean[][] a = new boolean[r][c];
        int best = Integer.MAX_VALUE;
        for (int mask = 0; mask < (1 << (r * c)); mask++) {
            if (Integer.bitCount(mask) == n) {
                int k = 0;
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        a[i][j] = (mask & (1 << k)) != 0;
                        k++;
                    }
                }

                int cnt = 0;
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        for (int d = 0; d < 4; d++) {
                            int ni = i + dx[d];
                            int nj = j + dy[d];
                            if (0 <= ni && ni < r && 0 <= nj && nj < c) {
                                if (a[i][j] && a[ni][nj]) {
                                    cnt++;
                                }
                            }
                        }
                    }
                }
                if (cnt < best) {
                    best = cnt;
                }
            }
        }
        return best / 2;
    }

    int solveSmart(int r, int c, int n) {
        if (r > c) {
            int t = r;
            r = c;
            c = t;
        }
        if (r == 1) {
            boolean[] a = new boolean[c];
            int p = 0;
            int delta = 2;
            for (int i = 0; i < n; i++) {
                a[p] = true;
                p += delta;
                if (p >= c) {
                    p = c - 1;
                    if (a[p]) {
                        p--;
                    }
                    delta = -2;
                }
            }
            int ans = 0;
            for (int i = 0; i < c - 1; i++) {
                if (a[i] && a[i + 1]) {
                    ans++;
                }
            }
            return ans;
        }

        if (r == 2) {
            int ans = 0;
            n -= c;
            if (n > 0) {
                ans += 2;
                n--;
            }
            if (n > 0) {
                ans += 2;
                n--;
            }
            if (n > 0) {
                ans += n * 3;
            }
            return ans;
        }

        int ans = (r - 1) * c + (c - 1) * r;
        n = r * c - n;
        int can2, can3, can4;
        if (r % 2 == 0 || c % 2 == 0) {
            can4 = (r - 2) * (c - 2) / 2;
            can3 = (r - 2) / 2 + (c - 2) / 2 + (r - 1) / 2 + (c - 1) / 2;
            can2 = 2;
        } else {
            can4 = ((r - 2) * (c - 2) + 1) / 2;
            can3 = (r - 2) / 2 + (c - 2) / 2 + (r - 2) / 2 + (c - 2) / 2;
            can2 = 4;
            if (n > can4 + can3) {
                can4 = (r - 2) * (c - 2) / 2;
                can3 = (r - 1) / 2 + (c - 1) / 2 + (r - 1) / 2 + (c - 1) / 2;
                can2 = 0;
            }
        }

        while (n > 0 && can4 > 0) {
            n--;
            can4--;
            ans -= 4;
        }
        while (n > 0 && can3 > 0) {
            n--;
            can3--;
            ans -= 3;
        }
        while (n > 0 && can2 > 0) {
            n--;
            can2--;
            ans -= 2;
        }
        return ans;
    }

    public void solve() throws IOException {
        if (false) {
            for (int r = 1; r <= 4; r++) {
                for (int c = 2; c <= 8 && r * c <= 25; c++) {
                    for (int n = 0; n <= r * c; n++) {
                        int ans = solveStupid(r, c, n);
                        int smart = solveSmart(r, c, n);
                        if (ans != smart) {
                            System.out.println("!!! " + r + " " + c + " " + n + " " + ans + " " + smart);
                        }
                    }
                }
            }
        }

        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int r = in.nextInt();
            int c = in.nextInt();
            int n = in.nextInt();

//            int ans = solveStupid(r, c, n);
            int ans = solveSmart(r, c, n);
//            if (ans != smart) {
//                System.out.println("!!! " + r + " " + c + " " + n + " " + ans + " " + smart);
//            }
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