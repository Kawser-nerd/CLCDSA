import java.io.*;
import java.util.*;

public class Main{
	
	Scanner in;
	PrintWriter out;
	
	int[] h;
	int ll = 1<<20;
	
	public void fill(int n){
		for(int i = ll;i<2*ll;i++){
			if (i-ll<n) h[i] = 1;
			else h[i] = 0;
		}
		for(int i = ll-1;i>0;i--)
			h[i] = h[2*i]+h[2*i+1];
		//System.out.println(h[ll]+" "+ll);
	}
	
	public int get(int p){
		int x = 1;
		//System.out.println(h[x]);
		while (x<ll){
			if (h[2*x]>=p) x = 2*x;
			else {
				p-=h[2*x];
				x = 2*x+1;
			}
		}
		//System.out.println(p);
		return x-ll;
	}
	
	public void del(int x){
		x+=ll;
		while (x>0) {
			h[x]--;
			x = x>>1;
		}
	}
	
	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		h = new int[2*ll];
		for(int __=0;__<_;__++){
			int n = in.nextInt();
			int m = in.nextInt();
			int[] d = new int[m];
			for(int i = 0;i<m;i++) {
				d[i] = in.nextInt()-1;
			}
			fill(n);
			int pos = 1;
			int[] res = new int[n];
			for(int i =0;i<n;i++){
				pos+=i;
				pos%=(n-i); 
				if (pos==0) pos+=(n-i);
				int t = get(pos);
				//System.out.println(t+" "+pos);
				res[t] = i+1;
				del(t);
			}
			out.print("Case #"+(__+1)+":");
			for(int i = 0;i<m;i++)
				out.print(" "+res[d[i]]);
			out.println();
		}
		out.close();
	}

	public static void main(String[] args) throws Exception{
		new Main().run();
	}	
}