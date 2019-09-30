import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            Set<Character> startSet = new HashSet<>(i);
            for (int j = 0; j < i; j++) {
                startSet.add(s[j]);
            }

            Set<Character> endSet = new HashSet<>(n - i);
            for (int j = i; j < n; j++) {
                endSet.add(s[j]);
            }

            startSet.retainAll(endSet);
            ans = Math.max(ans, startSet.size());
        }

        System.out.println(ans);
    }
}