import java.io.*;
import java.util.*;

public class Main{


	Scanner in;
	PrintWriter out;

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			int n = in.nextInt();
			int[] x = new int[n];
			int[] y = new int[n];
			int[] r = new int[n];
			int[] c = new int[n];
			for(int i = 0;i<n;i++){
				x[i] = in.nextInt();
				y[i] = in.nextInt();
				r[i] = in.nextInt();
				c[i] = in.nextInt();
			}
			boolean[][] e = new boolean[n][n];
			for(int i = 0;i<n;i++)
				for(int j = 0;j<n;j++)
					if (r[i]*r[i]>=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])){
						e[i][j] = true;
					}
			int max = 0;
			for(int nn = 0;nn<(1<<n);nn++){
				boolean ok = true;
				int sum = 0;
				for(int i = 0;i<n && ok;i++){
					if ((nn & (1<<i))!=0){
						for(int j = 0;j<n;j++)
							if (e[i][j] && ((nn & (1<<j))==0))
								ok = false;
						sum+=c[i];
					}
				}
				if (ok && sum>max) max = sum;
			}
			out.println("Case #"+(__+1)+": "+max);
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
