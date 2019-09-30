import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	public void solve(){
		int n = in.nextInt();
		int k = in.nextInt();
		int b = in.nextInt();
		int t = in.nextInt();
		int nl = 0;
		int no = 0;
		int ns = 0;
		int[] x = new int[n];
		int[] v = new int[n];
		for(int i = 0;i<n;i++)
			x[i] = in.nextInt();
		for(int i = 0;i<n;i++)
			v[i] = in.nextInt();
		for(int i = n-1;i>=0;i--){
			//out.println(no+" "+b+" "+t+" "+x[i]+" "+v[i]);
			if (b-x[i]<=v[i]*t){
				no++;
				ns+=nl;
				if (no==k) break;
			} else nl++;
		}
		if (no==k) out.println(ns);
		else out.println("IMPOSSIBLE");
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
