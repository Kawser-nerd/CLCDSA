import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private int ans = Integer.MAX_VALUE;

    private void solve(Scanner sc) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[][] A = new int[N][M];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                A[i][j] = sc.nextInt() - 1;
            }
        }
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < M; ++i) {
            set.add(i);
        }

        calc(A, N, M, set);

        _out.println(ans);
    }
    private void calc(int[][] A, int N, int M, Set<Integer> set) {
        int[] cnt = new int[M];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (set.contains(A[i][j])) {
                    ++cnt[A[i][j]];
                    break;
                }
            }
        }
        int P = -1;
        int max = 0;
        for (int i = 0; i < M; ++i) {
            if (cnt[i] > max) {
                max = cnt[i];
                P = i;
            }
        }
        if (max < ans) {
            ans = max;
        }

        set.remove(P);
        if (set.size() > 0) {
            calc(A, N, M, set);
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