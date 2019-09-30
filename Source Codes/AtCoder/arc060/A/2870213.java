import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
 
        int N = sc.nextInt();
        int A = sc.nextInt();
 
        int[] X=new int[N];
 
        int sum=0;
        for (int i = 0; i < N; i++) {
            X[i]=sc.nextInt();
            sum+=X[i];
        }
 
        long[][][] dp=new long[N+1][N+1][sum+1];
 
        dp[0][0][0]=1;
 
        for (int j = 1; j < N+1; j++) {
            for (int k = 0; k < N+1; k++) {
                    for (int s = 0; s <sum+1; s++) {
 
                    if(s<X[j - 1]) {
                        dp[j][k][s]=dp[j-1][k][s];
                    }else if(k>=1 && s>=X[j - 1]) {
                        dp[j][k][s]=dp[j-1][k][s]+dp[j-1][k-1][s-X[j - 1]];
                    }else {
                        dp[j][k][s]=0;
                    }
 
                }
            }
        }
 
        long ans=0;
        for (int k = 1; k < N+1 && k * A < sum + 1; k++) {
            ans+=dp[N][k][k*A];
        }
 
        System.out.println(ans);
    }
}