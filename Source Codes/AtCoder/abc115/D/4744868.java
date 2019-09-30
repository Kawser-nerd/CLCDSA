import java.util.Scanner;
import java.util.*;
public class Main {
    static long[] sum;
    static long[] p;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long x = sc.nextLong();
        sum = new long[n];
        p = new long[n];
        sum[0] = 1;
        p[0] = 1;
        for (int i = 1; i < n; i++) {
            sum[i] = 2 * sum[i - 1] + 3;
            p[i] = 2 * p[i - 1] + 1;
        }
        long ans = f(n, x);
        System.out.println(ans);
    }
    public static long f(int n, long x) {
        if (n == 0 && x == 0) {
            return 0;
        }
        if (n == 0 && x != 0) {
            return 1;
        }
        if (x <= 1) {
            return 0;
        } else if (x <= 1 + sum[n - 1]) {
            return f(n - 1, x - 1);
        } else if (x <= 2 + 2 * sum[n - 1]) {
            return p[n - 1] + 1 + f(n - 1, x - 2 - sum[n - 1]);
        } else {
            return 2 * p[n - 1] + 1;
        }
    }
}