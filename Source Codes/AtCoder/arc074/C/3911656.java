import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		int[] l=new int[m],r=new int[m],x=new int[m];
		for(int i=0;i<m;i++){
			l[i]=sc.nextInt();
			r[i]=sc.nextInt();
			x[i]=sc.nextInt();
		}
		Integer[] ind=new Integer[m];
		for(int i=0;i<m;i++) ind[i]=i;
		Arrays.sort(ind,(z,w)-> r[z]-r[w]);
		
		int mod=1000000007;
		
		int[][][] dp=new int[n+1][n+1][n+1];
		dp[1][0][0]=1;
		dp[0][1][0]=1;
		dp[0][0][1]=1;
		int iin=0;
		for(int i=1;i<=n;i++){
			while((iin < m) && (i == r[ind[iin]])){
				for(int j=0;j<i;j++){
					for(int k=0;k<i;k++){
						if(x[ind[iin]]==1){
							if((j >= l[ind[iin]]) || (k >= l[ind[iin]])){
								dp[i][j][k]=0;
								dp[j][i][k]=0;
								dp[j][k][i]=0;
							}
						}else if(x[ind[iin]]==2){
							if((j >= l[ind[iin]]) && (k >= l[ind[iin]])){
								dp[i][j][k]=0;
								dp[j][i][k]=0;
								dp[j][k][i]=0;
							}else if((j < l[ind[iin]]) && (k < l[ind[iin]])){
								dp[i][j][k]=0;
								dp[j][i][k]=0;
								dp[j][k][i]=0;
							}
						}else{
							if((j < l[ind[iin]]) || (k < l[ind[iin]])){
								dp[i][j][k]=0;
								dp[j][i][k]=0;
								dp[j][k][i]=0;
							}
						}
					}
				}
				iin++;
			}
			if(i==n) break;
			for(int j=0;j<i;j++){
				for(int k=0;k<i;k++){
					dp[i+1][j][k]+=dp[i][j][k];
					dp[i][i+1][k]+=dp[i][j][k];
					dp[i][j][i+1]+=dp[i][j][k];
					
					dp[i+1][j][k]%=mod;
					dp[i][i+1][k]%=mod;
					dp[i][j][i+1]%=mod;
					
					
					dp[j][i+1][k]+=dp[j][i][k];
					dp[j][i][i+1]+=dp[j][i][k];
					dp[i+1][i][k]+=dp[j][i][k];
					
					dp[j][i+1][k]%=mod;
					dp[j][i][i+1]%=mod;
					dp[i+1][i][k]%=mod;
					
					
					dp[k][j][i+1]+=dp[k][j][i];
					dp[i+1][j][i]+=dp[k][j][i];
					dp[k][i+1][i]+=dp[k][j][i];
					
					dp[k][j][i+1]%=mod;
					dp[i+1][j][i]%=mod;
					dp[k][i+1][i]%=mod;
				}
			}
		}
		long res=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if((i>0) && (i==j)) continue;
				res+=dp[i][j][n];
				res+=dp[n][i][j];
				res+=dp[j][n][i];
				res%=mod;
			}
		}
		System.out.println(res);
	}
}