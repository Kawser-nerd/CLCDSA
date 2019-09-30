import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        int M = sc.nextInt();
        final int Q = sc.nextInt();
        int[][] LR = new int[N+1][N+1];
        int[][] sum = new int[N+1][N+1];
        for(int i = 0;i < M;i++){
            int li = sc.nextInt();
            int ri = sc.nextInt();
            LR[li][ri]++;
        }
        for(int i = 1;i < N+1;i++){
            for(int j = 1;j < N+1;j++){
                sum[i][j] += sum[i][j-1]+LR[i][j];
            }
        }
        int[] ANS = new int[Q];
        for(int i = 0;i < Q;i++){
            int ans = 0;
            int pi = sc.nextInt();
            int qi = sc.nextInt();
            for(int j = pi;j <= qi;j++){
                ans += sum[j][qi]-sum[j][pi-1];
            }
            ANS[i] = ans;
        }
        for(int i = 0;i < Q;i++)    System.out.println(ANS[i]);
    }
}