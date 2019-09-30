import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class C_as implements Runnable {
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("C-large.in"));
        PrintWriter out = new PrintWriter(new File("C-large.out"));

        long[] p = new long[100000];
        int MAX = 1000000;
        int c = 2;
        int pn = 0;
        while (c <= MAX) {
            boolean isPrime = true;
            for (int i = 0; i < pn && p[i] * p[i] <= c; i++) {
                if (c % p[i] == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                p[pn++] = c;
            }
            c++;
        }

        long time = System.currentTimeMillis();
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            long n = in.nextLong();
            int ans = 1;
            if (n == 1) {
                ans = 0;
            }
            for (int i = 0; p[i] * p[i] <= n && i < pn; i++) {
                int j = 0;
                long k = n;
                while (k >= p[i]) {
                    k /= p[i];
                    j++;
                }
                ans += j - 1;
            }
            out.println("Case #" + test + ": " + ans);
        }

        in.close();
        out.close();

        System.err.println(System.currentTimeMillis() - time);
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            System.exit(1);
        }
    }

    public static void main(String[] s) {
        Locale.setDefault(Locale.US);
        new Thread(new C_as()).start();
    }
}