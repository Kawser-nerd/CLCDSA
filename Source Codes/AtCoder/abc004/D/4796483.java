import java.util.*;

public class Main {

    void run() {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt(), g = sc.nextInt(), b = sc.nextInt();

        long ans = 1 << 28;
        for (int i = -1000; i <= 1000; i++) {
            long sum = r(i - 1, r) + g(i, g) + b(i + g, b);
            if (ans > sum) {
                debug(i, i + g, r(i - 1, r), g(i, g), b(i + g, b));
            }
            ans = Math.min(ans, sum);
        }
        for (int i = 0; i < 300; i++) for (int j = 0; j < 300; j++) {
            if (r(-i - 100, j) != g(i, j)) {
                debug("error!!", i, j);
            }
        }
        debug(r(-99, 10), b(99, 10), g(0, 10));
        System.out.println(ans);
    }

    long r(int x, int r) {
        long cnt = 0;
        if (x <= -100) {
            cnt = sum(-(x - r + 100 + 1)) - sum(-(x + 100) - 1);
        } else {
            int c = (100 + x) * 2 + 1;
            if (c > r) {
                cnt += sum(r / 2) * 2 - (r % 2 == 0 ? r / 2 : 0);
            } else {
                cnt += sum(100 + x) * 2;
                int remaining = r - c;
                cnt += sum(c / 2 + remaining) - sum(c / 2);
            }
        }
        return cnt;
    }

    long g(int x, int g) {
        long cnt = 0;
        if (x < 0) {
            if (x + g - 1 > 0) {
                cnt = sum(-x) + sum(x + g - 1);
            } else {
                cnt = sum(-x) - sum(-(x + g));
            }
        } else {
            cnt = sum (x + g - 1) - sum(x - 1);
        }
        return cnt;
    }

    long b(int x, int b) {
        long cnt = 0;
        if (x >= 100) {
            cnt = sum((x + b - 100 - 1)) - sum(x - 100 - 1);
        } else {
            int c = (100 - x) * 2 + 1;
            if (c > b) {
                cnt += sum(b / 2) * 2 - (b % 2 == 0 ? b / 2 : 0);
            } else {
                cnt += sum(100 - x) * 2;
                int remaining = b - c;
                cnt += sum(c / 2 + remaining) - sum(c / 2);
            }
        }
        return cnt;
    }

    long sum(long x) {
        return x * (x + 1) / 2;
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}