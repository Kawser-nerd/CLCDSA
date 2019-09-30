import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int h=sc.nextInt(),w=sc.nextInt();
		int[][] table = new int[h][w];
		for(int i=0;i<h;i++){
			String str=sc.next();
			for(int j=0;j<w;j++) table[i][j]=(str.charAt(j)=='.'?0:1);
		}
		
		long res=Math.max(h,w);;
		long[][] dp=new long[h][w];
		for(int i=0;i<h;i++){
			dp[i][0]=0;
			if(i==0){
				for(int j=1;j<w;j++){
					dp[i][j]=1;
				}
				res=Math.max(res,maxHistRect(dp[i]));
				continue;
			}
			for(int j=1;j<w;j++){
				if((table[i][j]+table[i][j-1])%2 == (table[i-1][j]+table[i-1][j-1])%2){
					dp[i][j]=dp[i-1][j]+1;
				}else{
					dp[i][j]=1;
				}
			}
			res=Math.max(res,maxHistRect(dp[i]));
			//System.out.println(Arrays.toString(dp[i]));
		}
		System.out.println(res);
	}
	static long maxHistRect(long[] a){
		int n=a.length;
		long res=0;
		int[] stack=new int[n+1];
		int size=0;
		for(int i=0;i<n;i++){
			if((size==0) || (a[stack[size-1]] <= a[i])) stack[size++]=i;
			else{
				while((size>0) && (a[stack[size-1]] > a[i])){
					res=Math.max(res,a[stack[size-1]]*(1+(size==1?i:i-stack[size-2]-1)));
					size--;
				}
				stack[size++]=i;
			}
		}
		while(size>0){
			res=Math.max(res,a[stack[size-1]]*(1+(size==1?n:n-stack[size-2]-1)));
			size--;
		}
		return res;
	}
}