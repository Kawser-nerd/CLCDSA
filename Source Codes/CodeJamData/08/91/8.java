import java.io.*;
import java.util.*;

public class Main{
	
	Scanner in;
	PrintWriter out;
	
	public void solve() throws Exception{
		int n = in.nextInt();
		int[]x = new int[n];
		int[]y = new int[n];
		int[]z = new int[n];
		int M = 10000;
		for(int i = 0;i<n;i++){
			x[i] = in.nextInt();	
			y[i] = in.nextInt();	
			z[i] = in.nextInt();	
		}
		int[] k = new int[M+2];
		int best = 0;
		for(int u = 0;u<=M;u++){
			Arrays.fill(k,0);
			for(int i = 0;i<n;i++)
				if (x[i]<=u) if (y[i]<=M-u-z[i]+1){
					k[y[i]]++;
					k[M-u-z[i]+1]--;
				}
			int bb = 0;
			int b = 0;
			for(int i = 0;i<=M;i++){
				bb+=k[i];
				if (b<bb) b = bb;
			}
			if (best<b) {best = b;
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