import java.io.*;
import java.util.*;

public class Main{


	Scanner in;
	PrintWriter out;

	int[] pair;
	int[] dir;
	int[] upa;
	int[] doa;
	int upc;
	int doc;
	boolean[] g;
	int n;
	boolean[][] e;
	int INF = 10000;

	public boolean poisk(int v){
		g[v] = true;
		for(int i = 0;i<2*n;i++)
			if (e[v][i]){
				if (g[i]){
					if (dir[i]==dir[v]) return false;
				} else {
					dir[i] = 3-dir[v];
					if (!poisk(i)) return false;
				}
			}
		return true;
	}



	public int[] solve(int l, int r){
		if (l==r){
			int[] res = new int[n+1];
			for(int i = 0;i<=n;i++) res[i] = 0;
			return res;
		}
		if (pair[l]<l) throw new RuntimeException("B2");
		int min = 1;
		int max = n+1;
		dir[l] = 1;
		Arrays.fill(g,false);
		if (!poisk(l)) return new int[]{-1};
		for(int i = l;i<r;i++)
			if (dir[i]*dir[pair[i]]!=0) throw new RuntimeException("B3");
		int[] res = new int[n+1];
			int upn = 0;
			int downn = 0;
			boolean ok = true;
			for(int i=l;i<r;i++){
				if (dir[i]==0 && dir[pair[i]]==0){
					int j = i;
					while (j<r && dir[j]==0 && dir[pair[j]]==0) j++;
					int[] c = solve(i,j);
					if (c[0] == -1) return new int[]{-1};
					for(int t = 0;t<upn;t++)
						res[t] = INF;
					for(int t = upn;t<=n;t++)
						res[t] = Math.max(res[t],downn+c[t-upn]);
					i = j-1;
				} else if (dir[i]==1){
					res[upn] = INF;
					upn++; 
				} else if (dir[pair[i]]==1){
					upn--;
				} else if (dir[i]==2){
					downn++;
					for(int t = 0;t<=n;t++)
						if (res[t]<downn) res[t] = downn;
				} else if (dir[pair[i]]==2){
					downn--;
				} else throw new RuntimeException("B");
			}
		for(int i = 0;i<=n;i++)
			if (res[i]<INF){
				int t = res[i];
				res[t] = Math.min(res[t],i);
			}
		for(int i=0;i<n;i++)
			res[i+1] = Math.min(res[i+1],res[i]);
		return res;
	}

	public boolean into(int l, int r, int x){
		return (l<x) && (x<r);
	}

	public int sol() throws Exception{
		n = in.nextInt();
		String[] s = new String[2*n];
		for(int i = 0;i<2*n;i++)
			s[i] = in.next();
		pair = new int[2*n];
		dir = new int[2*n];
		g = new boolean[2*n];
		for(int i = 0;i<2*n;i++)
			for(int j = 0;j<2*n;j++) if (i!=j && s[i].equals(s[j]))
				pair[i] = j;
		e = new boolean[2*n][2*n];
		for(int i = 0;i<2*n;i++) if (i<pair[i])
			for(int j = 0;j<2*n;j++) if (j<pair[j])
				if (i!=j && (into(i,pair[i],j)!=into(i,pair[i],pair[j]))){
					e[i][j] = true;
				}
		int[] r = solve(0,2*n);
		if (r[0]==-1) return -1;
		int min = 10000;
		for(int i =0;i<=n;i++)
			if (i+r[i]<min) min = i+r[i];
		return min;
	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __ = 0;__<_;__++){
			out.println("Case #"+(__+1)+": "+sol());
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
