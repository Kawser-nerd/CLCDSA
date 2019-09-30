import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        long ans = syakutori(a, n);
        System.out.println(ans);
    }
    public static long syakutori(long[] a, int n) {
        int right = 0;
        long res = 0;
        long sum = 0;
        for (int left = 0; left < n; left++) {
            while (right < n && (sum ^ a[right]) == sum + a[right]) {
                sum += a[right];
                right++;
            }
            res += Math.max(0, right - left);
            sum -= a[left];
        }
        return res;
    }
}