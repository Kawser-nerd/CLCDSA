import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }

        int minCost = Integer.MAX_VALUE;
        for (int i = -100; i <= 100; i++) {
            int num = i;
            int cost = 0;
            for (int j = 0; j < n; j++) {
                if (as[j] != num) {
                    cost += (num - as[j]) * (num - as[j]);
                }
            }
            minCost = Math.min(minCost, cost);
        }
        System.out.println(minCost);
    }
}