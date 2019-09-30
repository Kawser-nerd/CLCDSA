import java.util.*;

public class Main {
    public static final int MAX_N = 50;

    public static void main(String[] args) {
        // read inputs
        final long K;
        try (Scanner in = new Scanner(System.in)) {
            K = in.nextLong();
        }

        // solve
        long[] xs = new long[MAX_N];
        final int N = 50;
        for (int i = 0; i < N; i++) {
            if (i < K % N) {
                xs[i] = i + (K / N + 1) * (N + 1) - K;
            } else {
                xs[i] = i + K / N * (N + 1) - K;
            }
        }
        System.out.printf("%d\n", N);
        System.out.printf("%d", xs[0]);
        for (int i = 1; i < N; i++) {
            System.out.printf(" %d", xs[i]);
        }
        System.out.printf("\n");
    }
}