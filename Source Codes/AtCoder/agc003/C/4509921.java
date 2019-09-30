import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    void run() {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] as = new int[n];
        Map<Integer, Integer> dm = new HashMap<>();

        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
            if (i % 2 == 0) {
                dm.put(as[i], dm.getOrDefault(as[i], 0) + 1);
            }
        }

        Arrays.sort(as);

        int cnt = 0;
        for (int i = 0; i < n; i += 2) {
            if (dm.containsKey(as[i]) && dm.get(as[i]) != 0) {
                dm.put(as[i], dm.get(as[i]) - 1);
            } else {
                cnt += 1;
            }
        }

        System.out.println(cnt);
    }

    public static void main(String[] args) {
        new Main().run();
    }
}