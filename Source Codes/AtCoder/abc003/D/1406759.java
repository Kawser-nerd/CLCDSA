import java.math.BigInteger;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    static BigInteger BIG = BigInteger.valueOf(1000000007);
    static BigInteger dp[][] = new BigInteger[901][901];

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int R = scan.nextInt();
        int C = scan.nextInt();
        int X = scan.nextInt();
        int Y = scan.nextInt();
        int D = scan.nextInt();
        int L = scan.nextInt();

        int roomPatern = (R - X + 1) * (C - Y + 1 );


        BigInteger sum = BigInteger.ZERO;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                int arrangePatern = roomPatern * comb(2, i).intValue() * comb(2, j).intValue();
                int square = (X - i) * (Y - j);
                if (square < L + D) {
                    break;
                }
                if ((i + j) % 2 == 0) {
                    sum = sum.add(BigInteger.valueOf(arrangePatern).multiply(comb(square, L)).multiply(comb(square - L, D)));
                } else {
                    sum = sum.subtract(BigInteger.valueOf(arrangePatern).multiply(comb(square, L)).multiply(comb(square - L, D)));
                }
            }
        }
        System.out.println(sum.mod(BIG));
    }

    private static BigInteger comb(int n, int k) {
        if (n < 2 * k) {
            k = n - k;
        }
        if (dp[n][k] != null) {
            return dp[n][k];
        }
        BigInteger m = BigInteger.ONE;
        for (int i : IntStream.range(1, k + 1).toArray()) {
            m = m.multiply(BigInteger.valueOf((n - i + 1)));
        }
        for (int i : IntStream.range(1, k + 1).toArray()) {
            m = m.divide(BigInteger.valueOf(i));
        }
        dp[n][k] = m;
        return m;
    }
}