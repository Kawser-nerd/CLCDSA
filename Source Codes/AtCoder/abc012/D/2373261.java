import java.util.Scanner;

public class Main {
    static int[][] map;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        map = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    map[i][j] = 1 << 29;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            int t = sc.nextInt();
            map[a][b] = t;
            map[b][a] = t;
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int a = Math.min(map[j][k], map[j][i] + map[i][k]);
                    map[j][k] = a;
                    map[k][j] = a;
                }
            }
        }

        int min = 1 << 29;
        for (int i = 0; i < n; i++) {
            int max = 0;
            for (int j = 0; j < n; j++) {
                max = Math.max(max, map[i][j]);
            }
            if (min > max) {
                min = max;
            }
        }
        System.out.println(min);
    }


}