import java.util.*;
import static java.lang.Math.*;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int zz = 1; zz <= T; zz++) {
            int N = in.nextInt();
            long[] M = new long[N];
            for (int i = 0; i < N; i++)
                M[i] = in.nextInt();
            long ans1 = 0;
            for (int i = 0; i < N - 1; i++) {
                ans1 += max(0, M[i] - M[i+1]);
            }
            long max = 0;
            for (int i = 0; i < N - 1; i++) {
                max = max(max, M[i] - M[i+1]);
            }
            long ans2 = 0;
            for (int i = 0; i < N - 1; i++)
                ans2 += min(max, M[i]);

            System.out.format("Case #%d: %d %d\n", zz, ans1, ans2);
        }
    }
}
