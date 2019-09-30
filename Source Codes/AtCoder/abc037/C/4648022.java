import java.math.BigDecimal;
import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int K = sc.nextInt();

        long[] scales = new long[N];
        long max = N - K + 1;
        for (int i = 0; i < N; i++) {
            if (i < K) {
                scales[i] = Math.min(max, i + 1);
            } else if (i + K >= N) {
                scales[i] = Math.min(max, N - i);
            } else {
                scales[i] = Math.min(max, K);
            }
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            long value = sc.nextLong();
            ans += value * scales[i];
        }

        System.out.println(ans);
    }
}