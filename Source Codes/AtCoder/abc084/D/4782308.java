import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Q = sc.nextInt();

        int[] l = new int[Q];
        int[] r = new int[Q];
        for (int i = 0; i < Q; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }

        int NUM = 100001;
        List<Integer> primes = sieveOfEratosthenes(NUM);

        boolean[] isPrime = new boolean[NUM];
        for (int p : primes) {
            isPrime[p] = true;
        }

        int[] cnt = new int[NUM];
        for (int i = 0; i < cnt.length; i++) {
            if (isPrime[i] && (i + 1) % 2 == 0 && isPrime[(i + 1) / 2]) {
                cnt[i]++;
            }
        }

        for (int i = 1; i < cnt.length; i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = 0; i < Q; i++) {
            out.println(cnt[r[i]] - cnt[l[i] - 1]);
        }
    }


    public static List<Integer> sieveOfEratosthenes(int max) {
        List<Integer> primes = new ArrayList<Integer>();

        int prime;
        int max_check = (int) Math.floor(Math.sqrt(max));   //?????????????????
        List<Integer> nums = new ArrayList<Integer>();     //????
        for (int i = 2; i <= max; i++) {
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
            List<Integer> rest_nums = new ArrayList<Integer>();
            for (int n : nums) {
                if (n % prime != 0) {
                    rest_nums.add(n);
                }
            }

            // ????????????
            nums = rest_nums;
        }

        //??????????
        for (int n : nums) {
            primes.add(n);
        }

        return primes;
    }

}