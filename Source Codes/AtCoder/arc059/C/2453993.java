import java.util.Arrays;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int C = scan.nextInt();
        long mod = (long)1e9+7;
        long[] A = new long[N];
        long[] B = new long[N];

        //K[i][j] = 0^j + 1^j + 2^j + ... + i^j
        long[][] K = new long[401][401];
        for(int i=0;i<401;++i){
            K[i][0]=1;
            for(int j=1;j<401;++j){
                K[i][j]=(K[i][j-1]*(long)i)%mod;
            }
        }
        for(int i=1;i<401;++i){
            for(int j=0;j<401;++j){
                K[i][j] = (K[i-1][j] + K[i][j])%mod;
            }
        }

        for(int i=0;i<N;++i)A[i]=scan.nextLong();
        for(int i=0;i<N;++i)B[i]=scan.nextLong();
        long[][] dp = new long[N+1][C+1];
        dp[0][0]=1;

        for(int i=0;i<N;++i){
            for(int c=0;c<=C;++c){
                for(int k=0;k<=c;++k)dp[i+1][c] = (dp[i+1][c] + (((K[(int)B[i]][k]-K[(int)A[i]-1][k]+mod)%mod)*dp[i][c-k])%mod)%mod;
            }
        }
        System.out.println(dp[N][C]);
    }
}