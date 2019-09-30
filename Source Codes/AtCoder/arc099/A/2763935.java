import java.util.*;

public class Main {

    public static void main(String [] args) {
        final Scanner sc = new Scanner(System.in);
        final int n;
        final int k;
        n = sc.nextInt();
        k = sc.nextInt();
        final int [] number = new int[n];
        int minIdx = 0;
        for (int i = 0; i < n; ++i) {
            number[i] = sc.nextInt();
            if (number[i] == 1) {
                minIdx = i;
            }
        }
        if (k >= n) {
            System.out.println(1);
            return;
        }
        if (n == 1) {
            System.out.println(0);
            return;
        }

        int minCount = Integer.MAX_VALUE;
        for (int left = 1; left <= k; ++left) {
            int leftCount =
                    (minIdx + 1 - left) % (k - 1) == 0 ?
                    (minIdx + 1 - left) / (k - 1) + 1 :
                    (minIdx + 1 - left) / (k - 1) + 1 + 1;
            int right = k - left;

            int rightCount =
                    (n - 1 - minIdx - right) % (k - 1) == 0 ?
                    (n - 1 - minIdx - right) / (k - 1) :
                    (n - 1 - minIdx - right) / (k - 1) + 1;
            int currentCount = leftCount + rightCount;
            if (currentCount < minCount) {
                minCount = currentCount;
            }
        }
        System.out.println(minCount);
    }

}