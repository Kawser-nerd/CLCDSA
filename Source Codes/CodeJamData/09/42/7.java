import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	String[] s;
	int n; int m; int f;
	int INF = 1000000000;

	boolean[][][] g2;
	int[][][] r2;
	public int poisk2(int x, int l, int r){
		if (g2[x][l][r]) return r2[x][l][r];
		g2[x][l][r] = true;
		int res = INF;
		for(int i = l;i<=r;i++)
			for(int j = i;j<=r;j++){
				int dd = j-i+1;
				if (s[x+1].charAt(i)=='.') dd--;
				if (i!=j && s[x+1].charAt(j)=='.') dd--;
				if (i>l && s[x+1].charAt(i-1)=='#'){
					int p=i; int xx = x+1;
					while (xx<n-1){
						if (s[xx+1].charAt(p)=='.') xx++;
						else break;
					}
					if (xx-x<=f){
						int d = 0;
						if (xx==x+1) d = poisk(x+1,p,i,j);
						else d = poisk(xx,p,p,p);
						if (d+dd<res) res = dd+d;
					}
				}
				if (j<r && s[x+1].charAt(j+1)=='#'){
					int p=j; int xx = x+1;
					while (xx<n-1){
						if (s[xx+1].charAt(p)=='.') xx++;
						else break;
					}
					if (xx-x<=f){
						int d = 0;
						if (xx==x+1) d = poisk(x+1,p,i,j);
						else d = poisk(xx,p,p,p);
						if (d+dd<res) res = dd+d;
					}
				}
			}
		return r2[x][l][r]=res;

	}


	boolean[][][][] g;
	int[][][][] rr;

	public int poisk(int x, int y, int _l, int _r){
		if (g[x][y][_l][_r]) return rr[x][y][_l][_r];
		g[x][y][_l][_r] = true;
		if (x==n-1) return 0;
		int l = y;
		boolean ok = true;
		while (l>=_l){
			if (s[x+1].charAt(l)=='.') {ok = false; break;}
			l--;
		}
		if (ok){
			while (l>=0){
				if (s[x].charAt(l)=='#'){
					l++; break;
				}
				if (s[x+1].charAt(l)=='.') 
					break;
				l--;
			}
			if (l<0) l++;
		}
		ok = true;
		int r = y;
		while (r<=_r){
			if (s[x+1].charAt(r)=='.') {ok = false; break;}
			r++;
		}
		if (ok){
			while (r<m){
				if (s[x].charAt(r)=='#'){
					r--; break;
				}
				if (s[x+1].charAt(r)=='.') 
					break;
				r++;
			}
			if (r==m) r--;
		}
		return rr[x][y][_l][_r] = poisk2(x,l,r);
	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			n = in.nextInt();
			m = in.nextInt();
			f = in.nextInt();
			s = new String[n];
			for(int i = 0;i<n;i++){
				s[i] = in.next();
			}
			rr = new int[n][m][m][m];
			g = new boolean[n][m][m][m];
			r2 = new int[n][m][m];
			g2 = new boolean[n][m][m];
			int t = poisk(0,0,0,0);
			if (t==INF) out.println("No");
			else out.println("Yes "+t);
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
