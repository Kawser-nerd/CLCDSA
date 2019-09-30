import java.util.Arrays;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        int[] hito = new int[n + 1];
        int[][] map = new int[n + 1][n + 1];
        for (int i = 0; i < n + 1; i++) {
            Arrays.fill(map[i], 0);
        }
        Arrays.fill(hito, 0);
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            map[a[i]][b[i]]++;
            map[b[i]][a[i]]++;
        }
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == j) {
                    continue;
                }
                if (map[i][j] == 1) {

                } else {
                    for (int k = 0; k < n + 1; k++) {
                        int gyou = map[i][k];
                        int retu = map[k][j];
                        if (gyou == 1 && retu == 1) {
                            map[i][j] = 2;
                        }
                    }
                }
            }
        }
        for (int i = 1; i < n + 1; i++) {
            int cnt = 0;
            for (int j = 1; j < n + 1; j++) {
                if (map[i][j] == 2) {
                    cnt++;
                }
            }
            System.out.println(cnt);
        }
        sc.close();
    }
}