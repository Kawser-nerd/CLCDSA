import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Map.Entry;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        HashMap<Integer, Integer> countMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int key = sc.nextInt();
            countMap.put(key, countMap.getOrDefault(key, 0) + 1);
        }

        long ans = 0l;
        for (Entry<Integer, Integer> e : countMap.entrySet()) {
            if (e.getValue() < e.getKey()) {
                ans += e.getValue();
            } else if (e.getValue() > e.getKey()) {
                ans += e.getValue() - e.getKey();
            }
        }
        System.out.println(ans);
    }
}