import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		long l=sc.nextLong();
		int n=sc.nextInt();
		long[] x=new long[n];
		for(int i=0;i<n;i++) x[i]=sc.nextLong();
		long[] y=new long[n];
		for(int i=0;i<n;i++) y[i]=l-x[n-1-i];
		/*
		long res=brute(x,l);
		
		
		pl(res);*/
		
		long res2=Math.max(sol(x,l),sol(y,l));
		pl(res2);
	}
	static long sol(long[] x,long l){
		int n=x.length;
		long nega=0;
		long res=0;
		for(int i=0;i<n;i++){//houkou suu
			if(i==0){
				long sum=x[n-1];
				nega=l-x[n-1];
				res=Math.max(res,sum);
			}else{
				long sum=l*(i+1);
				if(i%2==0){
					nega+=(x[n-1-i/2+1]-x[n-1-i/2+1-(i/2+1)])*2-(x[n-1+1-i/2]-x[n-1+1-i/2-1]);
				}else{
					nega+=(x[n-1-i/2]-x[n-1-i/2-(i/2+1)])*2;
				}
				sum-=nega;
				res=Math.max(res,sum);
			}
		}
		return res;
	}
	static long brute(long[] x,long l){
		int n=x.length;
		
		long[][][] dp=new long[n+1][n+1][2];
		for(int i=0;i<=n;i++){
			for(int j=0;i+j<=n;j++){
				if(i==0 && j==0)continue;
				
				//dp[i][j]
				//dp[i-1][j][0] dp[i-1][j][1]
				long it1=(i-1<=0)?0:x[i-2];
				long it2=(j==0)?0:x[n-1-j+1];
				dp[i][j][0]=(i==0)?0:Math.max((x[i-1]-it1+l)%l+dp[i-1][j][0],(x[i-1]-it2+l)%l+dp[i-1][j][1]);
				//dp[i][j-1][0] dp[i][j-1][1]
				long it3=(i==0)?0:x[i-1];
				long it4=(j-1<=0)?0:x[n-1-j+2];
				dp[i][j][1]=(j==0)?0:Math.max((it3-x[n-1-j+1]+l)%l+dp[i][j-1][0],(it4-x[n-1-j+1]+l)%l+dp[i][j-1][1]);
			}
		}
		long res=0;
		for(int i=0;i<=n;i++){
			res=Math.max(res,dp[i][n-i][0]);
			res=Math.max(res,dp[i][n-i][1]);
		}
		return res;
	}
	static void pl(Object o){
		System.out.println(o);
	}
}