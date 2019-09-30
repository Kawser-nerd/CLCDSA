import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        long[] a = new long[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextLong();
        }

        long[] acc = new long[N + 1];
        for (int i = 0; i < N; i++) {
            acc[i + 1] = acc[i] + a[i];
        }

        Map<Long, Integer> cnts = new HashMap<>();
        for (int i = 0; i <= N; i++) {
            int cnt = cnts.containsKey(acc[i]) ? cnts.get(acc[i]) : 0;
            cnts.put(acc[i], ++cnt);
        }

        long ans = 0;
        for (Map.Entry e : cnts.entrySet()) {
            int num = (int) e.getValue();
            ans += (long) num * (num - 1) / 2;
        }

        out.println(ans);
    }
}