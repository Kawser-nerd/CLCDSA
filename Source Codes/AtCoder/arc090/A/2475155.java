import java.util.Scanner;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int map[][] = new int[2][n];
        int sum[][] = new int[2][n];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        sum[0][0] = map[0][0];
        for (int j = 1; j < n; j++) {
            sum[0][j] = sum[0][j - 1] + map[0][j];
        }

        sum[1][0] = sum[0][0] + map[1][0];
        for (int j = 1; j < n; j++) {
            sum[1][j] = Math.max(sum[0][j], sum[1][j - 1]) + map[1][j];
        }

        System.out.println(sum[1][n - 1]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}