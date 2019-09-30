import static java.util.function.Function.*;
import static java.util.stream.Collectors.*;

import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        Long v[] = new Long[n];
        for (int i = 0; i < n; i++) {
            v[i] = sc.nextLong();
        }

        Arrays.sort(v, (o1, o2) -> Long.compare(o2, o1));
        Long sum[] = new Long[n];
        sum[0] = v[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + v[i];
        }
        Map<Long, Long> map = Arrays.stream(v).collect(groupingBy(identity(), counting()));

        long max = 0;
        long select = 1;
        long cnt = 0;
        for (int i = a; i <= b; i++) {
            if (max * i <= sum[i - 1] * select) {
                if (max * i == sum[i - 1] * select) {
                    cnt += calc(i, v, map);
                } else {
                    cnt = calc(i, v, map);
                }
                max = sum[i - 1];
                select = i;
            }
        }

        System.out.println(String.format("%f", (max * 1.0 / select)));
        System.out.println(cnt);
    }

    private long calc(int cnt, Long v[], Map<Long, Long> map) {
        long nowv = v[cnt - 1];
        long all = map.get(nowv);
        long now = 0;
        while ((now + cnt) < v.length && v[(int) (now + cnt)] == nowv) {
            now++;
        }

        if (all / 2 < now) {
            now = all - now;
        }

        long ans = 1;
        for (long i = 0; i < now; i++) {
            ans *= (all - i);
            ans /= (i + 1);
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}