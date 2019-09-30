import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by darshan on 2/19/19.
 */
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long n = Long.parseLong(br.readLine());
        long s = Long.parseLong(br.readLine());

        if (n < s) {
            System.out.println(-1);
            return;
        }
        if (n == s) {
            System.out.println(n + 1);
            return;
        }

        /*
        Let x = (square root of n) + 1
        Try all possible bases till x
        Once we exceed x, n can be represented in two digits of base x
         */
        long squareRootN = Double.valueOf(Math.ceil(Math.sqrt(n))).longValue();
        for (long base = 2; base <= squareRootN; base++) {
            long sum = sumDigitsInBase(base, n);
            if (sum == s) {
                System.out.println(base);
                return;
            }
        }

        /*
        b > x
        n = pb + q
        p + q = s
        b = (n - s) / p + 1
        p = [1, x]
         */
        long nMinusS = n - s;
        long minBase = -1;
        for (long p = 1; p <= squareRootN; p++) {
            if (nMinusS % p != 0) {
                continue;
            }
            long base = nMinusS / p + 1;
            if (base > squareRootN) {
                long sum = sumDigitsInBase(base, n);
                if (sum == s) {
                    minBase = base;
                }
            }
        }
        System.out.println(minBase);
    }

    private static long sumDigitsInBase(long base, long number) {
        if (base > number) {
            return number;
        }
        long sum = sumDigitsInBase(base, number / base);
        return sum + (number % base);
    }
}