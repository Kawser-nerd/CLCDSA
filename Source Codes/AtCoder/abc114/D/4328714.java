import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    private int prime[] = { 2, 3, 5, 7 };
    private int target[] = { 2, 4, 14, 24, 74 };

    public void main(Scanner sc) {
        int n = sc.nextInt();

        // 9! ?????????
        if (n < 10) {
            System.out.println(0);
            return;
        }

        // n! ??????
        List<Integer> list = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            int tmp = i;
            for (int j = 0; j < 4; j++) {
                if (tmp % prime[j] == 0) {
                    while (tmp % prime[j] == 0) {
                        list.add(prime[j]);
                        tmp /= prime[j];
                    }
                }
            }
            if (tmp != 1) {
                list.add(tmp);
            }
        }

        // ????????????
        Map<Integer, Long> map =
            list.stream().collect(Collectors.groupingBy(p -> p, Collectors.counting()));

        // 2,4,14,24,74 ?????????????????
        int tmp[] = new int[5];
        for (Long cnt : map.values()) {
            for (int i = 0; i < 5; i++) {
                if (cnt >= target[i]) {
                    tmp[i]++;
                }
            }
        }

        int ans = 0;
        // p^74 ?????
        ans += tmp[4];

        // p^2*q^24 ?????
        if (tmp[3] > 0) {
            ans += (tmp[0] - tmp[3]) * tmp[3];
            ans += tmp[3] * (tmp[3] - 1);
        }

        // p^4*q^14 ?????
        if (tmp[2] > 0) {
            ans += (tmp[1] - tmp[2]) * tmp[2];
            ans += tmp[2] * (tmp[2] - 1);
        }

        // p^2*q^4*r^4 ?????
        if (tmp[1] >= 2) {
            ans += (tmp[0] - tmp[1]) * tmp[1] * (tmp[1] - 1) / 2;
            ans += tmp[1] * (tmp[1] - 1) * (tmp[1] - 2) / 2;
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().main(sc);
        } catch (Exception e) {
            throw e;
        }
    }
}