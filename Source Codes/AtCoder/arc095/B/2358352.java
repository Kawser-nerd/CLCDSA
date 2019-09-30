import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        // long startTime = System.currentTimeMillis();

        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();

        Long[] X = new Long[N];
        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextLong();
        }
        scanner.close();

        Arrays.sort(X);

        Long n = X[N - 1];
        Double m = n / 2.0;
        Double d = Double.MAX_VALUE;
        // System.out.println(m);
        Long r = X[N - 1];
        for (int i = 0; i < N - 1; i++) {
            Double s = Math.abs(X[i] - m);
            if (d > s) {
                d = s;
                r = X[i];
            }
        }
        System.out.println(n + " " + r);
        // System.out.println(System.currentTimeMillis() - startTime);
    }
}