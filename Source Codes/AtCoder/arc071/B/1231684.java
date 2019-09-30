import java.util.Arrays;
import java.util.Scanner;

public class Main {

    private static final int MOD = 1000000007;

    public static long sum(long[] x, int n) {
        long s = 0;
        for (int i = 0; i < n; i++) {
            s += i * x[i] % MOD;
            s -= (n - 1 - i) * x[i] % MOD;
            s = (s + MOD) % MOD;
        }
        return s;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] x = new long[n];
        long[] y = new long[m];

        for (int i = 0; i < n; i++) {
            x[i] = sc.nextLong();
        }

        for (int j = 0; j < m; j++) {
            y[j] = sc.nextLong();
        }

        Arrays.sort(x);
        Arrays.sort(y);
        System.out.println(sum(x, n) * sum(y, m) % MOD);
    }
}