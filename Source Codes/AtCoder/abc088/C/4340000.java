import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] g = new int[3][3];
        for (int i = 0; i < 3; i++) {
            g[i][0] = sc.nextInt();
            g[i][1] = sc.nextInt();
            g[i][2] = sc.nextInt();
        }
        boolean ans = true;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if(g[i][j] - g[i+1][j] != g[i][j+1] - g[i+1][j+1]){
                    ans = false;
                    break;
                }
                if(g[i][j] - g[i][j+1] != g[i+1][j] - g[i+1][j+1]){
                    ans = false;
                    break;
                }
            }
        }

        if(ans) System.out.println("Yes");
        else System.out.println("No");
        sc.close();
    }

}