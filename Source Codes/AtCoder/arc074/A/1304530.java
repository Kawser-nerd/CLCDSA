import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private void solve(Scanner sc) {
        int H = sc.nextInt();
        int W = sc.nextInt();

        _out.println(Math.min(calc(H, W), calc(W, H)));
    }
    private long calc(int h, int w) {
        long res = Long.MAX_VALUE;

        for (int i = h / 3; i <= h / 2; ++i) {
            long a1 = i * w;
            long a2 = ((h - i) / 2) * w;
            long a3 = (h - i - ((h - i) / 2)) * w;

            long smax = Math.max(a1, Math.max(a2, a3));
            long smin = Math.min(a1, Math.min(a2, a3));

            res = Math.min(res, smax - smin);
        }

        for (int i = h / 3; i <= h / 2; ++i) {
            long a1 = i * w;
            long a2 = (h - i) * (w / 2);
            long a3 = (h - i) * (w - (w / 2));

            long smax = Math.max(a1, Math.max(a2, a3));
            long smin = Math.min(a1, Math.min(a2, a3));

            res = Math.min(res, smax - smin);
        }

        return res;
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