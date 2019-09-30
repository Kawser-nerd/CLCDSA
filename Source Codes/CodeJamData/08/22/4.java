import java.io.*;
import java.util.*;

public class B_as_large implements Runnable {
    class DSU {
        int[] p;
        int[] r;

        DSU(int n) {
            p = new int[n];
            r = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
        }

        int get(int x) {
            if (p[x] != x) {
                p[x] = get(p[x]);
            }
            return p[x];
        }

        void union(int x, int y) {
            x = get(x);
            y = get(y);
            if (x == y) {
                return;
            }

            if (r[x] == r[y]) {
                r[x]++;
            }

            if (r[x] > r[y]) {
                p[y] = x;
            } else {
                p[x] = y;
            }
        }

        int cnt() {
            int r = 0;
            for (int i = 0; i < p.length; i++) {
                if (p[i] == i) {
                    r++;
                }
            }
            return r;
        }
    }

    long gcd(long x, long y) {
        while (y != 0) {
            long t = x % y;
            x = y;
            y = t;
        }
        return x;
    }

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("B-large.in"));
        PrintWriter out = new PrintWriter(new File("B-large.out"));

        int tn = in.nextInt();

        int n = 1000001;
        long[] primes = new long[n];
        int pn = 0;
        for (int i = 2; i <= n; i++) {
            boolean isp = true;
            for (int j = 0; j < pn && primes[j] * primes[j] <= i; j++) {
                if (i % primes[j] == 0) {
                    isp = false;
                    break;
                }
            }
            if (isp) {
                primes[pn++] = i;
            }
        }

        for (int test = 0; test < tn; test++) {
            long a = in.nextLong();
            long b = in.nextLong();
            long p = in.nextLong();

            int lp = -1;
            int rp = pn;
            while (lp < rp - 1) {
                int mp = (lp + rp) / 2;
                if (primes[mp] < p) {
                    lp = mp;
                } else {
                    rp = mp;
                }
            }

            int sp = rp;

            lp = -1;
            rp = pn;
            while (lp < rp - 1) {
                int mp = (lp + rp) / 2;
                if (primes[mp] < b - a + 1) {
                    lp = mp;
                } else {
                    rp = mp;
                }
            }

            int fp = rp;

            DSU dsu = new DSU((int) (b - a + 1));
            for (int i = sp; i < fp; i++) {
                long st = a / primes[i] * primes[i];
                while (st < a) {
                    st += primes[i];
                }

                while (st + primes[i] <= b) {
                    dsu.union((int)(st - a), (int)(st - a + primes[i]));
                    st += primes[i];
                }
            }

            out.printf("Case #%d: %d\n", test + 1, dsu.cnt());
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
        new Thread(new B_as_large()).start();
    }
}