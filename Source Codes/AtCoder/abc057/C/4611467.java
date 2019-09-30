import java.math.BigDecimal;
import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        long N = sc.nextLong();

        long ans = Long.MAX_VALUE;
        long rootN = (long)Math.sqrt(N);
        for (long i = 1; i <= rootN; i++) {
            long muti = N / i;
            if (N % i == 0) {
                ans = Math.min(ans, digit(muti));
            }
        }

        System.out.println(ans);
    }

    private static int digit(long n) {
        return String.valueOf(n).length();
    }
}