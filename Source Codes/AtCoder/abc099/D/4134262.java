import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        final int C = sc.nextInt();
        int[][] A = new int[3][C+1];
        int[][] D = new int[C+1][C+1];
        int[][] B = new int[3][C+1];
        int ans = Integer.MAX_VALUE;
        for(int i = 1;i <= C;i++)   for(int j = 1;j <= C;j++)   D[i][j] = sc.nextInt();
        for(int i = 1;i <= N;i++){
            for(int j = 1;j <= N;j++){
                int r = (i+j)%3;
                int cij = sc.nextInt();
                A[r][cij]++;
            }
        }
        for(int i = 0;i < 3;i++){
            for(int j = 1;j <= C;j++){
                for(int k = 1;k <= C;k++){
                    B[i][j] += D[k][j]*A[i][k];
                }
            }
        }
        for(int i = 1;i <= C;i++){
            for(int j = 1;j <= C;j++){
                for(int k = 1;k <= C;k++){
                    if(i != j && i != k && j != k){
                        ans = Math.min(ans, B[0][i]+B[1][j]+B[2][k]);
                    }
                }
            }
        }
        System.out.println(ans);
    }
}