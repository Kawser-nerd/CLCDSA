import java.io.*;
import java.util.*;

public class Main{
	
	Scanner in;
	PrintWriter out;
	
	int MAXN = 1000002;
	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter(new FileWriter(new File("output.txt")));
		boolean[] p = new boolean[MAXN];
		int[] pr = new int[MAXN];
		int pp = 0;
		for(int i = 2;i<MAXN;i++){
			if (!p[i]){
				pr[pp++] = i;
				int j = 2*i;
				while (j<MAXN){
					p[j] = true; j+=i;
				}
			} 
		}
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			long a = in.nextLong();
			long b = in.nextLong();
			long P = in.nextLong();
			int ii = -1;
			for(int i = 0;i<pp;i++) {
				if (pr[i]>=P) {
					ii = i;
					break;
				}
			}
			long res = 0;
			int[] col = new int[pp];
			for(int i = 0;i<pp;i++) col[i] = i;
			if (ii==-1) res = b-a+1;
			else {
				int jj = ii;
				while (jj<pp && pr[jj]<=(b-a)) jj++;
				if (jj==ii) res = b-a+1;
				else {
					int e = jj-ii;
					for(int i = ii;i<jj;i++)
						for(int j = i+1;j<jj;j++) if (col[i]!=col[j]) {
							long t = a%(pr[i]*(long)pr[j]);
							if (t!=0) t = (pr[i]*(long)pr[j])-t;
							//System.out.println(pr[i]+" "+pr[j]+" "+t);
							if (a+t<=b){
								int s = col[j];
								e--;
								for(int k = ii;k<jj;k++)
									if (col[k]==s)
										col[k] = col[i];
							}
						}
					//System.out.println(e+" "+ii+" "+jj);
					res = e;
					int d = (int)(b-a+1);
					boolean[] h = new boolean[d];
					for(int i = ii;i<jj;i++){
						long u = a%pr[i];
						if (u!=0) u = pr[i]-u;
						int v = (int)u;
						while (v<d){
							h[v] =  true;
							v+=pr[i]; 
						}
					}
					for(int i =0;i<d;i++)
						if (!h[i]) res++;
				}
			} 
			out.println("Case #"+(__+1)+": "+res);
		}
		out.close();
		
	}

	public static void main(String[] args) throws Exception{
		new Main().run();
	}	
}