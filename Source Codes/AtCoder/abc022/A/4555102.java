import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = sc.nextInt();
        int t = sc.nextInt();
        int w = sc.nextInt();
        int[] a = new int[n];
        for (int i = 1; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            w += a[i];
            if (s <= w && w <= t) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}