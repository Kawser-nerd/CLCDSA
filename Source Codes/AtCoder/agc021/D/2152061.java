import java.util.Scanner;
import java.util.Arrays;

class Main{

    static int dp[][][] = new int[301][301][301];

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String S = scan.next();
        int K = scan.nextInt();
        int N = S.length();

        //dp[i][j][x]:[i,j)?x??????????
        for(int i=0;i<N;++i)for(int k=0;k<=K;++k){
            dp[i][i+1][k]=1;
            dp[i][i][k]=0;
        }
        for(int k=0;k<=K;++k){
            for(int L=2;L<=N;++L){
                int i=0,j=L;
                while(j<=N){
                    if(k==0)dp[i][j][k]=Math.max(dp[i+1][j][k],
                                        Math.max(dp[i][j-1][k],
                                        ((S.charAt(i)==S.charAt(j-1) ? dp[i+1][j-1][k]+2 : dp[i+1][j-1][k]))));
                    else dp[i][j][k] = Math.max(dp[i+1][j][k],
                                       Math.max(dp[i][j-1][k],
                                       Math.max(dp[i][j][k-1],
                                       ((S.charAt(i)==S.charAt(j-1) ? dp[i+1][j-1][k]+2 : dp[i+1][j-1][k-1]+2)))));
                    ++i;++j;
                }
            }
        }
        System.out.println(dp[0][N][K]);
    }
}