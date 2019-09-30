import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		long mod=1000000007;
		long[][][][] dp=new long[n+1][4][4][4];
		dp[0][3][3][3]=1;
		for(int i = 1; i<=n; i++){
			for(int j=0; j<4; j++){
				for(int k=0; k<4; k++){
					for(int l =0; l<4; l++){
						if(dp[i-1][j][k][l]==0){
							continue;
						}
						for(int u=0; u<4; u++){
							if(u==2 && k==0 && l==1){
								continue;
							}else if(u==2 && k==1 && l==0){
								continue;
							}else if(u==1 && l==2 && k==0){
								continue;
							}else if(u==2 && j==0 && k==1){
								continue;
							}else if(u==2 && l==1 && j==0){
								continue;
							}
							dp[i][k][l][u]+=dp[i-1][j][k][l];
							dp[i][k][l][u]%=mod;
						}
					}
				}
			}
		}
		long ans=0;
		for(int i = 0; i<4; i++){
			for(int j = 0; j<4; j++){
				for(int k = 0; k<4; k++){
					ans+=dp[n][i][j][k];
					ans%=mod;
				}
			}
		}
		System.out.println(ans);
	}
}