import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni(), m = ni();
		int[] a = na(n);
		int[] f = new int[n+1];
		for(int v : a){
			f[v]++;
		}
		SegmentTreeUnion st = new SegmentTreeUnion(n+1);
		for(int i = 1;i <= n;i++){
			if(f[i] > 0){
				st.add(Math.max(1, i-f[i]+1), i+1, 1);
			}
		}
		
		
		for(int i = 0;i < m;i++){
			int x = ni()-1;
			int y = ni();
			int o = a[x];
			{
				int v = o;
				st.add(Math.max(1, v-f[v]+1), v+1, -1);
			}
			{
				int v = y;
				st.add(Math.max(1, v-f[v]+1), v+1, -1);
			}
			f[a[x]]--;
			a[x] = y;
			f[a[x]]++;
			{
				int v = y;
				st.add(Math.max(1, v-f[v]+1), v+1, 1);
			}
			{
				int v = o;
				st.add(Math.max(1, v-f[v]+1), v+1, 1);
			}
			out.println(n-st.count[1]);
		}
	}
	
	public static class SegmentTreeUnion {
		public int M, H, N;
		public int[] st;
		public int[] count;
		
		public SegmentTreeUnion(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			count = new int[M];
		}
		
		public SegmentTreeUnion(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			count = new int[M];
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			count[i] = st[i] > 0 ? H/Integer.highestOneBit(i) : count[2*i]+count[2*i+1];
		}
		
		public void add(int l, int r, int v){ add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, int v, int cl, int cr, int cur)
		{
			if(cur >= H){
				st[cur] += v;
				count[cur] = st[cur] > 0 ? 1 : 0;
			}else if(l <= cl && cr <= r){
				st[cur] += v;
				propagate(cur);
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
	}
	
	public static void main(String[] args) throws Exception
	{
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