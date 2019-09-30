import java.io.*;
import java.util.*;

public class D_as_fast implements Runnable {
    final static int MOD = 10007;
    final static int[] inv = new int[MOD];
    int[] fac;

    class Rock implements Comparable<Rock> {
        int x;
        int y;

        Rock(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Rock o) {
            return
                    x == o.x ? y - o.y : x - o.x;
        }
    }

    int pow(int x, int y) {
        int r = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                r = (r * x) % MOD;
            }
            x = (x * x) % MOD;
            y /= 2;
        }
        return r;
    }

    int nfac(int n, int p) {
        int r = 0;
        while (n > 0) {
            r += n / p;
            n /= p;
        }
        return r;
    }

    int choose(int n, int k) {
        if (nfac(n, MOD) > nfac(k, MOD) + nfac(n - k, MOD)) {
            return 0;
        }
        int r = fac[n];
        r = (r * inv[fac[k]]) % MOD;
        r = (r * inv[fac[n - k]]) % MOD;
        return r;
    }

    int go(int h, int w) {
        int n = h + w;
        if (n % 3 != 0) {
            return 0;
        }
        n /= 3;
        h = h - n;
        w = w - n;
        if (h < 0 || w < 0) {
            return 0;
        }
        return choose(n, h);
    }

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("D-large.in"));
        PrintWriter out = new PrintWriter(new File("D-large.out"));

        for (int i = 1; i < MOD; i++) {
            inv[i] = pow(i, MOD - 2);
        }

        fac = new int[100000001];
        fac[0] = 1;
        for (int i = 1; i < fac.length; i++) {
            int j = i;
            while (j % MOD == 0) {
                j /= MOD;
            }
            j = j % MOD;
            fac[i] = (fac[i - 1] * j) % MOD;
        }

        System.err.println("Factorials done");

        int tn = in.nextInt();
        for (int test = 0; test < tn; test++) {
            int sh = in.nextInt() - 1;
            int sw = in.nextInt() - 1;
            int h = sh;
            int w = sw;
            int rn = in.nextInt();
            Rock[] r = new Rock[rn];
            for (int i = 0; i < rn; i++) {
                r[i] = new Rock(in.nextInt() - 1, in.nextInt() - 1);
            }
            Arrays.sort(r);

            int n = h + w;
            if (n % 3 != 0) {
                out.printf("Case #%d: %d\n", test + 1, 0);
                continue;
            }
            n /= 3;
            h = h - n;
            w = w - n;
            if (h < 0 || w < 0) {
                out.printf("Case #%d: %d\n", test + 1, 0);
                continue;
            }

            int ans = 0;
            for (int i = 0; i < 1 << rn; i++) {
                int x = 0;
                int y = 0;
                int c = 1;
                int p = 0;
                for (int j = 0; j < rn; j++) {
                    if ((i & (1 << j)) != 0) {
                        p++;
                        c = c * go(r[j].x - x, r[j].y - y) % MOD;
                        x = r[j].x;
                        y = r[j].y;
                    }
                }
                c = (c * go(sh - x, sw - y)) % MOD;
                if (p % 2 == 0) {
                    ans = (ans + c) % MOD;
                } else {
                    ans = ((ans - c) % MOD + MOD) % MOD;
                }
            }
            out.printf("Case #%d: %d\n", test + 1, ans);
            System.out.println(test);
        }

        in.close();
        out.close();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] s) {
        Locale.setDefault(Locale.US);
        new Thread(new D_as_fast()).start();
    }
}