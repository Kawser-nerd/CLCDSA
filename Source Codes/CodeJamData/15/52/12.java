import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int N = sc.nextInt();
            int K = sc.nextInt();
            int[] sums = new int[N - K + 1];
            for (int i = 0; i < N - K + 1; i++) {
                sums[i] = sc.nextInt(); // x[i] + ... + x[i+K-1]
            }
            int[] maxDiff = new int[K];
            int[] minDiff = new int[K];
            for (int i = 0; i < K; i++) {
                int totalDiff = 0;
                for (int j = i; j < N - K; j += K) {
                    totalDiff += sums[j + 1] - sums[j];
                    maxDiff[i] = Math.max(maxDiff[i], totalDiff);
                    minDiff[i] = Math.min(minDiff[i], totalDiff);
                }
            }

            long min = 0;
            long max = Integer.MAX_VALUE;
            while (min < max) {
                long mid = (min + max) / 2; // Check if everything can be in [0,
                                            // mid]
                boolean possible = true;
                long minSum = 0, maxSum = 0;
                for (int i = 0; i < K; i++) {
                    if (maxDiff[i] - minDiff[i] > mid) {
                        possible = false;
                        break;
                    }
                    long minValue = -minDiff[i], maxValue = mid - maxDiff[i]; // Range
                                                                              // for
                                                                              // x[i]
                    minSum += minValue;
                    maxSum += maxValue;
                }
                long target = ((sums[0] - minSum) % K + K) % K + minSum;
                if (possible && target <= maxSum) {
                    max = mid;
                } else {
                    min = mid + 1;
                }
            }
            System.out.println("Case #" + caseNum + ": " + min);
        }
    }
}
