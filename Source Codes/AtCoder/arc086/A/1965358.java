import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int N = sc.nextInt();
            int K = sc.nextInt();
            Map<Integer,Integer> map = new HashMap<>();

            for (int i = 0; i < N; i++) {
                int x = sc.nextInt();
                if (!map.containsKey(x)) {
                    map.put(x, 1);
                } else {
                    map.put(x, map.get(x) + 1);
                }
            }

            List<Integer> list = new ArrayList<>(map.values());
            Collections.sort(list);

            int ans = 0;

            for (int i = 0; i < list.size() - K; i++) {
                ans += list.get(i);
            }

            System.out.println(ans);
        }
    }
}