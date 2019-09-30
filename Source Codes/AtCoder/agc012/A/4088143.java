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
        int[] as = new int[3 * n];
        for (int i = 0; i < 3 * n; i++) {
            as[i] = sc.nextInt();
        }

        Arrays.sort(as);
        long ans = 0l;
        for (int i = 0; i < n; i++) {
            ans += as[3 * n - 2 - (i * 2)];
        }
        System.out.println(ans);
    }
}