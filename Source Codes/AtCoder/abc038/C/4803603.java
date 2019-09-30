import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        long ans = syakutori(a, n);
        System.out.println(ans);
    }
    public static long syakutori(int[] a, int n) {
        int right = 1;
        int res = 0;
        long ans = 0;
        for (int left = 0; left < n; left++) {
            while (right < n && (left >= right || a[right - 1] < a[right])) {
                right++;
            }
            ans += Math.max(0, right - left);
            if (left >= right) {
                right++;
            }
        }
        return ans;
    }
}