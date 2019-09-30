import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] w = sc.next().split("");

        Map<String, Integer> map = new HashMap<>();
        for (String s : w) {
            if (map.containsKey(s)) {
                map.put(s, map.get(s) + 1);
                continue;
            }
            map.put(s, 1);
        }

        for (String key: map.keySet()) {
            if (map.get(key) % 2 == 1) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }

}