import java.util.*;

public class Main {
    public void main(Scanner sc) {
        long n = sc.nextLong();
        long s = sc.nextLong();

        if (n == s) {
            System.out.println(n + 1);
            return;
        }

        if ((n + 1) / 2 < s) {
            System.out.println(-1);
            return;
        }

        for (long b = 2; b * b <= n; b++) {
            if (f(n, b) == s) {
                System.out.println(b);
                return;
            }
        }

        long min = Long.MAX_VALUE;
        for (long p = 1; p * p <= n; p++) {
            long b = (n - s) / p + 1;
            if (f(n, b) == s) {
                min = Math.min(min, b);
            }
        }
        System.out.println(min);
    }

    private long f(long n, long b) {
        if (n < b) {
            return n;
        } else {
            return f(n / b, b) + n % b;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}