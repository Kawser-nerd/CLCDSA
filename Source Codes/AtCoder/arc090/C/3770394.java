import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

public class Main {

	static PrintWriter out;
	static InputReader ir;
	static boolean debug =false;
    static final long mod=1000000007;

	static void solve() {
        int n=ir.nextInt();
		int m=ir.nextInt();
        Graph[] g=new Graph[n];
        for(int i=0;i<n;i++){
            g[i]=new Graph();
        }
        int s=ir.nextInt()-1;
		int t=ir.nextInt()-1;
		for(int i=0;i<m;i++){
			int u=ir.nextInt()-1;
			int v=ir.nextInt()-1;
			int d=ir.nextInt();
			g[u].add(new long[]{v,d});
			g[v].add(new long[]{u,d});
		}
		long[] ds=dijkstra(s,g);
		long[] dt=dijkstra(t,g);
		long[] rs=dijkCR(s,t,g,ds);
		long[] rt=dijkCR(t,s,g,dt);
		tr(rs);
		tr(rt);
		long res=0;
		for(int i=0;i<n;i++){
			if(ds[i]+dt[i]!=ds[t]||ds[i]*2>=ds[t])
				continue;
			for(long[] e : g[i]){
				int to=(int)e[0];
				if(ds[to]+dt[to]!=ds[t])
					continue;
				if(ds[i]+e[1]==ds[to]&&ds[to]*2>ds[t]){
					long u=(rs[i]*rt[to])%mod;
					res+=(u*u)%mod;
					res%=mod;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(ds[i]*2==ds[t]){
				long u=(rs[i]*rt[i])%mod;
				res+=(u*u)%mod;
				res%=mod;
			}
		}
		res=((rs[t]*rs[t])%mod)-res;		
		while(res<0)
			res+=mod;
		res%=mod;
		out.println(res);
	}

    static class Graph extends ArrayList<long[]>{}

    static long[] dijkstra(int s,Graph[] g){
		int n=g.length;
        long[] dist=new long[n];
		Arrays.fill(dist,Long.MAX_VALUE/2);
		dist[s]=0;
		PriorityQueue<long[]> pque=new PriorityQueue<long[]>(new Comparator<long[]>(){
			public int compare(long[] A,long[] B){
				return Long.compare(A[1],B[1]);
			}
		});
		pque.offer(new long[]{s,0});
		while(!pque.isEmpty()){
			long[] e=pque.poll();
			int from=(int)e[0];
			if(dist[from]!=e[1])
				continue;
			for(int i=0;i<g[from].size();i++){
				int to=(int)g[from].get(i)[0];
				if(dist[to]>dist[from]+g[from].get(i)[1]){
					dist[to]=dist[from]+g[from].get(i)[1];
					pque.offer(new long[]{to,dist[to]});
				}
			}
		}
		return dist;
    }

	static long[] dijkCR(int s,int t,Graph[] g,long[] d){
		int n=g.length;
		long[] num=new long[n];
		boolean[] v=new boolean[n];
		num[s]=1;
		PriorityQueue<long[]> pque=new PriorityQueue<long[]>(new Comparator<long[]>(){
			public int compare(long[] A,long[] B){
				return Long.compare(A[1],B[1]);
			}
		});
		pque.offer(new long[]{s,d[s]});
		while(!pque.isEmpty()){
			long[] e=pque.poll();
			int from=(int)e[0];
			if(v[from])
				continue;
			v[from]=true;
			for(int i=0;i<g[from].size();i++){
				int to=(int)g[from].get(i)[0];
				if(d[to]==d[from]+g[from].get(i)[1]){
					num[to]+=num[from];
					num[to]%=mod;
					pque.offer(new long[]{to,d[to]});
				}
			}
		}
		return num;
	}

	public static void main(String[] args) {
		ir = new InputReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.flush();
	}

	static class InputReader {

		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;

		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}

		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}

		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}

		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}

		public boolean hasNext() {
			skip();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}

	static void tr(Object... o) {
		if (debug)
			out.println(Arrays.deepToString(o));
	}
}