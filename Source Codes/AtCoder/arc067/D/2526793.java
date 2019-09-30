import java.io.*;
import java.util.*;

public class Main {
	static final Reader in = new Reader();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt(), m=in.nextInt();
		long[] a = new long[n];
		for(int i=0; i<n-1; ++i)
			a[i]=in.nextInt();
		long[][] b = new long[n][m];
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				b[i][j]=in.nextInt();
		SegTree st = new SegTree(n);
		long[] ini = new long[n], mx1 = new long[m];
		long ps=0, ans=0;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<m; ++j)
				ini[i]+=mx1[j]=Math.max(b[i][j], mx1[j]);
			ini[i]-=ps;
			ps+=a[i];
		}
		st.build(ini);
		int[][] nxt = new int[n][m];
		for(int i=n-1; i>=0; --i) {
			for(int j=0; j<m; ++j) {
				nxt[i][j]=i+1;
				while(nxt[i][j]<n&&b[nxt[i][j]][j]<b[i][j])
					nxt[i][j]=nxt[nxt[i][j]][j];
			}
		}
		ps=0;
		for(int i=0; i<n; ++i) {
			ans=Math.max(st.get(i, n-1)+ps, ans);
			for(int j=0; j<m; ++j) {
				st.add(i, nxt[i][j]-1, -b[i][j]);
				for(int k=i+1; k<n&&b[k][j]<b[i][j]; k=nxt[k][j])
					st.add(k, nxt[k][j]-1, b[k][j]);
			}
			ps+=a[i];
		}
		out.println(ans);
		out.close();
	}
	
	static class SegTree {
		int n, l1, r1;
		long v;
		long[] a, lazy;
		SegTree(int n) {
			this.n=n;
			a = new long[4*n];
			lazy = new long[4*n];
		}
		void build(long[] b) {
			build2(1, 0, n-1, b);
		}
		private void build2(int i, int l2, int r2, long[] b) {
			if(l2<r2) {
				int mid=(l2+r2)/2;
				build2(2*i, l2, mid, b);
				build2(2*i+1, mid+1, r2, b);
				a[i]=Math.max(a[2*i], a[2*i+1]);
			} else
				a[i]=b[l2];
		}
		void add(int l, int r, long x) {
			l1=l;
			r1=r;
			v=x;
			add2(1, 0, n-1);
		}
		private void add2(int i, int l2, int r2) {
			if(l1<=l2&&r2<=r1) {
				a[i]+=v;
				if(l2<r2) {
					lazy[2*i]+=v;
					lazy[2*i+1]+=v;
				}
			} else {
				int mid=(l2+r2)/2;
				push(i*2, l2, mid);
				push(i*2+1, mid+1, r2);
				if(l1<=mid)
					add2(i*2, l2, mid);
				if(mid<r1)
					add2(i*2+1, mid+1, r2);
				a[i]=Math.max(a[i*2], a[i*2+1]);
			}
		}
		void push(int i, int l, int r) {
			a[i]+=lazy[i];
			if(l<r) {
				lazy[2*i]+=lazy[i];
				lazy[2*i+1]+=lazy[i];
			}
			lazy[i]=0;
		}
		long get(int l, int r) {
			l1=l;
			r1=r;
			return get2(1, 0, n-1);
		}
		private long get2(int i, int l2, int r2) {
			push(i, l2, r2);
			if(l1<=l2&&r2<=r1)
				return a[i];
			else {
				int mid=(l2+r2)/2;
				long res=Long.MIN_VALUE;
				if(l1<=mid)
					res = Math.max(get2(2*i, l2, mid), res);
				if(mid<r1)
					res = Math.max(get2(2*i+1, mid+1, r2), res);
				return res;
			}
		}
	}
	
	static class Reader {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		String next() {
			while(st==null||!st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch(Exception e) {}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}