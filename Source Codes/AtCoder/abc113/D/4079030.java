import java.util.Scanner;
public class Main{
	static long mod=1_000_000_007;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int k = sc.nextInt();
		long[][] dp = new long[h+1][w+2];
		dp[0][1]=1;
		for(int i = 0; i<h; i++){
			for(int j = 1; j<=w; j++){
				long left = j-2;
				long right = w-j-1;
				long straight = bit(left)*bit(right);
				long Left = bit(left-1)*bit(right);
				long Right = bit(left)*bit(right-1);
				dp[i+1][j]=(dp[i][j]*straight+dp[i][j-1]*Left+dp[i][j+1]*Right)%mod;
			}
		}
		System.out.println(dp[h][k]);
	}
	public static long bit(long number){
		if(number<=0){
			return 1;
		}
		long ans=0;

	as:for(long i=0; i<Math.pow(2,number); i++){
			for(long k = 0; k<number; k++){
				if(k!=0){
					if((i>>k & 1)==1 && (i>>k-1 & 1)==1 ){
						continue as;
					}
				}
			}
			ans++;
		}
		return ans;
	}
}