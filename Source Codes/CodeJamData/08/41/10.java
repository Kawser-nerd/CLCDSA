import java.io.*;
import java.util.*;

public class Main{
	
	public void run() throws Exception{
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		int INF = Integer.MAX_VALUE/3;
		for(int __=0;__<_;__++){
			int n = in.nextInt();
			int v = in.nextInt();
			int[][] a = new int[n+1][2];
			int[] b = new int[n+1];
			int[] c = new int[n+1];
			for(int i = 1;i<=n;i++){
				b[i] = in.nextInt();
				if (i*2<n) c[i] = in.nextInt();
			}
			for(int i = n;i>=1;i--){
				if (i*2>n){
					a[i][b[i]] = 0;
					a[i][1-b[i]] = INF;
				} else {
					for(int j = 0; j<2;j++){
						a[i][j] = INF;
					}
					for(int k=0;k<2;k++)
						for(int l =0;l<2;l++){
							int t = k & l;
							if (b[i]==0) t = k | l;
							a[i][t] = Math.min(a[i][t],a[2*i][k]+a[2*i+1][l]);
							t = k & l;
							if (b[i]==1) t = k | l;
							if (c[i]==1)
								a[i][t] = Math.min(a[i][t],1+a[2*i][k]+a[2*i+1][l]);
						}
				}
				//System.out.println(a[i][0] +" "+a[i][1]);
			}
			out.print("Case #"+(__+1)+": ");
			if (a[1][v]<INF) out.println(a[1][v]);
			else out.println("IMPOSSIBLE");
				
		}
		out.close();
	}
	
	public static void main(String[] args) throws Exception{
		new Main().run();
	}
}