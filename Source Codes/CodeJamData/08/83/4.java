import java.io.*;
import java.util.*;

public class Main{
	
	Scanner in;
	PrintWriter out;
	
	int n;
	int k;
	boolean[] g;
	boolean[][] e;
	long[][] res;
	boolean[][] gg;
	long m = 1000000009;
	
	public long poisk(int v, int kk, int w){
		if (gg[v][kk]){
			return res[v][kk];
		}
		int cc = 0;
		for(int i = 0;i<n;i++){
			if (e[v][i] && i!=w){
				cc++;
			}
		}
		if (cc+kk>k) {
			gg[v][kk] = true;
			res[v][kk] = 0;
			return 0;
		}
		int ll = cc; if (w!=-1) ll++;
		long z = 1;
		for(int i = 0;i<n;i++)
			if (e[v][i] && i!=w){
				z = z*poisk(i,ll,v) % m;
			}
		for(int i = 0;i<cc;i++){
			z = z*(k-kk-i) %m;
		}
		gg[v][kk] = true;
		res[v][kk] = z;
		return z;
	}
	
	public void solve(int __) throws Exception{
		out.print("Case #"+__+": ");
		n = in.nextInt();
		k = in.nextInt();
		g = new boolean[n];
		e = new boolean[n][n];
		for(int i = 0;i<n-1;i++){
			int x = in.nextInt();
			int y = in.nextInt();
			e[x-1][y-1] = true;
			e[y-1][x-1] = true;
		}
		res = new long[n][n];
		gg = new boolean[n][n];
		out.println(poisk(0,0,-1));
	}
	public void run() throws Exception{		
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			solve(__+1);
		}
		out.close();
	}
	
	public static void main(String[] args){
		new Thread(){
			public void run(){
				try{
					new Main().run();
				} catch (Exception E){
					throw new RuntimeException(E);
				}
			}
		}.start();
	}
}