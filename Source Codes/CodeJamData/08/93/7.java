import java.io.*;
import java.util.*;

public class Main{
	
	Scanner in;
	PrintWriter out;
	
	public void solve() throws Exception{
		int n = in.nextInt();
		int m = in.nextInt();
		int[][] a = new int[n+2][m+2];
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++)
				a[i+1][j+1] = in.nextInt();
		}
 		boolean[][] b = new boolean[n+2][m+2];
		int best = 0;
		for(int ii = 0;ii<(1<<(n*m));ii++){
			int nn = 0;
			for(int x = 0;x<n;x++){
				for(int y = 0;y<m;y++){
					b[x+1][y+1] = ((1<<(nn++)) & ii)!=0;
				}
			} 
			boolean ok = true;
			for(int i = 1;i<=n;i++)
				for(int j = 1;j<=m;j++){
					int s = 0;
					for(int k =-1;k<=1;k++)
						for(int l= -1;l<=1;l++){
							if (b[i+k][j+l]) s++;
						}
					if (s!=a[i][j]) { ok = false; break;}
				}
			if (ok){
				int v = 0;
				for(int i = 0;i<m;i++)
					if (b[(n+1)/2][i+1]) v++;
				if (v>best) best = v;
			}
		}
		out.println(best);
	}
	
	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __ = 0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
 			solve();
		}
	}
	
	public void close(){
		out.close();
	}
	public static void main(String[] args){
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