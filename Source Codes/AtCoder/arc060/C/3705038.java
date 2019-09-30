import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[] aa=new long[n];
		for(int i=0;i<n;i++) aa[i]=sc.nextLong();
		long l=sc.nextLong();
		
		int[][] dp=new int[n][33];
		int right=n-1;
		for(int i=n-1;i>=0;i--){
			while((aa[right]-aa[i])>l)right--;
			dp[i][0]=right;
		}
		dp[n-1][0]=n;
		for(int i=1;i<33;i++){
			for(int j=n-1;j>=0;j--){
				dp[j][i]=(dp[j][i-1]==n?n:dp[dp[j][i-1]][i-1]);
			}
		}
		
		for(int q=sc.nextInt();q>0;q--){
			int a=sc.nextInt()-1;
			int b=sc.nextInt()-1;
			if(a>b){
				int c=a;
				a=b;
				b=c;
			}
			
			long res=0;
			int cur=a;
			while(cur<b){
				int bit=0;
				while(dp[cur][bit]<=b)bit++;
				bit--;
				if(bit<0){
					res++;
					break;
				}
				res+=(1L << bit);
				cur=dp[cur][bit];
			}
			pl(res);
		}
	}
		static void pl(Object o){System.out.println(o);}
}