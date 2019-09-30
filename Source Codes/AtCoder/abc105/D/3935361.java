import java.util.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long m = sc.nextLong();
        long[] sum = new long[n + 1];
        Map<Long, Long> map = new TreeMap<>();
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + sc.nextLong();
            if (!map.containsKey(sum[i + 1] % m)) {
                map.put(sum[i + 1] % m, 1l);
                list.add(sum[i + 1] % m);
            } else {
                map.put(sum[i + 1] % m, map.get(sum[i + 1] % m) + 1);
            }
        }
        long count = 0;
        for (int i = 0; i < map.size(); i++) {
            long tmp = map.get(list.get(i));
            if (list.get(i) == 0) {
                count += tmp + tmp * (tmp - 1) / 2;
            } else {
                count += tmp * (tmp - 1) / 2;
            }
        }
        System.out.println(count);
    }
}