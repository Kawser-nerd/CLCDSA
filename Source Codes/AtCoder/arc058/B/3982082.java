import java.util.Scanner;

public class Main {

    public static class Combination {

        long[] factorial;
        int maxN;
        long Module;

        public Combination(final int maxN, final long Module) {
            this.maxN = maxN;
            factorial = new long[maxN];
            this.Module = Module;
        }

        public void init() {
            factorial[0] = 1;
            factorial[1] = 1;
            for (int i = 2; i < maxN; ++i) {
                factorial[i] = ((factorial[i - 1] % Module) * (i % Module)) % Module;
            }
        }

        // find x[0] and y[0] such that a * x[0] + b * y[0] = 1, return gcd(a, b)
        long extgcd(long a, long b, long[] x, long[] y) {
            long d = a;
            if (b != 0) {
                d = extgcd(b, a % b, y, x);
                y[0] -= (a / b) * x[0];
            } else {
                x[0] = 1;
                y[0] = 0;
            }
            return d;
        }

        /**
         * to find (1 / a) mod m
         * that is, find x, such that a * x = 1 (mod m)
         * that is, { a * x - 1 = k * m}
         * that is, find x and k, such that a * x + k * m = 1. We can use extgcd algorithm
         */
        long inverseModule(long a, long m) {
            long[] x = new long[1];
            long[] y = new long[1];
            extgcd(a, m, x, y);
            return (m + x[0] % m) % m;
        }

        /**
         * find fetch n kinds from m kinds, mod k.
         * nCm = n! / (m! * (n - m)!)
         * nCm mod k = (n! (mod k) * (1 / (m!)) mod k * (1 / ((n - m)!)) mod k) mod k
         */
        long nCm(int n, int m, long k) {
            if (n < 0 || m < 0 || n < m) {
                return 0;
            }
            return (factorial[n] % k * inverseModule(factorial[m], k) % k
                    * inverseModule(factorial[n - m], k) % k) % k;
        }
    }

    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);

        int h = scanner.nextInt();
        int w = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int maxN = 200005;
        long Module = 1000000007;

        Combination combination = new Combination(maxN, Module);
        combination.init();
        long result = 0;

        for (int j = b + 1; j <= w; ++j) {
            result +=
                    (combination.nCm(h - a - 1 + j - 1, j - 1, Module) % Module)
            * (combination.nCm(a - 1 + w - 1 - (j - 1), a - 1, Module) % Module);
            result %= Module;

        }
        System.out.println(result);

    }
}