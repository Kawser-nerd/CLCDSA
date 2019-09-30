import java.io.*;
import java.util.*;

public class Bai4 {
	
	static int[] bfs(boolean[][] a, int st) {
		int n = a.length;
		int[] res = new int[n];
		Arrays.fill( res, 1000000);
		res[st] = 0;
		int[] q = new int[n];
		int le = 0, ri = 0;
		q[0] = st;
		while(le <= ri) {
			int u = q[le++];
			for(int v=0;v<n;++v) if(res[v] > res[u] + 1 && a[u][v]) {
				res[v] = res[u] + 1;
				q[++ri] = v;
			}
		}
		return res;
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		// Scanner sc = new Scanner(new FileReader("D-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("Dlarge.out"));
		
		int ntest = sc.nextInt();
		
		for(int test=1;test<=ntest;++test) {
			
			System.err.println("run test = " + test);
			
			int n = sc.nextInt();
			int w = sc.nextInt();
			boolean[][] a = new boolean[n][n];
			for(int i=0;i<w;++i) {
				String[] tmp = sc.next().split(",");
				int u = Integer.parseInt(tmp[0]);
				int v = Integer.parseInt(tmp[1]);
				
				a[u][v] = a[v][u] = true;
			}
			
			ArrayList<Integer>[] ke = new ArrayList[n];
			for(int i=0;i<n;++i) {
				ke[i] = new ArrayList<Integer>();
				for(int j=0;j<n;++j) if(a[i][j]) {
					ke[i].add(j);
				}
			}
			
			int[] d0 = bfs( a, 0);
			int[] d1 = bfs( a, 1);
			
			int dist01 = d0[1];
			
			ArrayList<Integer>[] ds = new ArrayList[dist01];
			for(int i=0;i<dist01;++i) ds[i] = new ArrayList<Integer>();
			
			for(int lvl=0;lvl<dist01;++lvl) {
				for(int i=0;i<n;++i) if(d0[i] == lvl && d0[i] + d1[i] == dist01) {
					ds[lvl].add(i);
				}
			}
			
			int[][][] F = new int[dist01][][];
			F[0] = new int[1][1];
			F[0][0][0] = 0;
			for(int i=1;i<n;++i) if(a[0][i]) ++F[0][0][0];
			
			for(int i=0;i+1<dist01;++i) {
				F[i+1] = new int[ds[i].size()][ds[i+1].size()];
				for(int j=0;j<ds[i].size();++j)
					for(int t=0;t<ds[i+1].size();++t)
						F[i+1][j][t] = -1;
				for(int j=0;j<F[i].length;++j) {
					for(int t=0;t<F[i][j].length;++t) {
						int z = F[i][j][t];
						
						if(z < 0) continue; 
						
						int u = ds[i].get(t);
						int tru = u;
						
						if(i > 0) tru = ds[i-1].get(j);
												
						for(int k=0;k<ds[i+1].size();++k) {
							int tmp = 0;
							int v = ds[i+1].get(k);
							if(!a[u][v]) continue; 
							for(int node : ke[v]) {
								if(!a[node][u] && !a[node][tru] && node != u && node != tru) ++tmp;
							}
							F[i+1][t][k] = Math.max( F[i+1][t][k], z - 1 + tmp);
						}
						
					}
				}
			}
			
			int res = 0;
			for(int i=0;i<F[dist01-1].length;++i)
				for(int j=0;j<F[dist01-1][i].length;++j)
					res = Math.max( res, F[dist01-1][i][j]);
			
			pw.print("Case #" + test + ": ");
			pw.print((dist01 - 1) + " " + res);
			pw.println();
		}
		pw.close();
		sc.close();
	}
}
