import java.util.Scanner;

public class Main {
    static int n;
    static int[] h, s;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        h = new int[n];
        s = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
            s[i] = sc.nextInt();
        }
        long ans = solve();
        System.out.println(ans);
    }

    static long solve() {
        long low = 0;
        long high = Double.valueOf(2e14).longValue();
        while(high - low > 1) {
            long mid = (low + high) / 2;
            if (check(mid)) {
                high = mid;
            } else low = mid;
        }
        return high;
    }

    static boolean check(long x) {
        int[] time = new int[n];
        for (int i = 0; i < n; i++) {
            if (x < h[i]) return false;
            time[(int)Math.min(n - 1, (x - h[i]) / s[i])]++;
        }

        for (int i = n - 1; i >= 1; i--) {
            if (time[i] < n - i) return false;
            time[i - 1] += time[i];
        }
        return true;
    }
}