
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class c {
    public static void main(String[] args) {
        Scanner s = new Scanner(new BufferedInputStream(System.in));

        boolean[] is_prime = new boolean[1000001];

        Arrays.fill(is_prime, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i <= 2000; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= 1000000; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        int num_primes = 0;
        long[] primes = new long[80000];
        for (int i = 0; i <= 1000000; ++i) {
            if (is_prime[i]) {
                primes[num_primes++] = i;
            }
        }

        int T = s.nextInt();
        for (int c = 1; c <= T; ++c) {
            long n = s.nextLong();
            int ans = 0;
            if (n > 1) {
                ans = 1;
                for (int i = 0; i < num_primes; ++i) {
                    long p = primes[i];
                    long ps = p * p;

                    if (ps > n) break;
                    while (ps <= n) {
                        ps *= p;
                        ++ans;
                    }
                }
            }

            System.out.format("Case #%d: %d%n", c, ans);
            
        }

    }
}
