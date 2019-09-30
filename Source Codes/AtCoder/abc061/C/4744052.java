import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();

        Map<Integer, Long> map = new TreeMap<>();
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            long b = sc.nextInt();

            if (map.containsKey(a)) {
                b += map.get(a);
            }

            map.put(a, b);
        }

        for (Map.Entry entry : map.entrySet()) {
            K -= (long) entry.getValue();
            if (K <= 0) {
                out.print(entry.getKey());
                return;
            }
        }
    }
}