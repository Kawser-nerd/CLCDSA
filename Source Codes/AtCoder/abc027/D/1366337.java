import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private void solve(Scanner sc) {
        String S = sc.nextLine();

        int[] addCnt = new int[S.length()];
        int[] subCnt = new int[S.length()];

        int add = 0;
        int sub = 0;
        List<Integer> A = new ArrayList<>();
        for (int i = S.length() - 1; i >= 0; --i) {
            char ch = S.charAt(i);
            if (ch == '+') {
                ++add;
            } else if (ch == '-') {
                ++sub;
            }

            addCnt[i] = add;
            subCnt[i] = sub;
            if (ch == 'M') {
                A.add(add - sub);
            }
        }

        Collections.sort(A);
        int former = 0;
        int latter = 0;
        for (int i = 0; i < A.size() / 2; ++i) {
            former += A.get(i);
        }
        for (int i = A.size() / 2; i < A.size(); ++i) {
            latter += A.get(i);
        }
        _out.println(latter - former);
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