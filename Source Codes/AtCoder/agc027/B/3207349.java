import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long X = sc.nextLong();

        long[] positionArr = new long[N];
        long[] cumulativeSum = new long[N+1];

        for (int i = 0; i < N; i++) {
            positionArr[i] = sc.nextLong();
            cumulativeSum[i+1] = cumulativeSum[i] + positionArr[i];
        }

        long sum = X * N + 5 * cumulativeSum[N];

        for (int i = 1; i < N; i++) {
            long cost = X * i + 5 * (cumulativeSum[N] - cumulativeSum[N - i]);
            for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
                if (cost > sum) {
                    break;
                }
                cost += j * (cumulativeSum[k] - cumulativeSum[Math.max(k - i, 0)]);
            }
            sum = Math.min(sum, cost);
        }
        System.out.println(sum + X * N);

    }
}