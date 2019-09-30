import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	public int sqr(int x){
		return x*x;
	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			int n = in.nextInt();
			int[] x = new int[n];
			int[] y = new int[n];
			int[] r = new int[n];
			for(int i = 0;i<n;i++){
				x[i] = in.nextInt();
				y[i] = in.nextInt();
				r[i] = in.nextInt();
			}
			if (n==1) out.println(r[0]);
			if (n==2) out.println(Math.max(r[0],r[1]));
			if (n==3) out.println(Math.min(
					Math.max(r[0],(r[1]+r[2]+Math.sqrt(sqr(x[1]-x[2])+sqr(y[1]-y[2])))/2),
					Math.min(Math.max(r[1],(r[0]+r[2]+Math.sqrt(sqr(x[0]-x[2])+sqr(y[0]-y[2])))/2),
					Math.max(r[2],(r[0]+r[1]+Math.sqrt(sqr(x[1]-x[0])+sqr(y[1]-y[0])))/2))));
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
