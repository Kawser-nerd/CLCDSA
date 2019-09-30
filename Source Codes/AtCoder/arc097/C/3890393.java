import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] b=new int[n],w=new int[n];
		int[] sk=new int[2*n];
		int[] nama=new int[2*n];
		for(int i=0;i<2*n;i++){
			char ch=sc.next().charAt(0);
			int ind=sc.nextInt()-1;
			if(ch=='W'){
				w[ind]=i;
				sk[i]=0;
				nama[i]=ind;
			}else{
				b[ind]=i;
				sk[i]=1;
				nama[i]=ind;
			}
		}
		int[][] ruib=new int[2*n][n+5];
		int[][] ruiw=new int[2*n][n+5];
		for(int i=0;i<n;i++){
			int num=nama[0];
			if(sk[0]==0){
				if(i<=num) ruiw[0][i]=1;
			}else{
				if(i<=num) ruib[0][i]=1;
			}
		}
		for(int i=1;i<2*n;i++){
			int num=nama[i];
			if(sk[i]==0){
				for(int j=0;j<n;j++){
					if(j<=num){
						ruiw[i][j]=ruiw[i-1][j]+1;
					}else{
						ruiw[i][j]=ruiw[i-1][j];
					}
					ruib[i][j]=ruib[i-1][j];
				}
			}else{
				for(int j=0;j<n;j++){
					if(j<=num){
						ruib[i][j]=ruib[i-1][j]+1;
					}else{
						ruib[i][j]=ruib[i-1][j];
					}
					ruiw[i][j]=ruiw[i-1][j];
				}
			}
			//System.out.println(Arrays.toString(ruib[i]));
			//System.out.println(Arrays.toString(ruiw[i]));
		}
		
		long[][] dp=new long[n+1][n+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				if((i==0)&&(j==0))continue;
				int kind=(i>0)?b[i-1]:-1;
				int wind=(j>0)?w[j-1]:-1;
				long bmin=(kind>=0)?dp[i-1][j]+ruib[kind][i]+ruiw[kind][j]:Integer.MAX_VALUE;
				long wmin=(wind>=0)?dp[i][j-1]+ruib[wind][i]+ruiw[wind][j]:Integer.MAX_VALUE;
				dp[i][j]=Math.min(bmin,wmin);
			}
		}
		System.out.println(dp[n][n]);
	}
}