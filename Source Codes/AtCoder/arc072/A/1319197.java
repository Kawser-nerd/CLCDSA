import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private void solve(Scanner sc) {
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = sc.nextInt();
        }

        long sum = 0;
        long ans1 = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (i % 2 == 0 && sum <= 0) {
                ans1 += Math.abs(sum) + 1;
                sum = 1;
            } else if (i % 2 == 1 && sum >= 0) {
                ans1 += sum + 1;
                sum = -1;
            }
        }

        sum = 0;
        long ans2 = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (i % 2 == 0 && sum >= 0) {
                ans2 += sum + 1;
                sum = -1;
            } else if (i % 2 == 1 && sum <= 0) {
                ans2 += Math.abs(sum) + 1;
                sum = 1;
            }
        }
        _out.println(Math.min(ans1, ans2));
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