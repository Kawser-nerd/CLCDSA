import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int N = sc.nextInt();
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int i = 0; i < N; i++) {
                int x = sc.nextInt();
                int c = 1;
                if (cnt.containsKey(x)) {
                    c = cnt.get(x) + 1;
                }
                cnt.put(x, c);
            }
            int ans = 0;
            for (int x : cnt.keySet()) {
                int c = cnt.get(x);
                if (c < x) {
                    ans += c;
                } else if (c > x) {
                    ans += c - x;
                }
            }
            System.out.println(ans);
        }
    }
}