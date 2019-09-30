import java.util.*;

public class Main {

    public void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        Map<Integer, Integer> countMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            countMap.put(a, countMap.getOrDefault(a, 0) + 1);
        }

        List<Integer> counts = new ArrayList<>(countMap.values());
        Collections.sort(counts);

        int ans = 0;
        for (int i = 0; i < counts.size() - k; i++) {
            ans += counts.get(i);
        }

        System.out.println(ans);
    }

    public static void main(String[] args){
        new Main().run();
    }
}