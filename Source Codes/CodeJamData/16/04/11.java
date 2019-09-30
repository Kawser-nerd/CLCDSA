import java.util.*;
import static java.lang.Math.*;

public class D {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            System.out.format("Case #%d:", t);
            long K = in.nextInt();
            long C = in.nextInt();
            long S = in.nextInt();
            if (C * S < K) {
                System.out.format(" IMPOSSIBLE\n");
                continue;
            }
            int at = 0;
            HashSet<Long> ans = new HashSet<Long>();
            for (int i = 0; i < S; i++) {
                long v = 0;
                for (int j = 0; j < C; j++) {
                    v *= K;
                    v += (at) % K;
                    at++;
                }
                ans.add(v + 1);
                if (at > K)
                    break;
            }
            for (long a : ans)
                System.out.format(" %d", a);
            System.out.format("\n");
        }
    }
}
