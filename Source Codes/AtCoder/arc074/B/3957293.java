import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long [] a = new long[n * 3];
        for (int i = 0; i < 3 * n; ++i) {
            a[i] = scanner.nextLong();
        }
        final PriorityQueue<Long> firstHalf = new PriorityQueue<>();
        final PriorityQueue<Long> secondHalf = new PriorityQueue<>(Comparator.reverseOrder());
        long [] leftSum = new long[n + 1];
        long [] rightSum = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            firstHalf.add(a[i]);
            leftSum[0] += a[i];
        }
        for (int i = n; i < 2 * n; ++i) {
            firstHalf.add(a[i]);
            long head = firstHalf.poll();
            leftSum[i - n + 1] = leftSum[i - n] + a[i] - head;
        }
        for (int i = 3 * n - 1; i >= 2 * n; --i) {
            secondHalf.add(a[i]);
            rightSum[n] += a[i];
        }
        for (int i = 2 * n - 1; i >= n; --i) {
            secondHalf.add(a[i]);
            long head = secondHalf.poll();
            rightSum[i - n] = rightSum[i - n + 1] + a[i] - head;
        }
        long result = Long.MIN_VALUE;
        for (int i = 0; i <= n; ++i) {
            result = Math.max(result, leftSum[i] - rightSum[i]);
        }
        System.out.println(result);

    }
}