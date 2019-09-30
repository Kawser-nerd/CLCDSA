import java.math.*;
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] rate = new int[n][2];
        for (int i = 0; i < n; ++i) {
            rate[i][0] = sc.nextInt();
            rate[i][1] = sc.nextInt();
        }

        long[] count = new long[2];
        count[0] = rate[0][0];
        count[1] = rate[0][1];

        for (int i = 1; i < n; ++i) {
            count = nextCount(rate[i], count);
        }
        System.out.println(count[0] + count[1]);
    }
    private static long[] nextCount(int[] rate, long[] count) {
        int r0 = rate[0];
        int r1 = rate[1];

        long n = Math.max((count[0] + r0 - 1) / r0, (count[1] + r1 - 1) / r1);
        count[0] = r0 * n;
        count[1] = r1 * n;

        return count;
    }
    private static int gcd(int v1, int v2) {
        BigInteger b1 = BigInteger.valueOf(v1);
        BigInteger b2 = BigInteger.valueOf(v2);
        return b1.gcd(b2).intValue();
    }
}