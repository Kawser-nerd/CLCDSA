import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
import java.util.Map.Entry;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        Map<Integer, Integer> aMap = new TreeMap<>((x, y) -> y - x);
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            Integer count = aMap.getOrDefault(a, 0) + 1;
            aMap.put(a, count);
        }

        long x = 0;
        for (Entry<Integer, Integer> e : aMap.entrySet()) {
            if (e.getValue() >= 4 && x == 0) {
                System.out.println((long)e.getKey() * e.getKey());
                return;
            }

            if (e.getValue() >= 2 && x == 0) {
                x = e.getKey();
                continue;
            }

            if (e.getValue() >= 2) {
                System.out.println(x * e.getKey());
                return;
            }
        }
        System.out.println(0);
    }
}