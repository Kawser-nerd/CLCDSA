import java.util.*;
import java.lang.*;


public class Main {
    static long dp[][] = new long[51][51];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int p = sc.nextInt();
        int a[] = new int[n];
        int odd = 0;
        int even = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if (a[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        long count = 0;
        long sumo = 0;
        long sume = 0;
        if (p == 0) {
            for (int i = 0; i <= odd; i += 2) {
                sumo += combination(odd, i);
            }
            for (int i = 0; i <= even; i++) {
                sume += combination(even, i);
            }
            count = sumo * sume;
            System.out.println(count);
        } else {
            for (int i = 1; i <= odd; i += 2) {
                sumo += combination(odd, i);
            }
            for (int i = 0; i <= even; i++) {
                sume += combination(even, i);
            }
            count = sumo * sume;
            System.out.println(count);
        }
    }
    static long combination(int n, int k) {
        if (n == k || k == 0) {
            return 1;
        } else if (dp[n][k] != 0) {
            return dp[n][k];
        }
        return dp[n][k] = combination(n - 1, k) + combination(n - 1, k - 1);
    }
}