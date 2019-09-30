import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n;
    boolean[] primes;
    int[] numPrimes;
    int MOD = 1000000007;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        solve();
    }

    void solve() {
        // prime number s less than sqrt(1000)
        // 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31
        primes = (new Primes(1000)).primeSieve(1000);
        numPrimes = new int[1001];
        for (int i = 2; i <= n; i++) {
            calcPrimes(i);
        }
        long ans = 1;
        for (int i = 0; i < numPrimes.length; i++) {
            ans *= numPrimes[i] + 1;
            ans %= MOD;
        }
        System.out.println(ans);
    }

    void calcPrimes(int n) {
        for (int i = 2; i < primes.length; i++) {
            if (!primes[i]) {
                continue;
            }
            while(n % i == 0) {
                numPrimes[i]++;
                n /= i;
            }
        }
    }

    class Primes {
        boolean[] isPrimes;

        Primes(int n) {
            isPrimes = new boolean[n + 1];
        }

        boolean[] primeSieve(int n) {
            for (int i = 2; i <= n; i++) {
                isPrimes[i] = true;
            }

            // mark non-primes <= n using Sieve of Eratosthenes
            for (int factor = 2; factor*factor <= n; factor++) {

                // if factor is prime, then mark multiples of factor as nonprime
                // suffices to consider mutiples factor, factor+1, ...,  n/factor
                if (isPrimes[factor]) {
                    for (int j = factor; factor*j <= n; j++) {
                        isPrimes[factor*j] = false;
                    }
                }
            }
            return isPrimes;
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}