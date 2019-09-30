import java.util.Arrays;
import java.util.Scanner;

public class Main {

    int n;
    long x;
    long[] as;

    void run() {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        x = sc.nextLong();
        as = new long[n];

        for (int i = 0; i < n; i++) {
            as[i] = sc.nextLong();
        }

        long[][] b = new long[2][n];
        Arrays.fill(b[0], 1L << 50);
        int idx = 1;
        long ans = 1L << 50;
        for (int k = 0; k < n; k++) {
            long sum = 0;
            for (int i = 0; i < n; i++) {
                b[idx][i] = Math.min(b[1 - idx][i], as[(i + n - k) % n]);
                sum += b[idx][i];
            }
            ans = Math.min(ans, k * x + sum);
            idx = 1 - idx;
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        new Main().run();
    }
}