import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int A, B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        A = fc.nextInt();
        B = fc.nextInt();
        System.out.println(solve());
    }

    static int MOD = 1_000_000_007;

    static long solve() {
        Map<Integer, Integer> factors = new HashMap<>();
        int[] P = getSqrtPrimes(A);

        for (int i = B+1; i <= A ; i++) {
            merge(factors, countFactors(i, P));
        }

        long ans = 1;
        for (Integer f : factors.keySet()) {
            ans *= factors.get(f) + 1;
            ans %= MOD;
        }
        return ans;
    }

    static void merge(Map<Integer, Integer> factors, Map<Integer, Integer> plus) {
        for (Integer f : plus.keySet()) {
            if( factors.containsKey(f) ) {
                factors.put(f, factors.get(f) + plus.get(f));
            } else {
                factors.put(f, plus.get(f));
            }
        }
    }

    static Map<Integer, Integer> countFactors(int n, int[] P) {
        Map<Integer, Integer> cnts = new HashMap<>();
        int i = 0;
        for (int p : P) {
            int cnt = 0;
            while( n % p == 0 ) {
                cnt++;
                n /= p;
            }
            if( cnt != 0 ) {
                cnts.put(p, cnt);
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

    static int[] getSqrtPrimes(int n) {
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