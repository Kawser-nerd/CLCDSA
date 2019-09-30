import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        Map<Integer, Set<Integer>> shipMap = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            shipMap.computeIfAbsent(a, e -> new HashSet<Integer>()).add(b);
        }

        Set<Integer> toSet = shipMap.getOrDefault(1, Collections.emptySet());
        for (Integer i : toSet) {
            Set<Integer> toSet2 = shipMap.getOrDefault(i, Collections.emptySet());
            if (toSet2.contains(n)) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}