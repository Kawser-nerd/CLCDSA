import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;


	boolean[] g;
	boolean[][] a;
	int minl;
	int maxx;
	int maxy;

	int[] x1;
	int[] y1;
	int[] x2;
	int[] y2;

	int n;

	public boolean intersect(int i, int j){
		int xmi = Math.max(x1[i],x1[j]);
		int xma = Math.min(x2[i],x2[j]);
		int ymi = Math.max(y1[i],y1[j]);
		int yma = Math.min(y2[i],y2[j]);
		if (xmi>xma+1) return false;
		if (ymi>yma+1) return false;
		if (xmi==xma+1 && ymi==yma+1 && ((x2[i]<x1[j] && y2[i]<y1[j]) || (x2[j]<x1[i] && y2[j]<y1[i]))) return false;
		return true;
	}

	public void poisk(int i){
		g[i] = true;
		if (x1[i]+y1[i]<minl){
			minl= x1[i]+y1[i];
		}
		if (x2[i]>maxx) maxx=x2[i];
		if (y2[i]>maxy) maxy=y2[i];
		for(int j = 0;j<n;j++)
			if (a[i][j] && !g[j]) poisk(j);
	}

	public void solve(){
		n = in.nextInt();
		x1 = new int[n];
		y1 = new int[n];
		x2 = new int[n];
		y2 = new int[n];
		for(int i = 0;i<n;i++){
			x1[i] = in.nextInt();
			y1[i] = in.nextInt();
			x2[i] = in.nextInt();
			y2[i] = in.nextInt();
		}
		a= new boolean[n][n];
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++){
				a[i][j] = intersect(i,j);
			}
		g = new boolean[n];
		Arrays.fill(g,false);
		int best = 0;
		for(int i = 0;i<n;i++) if (!g[i]){
			maxx = 0;
			maxy = 0;
			minl = x1[i]+y1[i];
			poisk(i);
			//System.out.println(minl+" "+maxl+" "+minx+" "+maxx);
			if (maxx+maxy-minl+1>best) best = maxx+maxy-minl+1;
		}
		out.println(best);

		
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
