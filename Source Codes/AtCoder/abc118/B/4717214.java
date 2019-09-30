import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < n; i++) {
            int k = sc.nextInt();
            for(int j = 0; j < k; j++) {
                int a = sc.nextInt();
                int b = 0;
                if(map.containsKey(a)) {
                    b = map.get(a);
                }
                map.put(a, b + 1);
            }
        }
        int ans = 0;
        for(int i : map.values()) {
            if(i == n) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}