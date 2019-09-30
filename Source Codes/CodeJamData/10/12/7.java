//Author: Fluorine
import java.util.*;

public class B{
	public static void main(String args[]){
		Scanner scanner=new Scanner(System.in);
		int caseNumber=scanner.nextInt();
		for (int cases=0;cases<caseNumber;++cases){
			int D=scanner.nextInt();
			int I=scanner.nextInt();
			int M=scanner.nextInt();
			int N=scanner.nextInt();
			int[] a=new int[N+1];
			int[][] opt=new int[N+1][257];
			for (int i=1;i<=N;++i)
				a[i]=scanner.nextInt();
			for (int i=0;i<256;++i)
				opt[0][i]=I;
			opt[0][256]=0;
			for (int i=1;i<=N;++i){
				int[] min=new int[256];
				for (int j=0;j<256;++j){
					min[j]=opt[i-1][256];
					for (int k=j-M;k<=j+M;++k){
						if (k<0) continue;
						if (k>255) continue;
						if (opt[i-1][k]<min[j])
							min[j]=opt[i-1][k];
					}
				}
				for (int j=0;j<256;++j){
					int delta,time;
					
					opt[i][j]=opt[i-1][j]+D;
					
					for (int k=0;k<256;++k){
						delta=Math.abs(j-k);
						if (M!=0) time=(delta-1)/M+1;
						else time=10000;
						if (j==k) time=0;
						if ((time!=10000)&&(opt[i-1][k]+D+I*time<opt[i][j]))
							opt[i][j]=opt[i-1][k]+D+I*time;
					}
					
					delta=Math.abs(a[i]-j);
					if (M!=0) time=(delta-1)/M+1;
					else time=10000;
					if (a[i]==j) time=0;
					if ((time!=10000)&&(min[a[i]]+time*I<opt[i][j]))
						opt[i][j]=min[a[i]]+time*I;
					
					for (int k=0;k<256;++k){
						delta=Math.abs(j-k);
						if (M!=0) time=(delta-1)/M+1;
						else time=10000;
						if (j==k) time=0;
						if ((time!=10000)&&(min[k]+Math.abs(k-a[i])+I*time<opt[i][j]))
							opt[i][j]=min[k]+Math.abs(k-a[i])+I*time;
					}
				}
				opt[i][256]=opt[i-1][256]+D;
			}
			int ans=opt[N][256];
			for (int i=0;i<256;++i)
				if (opt[N][i]<ans)
					ans=opt[N][i];
			System.out.println("Case #"+(cases+1)+": "+ans);
		}
	}
}