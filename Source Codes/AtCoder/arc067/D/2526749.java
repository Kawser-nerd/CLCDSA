import java.io.*;
import java.util.*;

public class Main {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt(), m=in.nextInt();
		long[] a=in.readLongArray(n-1, 0);
		long[][] b = new long[n][m];
		for(int i=0; i<n; ++i)
			b[i]=in.readLongArray(m, 0);
		SegTree st = new SegTree(n);
		long[] ini = new long[n], mx1 = new long[m];
		long ps=0, ans=0;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<m; ++j)
				ini[i]+=mx1[j]=Math.max(b[i][j], mx1[j]);
			ini[i]-=ps;
			if(i<n-1)
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
			if(i<n-1)
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
	
	static class StdIn {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
		public StdIn() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public StdIn(InputStream in) {
			try{
				din = new DataInputStream(in);
			} catch(Exception e) {
				throw new RuntimeException();
			}
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public String next() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == ' ' || c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c=read();
			}
			return s.toString();
		}
		public String nextLine() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c = read();
			}
			return s.toString();
		}
		public int nextInt() {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}
		public int[] readIntArray(int n, int os) {
			int[] ar = new int[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextInt()+os;
			return ar;
		}
		public long nextLong() {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}
		public long[] readLongArray(int n, long os) {
			long[] ar = new long[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextLong()+os;
			return ar;
		}
		public double nextDouble() {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');
			if (c == '.')
				while ((c = read()) >= '0' && c <= '9')
					ret += (c - '0') / (div *= 10);
			if (neg)
				return -ret;
			return ret;
		}
		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}
		private byte read() {
			try{
				if (bufferPointer == bytesRead)
					fillBuffer();
				return buffer[bufferPointer++];
			} catch(IOException e) {
				throw new RuntimeException();
			}
		}
		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
}