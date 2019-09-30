import java.io.*;
import java.util.*;
 
public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;
 
    private static PrintWriter _err = new PrintWriter(System.err);
 
    private int N;
    private int K;
    private long[] a;
 
    private void solve(Scanner sc, PrintWriter out) {
        N = sc.nextInt();
        K = sc.nextInt();
        a = new long[N];
        long max = 0;
        for (int i = 0; i < N; ++i) {
            a[i] = sc.nextLong();
            max += Math.max(a[i], 0);
        }
        long add = 0;
        long sub = 0;
        for (int i = 0; i < K; ++i) {
            add += Math.max(a[i], 0);
            sub += Math.min(a[i], 0);
        }
        long min = Math.min(add, -sub);
        for (int i = K; i < N; ++i) {
            add += Math.max(a[i], 0) - Math.max(a[i - K], 0);
            sub += Math.min(a[i], 0) - Math.min(a[i - K], 0);
            min = Math.min(min, Math.min(add, -sub));
        }
 
        out.println((max - min));
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