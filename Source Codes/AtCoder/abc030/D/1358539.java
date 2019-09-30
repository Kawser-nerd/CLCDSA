import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private void solve(Scanner sc) {
        int N = sc.nextInt();
        int a = sc.nextInt();
        BigInteger k = new BigInteger(sc.next());
        int[] b = new int[N];
        for (int i = 0; i < N; ++i) {
            b[i] = sc.nextInt();
        }

        int aa = a;
        int[] cnt = new int[N];
        do {
            ++cnt[aa - 1];
            aa = b[aa - 1];
        } while (cnt[aa - 1] < 2);

        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < N; ++i) {
            if (cnt[i] == 1) {
                ++cnt1;
            } else if (cnt[i] == 2) {
                ++cnt2;
            }
        }

        k = k.subtract(BigInteger.valueOf(cnt1)).remainder(BigInteger.valueOf(cnt2));

        int kk = k.intValue() + cnt1;
        aa = a;
        while (kk > 0) {
            aa = b[aa - 1];
            --kk;
        }

        _out.println(aa);
    }
    private static BigInteger C(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        for (long i = r; i > 1; --i) {
            res = res.divide(BigInteger.valueOf(i));
        }
        return res;
    }
    private static BigInteger P(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    /*
     * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
     * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
     */
    public static void main(String[] args) {
        long S = System.currentTimeMillis();

        Scanner sc = new Scanner(System.in);
        new Main().solve(sc);
        _out.flush();

        long G = System.currentTimeMillis();
        if (elapsed) {
            _err.println((G - S) + "ms");
        }
        _err.flush();
    }
}