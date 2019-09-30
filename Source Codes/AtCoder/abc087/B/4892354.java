import java.util.Scanner;

public class Main {
    private static int ROW = 3;
    private static int[] VALUES = {500, 100, 50};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] coins = new int[ROW];
        for (int i = 0; i < ROW; i++) {
            coins[i] = sc.nextInt();
        }
        int x = sc.nextInt();
        int cnt = 0;

        for (int n500 = 0; n500 <= coins[0]; n500++) {
            if (n500 * 500 > x) {
                continue;
            }
            for (int n100 = 0; n100 <= coins[1]; n100++) {
                if (n100 * 100 > x) {
                    continue;
                }
                for (int n50 = 0; n50 <= coins[2]; n50++) {
                    if (n50 * 50 > x) {
                        continue;
                    }

                    int sum = (n500 * 500) + (n100 * 100) + (n50 * 50);
                    if (sum == x) {
                        cnt++;
                    };
                }
            }
        }
        System.out.println(cnt);
    }
}