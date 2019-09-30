import java.math.BigInteger;
import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int MOD = 1000000007;

    public static void main(String[] args) {
        int r = sc.nextInt();
        int c = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        int d = sc.nextInt();
        int l = sc.nextInt();

        int kukakuPattern = (r - x + 1) * (c - y + 1);
        BigInteger haichiPattern = haichiPattern(x, y, d, l);
        long ans = haichiPattern.multiply(BigInteger.valueOf(kukakuPattern)).mod(BigInteger.valueOf(MOD)).longValue();
        System.out.println(ans);
    }

    static BigInteger haichiPattern(int x, int y, int d, int l) {
        return p(x, y, d, l).subtract(
                // 1??????????????
                p(x - 1, y, d, l).multiply(BigInteger.valueOf(2))
                        .add(p(x, y - 1, d, l).multiply(BigInteger.valueOf(2)))
                        // 2??????????????
                        .subtract(p(x - 1, y - 1, d, l).multiply(BigInteger.valueOf(4)))
                        .subtract(p(x - 2, y, d, l))
                        .subtract(p(x, y - 2, d, l))
                        // 3??????????????
                        .add(p(x - 2, y - 1, d, l).multiply(BigInteger.valueOf(2)))
                        .add(p(x - 1, y - 2, d, l).multiply(BigInteger.valueOf(2)))
                        // 4??????????????
                        .subtract(p(x - 2, y - 2, d, l))
        );
    }

    static BigInteger p(int x, int y, int d, int l) {
        return (x > 0 && y > 0 && x * y >= d + l) ?
                combination(x * y, d).multiply(combination(x * y - d, l)) :
                BigInteger.ZERO; // ????????????????0??
    }

    static BigInteger combination(int a, int b) {
        int aTmp = a;
        int bTmp = 1;
        BigInteger aSum = BigInteger.valueOf(1);
        BigInteger bSum = BigInteger.valueOf(1);
        for (int i = 0; i < b; i++) {
            aSum = aSum.multiply(BigInteger.valueOf(aTmp));
            bSum = bSum.multiply(BigInteger.valueOf(bTmp));
            aTmp--;
            bTmp++;
        }
        return aSum.divide(bSum);
    }


}