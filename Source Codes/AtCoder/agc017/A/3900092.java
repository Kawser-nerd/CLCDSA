import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int p = sc.nextInt();
        int numOfOdd = 0;
        for (int i = 0; i < n; i++) {
            int tmp = sc.nextInt();
            if (tmp % 2 == 1) {
                numOfOdd++;
            }
        }

        if (numOfOdd == 0) {
            System.out.println(p == 0 ? (long)Math.pow(2, n): 0);
            return;
        }

        System.out.println((long)Math.pow(2, n - 1));
    }
}