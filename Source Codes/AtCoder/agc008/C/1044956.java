import java.io.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _err = new PrintWriter(System.err);

    private void solve(Scanner sc, PrintWriter out) {
        long ai = sc.nextInt();
        long ao = sc.nextInt();
        long at = sc.nextInt();
        long aj = sc.nextInt();
        long al = sc.nextInt();
        long as = sc.nextInt();
        long az = sc.nextInt();

        long size = 0;

        size = (ai / 2 + aj / 2 + al / 2) * 2 + ao;
        if (ai > 0 && aj > 0 && al > 0) {
            size = Math.max(size, 3 + ((ai - 1) / 2 + (aj - 1) / 2 + (al - 1) / 2) * 2 + ao);
        }

        out.println(size);
    }
    private long C(long n, long r) {
        long res = 1;
        for (long i = n; i > n - r; --i) {
            res *= i;
        }
        for (long i = r; i > 1; --i) {
            res /= i;
        }
        return res;
    }
    private long P(long n, long r) {
        long res = 1;
        for (long i = n; i > n - r; --i) {
            res *= i;
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
        PrintWriter out = new PrintWriter(System.out);
        new Main().solve(sc, out);
        out.flush();

        long G = System.currentTimeMillis();
        if (elapsed) {
            _err.println((G - S) + "ms");
        }
        _err.flush();
    }
}