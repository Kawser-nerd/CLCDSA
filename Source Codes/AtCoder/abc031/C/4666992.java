import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int[] values = new int[N];
        for (int i = 0; i < N; i++) {
            values[i] = sc.nextInt();
        }

        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < N; i++) {
            int aokiSum = Integer.MIN_VALUE;
            int aokiPosi = 0;
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                int tmp = 0;
                for (int k = Math.min(i, j); k <= Math.max(i, j); k++) {
                    if ((k - Math.min(i, j) + 1) % 2 == 0) {
                        tmp += values[k];
                    }
                }
                if (tmp > aokiSum) {
                    aokiPosi = j;
                    aokiSum = tmp;
                }
            }
            int tmp = 0;
            for (int k = Math.min(i, aokiPosi); k <= Math.max(i, aokiPosi); k++) {
                if ((k - Math.min(i, aokiPosi) + 1) % 2 == 1) {
                    tmp += values[k];
                }
            }
            ans = Math.max(tmp, ans);
        }
        System.out.println(ans);
    }
}