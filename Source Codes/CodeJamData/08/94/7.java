import java.io.*;
import java.util.*;

public class Main{
	
	Scanner in;
	PrintWriter out;
	
	int[] dx = new int[]{-1,1,0,0};
	int[] dy = new int[]{0,0,-1,1};
	
	public void bfs(char[][]a, int[][] d, int[][] p, int n, int m, int x0, int y0){
		int[] xx = new int[n*m];
		int[] yy = new int[n*m];
		boolean[][] g = new boolean[n][m];
		int f = 0; int l = 1;
		xx[0] = x0; yy[0] = y0;
		g[x0][y0] = true;
		while (f<l){
			int x = xx[f];
			int y = yy[f];
			f++;
			for(int i = 0;i<4;i++){
				if (x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m && !g[x+dx[i]][y+dy[i]] && a[x+dx[i]][y+dy[i]]!='.'){
					g[x+dx[i]][y+dy[i]] = true;
					xx[l] = x+dx[i];
					yy[l] = y+dy[i];
					l++;
					p[x+dx[i]][y+dy[i]] = i;
					d[x+dx[i]][y+dy[i]] = d[x][y]+1;
				}
			}
		}
	}
	
	public void solve() throws Exception{
		int n = in.nextInt();
		int m = in.nextInt();
		char[][] a = new char[n][m];
		int fo = 1;
		int[] fx = new int[n*m];
		int[] fy = new int[n*m];
		for(int i = 0;i<n;i++){
			String s = in.next();
			for(int j = 0;j<m;j++){
				a[i][j] = s.charAt(j);
				if (a[i][j]=='T') {fx[fo] = i; fy[fo] = j; fo++;}
			}
		}
		int[][][] d = new int[fo][n][m];
		int[][][] p = new int[fo][n][m];
		for(int i = 0;i<fo;i++)
			bfs(a,d[i],p[i],n,m,fx[i],fy[i]);
		int s = 0;
		boolean[][] g = new boolean[n][m];
		for(int i = 1;i<fo;i++){
			int xx = fx[i]; int yy = fy[i];
			while (xx!=0 || yy!=0){
				s+=d[0][xx][yy];
				int t = p[0][xx][yy];
				g[xx][yy] = true;
				xx-=dx[t];
				yy-=dy[t];
			}
		}
		
		g[0][0] = true;
		for(int i = 0;i<n;i++)
			for(int j = 0;j<m;j++) if (!g[i][j] && a[i][j]!='.'){
				int best = 1000000;
				for(int k = 0;k<fo;k++)
					best = Math.min(best,d[k][i][j]);
				s+=best;
			}
		out.println(s);
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