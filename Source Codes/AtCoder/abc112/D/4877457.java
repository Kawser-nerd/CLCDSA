import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long M = sc.nextInt();

        Set<Long> divisors = new TreeSet<>(Collections.reverseOrder());
        for (long i = 1; i <= (long) Math.sqrt(M); i++) {
            if (M % i == 0) {
                divisors.add(i);
                divisors.add(M / i);
            }
        }

        // p(a1' + a2' + ... + aN') = M
        // ??????p????
        for (long p : divisors) {
            if (M % p == 0 && M / p >= N) {
                out.println(p);
                return;
            }
        }
    }
}