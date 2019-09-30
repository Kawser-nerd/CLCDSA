import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static long N;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextLong();
        System.out.println(solve());
    }

    static String solve() {
        int[] P = getSqrtPrimes(N);
        long g = f(N, P);
        if( g - N > N ) {
            return "Abundant";

        } else if( g - N == N ) {
            return "Perfect";

        } else {
            return "Deficient";
        }
    }

    // ??????????????????????????????????
    static long f(long n, int[] P) {
        Map<Long, Integer> factors = countFactors(n, P);

        long ans = 1;
        for (long factor : factors.keySet()) {
            int cnt = factors.get(factor);

            int sum = 1;
            for (int i = 1; i <= cnt; i++) {
                sum += (long)Math.pow(factor, i);
            }
            ans *= sum;
        }
        return ans;
    }

    static Map<Long, Integer> countFactors(long n, int[] P) {
        Map<Long, Integer> cnts = new HashMap<>();
        int i = 0;
        for (int p : P) {
            int cnt = 0;
            while( n % p == 0 ) {
                cnt++;
                n /= p;
            }
            if( cnt != 0 ) {
                cnts.put((long)p, cnt);
            }
        }
        if( n != 1 ) {
            cnts.put(n, 1);
        }
        return cnts;
    }

    static boolean[] sieveEratos(int n) {
        boolean[] primes = new boolean[n+1];
        Arrays.fill(primes, true);
        primes[0] = false;
        primes[1] = false;

        int root = (int)Math.sqrt(n);
        for (int i = 2; i <= root; i++) {
            if( primes[i] ) {
                for (int d = 2; d*i <= n; d++) {
                    primes[i*d] = false;
                }
            }
        }
        return primes;
    }

    static int[] getSqrtPrimes(long n) {
        boolean[] sieve = sieveEratos( (int)Math.sqrt(n) );
        int cnt = 0;
        for (boolean prime : sieve) {
            if( prime ) cnt++;
        }
        int[] primes = new int[cnt];
        int idx = 0;
        for (int num = 2; num < sieve.length; num++) {
            if( sieve[num] ) {
                primes[idx++] = num;
            }
        }
        return primes;
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}