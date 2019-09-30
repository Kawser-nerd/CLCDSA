import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        long ans = 0;
        long time = a[0];
        for (int i = 1; i < n; i++) {
            if (time + t <= a[i]) {
                time = a[i];
                ans += t;
            } else {
                ans += a[i] - time;
                time = a[i];
            }
        }
        ans += t;
        System.out.println(ans);
        sc.close();
    }
}