import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        long X = sc.nextLong();

        long[] layers = new long[100];
        long[] paties = new long[100];
        layers[0] = 1;
        paties[0] = 1;
        for (int i = 1; i <= N; i++) {
            layers[i] = layers[i-1] * 2L + 3;
            paties[i] = paties[i-1] * 2L + 1;
        }
        System.out.println(paty(N, X, layers, paties));
    }

    private static long paty(int N, long X, long[] layers, long[] paties) {
        if (X == 0) {
            return 0;
        }
        if (N == 0) {
            return 1;
        }
        if (X < layers[N - 1] + 2) {
            return paty(N - 1, X - 1, layers, paties);
        } else {
            return paties[N - 1] + 1 + paty(N - 1, X - layers[N - 1] - 2, layers, paties);
        }
    }
}