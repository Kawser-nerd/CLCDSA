import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        long ans = 0;
        long dp = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < k; i++) {
            dp += a[i];
        }
        for (int i = 0; i < n - k + 1; i++) {
            ans += dp;
            if (i == n - k) {
                break;
            }
            dp -= a[i];
            dp += a[k + i];
        }
        System.out.println(ans);
        sc.close();
    }
}