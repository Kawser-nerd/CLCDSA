import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private void solve(Scanner sc) {
        long A = sc.nextLong();
        long B = sc.nextLong();

        if (A == B) {
            _out.println(1);
            return;
        }

        long c = 0x4000000000000000L;
        while ((A & c) == (B & c)) {
            A = (A | c) ^ c;
            B = (B | c) ^ c;
            c >>>= 1;
        }
        long d = (c >>> 1);
        while ((B & d) != d) {
            d >>>= 1;
        }
        int r = Long.numberOfTrailingZeros(c) + 1;
        int k = Long.numberOfTrailingZeros(d) + 1;
        if (d == 0) {
            k = 0;
        }
        long sum = ((1L << r) - A);
        if ((1L << k) < A) {
            sum -= A - (1L << k);
        }
        _out.println(sum);
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