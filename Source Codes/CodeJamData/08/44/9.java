import java.io.*;
import java.util.*;

public class Main{
	
	public void run() throws Exception{
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		
		int INF = 1000000000;
		for(int __=0;__<_;__++){
			int m = in.nextInt();
			String ss= in.next();
			int n = ss.length();
			int[][] a = new int[m][m];
			int[][] b = new int[m][m];
			for(int i = 0;i<n;i+=m){
				for(int l =0;l<m;l++)
					for(int k = l+1;k<m;k++)
						if (ss.charAt(i+k)==ss.charAt(i+l)) a[k][l]++;
				if (i+m<n)
					for(int l =0;l<m;l++)
						for(int k = 0;k<m;k++)
							if (ss.charAt(i+k)==ss.charAt(i+m+l)) b[k][l]++;
			}
			for(int i = 0;i<m;i++){
				for(int j = i+1;j<m;j++){
					a[i][j] = a[j][i];
					//System.out.println(__+" "+b[i][j]+" "+b[j][i]+" "+a[i][j]+" "+a[j][i]);
				}
			}
			int[][][] u = new int[1<<m][m][m];
			for(int i = 0;i<(1<<m);i++) for(int j=0;j<m;j++) Arrays.fill(u[i][j],-INF);
			for(int i =0;i<m;i++) u[1<<i][i][i] = 0;
			for(int ii=1;ii<(1<<m);ii++){
				for(int k = 0;k<m;k++)
					for(int l = 0;l<m;l++)
						for(int s = 0; s<m;s++) if ((ii & (1<<s))==0){
							//System.out.println(ii+" "+s);
							if (u[ii+(1<<s)][k][s]<u[ii][k][l]+a[l][s]){
								u[ii+(1<<s)][k][s] = u[ii][k][l]+a[l][s];
							}
						}
			}
			int best = 0;
			for(int i =0;i<m;i++)
				for(int j = 0;j<m;j++)
					if (u[(1<<m)-1][i][j]+b[i][j]>best){
						best = u[(1<<m)-1][i][j]+b[i][j];
					}
			out.println("Case #"+(__+1)+": "+(n-best));
		}
		out.close();
	}
	
	public static void main(String[] args) throws Exception{
		new Main().run();
	}
}