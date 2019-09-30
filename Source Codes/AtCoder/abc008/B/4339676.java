import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            if (map.containsKey(s)) {
                map.put(s, map.get(s) + 1);
            } else {
                map.put(s, 1);
            }
        }
        Pair ans = new Pair("", 0);
        for (Map.Entry<String, Integer> ele : map.entrySet()) {
            if (ans.count < ele.getValue()) {
                ans = new Pair(ele.getKey(), ele.getValue());
            }
        }
        System.out.println(ans.name);
    }

    static class Pair {

        String name;
        int count;

        public Pair(String name, int count) {
            this.name = name;
            this.count = count;
        }
    }
}