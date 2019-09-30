import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        int[][] matrix = new int[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        int[][] d = warshallFloyd(matrix);
        long ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int a = sc.nextInt();
                if(a > -1) ans += d[a][1];
            }
        }

        System.out.println(ans);
        sc.close();
    }

    public static int[][] warshallFloyd(int[][] matrix){
        int[][] d = matrix.clone();
        int n = matrix.length;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        return d;
    }

}