import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int k = sc.nextInt();
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int key = sc.nextInt();
            countMap.put(key, countMap.getOrDefault(key, 0) + 1);
        }

        ArrayList<Integer> countList = new ArrayList<>(countMap.values());
        Collections.sort(countList);
        int ans = 0;
        for (int i = 0; i < countList.size() - k; i++) {
            ans += countList.get(i);
        }
        System.out.println(ans);
    }
}