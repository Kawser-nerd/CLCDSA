import java.io.*;
import java.util.*;

public class Main{
	
	double EPS = 1e-9;
	double INF = 1e8;
	
	double sol(int j, int[] x, int p, double u, int v){
		double xx = 0;
		if (j==0) xx = x[0]+x[1]+x[2];
		if (j==1) xx = -x[0]+x[1]+x[2];
		if (j==2) xx = x[0]-x[1]+x[2];
		if (j==3) xx = x[0]+x[1]-x[2];
		double dx = u*p;
		if (v==0) return xx-dx;
		else return xx+dx;
	}
	
	public double cou(int[][] x, int[] p, int n){
		double l = 0;
		double r = INF;
		while (r-l>EPS){
			double u = (l+r)/2;
			double[] ll = new double[4]; double[] rr = new double[4];
			Arrays.fill(ll,-INF);
			Arrays.fill(rr,INF);
			for(int i = 0;i<n;i++) for(int j =0;j<4;j++){
				double t = sol(j,x[i],p[i],u,0);
				if (ll[j]<t) ll[j] = t;
				t = sol(j,x[i],p[i],u,1);
				if (rr[j]>t) rr[j] = t;
			} 
			double e = 1;
			for(int j=0;j<4;j++)
				if (ll[j]-EPS>rr[j]) e = -1;
			if (e==1) r = u;
			else l = u;
		}
		return l;
	}
	
	public void run() throws Exception{
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			int n = in.nextInt();
			int[][] x = new int[n][3];
			int[] p = new int[n];
			for(int i = 0;i<n;i++){
				for(int j =0;j<3;j++)
					x[i][j] = in.nextInt();
				p[i] = in.nextInt();
			}
			out.println("Case #"+(__+1)+": "+(cou(x,p,n)));
		}
		out.close();
	}
	
	public static void main(String[] args) throws Exception{
		new Main().run();
	}
}