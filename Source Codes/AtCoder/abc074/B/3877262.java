import java.util.Arrays;
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
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            ans += Math.min(x, k - x) * 2;
        }
        System.out.println(ans);
    }
}