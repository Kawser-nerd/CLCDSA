import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;


	int INF = 1000000000;

	public void solve(){
		int n = in.nextInt();
		int[] a = new int[1<<n];
		for(int i = 0;i<(1<<n);i++)
			a[i] = in.nextInt();
		int[] c = new int[1<<n];
		int[] d = new int[1<<n];
		for(int i = 0;i<(1<<n)-1;i++)
			c[(1<<n)-1-i] = in.nextInt();
		for(int i=1;i<n;i++){
			int k = 1<<i;
			int m = 3*k-1;
			int mm = 3*(1<<(i-1));
			for(int t = k;t<mm;t++){
				int tt = c[t];
				c[t] = c[m-t];
				c[m-t] = tt;
			}
		}
		int[][] p = new int[1<<(n+1)][n+1];
		int ll = 1<<n;
		for(int  i=0;i<(1<<n);i++){
			for(int j = 0;j<=n;j++)
				if (a[i]>=j) p[i+ll][j] = 0;
				else p[i+ll][j] = INF;
		}
		for(int i = ll-1;i>=1;i--){
			for(int j = 0;j<n;j++){
				p[i][j] = Math.min(INF,Math.min(p[2*i][j+1]+p[2*i+1][j+1],c[i]+p[2*i][j]+p[2*i+1][j]));
			}
		}
		out.println(p[1][0]);

	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			solve();
		}
	}

	public void close() throws Exception{
		out.close();
	}

	public static void main(String[]  args){
		new Thread(){
			public void run(){
				try{
					Main a = new Main();
					a.run();
					a.close();
				} catch (Exception E){
					throw new RuntimeException(E);
				}
			}
		}.start();
	}
}
