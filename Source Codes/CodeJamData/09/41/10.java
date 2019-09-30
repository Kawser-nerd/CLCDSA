import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			int n = in.nextInt();
			String s;
			int[] t = new int[n];
			for(int i = 0;i<n;i++){
				s = in.next();
				int j = s.length()-1;
				while (j>=0 && s.charAt(j)=='0') j--;
				t[i] = j;
			}
			int res = 0;
			for(int i = 0;i<n;i++){
				int jj = -1;
				for (int j = i;j<n;j++){
					if (t[j]<=i){
						jj = j; break;
					}
				}
				if (jj==-1) throw new Exception("B1");
				res+=(jj-i);
				for(int j=jj;j>i;j--)
					t[j] = t[j-1];
			}
			out.println(res);
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
