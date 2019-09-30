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
        int ans = 0;
        int[] points = new int[n];
        for (int i = 0; i < n; i++) {
            points[i] = sc.nextInt();
            ans += points[i];
        }

        Arrays.sort(points);
        for (int i = 0; i < n && ans % 10 == 0; i++) {
            if (points[i] % 10 != 0) {
                ans -= points[i];
            }
        }
        System.out.println(ans % 10 == 0 ? 0 : ans);
    }
}