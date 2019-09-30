import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        long[] s = new long[n];
        boolean isZero = false;
        for (int i = 0; i < n; i++) {
            s[i] = sc.nextLong();
            if (s[i] == 0) {
                isZero = true;
            }
        }
        if (isZero) {
            System.out.println(n);
            return;
        }
        long ans = syakutori(s, k, n);
        System.out.println(ans);
    }
    public static long syakutori(long[] s, long k, int n) {
        int right = 0;
        long res = 0;
        long mult = 1;
        for (int left = 0; left < n; left++) {
            while (right < n && mult * s[right] <= k) {
                mult *= s[right];
                right++;
            }
            res = Math.max(res, right - left);
            if (left >= right) {
                right++;
                continue;
            }
            mult /= s[left];
        }
        return res;
    }
}