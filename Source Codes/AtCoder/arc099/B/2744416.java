import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int k = sc.nextInt();

        long n = 1;
        for (int i = 0; i < k; i++) {
            System.out.println(n);
            n = next(n + 1);
        }
    }

    private long next(long n) {
        double min = Double.MAX_VALUE;
        long minn = 0;
        for (long tmp = 1; tmp <= n; tmp *= 10) {
            for (int i = (int) ((n / tmp) % 10); i <= 9; i++) {
                long next = ((n / tmp / 10) * 10 + i) * tmp + (tmp - 1);
                int s = s(next);
                if (min > (next * 1.0 / s)) {
                    min = (next * 1.0 / s);
                    minn = next;
                }
            }
        }

        return minn;
    }

    private int s(long n) {
        int wa = 0;
        while (n != 0) {
            wa += n % 10;
            n /= 10;
        }

        return wa;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}