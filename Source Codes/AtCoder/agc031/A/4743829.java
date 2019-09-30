import java.util.*;
public class Main {
    static long INF = 1000000007;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (!map.containsKey(ch)) {
                map.put(ch, 0);
            }
            map.put(ch, map.get(ch) + 1);
        }
        long ans = 1;
        for (char key : map.keySet()) {
            ans *= map.get(key) + 1;
            ans %= INF;
        }
        ans--;
        System.out.println(ans);
    }
}