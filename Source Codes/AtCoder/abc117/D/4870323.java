import java.util.*;

import static java.lang.System.*;

public class Main {
    // 2^40 = 1_099_511_627_776
    // 2^39 =   549_755_813_888
    public static final int MAX_BIT = 39;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();

        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();
        }

        int[] oneBitNums = new int[MAX_BIT + 1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= MAX_BIT; j++) {
                if ((A[i] >> j & 1) == 1) {
                    oneBitNums[j]++;
                }
            }
        }

        int[] xBits = new int[MAX_BIT + 1];
        for (int i = MAX_BIT; i >= 0; i--) {
            if (oneBitNums[i] <= N / 2) {
                xBits[i] = 1;
            }
        }

        long X = 0;
        for (int i = MAX_BIT; i >= 0; i--) {
            if (xBits[i] == 1) {
                long num = (long) Math.pow(2.0, i);
                // K???????
                if (X + num <= K) {
                    X += num;
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += X ^ A[i];
        }

        out.println(ans);
    }
}