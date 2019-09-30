import java.util.Scanner;

public class Main {

    void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        long[] A = new long[n];

        for (int i = 0; i < n; i++) {
            A[i] = sc.nextLong();
        }
        long[] ba = new long[40];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 40; j++) {
                ba[j] += (A[i] >> j) & 1;
            }
        }

        long[] xors = new long[40];
        for (int j = 0; j < 40; j++) {
            xors[j] = (1L << j) * (ba[j] > n / 2 ? ba[j]: (n - ba[j]));
        }

        long ans = 0;
        long cur = 0;
        for (int j = 39; j >= 0; j--) {
            if (((k >> j) & 1) == 1) {
                long tmp = cur + ba[j] * (1L << j);
                for (int i = 0; i < j; i++) {
                    tmp += xors[i];
                }
                ans = Math.max(ans, tmp);
                cur += (n - ba[j]) * (1L << j);
            } else {
                cur += ba[j] * (1L << j);
            }
        }
        ans = Math.max(ans, cur);
        System.out.println(ans);
    }

    public static void main(String[] args) {
        new Main().run();
    }
}