import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int k = sc.nextInt();
        long a[] = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        long sum1[] = new long[n + 1];
        long sum2[] = new long[n + 1];
        sum1[0] = 0;
        sum2[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum1[i] = sum1[i - 1] + a[i - 1];
            sum2[i] = sum2[i - 1] + Math.max(0, a[i - 1]);
        }

        long ans = 0;
        for (int i = 0; i <= n - k; i++) {
            ans =
                Math.max(ans, Math.max(0, sum1[i + k] - sum1[i]) + sum2[n] - sum2[i + k] + sum2[i]);
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}