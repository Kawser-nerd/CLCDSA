import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = true;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private int N;
    private int W;

    private List<Pair<Integer>> list = new ArrayList<>();
    private Map<Pair<Integer>, Long> memo1 = new HashMap<>();

    private long[] dp;

    private long ans;

    private void solve(Scanner sc) {
        N = sc.nextInt();
        W = sc.nextInt();

        boolean overWeight = false;
        for (int i = 0; i < N; ++i) {
            int v = sc.nextInt();
            int w = sc.nextInt();

            list.add(new Pair<>(v, w));

            if (w > 1000) {
                overWeight = true;
            }
        }
        if (N <= 30) {
            ans = solve1(0, W);
        } else if (!overWeight) {
            ans = solve2();
        } else {
            ans = solve3();
        }

        _out.println(ans);
    }
    private long solve1(int d, int w) {
        Pair<Integer> key = new Pair<>(d, w);
        Long v = memo1.get(key);
        if (v != null) {
            return v;
        }
        if (d >= N) {
            return 0;
        }
        Pair<Integer> p = list.get(d);
        long a1 = solve1(d + 1, w);
        if (p.b > w) {
            memo1.put(key, a1);
            return a1;
        }
        long a2 = solve1(d + 1, w - p.b) + p.a;
        long a = Math.max(a1, a2);
        memo1.put(key, a);
        return a;
    }
    private long solve2() {
        int max = 1000;
        dp = new long[N * max + 1];
        for (int i = 0; i < N; ++i) {
            Pair<Integer> p = list.get(i);
            int wi = p.b;
            for (int j = N * max; j >= wi; --j) {
                dp[j] = Math.max(dp[j], dp[j - wi] + p.a);
            }
        }
        return dp[W];
    }
    private long solve3() {
        int max = 1000;
        dp = new long[N * max + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            Pair<Integer> p = list.get(i);
            int vi = p.a;
            for (int j = N * max; j >= vi; --j) {
                dp[j] = Math.min(dp[j], dp[j - vi] + p.b);
            }
        }
        for (int i = N * max; i >= 0; --i) {
            if (dp[i] <= W) {
                return i;
            }
        }
        return 0;
    }
    private static BigInteger C(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        for (long i = r; i > 1; --i) {
            res = res.divide(BigInteger.valueOf(i));
        }
        return res;
    }
    private static BigInteger P(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    private static class Pair<T extends Comparable<T>> implements Comparable<Pair<T>> {
        T a;
        T b;
        public Pair(T a, T b) {
            this.a = a;
            this.b = b;
        }
        @Override
        public int compareTo(Pair<T> that) {
            if (this == that) {
                return 0;
            }
            if (this.a != null && that.a == null) {
                return 1;
            } else if (this.a == null && that.a != null) {
                return -1;
            }
            if (this.b != null && that.b == null) {
                return 1;
            } else if (this.b == null && that.b != null) {
                return -1;
            }
            int r = 0;
            if (this.a != null && that.a != null) {
                r = this.a.compareTo(that.a);
                if (r != 0) {
                    return r;
                }
            }
            if (this.b != null && that.b != null) {
                r = this.b.compareTo(that.b);
                if (r != 0) {
                    return r;
                }
            }
            return r;
        }
        @Override
        public boolean equals(Object o) {
            if (o instanceof Pair) {
                Pair that = (Pair)o;
                boolean res = (this.a == null && this.a == that.a || this.a != null && this.a.equals(that.a));
                res = res && (this.b == null && this.b == that.b || this.b != null && this.b.equals(that.b));
                return res;
            }
            return false;
        }
        @Override
        public int hashCode() {
            int hashCode = 17;
            hashCode = hashCode * 31 + (a != null ? a.hashCode() : 0);
            hashCode = hashCode * 31 + (b != null ? b.hashCode() : 0);
            return hashCode;
        }
        @Override
        public String toString() {
            return "[" + a + ", " + b + "]";
        }
    }
    /*
     * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
     * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
     */
    public static void main(String[] args) {
        long S = System.currentTimeMillis();

        Scanner sc = new Scanner(System.in);
        new Main().solve(sc);
        _out.flush();

        long G = System.currentTimeMillis();
        if (elapsed) {
            _err.println((G - S) + "ms");
        }
        _err.flush();
    }
}