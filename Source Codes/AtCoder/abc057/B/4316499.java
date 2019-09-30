import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] ab = new int[n][3];
        int[][] cd = new int[m][2];
        
        for (int i = 0; i < n; i ++) {
            ab[i][0] = sc.nextInt();
            ab[i][1] = sc.nextInt();
        }
        
        for (int i = 0; i < m; i++) {
            cd[i][0] = sc.nextInt();
            cd[i][1] = sc.nextInt();
        }
        
        for (int i = 0; i < n; i++) {
            ab[i][2] = 0;
            int man = Math.abs(ab[i][0] - cd[0][0]) + Math.abs(ab[i][1] - cd[0][1]);
            for (int j = 1; j < m; j++) {
                int x = Math.abs(ab[i][0] - cd[j][0]);
                int y = Math.abs(ab[i][1] - cd[j][1]);
                if (x + y < man) {
                    ab[i][2] = j;
                    man = x + y;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            System.out.println(ab[i][2] + 1);
        }
    }
}