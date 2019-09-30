import java.util.*;

public class Main {
    public static final long INF = 1000000000000000000L;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        final int N = in.nextInt();
        long[] as = new long[N];
        for (int i = 0; i < N; i++) {
            as[i] = in.nextLong();
        }

        long K = 0;
        while (true) {
            boolean isFinished = true;
            for (int i = 0; i < N; i++) {
                final long k = as[i] / N;
                if (k > 0) {
                    isFinished = false;
                    K += k;
                    for (int j = 0; j < N; j++) {
                        if (j == i) {
                            as[j] = as[j] % N;
                        } else {
                            as[j] += k;
                        }
                    }
                }
            }
            if (isFinished) {
                break;
            }
        }
        System.out.printf("%d\n", K);
    }
}