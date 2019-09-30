import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long mod = 1_000_000_007;

		long[][][][] dp = new long[N+1][4][4][4];
		for (int c3=0;c3<4;c3++) {
			for (int c2=0;c2<4;c2++) {
				for (int c1=0;c1<4;c1++) {
					if (c3==0 && c2==1 && c1==2) {
						dp[3][c3][c2][c1]=0;
						continue;
					}
					if (c3==1 && c2==0 && c1==2) {
						dp[3][c3][c2][c1]=0;
						continue;
					}
					if (c3==0 && c2==2 && c1==1) {
						dp[3][c3][c2][c1]=0;
						continue;
					}
					dp[3][c3][c2][c1]=1;
				}
			}
		}
		for (int len=3;len<N;len++) {
			for (int c3=0;c3<4;c3++) {
				for (int c2=0;c2<4;c2++) {
					for (int c1=0;c1<4;c1++) {
						for (int a=0;a<4;a++) {
							if (c2==0 && c1==1 && a==2) {
								dp[len+1][c2][c1][a]=0;
								continue;
							}
							if (c2==1 && c1==0 && a==2) {
								dp[len+1][c2][c1][a]=0;
								continue;
							}
							if (c2==0 && c1==2 && a==1) {
								dp[len+1][c2][c1][a]=0;
								continue;
							}
							if (c3==0 && c1==1 && a==2) {
								dp[len+1][c2][c1][a]=0;
								continue;
							}
							if (c3==0 && c2==1 && a==2) {
								dp[len+1][c2][c1][a]=0;
								continue;
							}
							dp[len+1][c2][c1][a]+=dp[len][c3][c2][c1];
							dp[len+1][c2][c1][a]%=mod;
						}
					}
				}
			}
		}
		long ans=0;
		for (int c3=0;c3<4;c3++) {
			for (int c2=0;c2<4;c2++) {
				for (int c1=0;c1<4;c1++) {
					ans += dp[N][c3][c2][c1];
					ans = ans%mod;
				}
			}
		}
		System.out.println(ans);
	}
}