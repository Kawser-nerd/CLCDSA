import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        long[] sum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
            sum[i + 1] += a[i] + sum[i];
        }
        Map<Long, Integer> map = new HashMap<>();
        for (int i = 0; i < n + 1; i++) {
            if (map.containsKey(sum[i])) {
                map.put(sum[i], map.get(sum[i]) + 1);
            } else {
                map.put(sum[i], 1);
            }
        }
        long count = 0;
        for (Entry<Long, Integer> entry : map.entrySet()) {
                count += (long) entry.getValue() * (entry.getValue() - 1) / 2;
        }
        System.out.println(count);

    }

}