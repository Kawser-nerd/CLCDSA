import java.util.*;

public class Main {
    public static void main(String[] args) {
//        test();
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        System.out.println(calc(N));
    }
    
    private static long calc(int x) {
        int[] primes = new int[x+1];
        Arrays.fill(primes, 1);
        primes[0] = primes[1] = 0;
        for (int i = 3; i < primes.length; i++) {
            if (i % 2 == 0) primes[i] = 0;
        }

        int j = 3;
        while (j*j < primes.length) {
            for (int k = j+1; k < primes.length; k++) {
                if (k % j == 0) primes[k] = 0;
            }

            j += 2;
        }



        // Calc factorial
        int[] factors = new int[x + 1];

        while(x > 1) {
            int i = 3;
            int f = x;

            while (f % 2 == 0) {
                factors[2]++;
                f /= 2;
            }

            while (i <= f) {
                if (primes[i] == 1) {
                    while (f % i == 0) {
                        factors[i]++;
                        f /= i;
                    }
                }
                i += 2;
            }
            if (f != 1) factors[f]++;

            x--;
        }

//        System.out.println(Arrays.toString(factors));

        long d = (long)Math.pow(10, 9) + 7;
        long count = 1;
        for (int f: factors) {
            if (f != 0)
                count *= (f+1);
            while (count >= d) {
                count -= d;
            }
//            System.out.println(count);
        }

        return count;
    }
    
    private static void test() {
        assert calc(6) == 30;
        assert calc(1000) == 972926972;
    }
}