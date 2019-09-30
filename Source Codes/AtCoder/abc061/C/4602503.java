import java.math.BigDecimal;
import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        long K = sc.nextLong();

        TreeMap<Integer, Long> map = new TreeMap<>();
        for (int i = 0; i < N; i++) {
            int value = sc.nextInt();
            int count = sc.nextInt();
            map.put(value, map.containsKey(value) ? map.get(value) + count : count);
        }

        long sum = 0;
        for (Map.Entry<Integer, Long> entry: map.entrySet()) {
            if (sum < K && K <= sum + entry.getValue()) {
                System.out.println(entry.getKey());
            }
            sum += entry.getValue();
        }
    }
}