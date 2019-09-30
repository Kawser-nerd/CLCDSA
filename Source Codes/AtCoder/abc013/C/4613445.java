import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long h = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        long d = sc.nextLong();
        long e = sc.nextLong();
        long ans = n * a;
        for (int i = 0; i <= n; i++) {
            // i : ???????
            // ?????????????????
            long right = n - i;
            long left = -1;
            while (right - left > 1) {
                long mid = (left + right) / 2;
                if (b * i + d * mid + h - (n - mid - i) * e > 0) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            long cost = a * i + right * c;
            ans = Math.min(ans, cost);
        }
        System.out.println(ans);
        sc.close();
    }
}