import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextInt();
        long K = sc.nextInt();

        long comb = 0;

        // ??????
        // K???K, K???????????? x 3!
        comb += (K - 1) * (N - K) * 6;

        // 2?????
        // K??, K, K x 3?? + K, K, K????? x 3??
        comb += (K - 1) * 3;
        comb += (N - K) * 3;

        // 3????????(K??)
        comb++;

        // ??????
        double allComb = Math.pow(N, 3);

        out.println((double)comb / allComb);
    }
}