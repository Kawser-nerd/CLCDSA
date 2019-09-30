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
		int n = ni();
		int[] a = na(n);
		int ax = 0;
		for(int i = 0;i < n;i++){
			ax ^= a[i];
		}
		int[] b = na(n);
		int bx = 0;
		for(int i = 0;i < n;i++){
			bx ^= b[i];
		}
		int[] aa = Arrays.copyOf(a, n+1);
		aa[n] = ax;
		int[] bb = Arrays.copyOf(b, n+1);
		bb[n] = bx;
		{
			int[] aaa = Arrays.copyOf(aa, aa.length);
			int[] bbb = Arrays.copyOf(bb, bb.length);
			Arrays.sort(aaa);
			Arrays.sort(bbb);
			if(!Arrays.equals(aaa, bbb)){
				out.println("-1");
				return;
			}
		}
		int[] aaa = Arrays.copyOf(aa, aa.length);
		Arrays.sort(aaa);
		aaa = uniq(aaa);
		
		DJSet ds = new DJSet(n+1);
		int ans = 0;
		for(int i = 0;i <= n;i++){
			if(aa[i] != bb[i]){
				ds.union(Arrays.binarySearch(aaa, aa[i]), Arrays.binarySearch(aaa, bb[i]));
				ans++;
			}
		}
//		tr(ds.upper);
		int con = 0;
		for(int i = 0;i <= n;i++){
			if(ds.upper[i] < -1){
				ans--;
				con++;
			}
		}
		if(ans > 0){
			ans += 2*(con-1);
			if(ans > 0 && aa[n] == bb[n]){
				ans += 2;
				for(int i = 0;i < n;i++){
					if(ds.upper[ds.root(Arrays.binarySearch(aaa, aa[i]))] < -1 && aa[i] == aa[n]){
						ans--;
						break;
					}
				}
			}
		}
		out.println(ans);
		
//		int[] from = new int[n+1];
//		int[] to = new int[n+1];
//		int p = 0;
//		for(int i = 0;i <= n;i++){
//			if(aa[i] != bb[i]){
//				from[p] = Arrays.binarySearch(aaa, bb[i]);
//				to[p] = Arrays.binarySearch(aaa, aa[i]);
//				p++;
//			}
//		}
//		int[][] g = packD(n+1, from, to, p);
		
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
	}

	
	public static int[][] packD(int n, int[] from, int[] to){ return packD(n, from, to, from.length);}
	public static int[][] packD(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}
	
	public static int[] uniq(int[] a)
	{
		int n = a.length;
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || a[i] != a[i-1])a[p++] = a[i];
		}
		return Arrays.copyOf(a, p);
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