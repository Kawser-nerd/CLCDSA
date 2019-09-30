import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

class DEasy implements Runnable {
    final long MOD = 1000000007;

    long c;
    long pal;
    long next;
    boolean odd;
    long savec;

    void nextpal() {
        if (c + 1 == next) {
            if (odd) {
                odd = false;
                c = savec;
            } else {
                odd = true;
                next *= 10;
                c++;
                savec = c;
            }
        } else {
            c++;
        }
        pal = c * next;
        long mul = next / 10;
        if (odd) {
            pal /= 10;
            mul /= 10;
        }
        long cc = c;
        if (odd) {
            cc /= 10;
        }
        while (cc > 0) {
            pal += mul * (cc % 10);
            cc /= 10;
            mul /= 10;
        }
    }

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("D-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new File("D-small-attempt0.out"));

        int testn = in.nextInt();
        for (int test = 0; test < testn; test++) {
            long l = in.nextLong();
            long r = in.nextLong();

            c = 0;
            pal = 0;
            next = 10;
            odd = true;
            savec = 1;

            while (pal < l) {
                nextpal();
            }
            long neven = 1;
            long nodd = 0;
            long cnt = 0;
            long ans = 0;
            long prev = l;
            while (pal <= r) {
                long d = (pal - 1 - prev) * (pal - prev) / 2;
                d = d % MOD;
                if (cnt % 2 == 0) {
                    ans = (ans + neven * (pal - prev) + d) % MOD;
                    neven = (neven + pal - prev) % MOD;
                } else {
                    ans = (ans + nodd * (pal - prev) + d) % MOD;
                    nodd = (nodd + pal - prev) % MOD;
                }
                cnt++;
                prev = pal;
                nextpal();
            }
            pal = r + 1;
            long d = (pal - 1 - prev) * (pal - prev) / 2;
            d = d % MOD;
            if (cnt % 2 == 0) {
                ans = (ans + neven * (pal - prev) + d) % MOD;
            } else {
                ans = (ans + nodd * (pal - prev) + d) % MOD;
            }

            System.out.println("Case #" + (test + 1) + ": " + ans);
            out.println("Case #" + (test + 1) + ": " + ans);
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            throw new AssertionError();
        }
    }

    public static void main(String[] args) {
        new Thread(new DEasy()).start();
    }
}