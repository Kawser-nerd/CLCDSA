import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            long[] t = new long[n];
            long sumA = 0, sumB = 0;
            for (int i = 0; i < n; i++) {
                t[i] = sc.nextLong();
                sumB += t[i];
            }

            long ans = Long.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                sumA += t[i];
                sumB -= t[i];
                if ( i == n - 1 ) {
                    continue;
                }
                ans = Math.min(ans, Math.abs(sumA - sumB));
            }
            System.out.println(ans);
        }
    }
}