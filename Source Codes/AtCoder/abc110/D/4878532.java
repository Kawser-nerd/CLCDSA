import java.util.*;

import static java.lang.System.*;

public class Main {
    public static final long mod = 1_000_000_007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long M = sc.nextLong();

        long NUM = (long) Math.sqrt(1_000_000_001);
        List<Long> primes = sieveOfEratosthenes(NUM);

        Map<Long, Integer> primeNums = new HashMap<>();
        for (long p : primes) {
            int cnt = 0;
            while (M % p == 0) {
                cnt++;
                M /= p;
            }

            if (cnt != 0) {
                primeNums.put(p, cnt);
            }
        }

        // NUM???????????????
        if (M > 1) {
            primeNums.put(M, 1);
        }

        long ans = 1;
        for (Map.Entry primeNum : primeNums.entrySet()) {
            int cnt = (int) primeNum.getValue();
            ans *= combinationMod(cnt + (N - 1), cnt, mod);
            ans %= mod;
        }

        out.println(ans);
    }

    public static long combinationMod(int n, int k, long prime) {
        // ????
        long fac[] = new long[n + 1];
        long finv[] = new long[n + 1];
        long inv[] = new long[n + 1];
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; i++) {
            fac[i] = fac[i - 1] * i % prime;
            inv[i] = prime - inv[(int) (prime % Long.valueOf(i))] * (prime / i) % prime;
            finv[i] = finv[i - 1] * inv[i] % prime;
        }

        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;

        return fac[n] * (finv[k] * finv[n - k] % prime) % prime;
    }

    public static List<Long> sieveOfEratosthenes(long max) {
        List<Long> primes = new ArrayList<>();

        long prime;
        long max_check = (long) Math.floor(Math.sqrt(max));   //?????????????????
        List<Long> nums = new ArrayList<Long>();     //????
        for (long i = 2; i <= max; i++) {
            nums.add(i);
        }


        while (true) {
            // ????????????
            if (nums.size() < 2) {
                break;
            }
            prime = nums.get(0);

            // ???????????????????????????????
            if (prime >= max_check) {
                break;
            }

            primes.add(prime);

            // prime???????
            List<Long> rest_nums = new ArrayList<>();
            for (long n : nums) {
                if (n % prime != 0) {
                    rest_nums.add(n);
                }
            }

            // ????????????
            nums = rest_nums;
        }

        //??????????
        for (long n : nums) {
            primes.add(n);
        }

        return primes;
    }
}