import java.io.*;
import java.util.*;
import java.math.*;

public class A
{
    static BigInteger get(BigInteger r, BigInteger res) {
        BigInteger x = (BigInteger.valueOf(2).multiply(res).subtract(BigInteger.ONE)).multiply(res);
        return BigInteger.valueOf(2).multiply(r).multiply(res).add(x);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ntest = sc.nextInt();
        for(int test = 1; test <= ntest; ++test) {
            BigInteger r = BigInteger.valueOf(sc.nextLong());
            BigInteger t = BigInteger.valueOf(sc.nextLong());

            BigInteger left = BigInteger.ZERO, right = BigInteger.valueOf(1000111000111000111L);
            BigInteger res = left;
            while (left.compareTo(right) <= 0) {
                BigInteger mid = (left.add(right)).divide(BigInteger.valueOf(2));
                if (get(r, mid).compareTo(t) <= 0) {
                    res = mid;
                    left = mid.add(BigInteger.ONE);
                }
                else right = mid.subtract(BigInteger.ONE);
            }
            System.out.println("Case #" + test + ": " + res);
        }
    }
}