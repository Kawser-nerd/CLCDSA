import java.io.*;
import java.util.*;
import java.util.function.Function;
import java.util.function.IntBinaryOperator;
import java.util.function.IntUnaryOperator;

public class Main {

    static int N, K;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();

        System.out.println(solve());
    }

    static int MOD = 1_000_000_007;

    static long solve() {
        Map<Integer, Integer> factorCounts = countFactors(K);
        int[] factors = mkElements(factorCounts);
        List<Integer> dividors = enumDividors(factors, factorCounts);
        long ans = 0;
        for (int dividor : dividors) {
            ans += calc(dividor, factors);
            ans %= MOD;
        }
        return ans;
    }

    static int calc(int dividor, int[] factors) {
        int[] remainFactors = mkRemainFactors(dividor, factors);
        int n = N / dividor;
        int g = gcd(dividor, K);
        int k = K/g;

        int all = sequenceSum(n);
        int houjyo = execute(remainFactors, 1, (a, b) -> (int)((long)a * b % MOD), a -> (int)((long)a * sequenceSum(n/a) % MOD) );
        int diff = all - houjyo;
        if( diff < 0 ) {
            diff += MOD;
        }
        return (int)((long)diff * dividor % MOD * k % MOD);
    }

    static int[] mkRemainFactors(int d, int[] factors) {
        int r = K/d;

        int cnt = 0;
        for (int f : factors) {
            if (r % f == 0) {
                cnt++;
            }
        }
        int[] ret = new int[cnt];
        int idx = 0;
        for (int f : factors) {
            if (r % f == 0) {
                ret[idx++] = f;
            }
        }
        return ret;
    }

    static int execute(int[] elms, int init, IntBinaryOperator fold, IntUnaryOperator f) {
        int k = elms.length;
        int ret = 0;
        for (int b = 1; b < 1 << k; b++) {
            int x = init;
            for (int i = 0; i < k; i++) {
                if( (b & 1 << i) > 0 ) {
                    x = fold.applyAsInt(x, elms[i]);
                }
            }
            if( Integer.bitCount(b) % 2 == 1 ) {
                ret += f.applyAsInt(x);
                ret %= MOD;
            } else {
                ret -= f.applyAsInt(x);
                if( ret < 0 ) {
                    ret += MOD;
                }
            }
        }
        return ret;
    }

    static List<Integer> enumDividors(int[] factors, Map<Integer, Integer> factorCounts) {
        List<Integer> dividtors = new ArrayList<>();
        dividtors.add(1);
        dfs(1, 0, factors, factorCounts, dividtors);
        dividtors.sort(Comparator.naturalOrder());
        return dividtors;
    }

    static void dfs(int n, int idx, int[] factors, Map<Integer, Integer> factorCounts, List<Integer> dividors) {
        if( idx == factors.length ) return;

        int p = factors[idx];
        int cnt = factorCounts.get(p);
        dfs(n, idx+1, factors, factorCounts, dividors);
        int cur = p;
        for (int i = 0; i < cnt; i++) {
            dividors.add(n*cur);
            dfs(n*cur, idx+1, factors, factorCounts, dividors);
            cur *= p;
        }
    }

    static int[] mkElements(Map<Integer, Integer> factorCounts) {
        int[] factors = new int[factorCounts.size()];
        int idx = 0;
        for (Integer p : factorCounts.keySet()) {
            factors[idx++] = p;
        }
        Arrays.sort(factors);
        return factors;
    }

    static Map<Integer, Integer> countFactors(int n) {
        Map<Integer, Integer> cnts = new HashMap<>();
        for (int i = 2; i <= Math.sqrt(n); i++) {
            int cnt = 0;
            while( n % i == 0 ) {
                n/=i;
                cnt++;
            }
            if( cnt > 0 ) {
                cnts.put(i, cnt);
            }
        }
        if( n != 1 ) {
            cnts.put(n, 1);
        }
        return cnts;
    }

    // ?????????
    static int sequenceSum(int n) {
        return (int)((long)n * (n+1) / 2 % MOD);
    }

    static int gcd(int a, int b) {
        while (b > 0) {
            int c = a;
            a = b;
            b = c % b;
        }
        return a;
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

        int[] nextIntArray(int n, int delta) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt() + delta;
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }

    static <A> void writeLines(A[] as, Function<A, String> f) {
        PrintWriter pw = new PrintWriter(System.out);
        for (A a : as) {
            pw.println(f.apply(a));
        }
        pw.flush();
    }

    static void writeLines(int[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (int a : as) pw.println(a);
        pw.flush();
    }

    static void writeLines(long[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (long a : as) pw.println(a);
        pw.flush();
    }

    static int max(int... as) {
        int max = Integer.MIN_VALUE;
        for (int a : as) max = Math.max(a, max);
        return max;
    }

    static int min(int... as) {
        int min = Integer.MAX_VALUE;
        for (int a : as) min = Math.min(a, min);
        return min;
    }

    static void debug(Object... args) {
        StringJoiner j = new StringJoiner(" ");
        for (Object arg : args) {
            if (arg instanceof int[]) j.add(Arrays.toString((int[]) arg));
            else if (arg instanceof long[]) j.add(Arrays.toString((long[]) arg));
            else if (arg instanceof double[]) j.add(Arrays.toString((double[]) arg));
            else if (arg instanceof Object[]) j.add(Arrays.toString((Object[]) arg));
            else j.add(arg.toString());
        }
        System.err.println(j.toString());
    }
}