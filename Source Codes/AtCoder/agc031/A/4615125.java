import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0 ; i < n ; i++) {
            String t = s.substring(i, i + 1);
            if (map.containsKey(t)) {
                map.put(t, map.get(t) + 1);
            } else {
                map.put(t, 1);
            }
        }
        long mod = 1000000007;
        long sum = 1l;
        for (Entry<String, Integer> entry : map.entrySet()) {
            long c = entry.getValue();
            sum *= (long) (c + 1) % mod;
            sum %= (long) mod;
        }

        System.out.println(sum - 1);

    }

}