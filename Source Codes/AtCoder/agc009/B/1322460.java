import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private List<List<Integer>> list = new ArrayList<>();

    private void solve(Scanner sc) {
        int N = sc.nextInt();
        for (int i = 0; i < N; ++i) {
            list.add(new ArrayList<>());
        }
        for (int i = 0; i < N - 1; ++i) {
            int a = sc.nextInt();
            list.get(a - 1).add(i + 1);
        }
        _out.println(calc(0));
    }
    private int calc(int v) {
        List<Integer> child = list.get(v);
        if (child.size() == 0) {
            return 0;
        }

        List<Integer> tmp = new ArrayList<>();
        for (int u : child) {
            tmp.add(calc(u));
        }
        Collections.sort(tmp);
        int res = 0;
        for (int i = 0; i < tmp.size(); ++i) {
            int u = tmp.get(i);
            res = Math.max(res, u + child.size() - i);
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