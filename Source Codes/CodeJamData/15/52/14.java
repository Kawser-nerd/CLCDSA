import java.util.*;
import static java.lang.Math.*;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int zz = 1; zz <= T; zz++) {
            int N = in.nextInt();
            int K = in.nextInt();
            long[] sum = new long[N-K+1];
            for (int i = 0; i < sum.length; i++)
                sum[i] = in.nextInt();
            long[] diff = new long[N];
            long[] A = new long[K];
            long[] B = new long[K];
            for (int i = 0; i + 1 < sum.length; i++) {
                long d = sum[i+1] - sum[i];
                diff[i + K] = diff[i] + d;
                A[i % K] = min(A[i % K], diff[i + K]);
                B[i % K] = max(B[i % K], diff[i + K]);
            }

            long total = 0;
            for (int i = 0; i < K; i++) {
                total -= A[i];
                B[i] -= A[i];
                A[i] = 0;
            }
            Arrays.sort(B);
            long d = sum[0] - total;
            d = ((d % K) + K) % K;
            if (d < 0 || d >= K)
                throw new RuntimeException();
            for (long ans = B[K-1];; ans++) {
                long less = 0;
                for (long b : B)
                    less += ans - b;
                if (less >= d) {
                    System.out.format("Case #%d: %d\n", zz, ans);
                    break;
                }
            }
        }
    }
}
