import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[][] ws = new int[n][];
		int lsum = 0;
		for(int i = 0;i < n;i++){
			int L = ni();
			ws[i] = na(L);
			lsum += L;
		}
		int[][] es = new int[lsum][];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < ws[i].length;j++){
				es[p++] = new int[]{a[i], ws[i][j], j == 0 ? 0 : ws[i][j-1]};
			}
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});

		
		long max = 0;
		StarrySkyTree sst = new StarrySkyTree(500005);
		int q = 0;
		for(int i = 1;i <= 500001;i++){
			while(q < lsum && es[q][1] <= 2*i+1){
				sst.add(es[q][2]/2, i, -es[q][0]);
				q++;
			}
			long v = sst.min(0, i);
			max = Math.max(max, -v);
			sst.add(i, i+1, v);
		}
		out.println(max);
	}
	
	public static class StarrySkyTree {
		public int M, H, N;
		public long[] st;
		public long[] plus;
		public long I = Long.MAX_VALUE/4; // I+plus<int
		
		public StarrySkyTree(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			plus = new long[H];
		}
		
		public StarrySkyTree(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			plus = new long[H];
			Arrays.fill(st, H+N, M, I);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]) + plus[i];
		}
		
		public void add(int l, int r, long v){ if(l < r)add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, long v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cur >= H){
					st[cur] += v;
				}else{
					plus[cur] += v;
					propagate(cur);
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public long min(int l, int r){ return l >= r ? I : min(l, r, 0, H, 1);}
		
		private long min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				long ret = I;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret + plus[cur];
			}
		}
		
		public void fall(int i)
		{
			if(i < H){
				if(2*i < H){
					plus[2*i] += plus[i];
					plus[2*i+1] += plus[i];
				}
				st[2*i] += plus[i];
				st[2*i+1] += plus[i];
				plus[i] = 0;
			}
		}
		
		public int firstle(int l, int v) {
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2|cur>>>j&1;
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur;
					}else{
						return cur-H;
					}
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
				}
			}
		}
		
		public int lastle(int l, int v) {
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2|cur>>>j&1;
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur+1;
					}else{
						return cur-H;
					}
				}else{
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
					cur--;
				}
			}
		}
		
		public long[] toArray() { return toArray(1, 0, H, new long[H]); }
		
		private long[] toArray(int cur, int l, int r, long[] ret)
		{
			if(r-l == 1){
				ret[cur-H] = st[cur];
			}else{
				toArray(2*cur, l, l+r>>>1, ret);
				toArray(2*cur+1, l+r>>>1, r, ret);
				for(int i = l;i < r;i++)ret[i] += plus[cur];
			}
			return ret;
		}
	}

	
	public static void main(String[] args) throws Exception
	{
//		int n = 1000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(200000)-100000 + " ");
//		}
//		for(int i = 0;i < n;i++){
//			sb.append(500 + " ");
//			for(int j = 0;j < 500;j++){
//				sb.append(2*j+2 + " ");
//			}
//		}
//		INPUT = sb.toString();

		
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	private static boolean eof()
	{
		if(lenbuf == -1)return true;
		int lptr = ptrbuf;
		while(lptr < lenbuf)if(!isSpaceChar(inbuf[lptr++]))return false;
		
		try {
			is.mark(1000);
			while(true){
				int b = is.read();
				if(b == -1){
					is.reset();
					return true;
				}else if(!isSpaceChar(b)){
					is.reset();
					return false;
				}
			}
		} catch (IOException e) {
			return true;
		}
	}
	
	private static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;
	
	private static int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
//	private static boolean isSpaceChar(int c) { return !(c >= 32 && c <= 126); }
	private static int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private static double nd() { return Double.parseDouble(ns()); }
	private static char nc() { return (char)skip(); }
	
	private static String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private static char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private static char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private static int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private static int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}