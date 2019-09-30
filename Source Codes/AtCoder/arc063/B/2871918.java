import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            int t = sc.nextInt();
            long[] a = new long[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
            }

            long maxDiff = 0;
            long min = Long.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                if ( i != 0 ) {
                    maxDiff = Math.max(maxDiff, a[i] - min);
                }
                min = Math.min(min, a[i]);
            }

            int ans = 0;
            Map<Long, Long> cnt = new HashMap<>();
            for (int i = 0; i < n; i++) {
                long target = a[i] - maxDiff;

                if ( cnt.containsKey(target) ) {
                    ans += cnt.get(target);
                }

                Long tmpCnt = cnt.get(a[i]);
                if ( tmpCnt == null ) {
                    tmpCnt = 0L;
                }
                tmpCnt++;
                cnt.put(a[i], tmpCnt);
            }

            System.out.println(ans);
        }
    }
}