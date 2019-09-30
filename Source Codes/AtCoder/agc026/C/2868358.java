import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        String s = sc.next();
        char s1[] = s.substring(0, n).toCharArray();
        char s2[] = new StringBuilder(s.substring(n, 2 * n)).reverse().toString().toCharArray();

        Map<String, Long> map1 = new HashMap<>();
        Map<String, Long> map2 = new HashMap<>();
        for (int i = 0; i < (1 << n); i++) {
            StringBuilder red1 = new StringBuilder();
            StringBuilder blue1 = new StringBuilder();
            StringBuilder red2 = new StringBuilder();
            StringBuilder blue2 = new StringBuilder();
            for (int j = 0; j < n; j++) {
                if ((i >> j) % 2 == 1) {
                    red1.append(s1[j]);
                    blue2.append(s2[j]);
                } else {
                    blue1.append(s1[j]);
                    red2.append(s2[j]);
                }
            }

            String key1 = red1.toString() + ":" + blue1.toString();
            map1.compute(key1, (k, v) -> v == null ? 1 : v + 1);
            String key2 = red2.toString() + ":" + blue2.toString();
            map2.compute(key2, (k, v) -> v == null ? 1 : v + 1);
        }

        long sum = 0;
        for (Map.Entry<String, Long> entry : map1.entrySet()) {
            String key = entry.getKey();
            sum += entry.getValue() * map2.getOrDefault(key, 0L);
        }
        System.out.println(sum);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}