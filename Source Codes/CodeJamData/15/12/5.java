import java.util.*;
import static java.lang.Math.*;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int zz = 1; zz <= T; zz++) {
            int B = in.nextInt();
            long N = in.nextInt();
            long[] M = new long[B];
            for (int i = 0; i < B; i++)
                M[i] = in.nextInt();

            long start = 0;
            long end = (long)1e16;
            while (start < end) {
                long mid = (start + end) / 2;
                long count = 0;
                for (long t : M) {
                    count += (mid / t) + 1;
                }
                if (count >= N) {
                    end = mid;
                } else {
                    start = mid + 1;
                }
            }
            long count = 0;
            long exact = 0;
            for (long t : M) {
                count += (start / t) + 1;
                if (start % t == 0)
                    exact++;
            }
            long before = count - exact;
            int ans = -1;
            for (int i = 0; i < B; i++) {
                if (start % M[i] != 0)
                    continue;
                if (before + 1 == N) {
                    ans = i;
                    break;
                }
                before++;
            }
            System.out.format("Case #%d: %d\n", zz, ans + 1);
        }
    }
}
