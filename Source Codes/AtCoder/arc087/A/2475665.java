import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            map.compute(a, (k, v) -> v == null ? 1 : v + 1);
        }

        int res = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();
            if (key < value) {
                res += value - key;
            } else if (key > value) {
                res += value;
            }
        }
        System.out.println(res);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}