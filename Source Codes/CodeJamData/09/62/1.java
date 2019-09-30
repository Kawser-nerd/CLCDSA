import java.io.*;
import java.util.*;

public class Main{


	Scanner in;
	PrintWriter out;


	double[]x;
	double[] y;
	public double cou(int i, int j, int k){
		return dist(i,j)+dist(i,k)+dist(j,k);
	}
	public double dist(int i, int j){
		return Math.sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	}

	public void solve() throws Exception{
		int n = in.nextInt();
		x = new double[n];
		y = new double[n];
		for(int i=0;i<n;i++){
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		double best = 1e100;
		System.out.println(best);
		for(int i = 1;i<n;i++)
			for(int j = i+1;j<n;j++){
				double d = cou(0,i,j);
				if (d<best) best = d;
			}
		System.out.println(best);
		int[] z = new int[n];
		for(int i =1;i<n;i++){
			int zz = 0;
			for(int j = i+1;j<n;j++)
				if (dist(i,j)<best){
					z[zz++] = j;
				}
			for(int k = 0;k<zz;k++)
				for(int l =k+1;l<zz;l++){
					double d=  cou(i,z[k],z[l]);
					if (d<best) best = d;
				}
			
		}
		out.println(best);
				
	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
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
