import java.util.*;

public class Main {

    public void main(Scanner sc) {
        int n = sc.nextInt();
        long a = sc.nextLong();
        long b = sc.nextLong();
        long h[] = new long[n];
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextLong();
        }

        long l = 1;
        long r = 1_000_000_000;
        while (l != r) {
            long mid = (l + r) / 2;
            if (count(mid, h, a, b) <= mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        System.out.println(l);
    }

    private long count(long mid, long h[], long a, long b) {
        long sa = a - b;

        long cnt = 0;
        for (int i = 0; i < h.length; i++) {
            cnt += Math.max((h[i] - mid * b + sa - 1) / sa, 0);
        }

        return cnt;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}