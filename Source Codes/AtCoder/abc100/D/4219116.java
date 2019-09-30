import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        long [] x = new long[n];
        long [] y = new long[n];
        long [] z = new long[n];
        for (int i = 0; i < n; ++i) {
            x[i] = scanner.nextLong();
            y[i] = scanner.nextLong();
            z[i] = scanner.nextLong();
        }
        int[] scale = {-1, 1};
        long result = 0;
        for (int a = 0; a < 2; ++a) {
            for (int b = 0; b < 2; ++b) {
                for (int c = 0; c < 2; ++c) {
                    PriorityQueue<Long> sum = new PriorityQueue<>(Comparator.reverseOrder());
                    long currentSum = 0;
                    for (int i = 0; i < n; ++i) {
                        long current = scale[a] * x[i] +
                                scale[b] * y[i] +
                                scale[c] * z[i];
                        sum.add(current);
                    }
                    for (int i = 0; i < m; ++i) {
                        currentSum += sum.poll();
                    }
                    result = Math.max(result, currentSum);
                }
            }
        }
        System.out.println(result);
    }
}