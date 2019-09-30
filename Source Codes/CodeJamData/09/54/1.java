import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int _ = in.nextInt();
		int last = 1;
		long[] a = new long[25000000];
		int[] e = new int[10];
		for(int k = 1;k<=7;k++){
			Arrays.fill(e,0);
			e[0] = 0;
			while (true){
				e[0]++; int cc = 0;
				while (cc<k  && e[cc]==10){
					e[cc] = 0; e[cc+1]++; cc++;
				}
				if (cc==k) break;
				if (e[0]==0) e[0] = 1;
				long d = 0;
				for(int i = 0;i<k;i++)
					d = d*10+e[i];
				for(int i = k-2;i>=0;i--)
					d = d*10+e[i];
				a[last++] = d;
				if (k!=7){
					d = 0;
					for(int i = 0;i<k;i++)
						d = d*10+e[i];
					for(int i = k-1;i>=0;i--)
						d = d*10+e[i];
					a[last++] = d;
				}
			}
		}
		System.out.println(1);
		Arrays.sort(a,0,last);
		System.out.println(2);
		a[last] = 1000000000000000000l;
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			long l = in.nextLong()-1;
			long r = in.nextLong();
			int ii = 0;
			while (a[ii]<l) ii++;
			int jj = ii;
			if (a[ii] == l) jj++;
			long[] ee = new long[2];
			int cur = 0;
			long ll = l;
			while (a[ii]<=r){
				ee[cur]+=a[ii]-ll;
				ll = a[ii];
				cur = 1-cur;
				ii++;
			}
			ee[cur]+=r+1-ll;
			if (a[ii]==r) ii++;
			long M = 1000000007;
			ee[0] = ee[0] % M;
			ee[1] = ee[1] % M;
			out.println((ee[0]*(ee[0]-1)/2+ee[1]*(ee[1]-1)/2)%M);
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
