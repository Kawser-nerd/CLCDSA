import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        long[] A = new long[N];
        long[] B = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();
            B[i] = sc.nextLong();
        }

        long cnt = 0;
        for (int i = N - 1; i >= 0; i--) {
            A[i] += cnt;
            if (A[i] % B[i] != 0) {
                cnt += ((long) (A[i] / B[i]) + 1) * B[i] - A[i];
            }
        }

        out.println(cnt);
    }
}