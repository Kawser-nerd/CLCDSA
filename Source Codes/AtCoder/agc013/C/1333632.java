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
        int L = sc.nextInt();
        int T = sc.nextInt();
        int[] X = new int[N];
        int[] W = new int[N];
        for (int i = 0; i < N; ++i) {
            X[i] = sc.nextInt();
            W[i] = sc.nextInt();
        }

        int[] p = new int[N];
        int x0 = 0;
        for (int i = 0; i < N; ++i) {
            if (W[i] == 1) {
                p[i] = (X[i] + T) % L;
                x0 += (X[i] + T) / L;
            } else {
                p[i] = (X[i] - T) % L;
                x0 += (X[i] - T) / L;
                if (p[i] < 0) {
                    p[i] += L;
                    --x0;
                }
            }
        }
        Arrays.sort(p);
        x0 %= N;
        if (x0 < 0) {
            x0 += N;
        }
        for (int i = 0; i < N; ++i) {
            _out.println(p[(i + x0) % N]);
        }
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