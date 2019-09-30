import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int oddCount = 0;
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            if (a % 2 == 1) {
                oddCount++;
            }
        }
        System.out.println(oddCount % 2 == 0 ? "YES" : "NO");
    }
}