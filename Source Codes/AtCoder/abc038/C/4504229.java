import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int tmp = 0;
        long cnt = 0;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            if (tmp < a[i]) {
                cnt++;
            } else {
                ans += (cnt * (cnt + 1)) / 2;
                cnt = 1;
            }
            tmp = a[i];
            if (i == n - 1) {
                ans += (cnt * (cnt + 1)) / 2;
            }
        }
        sc.close();
        System.out.println(ans);
    }
}