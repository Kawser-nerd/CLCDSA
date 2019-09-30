import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();

        if (Math.abs(n - m) >= 2) {
            System.out.println(0);
            return;
        }

        long ans = (m == n) ? 2 : 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans * i) % (1_000_000_000 + 7);
        }

        for (int i = 1; i <= m; i++) {
            ans = (ans * i) % (1_000_000_000 + 7);
        }

        System.out.println(ans);
    }
}