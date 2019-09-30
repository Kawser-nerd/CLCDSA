import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int c=sc.nextInt();
		int[] a=new int[n];
		int[] b=new int[n];
		for(int i=0;i<n;i++) a[i]=sc.nextInt();
		for(int i=0;i<n;i++) b[i]=sc.nextInt();
		
		long mod=1000000007;
		
		long[][] table=new long[1000][1000];
		for(int i=0;i<table.length;i++){
			long sum=0;
			for(int j=0;j<table[i].length;j++){
				sum=(sum+modPow(j,i,mod))%mod;
				table[i][j]=sum;
			}
		}
		
		long[][] dp=new long[n][c+1];
		for(int i=0;i<n;i++){
			if(i==0){
				for(int j=0;j<=c;j++){
					dp[i][j]=(table[j][b[i]]-table[j][a[i]-1]+mod)%mod;
				}
			}else{
				for(int j=0;j<=c;j++){
					for(int k=0;k<=j;k++){
						dp[i][j]+=dp[i-1][j-k]*(table[k][b[i]]-table[k][a[i]-1]+mod)%mod;
						dp[i][j]%=mod;
					}
				}
			}
		}
		System.out.println(dp[n-1][c]);
	}
	static long modPow(long a,long b,long mod){
		long res=1;
		long c=a;
		while(b>0){
			if(b%2==1) res=(res*c)%mod;
			c=(c*c)%mod;
			b/=2;
		}
		return res;
	}
}