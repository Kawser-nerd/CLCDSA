import java.io.*;
import java.util.*;

public class Main{
	
	Scanner in;
	PrintWriter out;
	
	
	public void solve(int __) throws Exception{
		out.print("Case #"+__+": ");
		int n = in.nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		int[] z = new int[n];
		HashMap<String,Integer> h = new HashMap<String,Integer>();
		int nn = 0;
		for(int i = 0;i<n;i++){
			String s = in.next();
			if (h.containsKey(s)) z[i] = h.get(s);
			else { z[i] = nn; h.put(s,nn); nn++;}
			x[i] = in.nextInt()-1;
			y[i] = in.nextInt()-1;
		}
		for(int i = 0;i<n;i++)
			for(int j = i+1;j<n;j++) if (x[i]>x[j]){
				int t;
				t = x[i]; x[i] = x[j]; x[j] = t;
				t = y[i]; y[i] = y[j]; y[j] = t;
				t = z[i]; z[i] = z[j]; z[j] = t;
			}
		int m = 10000;
		int best = 2*n;
		for(int i = 0;i<nn;i++)
			for(int j = i+1;j<=nn;j++)
				for(int k = Math.min(j+1,nn);k<=nn;k++){
					int last = 0;
					int l = 0;
					int ss = 0;
					while (l<n && last<m){
						int max = -1;
						if (x[l]>last) break;
						while (l<n && x[l]<=last){
							if (y[l]>max && (z[l]==i || z[l]==j || z[l]==k)) max = y[l]+1;
							l++;
						}
						ss++;
						last = max;
					}
					if (last==m && ss<best) best = ss;
				}
		if (best<=n) out.println(best);
		else out.println("IMPOSSIBLE");
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