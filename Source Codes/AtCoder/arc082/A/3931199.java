import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int[] as = new int[100000 + 1];
        for (int i = 0; i < n; i++) {
            as[sc.nextInt()]++;
        }

        int ans = 0;
        for (int i = 1; i < 100000; i++) {
            ans = Math.max(ans, as[i - 1] + as[i] + as[i + 1]);
        }
        System.out.println(ans);
    }
}