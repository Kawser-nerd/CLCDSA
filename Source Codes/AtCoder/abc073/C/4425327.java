import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Long> a = new ArrayList<>();
        IntStream.range(0, n).forEach(i -> a.add(sc.nextLong()));

        int count = 0;
        Map<Long, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            long target = a.get(i);
            if (map.containsKey(target)) {
                map.put(target, map.get(target) + 1);
                continue;
            }
            map.put(target, 1);
        }
        for (Long key : map.keySet()) {
            if (map.get(key) % 2 != 0) {
                count++;
            }
        }
        System.out.println(count);
    }

}